import os

s = "Rearrange an array with extra space"
exe = ".cpp"

s = s.replace(" ", "_")
s = s+exe

if not os.path.exists(s):
    open(s, 'x').close()
    print(f"File {s} created")
else:
    print("File exists")
    
os.system(f"code {s}")
