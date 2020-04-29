import sys

# Usage checking
if (len(sys.argv)) != 2:
    print("Usage: python3 bleep.py dictionaryfile")
    exit(1)

def main():
    # Open and read file
    f = open(f"{sys.argv[1]}", "r")
    file = f.read()
    file = file.split()

    # Convert file contents to uppercase and lowercase, then store in a python set
    bannedWordsUpper = set(file.upper() for file in file)
    bannedWordsLower = set(file.lower() for file in file)

    # Prompt user to provide a message
    print("What message would you like to censor?")
    message = input().split()

    # Compare user message with lowercase and uppercase banned words then make modifications
    for x in range(len(message)):
        for bannedWord in bannedWordsUpper:
            if message[x] == bannedWord:
                bleep = ""
                for j in range(len(bannedWord)):
                    bleep = bleep + "*"
                message[x] = bleep

        for bannedWord in bannedWordsLower:
            if message[x] == bannedWord:
                bleep = ""
                for j in range(len(bannedWord)):
                    bleep = bleep + "*"
                message[x] = bleep

    # Return censored version of user message
    message = " ".join(message)
    print(message)


if __name__ == "__main__":
    main()