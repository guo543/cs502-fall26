import itertools
import subprocess
import sys
import glob
import io

parser = sys.argv[1]
test_dir = sys.argv[2]

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
    if expected_err.lower() != err.lower():
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

if failures > 0:
    sys.exit(1)
