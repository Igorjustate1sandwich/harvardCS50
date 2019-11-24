import sys

# usage checking
if (len(sys.argv)) != 2:
    print("Usage: python3 bleep.py dictionaryfile")
    exit(1)

def main():
    # open and read file
    f = open(f"{sys.argv[1]}", "r")
    file = f.read()
    file = file.split()

    # Convert file contents to uppercase and lowercase
    fileUp = [file.upper() for file in file]
    fileLow = [file.lower() for file in file]

    # Store file contents in python set
    bannedWordsUpper = set(fileUp)      # contains words that are lower ("heck", "gosh" etc...)
    bannedWordsLower = set(fileLow)     # contains words that are upper ("HECK", "GOSH" etc...)

    # prompt user to provide a message
    print("What message would you like to censor?")        
    modifiedMsg = input().split()

    # Compare user message with lowercase and uppercase banned words then make modifications
    for x in range(len(modifiedMsg)):
        for i in bannedWordsUpper:
            if modifiedMsg[x] == i:
                bleep = ""
                for j in range(len(i)):
                    bleep = bleep + "*"
                modifiedMsg[x] = bleep

        for i in bannedWordsLower:
            if modifiedMsg[x] == i:
                bleep = ""
                for j in range(len(i)):
                    bleep = bleep + "*"
                modifiedMsg[x] = bleep

    # Return censored version of user message
    modifiedMsg = " ".join(modifiedMsg)
    print(modifiedMsg)


if __name__ == "__main__":
    main()