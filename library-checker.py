import os
import subprocess



LIBRARY_PATH = "library"
IGNORE = set([".DS_Store"])

def get_all_files():
    return [os.path.join(LIBRARY_PATH, e) for e in list(os.walk(LIBRARY_PATH))[0][2]]

def test(path):
    if path.split('/')[-1] in IGNORE: 
        return
    print(path.ljust(30), end="\t", flush=True)
    subprocess.run(["g++", path, "-o", "file", "-std=c++17"]) 
    subprocess.run("./file")
    os.remove("./file")

if __name__ == "__main__":
    for path in get_all_files():
        test(path)
    