def linearSearch(list, target):
    result = None
    #returns the index if found, otherwise return None
    for i in range(len(list)):
        if list[i] == target:
            result = i
            break

    return result

def verify(result):
    #we use is keyword to check an object's identity, since None is not technically a value (there is no value in variable result in the first place)
    if result is not None: 
        print("Found at index", result)
    else:
        print("Not Found")

#main
number = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
print("list =", number)

target = int(input("target = "))

verify(linearSearch(number, target))