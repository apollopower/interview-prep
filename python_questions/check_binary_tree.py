# Write a function to check if a binary tree is a valid
# binary search tree (BST). Here is a binary tree node class:

class tree_node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
    
    def insert_left(self, val):
        self.left = tree_node(val)
    
    def insert_right(self, val):
        self.right = tree_node(val)


# ANSWER

# To be a valid BST, a node must make sure that its left child is LESS than
# its own value, and that its right child is GREATER than its own value. 

# We need to check all nodes in the tree to make sure it is valid, so we will take
# at least O(N) time to traverse the tree. Our options to traverse the tree are BFS
# (breadth-first-search) and DFS (depth-first-search). Both are valid options, but
# for this example we will implement DFS.

# While traversing the tree, we will keep track of 3 items at once: the current node
# we are checking, a lower bound (the value it must be greater than. For example, a node
# who is the right child of another must be larger than the parent. The parent's value will
# be the  lower bound), as well as an upper bound (same concept but for a left child).

# If a current node's value goes over any of its bounds, than we know it is not a valid BST. If
# we traverse the entire tree and all of the node's fall within their proper bounds, then it is a 
# valid BST

def check_binary_tree(root):

    # Our "stack", which will keep track of a node ands its bounds.
    # Remember, DFS implements stacks while BFS implements queues to
    # tracerse trees. This is why we are treating this list as a stack

    nodes_with_bounds = []

    # We start by adding the root, and arbitrary upper and lower bounds (since
    # the root is not bounded by any parental values)

    nodes_with_bounds.append((root, -float('inf'), float('inf')))

    # Our while loop that runs while we still have nodes to check
    while len(nodes_with_bounds):
        
        # Pop the node and its bounds from our stack
        node, lower_bound, upper_bound = nodes_with_bounds.pop()

        # Let us check if the node's value does not fall within its bounds
        if node.val <= lower_bound or node.val >= upper_bound:
            # Out of bounds, end function call and return False. Not a valid
            # BST
            return False
        
        # Check for left and right children. If they exist, append them to the
        # stack. Depending on wether a right or left child, we will specify a 
        # lower or upper bound based on the current node's value

        if node.left:
            nodes_with_bounds.append((node.left, lower_bound, node.val))
        
        if node.right:
            nodes_with_bounds.append((node.right, node.val, upper_bound))
    
    # We now have traverse the entire tree. This means all nodes are valid, and
    # the given tree is a valid BST
    return True