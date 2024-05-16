import sys
import os
import protobuf_decoder
msg_dir="msg"
if len(sys.argv)>0:
    #print("PROTO FILE IN ",sys.argv[1])
    dir_in = sys.argv[1]
else:
    print("MISSING INPUT DIRECTORY")
    exit(-1)
if len(sys.argv)>2:
    #print("PB.H IN ",sys.argv[2])
    dir_out = sys.argv[2]
else:
    print("MISSING OUTPUT DIRECTORY [-] for console")
    exit(-1)
if len(sys.argv)>3:
    msg_dir = sys.argv[3]
else:
    print("MISSING OUTPUT MSG_DIR [-] for no generation")
    exit(-1)
#print("MSG_DIR ", msg_dir)
def tou(name):
        if(len(name)>0):
            return str(name[0].upper()) + name[1::]
        return name
def clean(name):
    spl=name.split("_")
    return "".join([tou(x) for x in spl])

if msg_dir != "-" and not os.path.exists(msg_dir):
    os.makedirs(msg_dir)
for root, _, files in os.walk(sys.argv[1]):
    for file in files:
        if file.endswith((".proto")):
            path=os.path.join(root, file)
            rd = open (path, "r")
            content = rd.readlines()
            print("Decoding",path)
            h_file, msgs= protobuf_decoder.decode(content)
            
            new_path=path.replace(dir_in,dir_out).replace(".proto",".pb.h")
            if dir_out != "-":
                #print(path,"=>",new_path)
                dir_path=os.path.dirname(new_path)
                if not os.path.exists(dir_path):
                    os.makedirs(dir_path)
            
                ww = open (new_path, "w")
                ww.write(h_file)
                ww.close()
            else:
                print(path,"=>")
                print(h_file)
            if msg_dir != "-":
                for msg in msgs:
                    if(msg.obj_type=="message"):
                        spl=msg.rosname.split("_")
                        message = "".join([tou(x) for x in spl])
                        w = open (os.path.join(msg_dir,message+".msg"), "w")
                        for f in msg.fields:
                            if f[2] is not None:
                                w.write(f[0]+" "+f[1]+" "+f[2]+"\n")
                            else:
                                w.write(f[0]+" "+f[1]+"\n")
                        w.close()
                    if(msg.obj_type == "oneof"):
                        spl = msg.rosname.split("_")
                        message = "".join([tou(x) for x in spl])
                        #print("ONEOF ", os.path.join(msg_dir, message + ".msg"))
                        w = open(os.path.join(msg_dir, message+".msg"), "w")
                        for f in msg.fields:
                            w.write(f[0]+" "+f[1]+"\n")
                        w.close()
                    if(msg.obj_type == "map_msg"):
                        spl = msg.rosname.split("_")
                        message = "".join([tou(x) for x in spl])
                        #print("map_msg ", os.path.join(msg_dir, message + ".msg"))
                        w = open(os.path.join(msg_dir, message+".msg"), "w")
                        for f in msg.fields:
                            w.write(f[0]+" "+f[1]+"\n")
                        w.close()
            
