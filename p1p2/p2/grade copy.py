import itertools
import subprocess
import sys
import glob
import os
import io

rootdir = sys.argv[1]
# testRunner = "/homes/cs352/Spring23/Grading/tarindu/p2test/p2grading/test_runner.py"

def runTests(parser, test_dir):
    def checkFile(filename):
        with open(filename, "r") as f:
            lines = f.readlines()
            expected_errlines = itertools.takewhile(lambda line: line.startswith("// Type") or line.startswith("// Syntax"), lines)
            expected_err = ("".join([line[3:] for line in expected_errlines]))


        display_filename = ".".join(filename.split("/")[-1].split(".")[:-1])
        
        proc = subprocess.run([parser, filename], stderr=subprocess.PIPE)
        errbuf = io.StringIO(str(proc.stderr, encoding="utf-8"))
        errlinesiter = errbuf.readlines()
        errlines = itertools.takewhile(lambda line: line.startswith("Syntax") or line.startswith("Type"), errlinesiter)
        err = ("".join([line for line in errlines]))
        
        # err = str(proc.stderr, encoding="utf-8")
        if expected_err.lower().strip() != err.lower().strip():
            if not (display_filename == "StatementAssignBadLValue" and err.lower().strip() == "Type violation in line 7\nType violation in line 7\n".lower().strip()): 
                print(f"\033[91m[ FAIL ]\033[0m {display_filename}")
                print(f"Got error: '{proc.stderr}'")
                print(f"Expected : '{bytes(expected_err, encoding='utf-8')}'")
                print(f"Run '{parser} {filename}'")
                return False

        print(f"\033[92m[ PASS ]\033[0m {display_filename}")
        return True


    files = [file for file in glob.glob(f"{test_dir}/**", recursive=True) if file.endswith(".java")]

    failures = 0
    
    for file in files:
        if not checkFile(file):
            failures += 1

    print(f"Ran {len(files)} test. {failures} failures")
    
for root, dirs, files in os.walk(rootdir):
    for file in files:
        if file == "makefile" or file == "Makefile":
            
            try:
                user = root[len(rootdir):root.find(".Z")]
                print(user)
                
                os.chdir(root)
                os.system(f"make 2>&1")
                # os.system(f"make >/dev/null 2>&1")
                
                parser="./parser"
                test_dir = "/homes/cs352/Spring23/Grading/tarindu/p2test/tests/testcases"
                runTests(parser, test_dir)
                print("####################")
                print()
            except:
                print("####################")
                print()
                continue
            
           