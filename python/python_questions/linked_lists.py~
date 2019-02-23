class ListNode():
    def __init__(self, val):
        self.val = val
        self.next_ = None

    def add_node(self, val):
        current = self
        while current.next_:
            current = current.next_
        current.next_ = ListNode(val)

    def remove_node(self, val):
        current = self
        
        if self.val == val:
            self = self.next_
            return self
        else:
            while current.next_.val != val:
                current = current.next_
            current.next_ = current.next_.next_
            return self

    def print_nodes(self):
        current = self
        while current:
            print(current.val)
            current = current.next_
 
root = ListNode(5)
root.add_node(8)
root.add_node(13)
root.add_node(19)

root.remove_node(5)

root.print_nodes()
