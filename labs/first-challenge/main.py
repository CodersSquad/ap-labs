def substring(string):
    if(not string):
        return -1
    mySet = set()
    counter = 0
    for letter in string:
        if(letter not in mySet):
            mySet.add(letter)
            if(len(mySet)>counter):
                counter = len(mySet)
        else: 
            mySet.clear()
            mySet.add(letter)
    return counter
print(substring("pwwkew"))
