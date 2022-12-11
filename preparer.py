from cgi import test
import shutil
from bs4 import BeautifulSoup
import os
import sys
import shutil
import time
import subprocess


def make_CF_contest(dir_number):
    dir_name = os.path.join("rounds", dir_number)
    for letter in "ABCDEFGHIJK": 
        shutil.copytree("template-directory", os.path.join(dir_name, letter))
        shutil.copy(os.path.join(dir_name, letter, "template.cpp"), os.path.join(dir_name, letter, "brut.cpp"))
        shutil.move(os.path.join(dir_name, letter, "template.cpp"), os.path.join(dir_name, letter, "wzor.cpp"))

make_CF_contest(sys.argv[1])
