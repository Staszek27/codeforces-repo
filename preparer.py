import shutil
import os
import sys
import shutil

def make_CF_contest(dir_number):
    dir_name = os.path.join("rounds", dir_number)
    for letter in "ABCDEFGHIJK": 
        shutil.copytree("template-problem", os.path.join(dir_name, letter))
        shutil.copy(os.path.join(dir_name, letter, "template.cpp"), os.path.join(dir_name, letter, "brut.cpp"))
        shutil.move(os.path.join(dir_name, letter, "template.cpp"), os.path.join(dir_name, letter, "wzor.cpp"))
    
    for f in list(os.walk('template-directory'))[0][2]:
        shutil.copy(os.path.join("template-directory", f), dir_name)

try:
    make_CF_contest(sys.argv[1])
except IndexError:
    print("error: Provide code of a contest!")
    exit(1)