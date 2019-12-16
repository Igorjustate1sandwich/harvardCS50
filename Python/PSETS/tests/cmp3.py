# working file for pset7 (similarities)
import sys

# Variables
n = 7
similarSubs = []

# Open files
f = open("/home/stndn/Documents/Git Repo/Learning/Python/psets/similarities/inputs/test1.txt", "r")
file1 = f.read()
f = open("/home/stndn/Documents/Git Repo/Learning/Python/psets/similarities/inputs/test1.txt", "r")
file2 = f.read()

##### SUBSTRINGS #####
text1 = file1.replace("\n","")
text2 = file2.replace("\n","")

if (n > len(text1) or n > len(text2)):
    exit(1)

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

# Compare and Output
similarSubs = set(substrings1).intersection(set(substrings2))
print(similarSubs)

