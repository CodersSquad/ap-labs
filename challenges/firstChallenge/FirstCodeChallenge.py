word = input('Input: ')
a = ''
b = ''
i = 0
while (word[i] not in a and i < len(word)):
    a  += word[i]
    i += 1

while (i < len(word)):
    if  (word[i] in b):
        b  = word[i]
    else:
        b += word[i]
    if len(b) > len(a):
        a = b
        b = ''
    i += 1
print('Output: ',len(a))
