# working file for pset7 (similarities)
import sys

# open files
f = open("/home/stndn/Documents/Git Repo/Learning/Python/psets/similarities/inputs/hello.c", "r")
file1 = f.read()

f = open("/home/stndn/Documents/Git Repo/Learning/Python/psets/similarities/inputs/hey.c", "r")
file2 = f.read()

# split strings into lines and store in list
text1 = file1.splitlines()
text2 = file2.splitlines()


# screen list for duplicates and remove them by creating a dictionary as dicts cannot have duplicate keys
#text1 = list(dict.fromkeys(text1))
#text2 = list(dict.fromkeys(text2))

# compare lines in text1 and text2 and save any similarities
ctr = 0
for i in range(len(text1)):
    for j in range(len(text2)):
        if text1[i] == text2[j] and len(text1[i]) >=1:
            ctr += 1
            print("\nSimilarities detected.")
            print(f"Line in text1: {text1[i]}")
            print(f"Line in text2: {text2[j]}\n")
            break           
print(ctr)