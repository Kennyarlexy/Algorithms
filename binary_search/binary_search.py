def binarySearch(list, target):
    result = None
    first = 0
    last = len(list) - 1
    while first <= last:
        middle = (first + last) // 2
        if list[middle] == target:
            result = middle
            break
        elif list[middle] < target:
            first = middle + 1
        else:
            last = middle - 1

    return result

def verify(result):
    if result is not None: 
        print("Found at index", result)
    else:
        print("Not Found")

#main
number = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
print("list =", number)

target = int(input("target = "))

verify(binarySearch(number, target))