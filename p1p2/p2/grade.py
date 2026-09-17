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
        
        
        if expected_err.lower().strip() != err.lower().strip():
            if not (display_filename == "StatementAssignBadLValue" and err.lower().strip() == "Type violation in line 7\nType violation in line 7\n".lower().strip()): 
                print(f"\033[91m[ FAIL ]\033[0m {display_filename}")
                print(f"Got error: '{proc.stderr}'")
                print(f"Expected : '{bytes(expected_err, encoding='utf-8')}'")
                print(f"Run '{parser} {filename}'")
                if "type" in expected_err.lower() and not "syntax" in err.lower():
                    return (True, False)
                return (False, False)

        print(f"\033[92m[ PASS ]\033[0m {display_filename}")
        return (True, True)
    


    files = [file for file in glob.glob(f"{test_dir}/**", recursive=True) if file.endswith(".java")]

    syntaxfailures = 0
    typefailures = 0
    
    for file in files:
        (synBool, typeBool) = checkFile(file)
        if not synBool:
            syntaxfailures += 1
        if not typeBool:
            typefailures += 1

    print(f"Ran {len(files)*2} test. {syntaxfailures} syntax failures {typefailures} type failures")
    
for root, dirs, files in os.walk(rootdir):
    for file in files:
        if file == "makefile" or file == "Makefile":
            print("####################")
            try:
                # --- REPLACE THE TWO ORIGINAL LINES WITH THIS ---
                from pathlib import Path
                relative = Path(root).relative_to(Path(rootdir))
                user = relative.parts[0].removesuffix(".Z")
                print(user)
                # ------------------------------------------------
                
                os.chdir(root)
                
                os.system(f"make 2>&1")
#                os.system(f"make >/dev/null 2>&1")
                
                # subprocess.check_output("make clean", shell=True)
                # make = subprocess.check_output("make 2>&1", shell=True)
                # print(make.decode("utf-8"))
                
                print("####################")
                parser="./parser"
                test_dir = "/homes/cs352/Spring23/Grading/tarindu/p2test/tests/testcases"
                runTests(parser, test_dir)
                print("####################")
                print()
            except:
                print("####################")
                print()
                continue
            
           
