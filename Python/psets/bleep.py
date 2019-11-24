import sys

if (len(sys.argv)) != 2:
    print("Usage: python3 bleep.py dictionaryfile")
    exit(1)

def main():
    # open and read file
    f = open(f"{sys.argv[1]}", "r")
    file = f.read()
    file = file.split()

    # Convert file contents to lowercase
    file = [file.lower() for file in file]

    # store file contents in python set
    dictionary = set(file)
    print(dictionary)

    # prompt user to provide a message


if __name__ == "__main__":
    main()
