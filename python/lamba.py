"""
==================================================
PYTHON LAMBDA FUNCTIONS - COMPLETE GUIDE
==================================================

A lambda function is a small anonymous function.

Syntax:

lambda arguments: expression

Equivalent to:

def function_name(arguments):
    return expression

Lambda can only contain ONE expression.
"""

# ==================================================
# 1. BASIC LAMBDA
# ==================================================

square = lambda x: x * x

print(square(5))  # 25


# ==================================================
# 2. MULTIPLE PARAMETERS
# ==================================================

add = lambda a, b: a + b

print(add(10, 20))  # 30


# ==================================================
# 3. THREE PARAMETERS
# ==================================================

multiply = lambda a, b, c: a * b * c

print(multiply(2, 3, 4))  # 24


# ==================================================
# 4. LAMBDA VS NORMAL FUNCTION
# ==================================================

def square_func(x):
    return x * x

square_lambda = lambda x: x * x

print(square_func(4))
print(square_lambda(4))


# ==================================================
# 5. USING LAMBDA WITH map()
# ==================================================

numbers = [1, 2, 3, 4, 5]

result = list(map(lambda x: x * 2, numbers))

print(result)

# Output:
# [2, 4, 6, 8, 10]


# ==================================================
# 6. USING LAMBDA WITH filter()
# ==================================================

numbers = [1, 2, 3, 4, 5, 6]

even_numbers = list(
    filter(lambda x: x % 2 == 0, numbers)
)

print(even_numbers)

# Output:
# [2, 4, 6]


# ==================================================
# 7. USING LAMBDA WITH reduce()
# ==================================================

from functools import reduce

numbers = [1, 2, 3, 4, 5]

total = reduce(
    lambda x, y: x + y,
    numbers
)

print(total)

# Output:
# 15


# ==================================================
# 8. SORTING LIST
# ==================================================

numbers = [5, 2, 8, 1, 9]

numbers.sort(
    key=lambda x: x
)

print(numbers)

# Output:
# [1, 2, 5, 8, 9]


# ==================================================
# 9. SORTING DESCENDING
# ==================================================

numbers = [5, 2, 8, 1, 9]

numbers.sort(
    key=lambda x: x,
    reverse=True
)

print(numbers)

# Output:
# [9, 8, 5, 2, 1]


# ==================================================
# 10. SORT STRINGS BY LENGTH
# ==================================================

words = [
    "apple",
    "kiwi",
    "banana",
    "pear"
]

words.sort(
    key=lambda word: len(word)
)

print(words)

# Output:
# ['kiwi', 'pear', 'apple', 'banana']


# ==================================================
# 11. SORT TUPLES BY SECOND VALUE
# ==================================================

pairs = [
    (1, 5),
    (2, 3),
    (4, 1)
]

pairs.sort(
    key=lambda pair: pair[1]
)

print(pairs)

# Output:
# [(4,1), (2,3), (1,5)]


# ==================================================
# 12. SORT DICTIONARY ITEMS
# ==================================================

students = [
    {"name": "Ali", "marks": 80},
    {"name": "Sara", "marks": 95},
    {"name": "John", "marks": 70}
]

students.sort(
    key=lambda student: student["marks"]
)

print(students)


# ==================================================
# 13. MAX USING LAMBDA
# ==================================================

students = [
    ("Ali", 80),
    ("Sara", 95),
    ("John", 70)
]

top_student = max(
    students,
    key=lambda x: x[1]
)

print(top_student)

# Output:
# ('Sara', 95)


# ==================================================
# 14. MIN USING LAMBDA
# ==================================================

lowest_student = min(
    students,
    key=lambda x: x[1]
)

print(lowest_student)

# Output:
# ('John', 70)


# ==================================================
# 15. ANY()
# ==================================================

numbers = [1, 3, 5, 8]

result = any(
    map(lambda x: x % 2 == 0, numbers)
)

print(result)

# Output:
# True


# ==================================================
# 16. ALL()
# ==================================================

numbers = [2, 4, 6, 8]

result = all(
    map(lambda x: x % 2 == 0, numbers)
)

print(result)

# Output:
# True


# ==================================================
# 17. CONDITIONAL LAMBDA
# ==================================================

even_or_odd = lambda x: "Even" if x % 2 == 0 else "Odd"

print(even_or_odd(7))

# Output:
# Odd


# ==================================================
# 18. MULTIPLE CONDITIONS
# ==================================================

grade = lambda marks: (
    "A" if marks >= 90
    else "B" if marks >= 75
    else "C"
)

print(grade(82))

# Output:
# B


# ==================================================
# 19. LAMBDA RETURNING LAMBDA
# ==================================================

def multiplier(x):
    return lambda y: x * y

double = multiplier(2)

print(double(10))

# Output:
# 20


# ==================================================
# 20. IMMEDIATE EXECUTION
# ==================================================

print(
    (lambda x: x * x)(5)
)

# Output:
# 25


# ==================================================
# 21. LIST COMPREHENSION VS LAMBDA
# ==================================================

numbers = [1, 2, 3, 4, 5]

result = list(
    map(lambda x: x * 2, numbers)
)

print(result)

# Better Python style:

result = [x * 2 for x in numbers]

print(result)


# ==================================================
# LEETCODE MOST IMPORTANT LAMBDAS
# ==================================================

# Sort list
sorted_nums = sorted(
    [5, 2, 8, 1],
    key=lambda x: x
)

# Sort descending
sorted_desc = sorted(
    [5, 2, 8, 1],
    key=lambda x: x,
    reverse=True
)

# Sort by second element
pairs = [(1, 5), (2, 3), (4, 1)]

pairs.sort(
    key=lambda x: x[1]
)

# Max based on second value
best = max(
    pairs,
    key=lambda x: x[1]
)

# Filter even numbers
evens = list(
    filter(lambda x: x % 2 == 0,
           [1, 2, 3, 4, 5, 6])
)

# Map square
squares = list(
    map(lambda x: x * x,
        [1, 2, 3, 4, 5])
)