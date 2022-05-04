#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
using namespace std;

struct Node {
    int data;
    Node* next_node;
    Node() {}
    
    Node(int data) {
        this->data = data;
        this->next_node = nullptr;
    }
};

ostream& operator << (ostream& output, Node node) {
    output << "<node data: " << node.data << ">";

    return output;
}

struct LinkedList {
    Node* head;
    LinkedList() {
        this->head = nullptr;
    }

    bool isEmpty() {
        return this->head == nullptr;
    }

    void add(int data) {
        Node* new_node = new Node(data);
        new_node->next_node = this->head;
        this->head = new_node;
    }

    int size() {
        Node* current = this->head;
        int size = 0;
        while (current != nullptr) {
            size++;
            current = current->next_node;
        }

        return size;
    }

    bool search(int target) {
        Node* current = this->head;
        while (current != nullptr) {
            if (current->data == target) {
                return true;
            } else {
                current = current->next_node;
            }
        }

        return false;
    }

    void insert(int target_position, int data) {
        if (target_position == 0) {
            this->add(data);
        } else {
            Node* current_node = this->head;
            int current_position = 0;
            while (current_position < target_position - 1) {
                current_node = current_node->next_node;
                current_position++;
                if (current_node == nullptr) {
                    cout << "Index out of range!\n";
                    return;
                }
            }

            Node* new_node = new Node(data);
            new_node->next_node = current_node->next_node;
            current_node->next_node = new_node;
        }
    }

    Node* removeData(int data) {
        Node* current = this->head;
        Node* prev_node = nullptr;

        while (current != nullptr) {
            if (current->data == data) {
                if (current == this->head) {
                    this->head = current->next_node;
                } else {
                    prev_node->next_node = current->next_node;
                }
                return current;
            }
            prev_node = current;
            current = current->next_node;
        }
        
        return nullptr;
    }

    Node* getNodeAt(int index) {
        Node* current_node = this->head;
        int count = 0;
        while (current_node != nullptr) {
            if (count == index) break;
            current_node = current_node->next_node;
            count++;
        }

        return current_node;
    }
};

//works independently from operator for Node objects
ostream& operator << (ostream& output, const LinkedList& list) {
    Node* current = list.head;
    while (current != nullptr) {
        if (current == list.head) {
            output << "[Head: " << current->data << "]";
        } else if (current->next_node == nullptr) {
            output << " -> [Tail: " << current->data << "]";
        } else {
            output << " -> [" << current->data << "]";
        }
        current = current->next_node;
    }

    return output;
}