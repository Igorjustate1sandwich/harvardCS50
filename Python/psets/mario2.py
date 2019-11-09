# Conditional Checking
while True:
    print("Height:", end=" ")
    height = input()

    # Try to convert height into int. If user inputted str, print error and retry.
    try:
        height = int(height)
    except ValueError:
        print("Height must be an integer between 1 and 8.")
        continue

    # Make sure int is within bounds.
    if height < 1 or height > 8:
        print("Height must be an integer between 1 and 8.")
    else:
        break

# Logic
for i in range(height):
    for j in range((height-i)-1):   # track how much whitespace to print for each line
        print(" ", end="")          # print whitespace
    for k in range(i+1):
        print("#", end="")          # print n hashes on one line. "" prevents newline
    print()  