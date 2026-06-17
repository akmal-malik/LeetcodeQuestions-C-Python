Input_word = input("Enter the word: ")

reformed_word = ""
i = 0

while i < len(Input_word):
    if Input_word[i] == 'G':
        reformed_word += 'G'
        i += 1

    elif Input_word[i:i+2] == '()':
        reformed_word += 'o'
        i += 2

    elif Input_word[i:i+4] == '(al)':
        reformed_word += 'al'
        i += 4

print("reformed_word is", reformed_word)