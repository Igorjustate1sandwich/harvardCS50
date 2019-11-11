num = [5,12,6,19]
sum = 0


for i in range(4):
    if len(str(num[i])) > 1:
        print(num[i])

        while num[i] > 0:
            digit = num[i] % 10
            num[i] = num[i]//10
            sum += digit
        print(sum)
        sum = 0
        i = 0
        digit = 0

