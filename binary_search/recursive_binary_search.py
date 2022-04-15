def recursiveBinarySearch(list, target, first = 0, last = None):
    if last is None:
        last = len(list) - 1

    middle = (first + last) // 2

    #stop condition
    if first > last:
        return None
    elif list[middle] == target:
        return middle

    if list[middle] < target:
        return recursiveBinarySearch(list, target, middle + 1, last)
    else:
        return recursiveBinarySearch(list, target, first, middle - 1)

def verify(result):
    if result is not None: 
        print("Found at index", result)
    else:
        print("Not Found")

#main
number = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
print("list =", number)

target = int(input("target = "))

verify(recursiveBinarySearch(number, target))