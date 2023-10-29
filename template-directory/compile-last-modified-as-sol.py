import os
import subprocess
import datetime 

SOLUTION_NAME = "sol"

def get_cur_time():
    return datetime.datetime.timestamp(datetime.datetime.now())

def run_command(command, with_output_print = False):
    process = subprocess.Popen(
        command.split(), 
        **(dict(stdout=subprocess.PIPE, stderr=subprocess.PIPE) if not with_output_print else dict())
    )
    stdout, stderr = process.communicate()
    return stdout.decode() if not with_output_print else None


def get_modified_time(path):
    result = run_command(f"GetFileInfo -m {path}")
    date, time = result.split()
    month, day, year = date.split('/')
    date = f"{year}/{month}/{day}"
    return " ".join([date, time])


def get_cpp_file_paths():
    res = []
    for root, _, files in os.walk(".", topdown=False):
        for name in files:
            path = os.path.join(root, name)
            if path.split('.')[-1] != "cpp": continue
            res.append(path)
    return res

def get_best_path_by_timestap():
    l = []
    for path in get_cpp_file_paths():
        l.append((get_modified_time(path), path))
    l = sorted(l)
    return l[-1][1]

def compile(path):
    print(f"[compiling {path}]\n")
    return run_command(
        f"g++ {path} -o {SOLUTION_NAME} -std=c++17  -W -Wall -fstack-protector-all -O3", 
        with_output_print=True
    )

if __name__ == "__main__":
    path = get_best_path_by_timestap()
    compile(path)
    print()