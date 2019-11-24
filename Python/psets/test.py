import sys

# READ DICTIONARY WITH BANNED WORDS
f = open("/home/stndn/Documents/Git Repo/Learning/Python/psets/banned.txt", "r")
file = f.read()
file = file.split()
file = [file.lower() for file in file]
bannedWords = set(file)

# MESSAGE
raw = "what the heck are you doing"
modified = raw.split()
modified = [modified.lower() for modified in modified]


# Compare message with dictionary
for x in range(len(modified)):
    for i in bannedWords:
        if modified[x] == i:
            print("BAD WORD =", i)

