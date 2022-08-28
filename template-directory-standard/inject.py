import sys
import os
key_word = "// inject here"
library_path = "../../../library"

def get_content(name):
    with open(f"{library_path}/{name}.cpp", "r") as file_obj:
        file_data = file_obj.read()
        ind = file_data.index(key_word)
        ind += len(key_word)
        return file_data[ind:]

def inject_content(content):
    data = None
    with open("wzor.cpp", "r") as file_obj:
        file_data = file_obj.read()
        data = file_data.replace(key_word, f"{key_word}\n{content}")

    with open("wzor.cpp", "w") as file_obj:
        file_obj.write(data)

name = sys.argv[1]

if name == '-ls':
    os.system(f"ls {library_path}")
else:   
    content_to_inject = get_content(name)
    inject_content(content_to_inject)
