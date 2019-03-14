# Implementing a Linked List in Python


# First, we define the concept of a node, which will have a value
# and a pointer that leads to the next node (if any)

class ListNode:
    def __init__(self, val):
        self.val = val
        self.next_ = None

    # How to add a new node? We go down the linked list until next_
    # is a null value
    def add_node(self, val):
        current_node = self
        while current_node.next_:
            current_node = current_node.next_

        current_node.next_ = ListNode(val)

    # And to print the list, we just need to traverse it:
    def print_list(self):
        current_node = self
        while current_node:
            print(current_node.val)
            current_node = current_node.next_


# Example:

root = ListNode(5)

root.add_node(14)
root.add_node(82)
root.add_node(-1)

root.print_list()
