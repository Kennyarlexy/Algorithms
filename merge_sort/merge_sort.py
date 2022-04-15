def split(list):
    """
    split the unsorted list into left and right half
    return left and right
    """
    mid = (len(list) + 1) // 2
    left = list[:mid]
    right = list[mid:]

    return left, right

def merge(left, right):
    merged = []
    i = 0
    j = 0

    while i < len(left) and j < len(right):
        if (left[i] < right[j]):
            merged.append(left[i])
            i += 1
        else:
            merged.append(right[j])
            j += 1
    
    while i < len(left):
        merged.append(left[i])
        i += 1

    while j < len(right):
        merged.append(right[j])
        j += 1
    
    return merged

def mergeSort(list):
    """
    divide list into two halves, sort each half and combine them back.
    return the newly sorted list.
    """
    if len(list) <= 1:
        return list

    leftHalf, rightHalf = split(list)
    leftHalf = mergeSort(leftHalf)
    rightHalf = mergeSort(rightHalf)

    return merge(leftHalf, rightHalf)

def verifySorted(list, begin = 0):
    if begin + 1 == len(list):
        return True

    return list[begin] <= list[begin + 1] and verifySorted(list, begin+1)

#main
list = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
list = mergeSort(list)
print(list)
print(verifySorted(list))