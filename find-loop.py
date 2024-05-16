import sys
import os

msg_dir = "msg"
if len(sys.argv) > 1:
    msg_dir = sys.argv[1]

def throw_if_loop(content, names):
    for line in content:
        if line.startswith("apollo_msgs/"):
            msg = line.split()[0].split("/")[1].replace("[", "").replace("]", "")
            msg_file = msg + ".msg"
            if msg_file in names:
                raise Exception("->".join(names) + "->" +msg_file)
            path = os.path.join(msg_dir, msg_file)
            rd = open(path, "r")
            content = rd.readlines()
            throw_if_loop(content,[*names,msg_file])
            rd.close()

for root, _, files in os.walk(msg_dir):
    for file in files:
        if file.endswith((".msg")):
            path = os.path.join(root, file)
            rd = open(path, "r")
            content = rd.readlines()
            try:
                throw_if_loop(content, [file])
            except Exception as e:
                print(e)
            rd.close()
