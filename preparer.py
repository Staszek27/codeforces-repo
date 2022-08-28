from cgi import test
import shutil
from bs4 import BeautifulSoup
import os
import sys
import shutil
import time
import subprocess

def clear_work_files():
    try:
        os.remove("./buffer2.txt")
        os.remove("./buffer.txt")
    except FileNotFoundError:
        pass


def delete_improper_things(s):
    res, ok = "", True
    for e in s:
        if e == '<':
            ok = False
        elif e == '>':
            ok = True
            res += '\n'
        elif ok:
            res += e
    return res


def save_input_outputs(dir_name, letter, data):
    for name in ["inputs", "outputs"]:
        dir_path = os.path.join(dir_name, letter, name)
        os.makedirs(dir_path)

        for i, test_case in enumerate(data[name]):
            file_path = os.path.join(dir_path, f"test{i}.txt")
            with open(file_path, "w") as file_obj:
                file_obj.write(delete_improper_things(test_case))


def check_content(dir_name, content):
    bs = BeautifulSoup(content, "html.parser")
    out_pref = "<div class=\"title\">Output</div><pre>"
    out_suf = "</pre>"

    in_pref = "<div class=\"title\">Input</div><pre>"
    in_suf = "</pre>"

    output_l = ["outputs", out_pref, out_suf]
    input_l = ["inputs", in_pref, in_suf]

    for letter in "ABCDEFGHIJK": 
        res = bs.find_all(problemindex=letter)
        if not res:
            continue
        shutil.copytree("template-directory", os.path.join(dir_name, letter))
        shutil.copy(os.path.join(dir_name, letter, "template.cpp"), os.path.join(dir_name, letter, "brut.cpp"))
        shutil.move(os.path.join(dir_name, letter, "template.cpp"), os.path.join(dir_name, letter, "wzor.cpp"))
        res = str(res[0])

        i, ok, data = 0, True, {"inputs": [], "outputs": []}
        
        while ok:
            for key, pref, suf in [input_l, output_l    ]:
                if pref not in res or suf not in res: 
                    ok = False
                    break
                beg = res.find(pref) + len(pref)
                en = res[beg:].find(suf) + beg
                
                data[key].append(res[beg:en])
                res = res[en:]
        save_input_outputs(dir_name, letter, data)


def make_CF_contest(dir_number):
    dir_name = os.path.join("rounds", dir_number)
    try:
        os.makedirs(dir_name)
    except FileExistsError:
        pass

    while True:
        os_walk_result = list(os.walk(dir_name))[0]
        if os_walk_result[1] + os_walk_result[2]:
            print(f"[{dir_name} finally exists]")
            break

        clear_work_files()
        cmd_line = f"curl https://codeforces.com/contest/{dir_number}/problems > buffer.txt 2> buffer2.txt &"
        print(f"[invoking] {cmd_line}")
        subprocess.run(cmd_line, shell=True)

        time.sleep(0.5)
        if not os.path.exists("buffer.txt"):
            continue

        with open("buffer.txt", "r") as file_obj:
            data = file_obj.read()
            if data == "":
                continue
            check_content(dir_name, data)
        clear_work_files()
    return dir_name

def make_normal_contest(dir_name):
    dir_name = os.path.join("others", dir_name)

    shutil.copytree("template-directory-standard", dir_name)
    for i in range(8):
        shutil.copy("template-directory-standard/rozw1.cpp", f"{dir_name}/rozw{i+2}.cpp")
    return dir_name

try:
    dir_number = str(int(sys.argv[1]))
    dir_name = make_CF_contest(dir_number)
except Exception:
    dir_name = make_normal_contest(sys.argv[1])


