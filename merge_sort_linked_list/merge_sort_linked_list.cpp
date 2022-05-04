#include "linked_list.cpp" //not recommended to include .cpp file in a real world projects, use .h file instead to define the class and other .cpp file for the implementation.

pair<LinkedList, LinkedList> split(LinkedList &linked_list) {
    /*
    since LinkedList only contains a single pointer -- which is the head -- then there is no need to worry about the memory usage when creating a new LinkedList from an existing one.
    We're essentially creating a new pointer to the old existing linked_list -- which nodes never actually changes.
    */
    int mid = (linked_list.size() - 1) / 2;
    Node* mid_node = linked_list.getNodeAt(mid);

    LinkedList left = linked_list;
    LinkedList right;
    right.head = mid_node->next_node;
    mid_node->next_node = nullptr;

    return make_pair(left, right);
}

LinkedList merge(LinkedList &left, LinkedList &right) { 
    LinkedList merged;
    merged.add(0);
    Node* merged_pointer = merged.head;
    Node* left_pointer = left.head;
    Node* right_pointer = right.head;

    while (left_pointer != nullptr && right_pointer != nullptr) {
        if (left_pointer->data < right_pointer->data) {
            merged_pointer->next_node = left_pointer;
            left_pointer = left_pointer->next_node;
        } else {
            merged_pointer->next_node = right_pointer;
            right_pointer = right_pointer->next_node;
        }
        merged_pointer = merged_pointer->next_node;
    }

    while (left_pointer != nullptr) {
        merged_pointer->next_node = left_pointer;
        left_pointer = left_pointer->next_node;
        merged_pointer = merged_pointer->next_node;
    }

    while (right_pointer != nullptr) {
        merged_pointer->next_node = right_pointer;
        right_pointer = right_pointer->next_node;
        merged_pointer = merged_pointer->next_node;
    }

    //discard the temp head node
    merged.head = merged.head->next_node;

    return merged;
}

LinkedList mergeSort(LinkedList &linked_list) {
    if (linked_list.size() < 2) return linked_list;

    LinkedList left, right;
    tie(left, right) = split(linked_list);
    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}

int main() {
    LinkedList test;
    test.add(10);
    test.add(20);
    test.add(30);
    test.add(40);
    
    LinkedList sorted = mergeSort(test);
    cout << sorted << "\n";
    
    return 0;
}