import sys
import os
key_word = "// inject here"
key_word_stop = "// inject stop"
library_path = "/Users/michal/Documents/codeforces/codeforces-repo/library"

def get_art_begin(lib_name):
    return """
// -----  BEGIN: {}  -----
//
//              O  o
//         _\_   o       [ lovely fish is ready ]
//      \\\/  o\ .        [   to help you with   ]
//      //\___=          [    this problem!     ]
//         ''
//          

""".format(lib_name)

def get_art_en(lib_name):
    return "// -----   END: {}   -----\n\n".format(lib_name)

def get_content(name):
    with open(f"{library_path}/{name}.cpp", "r") as file_obj:
        file_data = file_obj.read()
        ind = file_data.find(key_word)
        ind_stop = file_data.find(key_word_stop)
        ind += len(key_word)
        return "{}{}{}".format(
            get_art_begin(name),
            file_data[ind:ind_stop],
            get_art_en(name),
        )
    


def inject_content(content):
    data = None
    dest_file = os.path.join('.', "wzor.cpp")
    with open(dest_file, "r") as file_obj:
        file_data = file_obj.read()
        data = file_data.replace(key_word, f"{key_word}\n{content}")

    with open(dest_file, "w") as file_obj:
        file_obj.write(data)

try:
    lib_name = sys.argv[1]
    if lib_name == '-ls':
        os.system(f"ls {library_path}")
    else:   
        letter = sys.argv[2]
        content_to_inject = get_content(lib_name)
        inject_content(content_to_inject)
except IndexError:
    print("Please use like:")
    print("1. python3 inject.py -ls")
    print("2. python3 point-seg-tree A")
