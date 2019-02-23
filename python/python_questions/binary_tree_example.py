# Binary tree

class BinaryTreeNode:
  def __init__(self, val):
    self.val = val
    self.left_ = None
    self.right_ = None
  

def addNode(root, new_val):
  if not root:
    root = BinaryTreeNode(new_val)
    return root
  elif new_val < root.val:
    root.left_ = addNode(root.left_, new_val)
  else:
    root.right_ = addNode(root.right_, new_val)
  
  return root

tree = BinaryTreeNode(10)

addNode(tree, 5)

print(tree.left_.val)