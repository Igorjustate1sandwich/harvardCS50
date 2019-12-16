# working file for pset7 (similarities)
import sys

# Variables
n = 2
similarSubs = []

# Open files
f = open("/home/stndn/Documents/Git Repo/Learning/Python/psets/similarities/inputs/test1.txt", "r")
file1 = f.read()
f = open("/home/stndn/Documents/Git Repo/Learning/Python/psets/similarities/inputs/test2.txt", "r")
file2 = f.read()

##### SUBSTRINGS #####
text1 = file1.replace("\n","")
text2 = file2.replace("\n","")

#print(text1.replace("\n",""))
#print(text2.replace("\n",""))

# Find all substrings in text1
substrings1 = []
x = 0
j = n
while x < len(text1):
    substrings1.append(text1[x:j])
    j+=1
    x+=1
    # If a potential substring is not exactly n characters long then QUIT as there are no more substrings to find.
    if (len(text1[x:j]) != n):
        break

# Find all substrings in text2
substrings2 = []
x = 0
j = n
while x < len(text2):
    substrings2.append(text2[x:j])
    j+=1
    x+=1
    # If a potential substring is not exactly n characters long then QUIT as there are no more substrings to find.
    if (len(text2[x:j]) != n):
        break

# Compare
ctr = 0
for i in range(len(substrings1)):
    for j in range (len(substrings2)):
        if (substrings1[i] == substrings2[j] and len(substrings1[i]) >=1):
            ctr+=1
            similarSubs.append(substrings1[i])
            print(f"{substrings1[i]} = {substrings2[j]}")
            break

# Output
print(ctr, similarSubs)

# ADVICE, USE SET INSTEAD OF LIST FOR SUBSTR