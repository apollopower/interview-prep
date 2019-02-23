from queue import Queue

class TreeNode():
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
    

def add_node(root, val):
    if not root:
        return TreeNode(val)
    elif val < root.val:
        root.left = add_node(root.left, val)
    else:
        root.right = add_node(root.right, val)
    return root

def bfs(root):
    tree_queue = Queue()
    tree_queue.put(root)

    while not tree_queue.empty():
        current = tree_queue.get()

        print(current.val)

        if current.left:
            tree_queue.put(current.left)
        if current.right:
            tree_queue.put(current.right)

def in_order_trav(root):
    if root.left:
        in_order_trav(root.left)
    
    print(root.val)

    if root.right:
        in_order_trav(root.right)

# Running some sample tests on this

root = TreeNode(10)

add_node(root, 20)
add_node(root, 5)
add_node(root, 15)
add_node(root, 7)
add_node(root, 12)
add_node(root, 2)

in_order_trav(root)