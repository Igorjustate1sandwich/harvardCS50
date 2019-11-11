# Variables
data = 4222222222222
size = len(str(data))
sumDigits = 0

# Convert int into list (array)
numbers = [int(x) for x in str(data)]

# Luhns Algorithim
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
    print("\nCredit card validated successfully! Mod:", total%10)
else:
    print("\nInvalid credit card. Mod:", total%10)







        



