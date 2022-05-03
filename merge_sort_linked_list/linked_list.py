class Node:
    data = None
    next_node = None

    def __init__(self, data):
        self.data = data
        

    def __repr__(self):
        return "<Node data: " + str(self.data) + ">"


class LinkedList:
    def __init__(self):
        self.head = None

    def isEmpty(self):
        return self.head is None

    def size(self):
        current = self.head #current is a Node object
        count = 0

        while current is not None:
            count += 1
            current = current.next_node
        return count
    
    def add(self, data):
        new_node = Node(data)
        new_node.next_node = self.head
        self.head = new_node

    def search(self, target):
        current = self.head
        while current is not None:
            if current.data == target:
                return True
            else:
                current = current.next_node
        return False

    def insert(self, target_position, data):
        if target_position == 0:
            self.add(data)
        else:
            current_node = self.head
            current_position = 0

            while current_position < target_position - 1:
                current_node = current_node.next_node
                current_position += 1
                if current_node is None:
                    print("Index out of range!")
                    return

            new_node = Node(data)
            new_node.next_node = current_node.next_node
            current_node.next_node = new_node

    #additional method so split function in merge sort can work (since it involves copying the data to new LinkedList or temp LinkedList)
    def getNodeAt(self, index):
        current_node = self.head
        count = 0
        while current_node is not None:
            if count == index:
                break
            current_node = current_node.next_node
            count += 1
        return current_node

    def removeData(self, data):
        current = self.head
        prev_node = None

        while current is not None:
            if current.data == data:
                if current == self.head:
                    self.head = current.next_node
                else:
                    prev_node.next_node = current.next_node
                break
            prev_node = current
            current = current.next_node
        return current

    def __repr__(self) -> None:
        output = []
        current = self.head
        while current is not None:
            if current == self.head:
                output.append("[Head: %s]" % current.data)
            elif current.next_node is None:
                output.append("[Tail: %s]" % current.data)
            else:
                output.append("[%s]" % current.data)
            current = current.next_node

        return " -> ".join(output)