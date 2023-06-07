import os

s = "Find First and Last Position of Element in Sorted Array"
exe = ".cpp"

s = s.replace(" ", "_")
s = s+exe

if not os.path.exists(s):
    open(s, 'x').close()
    print(f"File {s} created")
else:
    print("File exists")

os.system(f"code {s}")
