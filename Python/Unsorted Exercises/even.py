#### Python division ####
# Floating Point Division (regular)
    # Gives exact value
    # 15 / 2 = 7.50

# Integer Division
    # Rounds variable down to nearest whole
    # 15 / 2 = 7

# Boolean expression to determine whether 'x' is even or odd. 
# This REQUIRES integer division as the value must be rounded down.
# If you did floating point divison, you'd always get an 'even' response regardless of 'x'.
x = 15
if (x//2) * 2 == x:
    print("Even")
else:
    print("Odd")


# Floating Point: (15/2) * 2 == 15.0 (Technically correct, but incompatible with formula as 15.0 is not an even number.)
# Integer: (15 // 2) * 2 == 14 (14 not equal to 15 , therefore print "Odd" which is true since 15 is a odd number.)
