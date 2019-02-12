# Given the root of a binary tree, return its deepest node

class TreeNode():
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None


def add_node(root, val):
    if root is None:
        return TreeNode(val)
    elif val < root.val:
        root.left = add_node(root.left, val)
    else:
        root.right = add_node(root.right, val)
    return root

def in_order_trav(root):
    if root.left:
        in_order_trav(root.left)

    print(root.val)

    if root.right:
        in_order_trav(root.right)

root = TreeNode(10)
add_node(root, 20)
add_node(root, 1)
add_node(root, 15)

in_order_trav(root)
