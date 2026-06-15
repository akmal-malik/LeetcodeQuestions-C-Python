
def  reverse_integer ():
    rev = 0
    num = int(input("enter the number"))
    sign = 1
    while num > 0:
        rem = num % 10
        rev = (rev*10) + rem
        num = num // 10
    if sign < 0:
        rev = -rev
    if rev < -2**31 or rev > 2**31 -1:
        return 0
    return rev

result = reverse_integer()
print(result)










    