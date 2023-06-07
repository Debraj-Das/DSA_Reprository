# remove all .exe files from the current repository
import os
for root, dirs, files in os.walk("."):
    for file in files:
        if (file.endswith(".exe")):
            os.remove(os.path.join(root, file)) 

# add the staged files to the commit
os.system("git add .")

#* message for the commit
s = "Completed the Recursion , Binary tree , BST , Some part of Matrix completed"

# commit the changes with a message
os.system(f"git commit -m \"{s}\"")
# push the changes to the remote repository
os.system("git push origin master")

print("All changes are commit and pushed to the remote repository")
