# Given two singly linked lists that intersect at some point, 
# find the intersecting node. The lists are non-cyclical.

# For example, given A = 3 -> 7 -> 8 -> 10 and B = 99 -> 1 -> 8 -> 10,
# return the node with value 8.

# In this example, assume nodes with the same value are the exact same node objects.

class ListNode:
    def __init__(self, val):
        self.val = val
        self.next_ = None
    
    def add_node(self, val):
        current_node = self
        while current_node.next_:
            current_node = current_node.next_
        current_node.next_ = ListNode(val)


def merge_value(list_1, list_2):
    list_set = set()
    current_node = list_1
    while current_node:
        list_set.add(current_node.val)
        current_node = current_node.next_
    
    current_node = list_2
    while current_node:
        if current_node.val in list_set:
            return current_node.val
        current_node = current_node.next_
    
    return None

list_1 = ListNode(1)
for i in range(2,6):
    list_1.add_node(i)

list_2 = ListNode(9)
list_2.add_node(7)
list_2.add_node(5)

print(merge_value(list_1, list_2))