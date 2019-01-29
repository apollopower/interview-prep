# Given the head of a linked list, reverse it in-place:

class ListNode():
    def __init__(self, val):
        self.val = val
        self.next_ = None

    def add_node(self, val):
        current = self
        while current.next_:
            current = current.next_
        current.next_ = ListNode(val)

    def print_list(self):
        current = self
        while current:
            print(current.val)
            current = current.next_

    def reverse_list(self):
        self
        prev = None
        next_ = None
        
        while self:
            # Save the value of the upcoming node to transfer later
            next_ = self.next_
            # point the current node to the previous one
            self.next_ = prev
            
            # Reverse is done, set up previous node and current node for next iteration
            prev = self
            self = next_


root = ListNode(10)
root.add_node(13)
root.add_node(19)
root.add_node(4)

root.print_list()

print("Reversing list........................")

root.reverse_list()

root.print_list()
