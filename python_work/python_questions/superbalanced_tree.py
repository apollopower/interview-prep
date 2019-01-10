# Write a function to see if a binary tree is "superbalanced", meaning that
# the difference in depths between any leaf nodes is not greater than 1.


# ANSWER

# We need to reach all the leaf nodes of our tree, and check their depth level.
# If we have more than 2 depth levels, that would not fit the definition of 
# "superbalanced", and should return false. If 2 depth levels differ by more than
# one, it is also not superbalanced, so we can return false as well. We ONLY return
# True IF we check all leaf nodes and depths and are sure that the difference is only 1
# (between at most 2 depths)

# The fastest way to traverse the tree and hit a leaf node would be through a depth-first-search.
# By implementing a stack, we can use DFS to reach leaves, keeping track of nodes and their depths along the way

# Runtime => O(N), we need to traverse all nodes in the tree only once

# Space => O(N), we need to create a stack that will at most hold nodes as deep as the tree.
# So TECHNICALLY, space is O(D), where D is the depth. The depths set will only hold no more than
# 3 items at once, so the space for it is O(1)

def is_balanced(tree_root):

    # Determine if the tree is superbalanced
    if tree_root is None:
        return True
    
    # Short circuit if length is greater than 2
    depths = set()
    
    # "Stack" to keep track of tuple that holds node and its depth
    node_stack = []
    
    node_stack.append((tree_root, 0))
    
    while len(node_stack):
        node, depth = node_stack.pop()
        
        # Case: node is a leaf
        if not node.left and not node.right:
            # Check depth, add it to depths (if not already in depths)
            if depth not in depths:
                depths.add(depth)
            
                if len(depths) > 2 or (len(depths) == 2 and abs(dephts[0] - depths[1]) > 1):
                    return False
        else:
            if node.left:
                node_stack.append((node.left, depth + 1))
            
            if node.right:
                node_stack.append((node.right, depth + 1))
    

    return True