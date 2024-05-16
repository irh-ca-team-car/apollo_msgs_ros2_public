import sys
import os
for root, _, files in os.walk(sys.argv[1]):
    for file in files:
        if file.endswith((".msg")):
            path=os.path.join(root, file)
            rd = open (path, "r")
            # Read list of lines
            out = rd.readlines()
            rd.close()
            out_lines = []
            try:
                for line in out:
                    obj_type = line.split()[0]
                    if(obj_type.startswith("apollo_msgs/")):
                        obj_type=obj_type[len("apollo_msgs/")::]
                        was_array = "[" in obj_type
                        obj_name = line.split()[1]
                        obj_type=obj_type.split("[")[0]
                        if not os.path.exists(os.path.join(sys.argv[2],obj_type+".msg")):
                            if not "Type" in obj_type:
                                print("Does not exists",path,obj_type)
                            out_lines.append("int32"+("[] " if was_array else " ")+obj_name+"#"+obj_type+"\n")
                        else:
                            out_lines.append(line)
                    else:
                        out_lines.append(line)
            except:
                print("Error ",path)
            rd = open (path, "w")
            # Read list of lines
            for line in out_lines:
                rd.write(line)
            rd.close()
