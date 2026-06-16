n = int(input("enter the number of elements in the list"))
nums = []

for _ in range(n):
    num = int(input("enter a number: "))
    nums.append(num)

print("nums before loop =", nums)

mylist = []

for i in range(1, len(nums)):
    nums[i] += nums[i-1]
    print(f"i={i}, nums={nums}")
    mylist.append(nums[i])

print("mylist =", mylist)