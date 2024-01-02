import shutil
import os
import sys
import shutil

def make_template_directory(dir_name, to_fail = False):
    for f in list(os.walk('template-directory'))[0][2]:
        shutil.copy(os.path.join("template-directory", f), dir_name)
    print("Prevent code -r")
    sys.exit(1)

def make_CF_contest(dir_name):
    for letter in "ABCDEFGHIJK": 
        shutil.copytree("template-problem", os.path.join(dir_name, letter))
        shutil.copy(os.path.join(dir_name, letter, "template.cpp"), os.path.join(dir_name, letter, "brut.cpp"))
        shutil.move(os.path.join(dir_name, letter, "template.cpp"), os.path.join(dir_name, letter, "wzor.cpp"))
    make_template_directory(dir_name)


try:
    round_name = sys.argv[1].split('/')[-1]
    dir_name = os.path.join("rounds", round_name)
    if len(sys.argv) > 2:
        if sys.argv[2] == 'reset':
            make_template_directory(dir_name, True)
        else:
            print("error: Second arg must be reset")
    else:
        try:
            make_CF_contest(dir_name)
        except FileExistsError:
            print("OK. contest already exists.")
except IndexError:
    print("error: Provide code of a contest!")
    exit(1)