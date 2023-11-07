import sys
import os
import importlib  
get_best_path_by_timestap = importlib.import_module(
    "compile-last-modified-as-sol").get_best_path_by_timestap

begin_word    = "BEGIN"
end_word      = " END "
key_word      = "// inject here"
key_word_stop = "// inject stop"
library_path  = "/Users/michal/Documents/codeforces/codeforces-repo/library"


def place_string_in_the_middle(word, c, total = 30):
    rest = total - len(word)
    l, r = rest // 2, rest - rest // 2
    return f"{c*l}{word}{c*r}"

def comment(s):
    return "\n".join([f"// {line}" for line in s.split("\n")])

def inset(b, word):
    return comment(
        f"{b} ---> {place_string_in_the_middle(word, ' ')} <---")

def get_content(name):
    with open(f"{library_path}/{name}.cpp", "r") as file_obj:
        file_data = file_obj.read()
        ind = file_data.find(key_word)
        ind_stop = file_data.find(key_word_stop)
        ind += len(key_word)
        return "\n{}{}{}\n".format(
            inset(begin_word, name),
            file_data[ind:ind_stop],
            inset(end_word, name),
        )
    
def clean(dest_file):
    def find_first_index_with(word, lines, from_begin = True):
        for line in lines:
            print(line)
        return (min if from_begin else max)([
            i for i, line in enumerate(lines)
            if line.find(word) != -1
        ])

    data = None
    with open(dest_file, "r") as file_obj:
        try:
            lines = file_obj.read().split("\n")
            beg_idx = find_first_index_with(begin_word, lines)
            en_idx  = find_first_index_with(end_word, lines, False)
            data = "\n".join(lines[:beg_idx] + lines[en_idx+1:])
        except ValueError:
            print(f"Format of {dest_file} does not allow to perform this operation")
            return
    with open(dest_file, "w") as file_obj:
        file_obj.write(data)

def inject_content(content, dest_file):
    data = None
    with open(dest_file, "r") as file_obj:
        file_data = file_obj.read()
        data = file_data.replace(key_word, f"{key_word}\n{content}")

    with open(dest_file, "w") as file_obj:
        file_obj.write(data)


if __name__ == "__main__":
    lib_name = sys.argv[1]
    if lib_name == '-ls':
        os.system(f"ls {library_path}")
    else:   
        letter = get_best_path_by_timestap().split('/')[-2]
        dest_file = os.path.join(letter, "wzor.cpp")
        if lib_name == "-clean": 
            clean(dest_file)
        else:
            inject_content(get_content(lib_name), dest_file)
        print(f"OK - {dest_file} modified")
