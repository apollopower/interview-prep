# Return the count of nodes in a binary tree:

class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def add_tree_node(root, val):
    if not root:
        return TreeNode(val)
    elif val < root.val:
        root.left = add_tree_node(root.left, val)
    else:
        root.right = add_tree_node(root.right, val)
    
    return root

def in_order_traversal(root):
    if root.left:
        in_order_traversal(root.left)
    if root:
        print(root.val)
    if root.right:
        in_order_traversal(root.right)

def count_nodes(root):
    node_count = 0
    node_stack = [root]

    while len(node_stack):
        node = node_stack.pop()

        node_count += 1

        if node.left:
            node_stack.append(node.left)
        if node.right:
            node_stack.append(node.right)
    
    return node_count

root = TreeNode(10)

add_tree_node(root, 5)
add_tree_node(root, 3)
add_tree_node(root, 9)
add_tree_node(root, 4)
add_tree_node(root, 15)
add_tree_node(root, 11)

print(count_nodes(root))