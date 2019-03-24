# Implement a linked list that has a prepend and an append method

class ListNode:
    def __init__(self, val):
        self.val = val
        self.next_ = None
        self.tail = self

    def append_node(self, val):
        self.last.next_ = ListNode(val)
        self.last = self.last.next_

    def print_list(self, val):
        current = self
        while current:
            print(current.val, end='')
            current = current.next_
        print()

