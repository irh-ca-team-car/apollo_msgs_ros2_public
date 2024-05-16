import sys
import os

print("PROTO FILE IN ",sys.argv[1],":")
stack=[]
message=""
fields=[]
obj_type="NONE"


translation = {
    "double":"float64",
    "float":"float32",
    "apollo.common.Header":"apollo_msgs/ApolloCommonHeader",
    "apollocommonHeader": "apollo_msgs/ApolloCommonHeader",
    "bytes":"apollo_msgs/Bytes",
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

def begin(name,object_type):
    global stack, message, fields,obj_type
    stack.append(fields)
    stack.append(message)
    stack.append(obj_type)
    message=name
    fields=[]
    obj_type=object_type
def clean(name):
    spl=name.split("_")
    return "".join([str(x[0].upper())+x[1::] for x in spl])

def endMessage():
    global stack, message, fields,obj_type
    if(obj_type=="message"):
        message = clean(message)
        w = open (os.path.join("msg",message+".msg"), "w")
        for f in fields:
            w.write(f[0]+" "+f[1]+"\n")
        w.close()
    obj_type=stack.pop()
    message = stack.pop()
    fields = stack.pop()
def appendField(field_type,field_name,isArray=False, defaultValue=None):
    global stack, message, fields,obj_type
    if(field_type in forbidden):
        raise Exception(field_type)
    if("_" in field_name):
        field_type=clean(field_type)
    if(field_type in translation):
        field_type = translation[field_type]
    if("." in field_type):
        field_type="apollo_msgs/"+field_type.split(".")[-1]
    if(field_type[0].isupper()):
        field_type="apollo_msgs/"+field_type
    if(isArray):
        field_type=field_type+"[]"
    if("[][]" in field_type):
        raise Exception(field_type)
    field_name=field_name.lower().replace("=","")
    if(field_name=="virtual"):
        field_name="virtual_l"
    fields.append([field_type,field_name])
def decode(path,lines):
    global stack, message, fields,obj_type
    stack=[]
    message=""
    fields=[]
    for line in lines:
        try:
            line=line.strip()
            if(line.startswith("message")):
                begin(line.split()[1],"message")
            if(line.startswith("enum")):
                begin(line.split()[1],"enum")
            if(line.startswith("oneof")):
                begin(line.split()[1],"oneof")
            if(line.startswith("service")):
                begin(line.split()[1],"service")
            if(line.startswith("}")):
                endMessage()
            if(line.startswith(("optional","required"))):
                if("default" in line):
                    print(line, line.split())
                    exit(-1)
                spl = line.split()
                field_type = spl[1]
                field_name = spl[2]
                appendField(field_type,field_name)
            if(line.startswith("repeated")):
                spl = line.split()
                field_type = spl[1]
                field_name = spl[2]
                appendField(field_type,field_name,True)
        except:
            print(path,"Cannot process line",line)

for root, _, files in os.walk(sys.argv[1]):
    for file in files:
        if file.endswith((".proto")):
            path=os.path.join(root, file)
            rd = open (path, "r")
            # Read list of lines
            out = rd.readlines()
            decode(path,out)
