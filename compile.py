# make name=NAME -> Will look for the file with the name NAME in all subdirectories and:
# 1. If it is a .c file, it will compile it, create a .o file and execute it. Then, it will delete the .o file.
# 2. If it is a .cpp file, it will compile it, create a .o file and execute it. Then, it will delete the .o file.
# 3. If it is a .py file, it will execute it.
# 4. If it is a .jl file, it will execute it.
# It will redirect the input from the file ./inputs/NAME.in and the output to the file ./outputs/NAME.out.

#!/usr/bin/env python

import os
import subprocess
import sys

def find_file(filename):
    for root, dirs, files in os.walk('.'):
        if filename in files:
            return os.path.join(root, filename)
    return None

def execute_c(file_path, filename):
    filename = os.path.splitext(filename)[0]
    subprocess.call(['gcc', '-o', os.path.splitext(file_path)[0], '-O3', file_path, '-lm'])
    subprocess.call([os.path.splitext(file_path)[0]], 
                    stdin=open(f'./inputs/{filename}.in', 'r'),
                    stdout=open(f'./outputs/{filename}.out', 'w'))
    subprocess.call(['rm', os.path.splitext(file_path)[0]])

def execute_cpp(file_path, filename):
    filename = os.path.splitext(filename)[0]
    subprocess.call(['g++', '-o', os.path.splitext(file_path)[0], '-O3', file_path, '-lm'])
    subprocess.call([os.path.splitext(file_path)[0]], 
                    stdin=open(f'./inputs/{filename}.in', 'r'),
                    stdout=open(f'./outputs/{filename}.out', 'w'))
    subprocess.call(['rm', os.path.splitext(file_path)[0]])

def execute_py(file_path, filename):
    filename = os.path.splitext(filename)[0]
    subprocess.call(['python', file_path], 
                    stdin=open(f'./inputs/{filename}.in', 'r'),
                    stdout=open(f'./outputs/{filename}.out', 'w'))

def execute_jl(file_path, filename):
    filename = os.path.splitext(filename)[0]
    subprocess.call(['julia', '-O3', file_path], 
                    stdin=open(f'./inputs/{filename}.in', 'r'),
                    stdout=open(f'./outputs/{filename}.out', 'w'))

if __name__ == '__main__':
    if len(sys.argv) != 2:
        print("Usage: ./script.py FILENAME")
        sys.exit(1)

    filename = sys.argv[1]
    file_path = find_file(filename)

    if file_path is None:
        print(f"File {filename} not found.")
        sys.exit(1)

    print(f"Found file: {file_path}")

    _, file_extension = os.path.splitext(file_path)
    subprocess.call(['python3', 'inputs/inputs.py', os.path.splitext(filename)[0]])
    if file_extension == '.c':
        execute_c(file_path, filename)
    elif file_extension == '.cpp':
        execute_cpp(file_path, filename)
    elif file_extension == '.py':
        execute_py(file_path, filename)
    elif file_extension == '.jl':
        execute_jl(file_path, filename)
    else:
        print("Unsupported file type.")
