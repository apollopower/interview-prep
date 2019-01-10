# Write a function that returns the sum of values of nodes at a given depth
# for a binary tree, where 0 would be the root, and each level after
# increments by 1:

class TreeNode():

    def __init__(self, val):
        self.val = val
        self.children = set()
    
    def add_node(self, val):
        self.children.add(TreeNode(val))






# ANSWER

# Like most tree problems, the key here is traversal. We are given
# a root, and then need to travel down to the desired level, where we 
# can keep track of the sum of all values there.

# This leaves us two options: Either BFS or DFS. Sometimes, choosing one
# over the other does not impact greatly the quality of the solution, but 
# here it does. Why?

# With DFS, we would go all the way down until we reach a leaf node. This means
# that for whatever level we are keeping track of the sum, we will need to make 
# as many traversals through the level as there are nodes in it! Its easier to visualize this.

# With DFS, you are crossing the tree at the level you want multiple times to actually do 
# something meaningful (add a value to the total sum). With BFS, you calculate the total sum in
# a clean sweep throughout the given level. While the worst case runtime for both is the same, you
# ARE improving the average case runtime.

# So in short, we use BFS to traverse the tree, keeping track of nodes and their respective
# levels in a queue. Once we are done computing all values at our desired level, we can break
# our traversal and return our answer.

# SPACE-TIME COMPLEXITY
# Runtime => O(N), BFS will take at most one traversal down the tree
# Space => O(N), we keep track of queue which will grow linearly to the size of the tree

from queue import Queue

def level_sum(root, level):

    # root is level 0, so if 0 just return the value of root
    if level == 0:
        return root.val
    
    # our level_sum variable, which we will return at the
    # end of the function
    level_sum = 0
    
    # Breadth first Search: We will use a queue to traverse
    # the tree. Each element in the queue will be a tuple
    # of a node and its current level
    nodes_with_levels = Queue()

    # add in the root, and level 0
    nodes_with_levels.put((root, 0))

    # Our tree traversal
    while not nodes_with_levels.empty():

        # "pop" the current node and level
        node, current_level = nodes_with_levels.get()

        if current_level == level:
            # This is the level we are looking for, add node's value
            # to total sum
            level_sum += node.val
        elif current_level > level:
            # We have already traversed the desired level for our total sum.
            # break the loop and return the function early
            break
        
        # Add the current node's children to the queue, with their level
        # (one level deeper than the current)
        for child in node.children:
            nodes_with_levels.put((child, current_level + 1))
    
    return level_sum

root = TreeNode(10)

for i in range(1,4):
    root.add_node(i)

for child in root.children:
    for i in range(1,4):
        child.add_node(i)

print(level_sum(root, 2))