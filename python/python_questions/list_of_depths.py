# Write code that would transorm a binary tree into an array
# of linked lists, where each linked list is a chain of all nodes
# at a particular depth in the tree. For example, a tree with 5 depths
# should have 5 linked lists inside the final array

# BINARY TREE NODE CLASS
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None


# LINKED LIST NODE CLASS
class ListNode:
    def __init__(self, val):
        self.val = val
        self.next_ = None
    
    def add_list_node(self, val):
        current = self

        while current.next_:
            current = current.next_

        current.next_ = ListNode(val)



# ANSWER

# Runtime => O(N)?
# Space => O(N), returning a list of linked lists according to size of input tree

from queue import Queue

def tree_to_lists(root):

    linked_lists = []
    current_depth = -1
    current_list = None

    node_queue = Queue()

    node_queue.put((root, 0))

    while not node_queue.empty():
        node, depth = node_queue.get()

        if depth != current_depth:
            if current_list:
                linked_lists.append(current_list)

            current_list = ListNode(node)
        else:
            current_list.add_list_node(node)
        
        if node.left:
            node_queue.put((node.left, depth + 1))
        if node.right:
            node_queue.put((node.right, depth + 1))
    
    if current_list != linked_lists[-1]:
        linked_lists.append(current_list)
    
    return linked_lists