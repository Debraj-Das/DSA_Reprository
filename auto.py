import os

def remove():
    files = [f for f in os.listdir('.') if os.path.isfile(f) if f.endswith(".exe")]
    for file in files:
        os.remove(file)

def move(no_move_files):
    files = [f for f in os.listdir('.') if os.path.isfile(f) if f.endswith(".cpp")]
    for file in files:
        if (file not in no_move_files):
            os.system(f"move {file} ./Code")

def commit(commit_message):
    os.system("git add .")
    os.system(f"git commit -m \"{commit_message}\"")
    os.system("git push origin master")

def main(files, message):
    remove()
    move(no_move_files=files)
    commit(commit_message=message)


not_move_files = {"Rough.cpp", "test.cpp"}
commit_message = "Practice of DSA"

main(not_move_files, commit_message)