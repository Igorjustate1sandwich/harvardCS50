# Final solution for pset6 (credit) by stndn.
# PSET Specification: https://cs50.harvard.edu/x/2020/psets/6/credit/
# Example: Input 4012888888881881 and get 'VISA' as output.

# Conditional checking & variable declarations
while True:
    print("\nNumber:", end=" ")
    data = input()

    # Convert string input into integer (because credit card numbers are integers....)
    try:
        data = int(data)
    except ValueError:
        print("Invalid input. Try again.")
        continue

    # Make sure data is positive (because credit card numbers don't have negative values...)
    if data <= 0:
        print("Invalid input. Try again.")
    else:
        break

size = len(str(data))
sumDigits = 0
total = 0

# Convert int into list (array)
numbers = [int(x) for x in str(data)]

# Determine whether card is VISA, AMEX or Mastercard (or neither)
if numbers[0] == 4:
    card = "VISA"
elif numbers[0] == 3 and numbers[1] == 4 or numbers[1] == 7:
    card = "AMEX"
elif numbers[0] == 5 and numbers[1] == 1 or numbers[0] == 5 and numbers[1] == 2 or numbers[0] == 5 and numbers[1] == 2 or numbers[0] == 5 and numbers[1] == 3 or numbers[0] == 5 and numbers[1] == 4 or numbers[1] == 5 and numbers[1] == 5:
    card = "MASTERCARD"
else:
    card = "Unknown Card"

# Luhns Algorithim
# https://en.wikipedia.org/wiki/Luhn_algorithm
for i in range(size-2, -1, -2):
    # Step 1: Double value of every second digit
    numbers[i] = numbers[i] * 2

    # Step 2: If doubling results in a two digit number, sumDigits both digits
    if len(str(numbers[i])) > 1:
        while numbers[i] > 0:
            digit = numbers[i] % 10
            numbers[i] = numbers[i]//10
            sumDigits += digit
        numbers[i] = sumDigits
        sumDigits = 0
    
    # Step 3: sumDigits all the digits
    total = sum(numbers)

# Step 4: Determine validity via modulo
if (total % 10) == 0:
    print(card)
else:
    print("INVALID\n")