import os

LIBRARY_PATH = "./library"
INJECTOR_PATH = "./template-directory/library-injector.md"
TOKEN = "$$$"
PATTERN = """
```bash {cmd}
python3 inject.py $$$ >> logs.txt
```
"""
SECTION_PREF = "##"
SUFFIX = """

## tools

### clean libraries in the current file

```bash {cmd}
python3 inject.py  -clean >> logs.txt
```

### show lib

```bash {cmd}
python3 inject.py  -ls
```

### update markdown

```bash {cmd}
cd ~/Documents/codeforces/codeforces-repo && python3 library-injector-gen.py

```

### update files in the current directory

```bash {cmd}
PWD=$(pwd)
cd ~/Documents/codeforces/codeforces-repo
./preparer.sh $PWD 
```

"""

def gen_seg(path):
    return PATTERN.replace(TOKEN, path) 

def upd_d(d, path):
    path = path[len(LIBRARY_PATH)+1:]
    section_name = " ".join(path.split("/")[:-1])
    if section_name == "": return
    if section_name not in d:
        d[section_name] = ""
    d[section_name] += gen_seg(path)

def gen_context():
    d = dict()
    for root, _, files in os.walk(LIBRARY_PATH):
        for fn in files:
            upd_d(d, os.path.join(root, fn))

    res = ""
    for sec_name, data in d.items():
        res += f"{SECTION_PREF} {sec_name}\n{data}"
    return res + SUFFIX

def save_context(data):
    with open(INJECTOR_PATH, "w") as fp:
        fp.write(data)

if __name__ == "__main__":
    save_context(gen_context())
            