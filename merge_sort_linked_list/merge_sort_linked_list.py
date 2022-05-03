from linked_list import LinkedList

def split(linked_list):
    """
    get the median index, this median is the end of the first half. we call this mid.
    from this median index, get the node at that index.
    create new splited LinkedList named left and right.
    return left and right
    """
    
    mid = (linked_list.size() - 1) // 2 #end of the left half (index)

    mid_node = linked_list.getNodeAt(mid)
    left = linked_list
    right = LinkedList()
    right.head = mid_node.next_node
    mid_node.next_node = None

    return left, right

def merge(left, right):
    """
    create an new LinkedList to store the merged result, but need to add a temp head node to merged so we can reference next_node.
    this will be discarded later after all process done
    """
    
    merged = LinkedList()
    merged.add(0)
    merged_pointer = merged.head
    left_pointer = left.head
    right_pointer = right.head

    while left_pointer is not None and right_pointer is not None:
        if left_pointer.data < right_pointer.data:
            merged_pointer.next_node = left_pointer
            left_pointer = left_pointer.next_node
        else:
            merged_pointer.next_node = right_pointer
            right_pointer = right_pointer.next_node
        merged_pointer = merged_pointer.next_node

    while left_pointer is not None:
        merged_pointer.next_node = left_pointer
        left_pointer = left_pointer.next_node
        merged_pointer = merged_pointer.next_node

    while right_pointer is not None:
        merged_pointer.next_node = right_pointer
        right_pointer = right_pointer.next_node
        merged_pointer = merged_pointer.next_node

    #discard the temp head node
    merged.head = merged.head.next_node

    return merged

def merge_sort(linked_list):
    if linked_list.size() < 2:
        return linked_list

    left, right = split(linked_list)
    left = merge_sort(left)
    right = merge_sort(right)

    return merge(left, right)


#main
test = LinkedList()
test.add(32)
test.add(2)
test.add(54)
test.add(413)
test.add(22)
test.add(145)
test.add(65)
test.add(14)
test.add(55)
test.add(8)

print(test)
sorted = merge_sort(test)
print(sorted)