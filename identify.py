import sys
import os
import re

msg_dir = "msg"
if len(sys.argv) > 1:
    msg_dir = sys.argv[1]

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
referenced = ["ApollocanbusChassis","ApollostaticTransformConf","ApolloperceptionPerceptionLanes","ApollothirdPartyPerceptionRadarObstacles","ApollothirdPartyPerceptionRadarObstacles","ApollolocalizationLocalizationEstimate"]

adapters = []
raw_type = ["int32", "int64","bool","float32","float64","uint32","uint64","uint8","string"]
raw_type_desc = ["int", "long", "bool", "float", "double", "uint32_t", "uint64_t", "uint8_t", "std::string"]
raw_type_adapter = ["atoi","atol","(bool)atoi","(float)atof","atof","atoi","atol","(uint8_t)atoi",""]
for root, _, files in os.walk(msg_dir):
    len_before = 0
    while len_before != len(referenced):
        len_before= len(referenced)
        for file in files:
            if file.endswith((".msg")):
                f=file.replace(".msg","")
                
                if f not in referenced: 
                    if "hdmap" in f or "relativeMap" in f:
                        referenced.append(f)
                    continue
                path = os.path.join(root, file)
                rd = open(path, "r")
                content = rd.readlines()

                for x in content:
                    spl = x.split()
                    if(len(spl)==0): continue
                    t = spl[0]
                    if ('/' in t):
                        spl = t.split("/")
                        group = spl[0]
                        t = spl[1].replace("[", "").replace("]", "")
                        if t not in referenced: 
                            referenced.append(t)

    unused = set([f.replace(".msg","") for f in files if ".msg" in f]) - set(referenced)
    
print(referenced)
print("unused",unused)

for x in unused:
    os.remove("msg/"+x+".msg")
