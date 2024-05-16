import re
class proto_obj:
    def __init__(self):
        self.lines=[]
        self.fields=[]
        self.obj_type="NONE"
        self.name = ""
        self.rosname=""
        self.hasNested=False
        self.parent=None
        self.keepall=False
    def getName(self):
        if self.parent is not None:
            return self.parent.getName()+"::"+self.getCleanName()
        return self.getCleanName()
    def getCleanName(self):
        return self.name.replace(".", "::").replace(";", "")
    def getCleanRosName(self):
        return self.rosname.replace(".","::").replace(";","")
    def __str__(self):
        return self.obj_type+ " "+ self.getName()+"\r\n"+ ("\r\n".join(self.lines))
    def __repr__(self):
        return self.obj_type+ " "+ self.getName()
def tou(e):
    if(len(e)>0):
        e = str(e[0].upper()) + e[1::]
    return e
        
def clean(name):
    spl = name.split("_")
    e = "".join([tou(x) for x in spl])
    return e

def decode(lines):
    a = re.compile('((?<=[a-z0-9])[A-Z]|(?!^)[A-Z](?=[a-z]))')
    translation = {
    "double":"float64",
    "float":"float32",
    "apollo.common.Header":"apollo_msgs/ApollocommonHeader",
    "apollocommonHeader": "apollo_msgs/ApollocommonHeader",
    "bytes":"apollo_msgs/Bytes",
    "Bytes":"apollo_msgs/Bytes",
    "ApollocommonBytes":"apollo_msgs/Bytes",
    "ApollodriversgnssconfigBytes":"apollo_msgs/Bytes",
    "String":"string",
    "Double":"float64",
    "Float":"float32",
    "Int32":"int32",
    "Bool":"bool",
    "Uint32":"uint32",
    "Uint64":"uint64",
    "Int64":"int64"
    }
    forbidden = []
    stack=[]
    current_obj=proto_obj()
    out_lines=["#pragma once"]
    out_objs = [current_obj]
    
        
    def roshpp(name):
        tmp = a.sub(r'_\1', name).lower()
        toremove=[]
        for i in range(len(tmp)):
            c1 = tmp[i]
            if c1=="_" and len(tmp) > i+1:
                c=tmp[i+1]
                if c.isdigit():
                    toremove.append(i)
        string = "".join([tmp[i] for i in range(len(tmp)) if not i in toremove])
        return string

    def begin(name,object_type):
        current_obj=stack[-1]
        current_obj.hasNested=True
        
        current_obj=proto_obj()
        current_obj.keepall = object_type=="enum"
        current_obj.parent=stack[-1]
        current_obj.name = name
        if(current_obj.parent.rosname  == ""):
            current_obj.rosname = current_obj.parent.getCleanName().replace("::", "") + name
        else:
            current_obj.rosname=current_obj.parent.getCleanRosName().replace("::","") + name
        current_obj.obj_type=object_type
        current_obj.lines=[]
        current_obj.fields=[]
        stack.append(current_obj)


    def endMessage():
        current_obj=stack[-1]
        out_objs.append(current_obj)
        current_obj = stack.pop()
        #print(current_obj)
        
    def appendField(field_type,field_name,isArray, defaultVal):
        current_obj = stack[-1]
        field_type = field_type.strip ()
        field_name=field_name.strip ()
        if(field_type in forbidden):
            raise Exception(field_type)
        if("_" in field_name):
            field_type=clean(field_type)
        if(field_type in translation):
            field_type = translation[field_type]
        if("." in field_type):
            field_type = "apollo_msgs/" + tou(field_type.replace(".", ""))
        if (field_type[0].isupper()):
            d = current_obj
            while (d.parent != None):
                d = d.parent
                
            field_type = "apollo_msgs/" + \
                clean(tou(d.name.replace("::", "").replace(
                    ";", "").replace(".", "")))+field_type
        if(isArray):
            field_type=field_type+"[]"
        if("[][]" in field_type):
            raise Exception(field_type)
        if("_" in field_name):
            field_name=clean(field_name)
        field_name = (field_name.lower().replace("=", "").replace(";", ""))
        if(field_name=="static"):
            field_name = "staticc"
        if(field_name=="virtual"):
            field_name = "virtuall"
        if(field_name == "yield"):
            field_name = "yieldd"
        if(field_name == "header"):
            field_name = "apolloheader"
        if "/" in field_type:
            defaultVal=None  
        if(isArray and defaultVal is not None):
            print (field_type,field_name,defaultVal)
        if defaultVal is not None:
            if defaultVal[-2::] == ("];"):
                defaultVal = defaultVal[0:-2]
            if defaultVal == "nan":
                defaultVal=None
       
        current_obj.fields.append([field_type,field_name, defaultVal])
    
    stack=[current_obj]
    out_objs=[current_obj]
    out_lines=["#pragma once"]
    for line in lines:
        try:
            line=line.strip()
            current_obj=stack[-1]
            if("{}" in line):
                continue
            if(line.startswith("package")):
                current_obj.name = line.split()[1]
            elif(line.startswith("import")):
                out_lines.append(line.replace("import","#include").replace(".proto",".pb.h").replace(";",""))
            elif(line.startswith("message")):
                if("}" in line):
                    print("FAILURE, INCORRECT FORMATTING FOR LINE::",line)
                    exit(-1)
                begin(line.split()[1],"message")
            elif(line.startswith("enum")):
                if("}" in line):
                    print("FAILURE, INCORRECT FORMATTING FOR LINE::",line)
                    exit(-1)
                begin(line.split()[1],"enum")
            elif(line.startswith("oneof")):
                if("}" in line):
                    print("FAILURE, INCORRECT FORMATTING FOR LINE::",line)
                    exit(-1)
                field_name = line.split()[1]
                field_type = tou(stack[-1].name.replace("::", "").replace(
                        ";", "").replace(".", ""))+field_name
                appendField(field_type, field_name, False,None)
                begin(field_name, "oneof")
            elif(line.startswith("map<")):
                field_name = line.split(">")[1].split()[0]
                field_type = tou(stack[-1].name.replace("::", "").replace(
                        ";", "").replace(".", ""))+field_name
                appendField(field_type, field_name, True,None)
                
                map_types = line.split(">")[0].split("<")[1].split(",")
                
                begin(field_name, "map_msg")
                appendField(map_types[0],"key",False,None)
                appendField(map_types[1],"data",False,None)
                endMessage()

            elif(line.startswith("service")):
                if("}" in line):
                    print("FAILURE, INCORRECT FORMATTING FOR LINE::",line)
                    exit(-1)
                begin(line.split()[1],"service")
            elif(line.startswith("}")):
                endMessage()
            elif(line.startswith(("optional","required"))):
                defaultVal=None
                spl = line.split()
                if("default =" in line) or ("default=" in line):
                    idx = len(spl) - spl[::-1].index("=")
                    defaultVal=spl[idx]
                spl = line.split()
                field_type = spl[1]
                field_name = spl[2]
                appendField(field_type, field_name, False, defaultVal)
            elif(current_obj.obj_type == "oneof" and "=" in line):
                spl = line.split()
                if (len(spl) != 4):
                    print(line)
                field_type = spl[0]
                field_name = spl[1]
                appendField(field_type,field_name,False,None)
            elif(line.startswith("repeated")):
                defaultVal=None
                spl = line.split()
                if("default =" in line) or ("default=" in line):
                    idx = len(spl) - spl[::-1].index("=")
                    defaultVal=spl[idx]
                
                field_type = spl[1]
                field_name = spl[2]
                appendField(field_type,field_name,True,defaultVal )
            elif current_obj.keepall:
                current_obj.lines.append("\t\t"+line.replace(";",","))
        except Exception as e :
            print("Cannot process line",line)
            raise e
    for obj in out_objs:
        if obj.obj_type == "message" :
            out_lines.append("#include \"apollo_msgs/msg/" + roshpp(obj.getCleanRosName()) + ".hpp\"")
            out_lines.append("#include \"adapter/serialization/apollo_msgs/"+roshpp(obj.getCleanRosName())+".hpp\"")
            if obj.hasNested == False:
                out_lines.append("namespace "+obj.parent.getName()+"{")
                out_lines.append("\ttypedef apollo_msgs::msg::"+clean(obj.rosname)+" "+(obj.getCleanName())+";")
                out_lines.append("}")
    for obj in out_objs:
        if obj.obj_type == "enum":
            out_lines.append("namespace "+obj.parent.getName()+"{")
            out_lines.append("\tenum "+obj.getCleanName()+" {")
            if(len(obj.lines)==0):
                print("FAILURE")
                print(obj,obj.lines,obj.fields,obj.obj_type)
                exit(-1)
            obj.lines[-1]=obj.lines[-1].replace(",","")
            out_lines.extend(obj.lines)
            out_lines.append("\t};")
            out_lines.append("}")
    return "\r\n".join(out_lines), [i for i in out_objs if (i.obj_type == "message" or i.obj_type == "oneof" or i.obj_type == "map_msg") and
        (not "dreamview" in i.rosname)
    ]
