import sys
import os
import re

msg_dir = "msg"
if len(sys.argv) > 1:
    msg_dir = sys.argv[1]
try:
    os.mkdir("include/adapter")
except:
    pass
try:
    os.mkdir("include/adapter/serialization")
except:
    pass
try:
    os.mkdir("include/adapter/serialization/apollo_msgs")
except:
    pass
try:
    os.mkdir("src")
except:
    pass
try:
    os.mkdir("src/adapter")
except:
    pass
try:
    os.mkdir("src/adapter/serialization")
except:
    pass
try:
    os.mkdir("src/adapter/serialization/apollo_msgs")
except:
    pass

def roshpp(name):
    a = re.compile('((?<=[a-z0-9])[A-Z]|(?!^)[A-Z](?=[a-z]))')
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

adapters = []
raw_type = ["int32", "int64","bool","float32","float64","uint32","uint64","uint8","string"]
raw_type_desc = ["int", "long", "bool", "float", "double", "uint32_t", "uint64_t", "uint8_t", "std::string"]
raw_type_adapter = ["atoi","atol","(bool)atoi","(float)atof","atof","atoi","atol","(uint8_t)atoi",""]
for root, _, files in os.walk(msg_dir):
    for file in files:
        if file.endswith((".msg")):
            f=file.replace(".msg","")
            ww = open("include/adapter/serialization/apollo_msgs/" + roshpp(f)+ ".hpp", "w")
            wws = open("src/adapter/serialization/apollo_msgs/" + roshpp(f) + ".cpp", "w")
            
            wws.write("#include \"adapter/serialization/apollo_msgs/" + roshpp(f) + ".hpp\"\n")
            ww.write("#pragma once\n")
            ww.write("#include \"apollo_msgs/msg/" + roshpp(f)+ ".hpp\"\n")
            ww.write("#include \"rclcpp/rclcpp.hpp\"\n")
            ww.write("#include \"nlohmann/json.hpp\"\n")
            ww.write("#include \"cyber/common/log.h\"\n")
            ww.write("#include \"adapter/serialization/std_msgs/header.hpp\"\n")
            ww.write("#include <string>\n")
            path = os.path.join(root, file)
            rd = open(path, "r")
            content = rd.readlines()

            included=[]
            for x in content:
                t = x.split()[0]
                if ('/' in t):
                    spl = t.split("/")
                    group = spl[0]
                    t = spl[1].replace("[", "").replace("]", "")
                    toadd = "#include \"adapter/serialization/" + group + "/" + roshpp(t) + ".hpp\"\n"
                    if not toadd in included:
                        ww.write(toadd)
                        included.append(toadd)
                    if (not toadd in adapters) and (not "apollo_msgs" in toadd):
                        adapters.append(toadd)
                else:
                    t = t.replace("[", "").replace("]", "")
                    if t in raw_type:
                        continue
                    toadd="#include \"adapter/serialization/std_msgs/"+roshpp(t)+".hpp\"\n"
                    if not toadd in included:
                        ww.write(toadd)
                        included.append(toadd)
                    if not toadd in adapters:
                        adapters.append(toadd)

            ww.write("namespace apollo_msgs::msg {\n")
            wws.write("namespace apollo_msgs::msg {\n")
            
            ww.write("    nlohmann::json to_json (const " + f + " &msg) ;\n")
            wws.write("    nlohmann::json to_json (const " + f + " &msg) {\n")
            wws.write("        nlohmann::json obj;\n")
            for x in content:
                spll = x.split()
                try:
                    t = spll[0]
                    name = spll[1].split("#")[0]
                except:
                    print(spll)
                group = "std_msgs"
                if ('/' in t):
                    spl = t.split("/")
                    group = spl[0]
                    t = spl[1]
                isArray = "[" in t
                t = t.replace("[", "").replace("]", "")
                if t in raw_type:
                    if isArray:
                        wws.write("        nlohmann::json arr_" + name + ";\n")
                        wws.write("        for (auto it = msg."+name+".begin(); it != msg."+name+".end(); ++it) {\n")
                        wws.write("            arr_" + name + ".push_back((*it));\n")
                        wws.write("        }\n")
                        wws.write("        obj[\""+name+"\"] = arr_" + name + ";\n")
                    else:
                        wws.write("        obj[\""+name+"\"] = (msg."+name+");\n")
                else:
                    if isArray:
                        wws.write("        nlohmann::json arr_" + name + ";\n")
                        wws.write("        for (auto it = msg."+name+".begin(); it != msg."+name+".end(); ++it) {\n")
                        wws.write("            arr_" + name + ".push_back(to_json(*it));\n")
                        wws.write("        }\n")
                        wws.write("        obj[\""+name+"\"] = arr_" + name + ";\n")
                    else:
                        wws.write("        obj[\""+name+"\"] = to_json(msg."+name+");\n")
            wws.write("        return obj;\n")
            wws.write("    }\n")
            ww.write("    "+f+" from_json_"+f+" (nlohmann::json obj) ;\n")
            wws.write("    "+f+" from_json_"+f+" (nlohmann::json obj) {\n")
            wws.write("        "+f+" msg;\n")
            for x in content:
                spll=x.split()
                t = spll[0]
                name=spll[1].split("#")[0]
                group = "std_msgs"
                if ('/' in t):
                    spl = t.split("/")
                    group = spl[0]
                    t = spl[1]
                isArray = "[" in t
                t = t.replace("[", "").replace("]", "")
                
                wws.write("        if(obj.contains(\""+name+"\"))\n")
                wws.write("        {\n")
                if isArray:
                    wws.write("            if(obj[\""+name+"\"].is_array())\n")
                    wws.write("            {\n")
                    wws.write("                for (auto& element : obj[\""+name+"\"])\n")
                    wws.write("                {\n")
                    wws.write("                    msg." + name + ".push_back(")
                    if t in raw_type:
                        adapter = raw_type_adapter[raw_type.index(t)]
                        descriptor = raw_type_desc[raw_type.index(t)]
                        wws.write("(element.is_string()?"+adapter+"(element.get<std::string>().c_str()):")
                        wws.write("element.get<"+descriptor+">())")
                    else:
                        wws.write("from_json_"+t+"(element)")
                    wws.write(");\n")
                    wws.write("                }\n")
                    wws.write("            }\n")
                    wws.write("            else\n")
                    wws.write("            {\n")
                    wws.write("                msg." + name + ".push_back(")
                    if t in raw_type:
                        adapter = raw_type_adapter[raw_type.index(t)]
                        descriptor = raw_type_desc[raw_type.index(t)]
                        wws.write("(obj[\""+name+"\"].is_string()?"+adapter +
                                  "(obj[\""+name+"\"].get<std::string>().c_str()):")
                        wws.write("obj[\""+name+"\"].get<"+descriptor+">())")
                    else:
                        wws.write("from_json_"+t+"(obj[\""+name+"\"])")
                    wws.write(");\n")
                    wws.write("            }\n")
                else:
                    if t in raw_type:
                        adapter = raw_type_adapter[raw_type.index(t)]
                        descriptor = raw_type_desc[raw_type.index(t)]
                        
                        wws.write("            msg." + name + " = ")
                        wws.write("(obj[\""+name+"\"].is_string()?"+adapter+"(obj[\""+name+"\"].get<std::string>().c_str()):")
                        wws.write("obj[\""+name+"\"].get<"+raw_type_desc[raw_type.index(t)]+">());\n")
                    else:
                        wws.write("            msg."+name+" = from_json_"+t+"(obj[\""+name+"\"]);\n")
                wws.write("        }\n")
            wws.write("        return msg;\n")
            wws.write("    }\n")
            ###
            ww.write("    template <>\n")
            ww.write("    " + f + " from_json<" + f + ">(nlohmann::json obj);\n")
            wws.write("    template <>\n")
            wws.write("    " + f + " from_json<" + f + ">(nlohmann::json obj){\n")
            wws.write("        return from_json_" + f + "(obj);\n")
            wws.write("    }\n")
            ww.write("    nlohmann::json &operator>>(nlohmann::json &os, " + f + " &dt);\n")
            wws.write("    nlohmann::json &operator>>(nlohmann::json &os, " + f + " &dt)\n")
            wws.write("    {\n")
            wws.write("        dt=from_json_" + f + "(os);\n")
            wws.write("        return os;\n")
            wws.write("    }\n")
            ww.write("    std::ostream & operator<<(std::ostream & os, const " + f + " & dt);\n")
            wws.write("    std::ostream & operator<<(std::ostream & os, const " + f + " & dt)\n")
            wws.write("    {\n")
            wws.write("        os << to_json(dt);\n")
            wws.write("        return os;\n")
            wws.write("    }\n")
            ww.write("    close_after_if_not_null & operator<<(close_after_if_not_null & os, const " + f + " & dt);\n")
            wws.write("    close_after_if_not_null & operator<<(close_after_if_not_null & os, const " + f + " & dt)\n")
            wws.write("    {\n")
            wws.write("        os << to_json(dt);\n")
            wws.write("        return os;\n")
            wws.write("    }\n")
            #ww.write("    close_after_if_not_null &operator<< (close_after_if_not_null stream, const " + f + " &msg);\n")
            #wws.write("    close_after_if_not_null &operator<< (close_after_if_not_null stream, const " + f + " &msg) {\n")
            #wws.write("        return stream << to_json(msg);\n")
            #wws.write("    }\n")
            rd.close()
            ww.write("}\n")
            ww.close()
            wws.write("}\n")
            wws.close()
adapters = [x.replace("#include \"","").replace("\"\n","") for x in adapters]
print(adapters)
