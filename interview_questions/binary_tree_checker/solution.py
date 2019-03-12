# Write a function to check if a binary tree is a correct implementation of a binary search tree

class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

    def add_left(self, val):
        root = self
        while root.left:
            root = root.left
        root.left = TreeNode(val)
        return self 

    def add_right(self, val):
        root = self
        while root.right:
            root = root.right
        root.right = TreeNode(val)
        return self

# To create a proper binary search tree
def add_node(root, val):
    if root is None:
        return TreeNode(val)
    elif val < root.val:
        root.left = add_node(root.left, val)
    else:
        root.right = add_node(root.right, val)
    return root



def binary_tree_checker(root):
    tree_stack = []
    tree_stack.append((root, -float('inf'), float('inf')))

    while len(tree_stack):
        node, lower_bound, upper_bound = tree_stack.pop()

        if node.val <= lower_bound or node.val >= upper_bound:
            return False

        if node.left:
            tree_stack.append((node.left, lower_bound, node.val))

        if node.right:
            tree_stack.append((node.right, node.val, upper_bound))

    return True

# TESTS

# Invalid tree implementation
invalid = TreeNode(20)
invalid.add_left(10)
invalid.add_right(30)
invalid.add_left(60)

# Valid tree implementation
valid = TreeNode(10)
add_node(valid, 20)
add_node(valid, 5)
add_node(valid, 3)
add_node(valid, 7)


assert(binary_tree_checker(invalid) == False)
assert(binary_tree_checker(valid) == True)

