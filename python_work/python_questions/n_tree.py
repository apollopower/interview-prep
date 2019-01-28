from queue import Queue

class TreeNode():
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

# ------------------------------------
    
def add_tree_node(root, val):
    if root is None:
        return TreeNode(val)
    elif val < root.val:
        root.left = add_tree_node(root.left, val)
    else:
        root.right = add_tree_node(root.right, val)
    return root

def in_order(root):
    if root.left:
        in_order(root.left)

    print(root.val)

    if root.right:
        in_order(root.right)


# Adding tests

root = TreeNode(10)

add_tree_node(root, 20)
add_tree_node(root, 5)
add_tree_node(root, 13)
add_tree_node(root, 7)

in_order(root)
