# Write a function to tell if a binary tree is "super balanced", meaning that there are no more than 2 depths
# in the tree, and that their difference in size is no larger than 1.

class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

    
    def is_balanced(self):
        stack = []
        levels = []
        stack.append((self, 0))

        while len(stack):
            node, level = stack.pop()

            if node.left is None and node.right is None:
                if level not in levels:
                    levels.append(level)

                # Now check if conditions have been broken for a "super balanced" tree
                if len(levels) > 2 or (len(levels) == 2 and abs(levels[0] - levels[1]) > 1):
                    return False
            else:
                if node.left:
                    stack.append((node.left, level + 1))
                
                if node.right:
                    stack.append((node.right, level + 1))
        return True
