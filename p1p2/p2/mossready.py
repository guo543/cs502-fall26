import itertools
import subprocess
import sys
import glob
import os
import io

rootdir = sys.argv[1]
# testRunner = "/homes/cs352/Spring23/Grading/tarindu/p2test/p2grading/test_runner.py"
    
mosssubspath = "/homes/cs352/Spring23/Grading/tarindu/p2test/p2grading/mosssubs"
os.system(f"rm -rf {mosssubspath}")
os.system(f"mkdir {mosssubspath}")
    
for root, dirs, files in os.walk(rootdir):
    for file in files:
        if file == "makefile" or file == "Makefile":       
            try:
                user = root[len(rootdir):root.find(".Z")]
                print(user)
                
                os.chdir(root)
                os.system(f"mkdir {mosssubspath}/{user}")
                os.system(f"cp * {mosssubspath}/{user}")
                
                print("####################")
                print()
            except:
                print("Failed")
                print()
                continue
            
           