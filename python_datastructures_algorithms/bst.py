class TreeNode(object):

  def __init__(self, val):
    self.val = val
    self.left_ = None
    self.right_ = None

# Note: For recursive calls to work on None,
# we set addNode as a seperate function outside
# the TreeNode class (since addNode would only
# be a method for TreeNode and nothing else)
def addNode(root, newVal):
  if not root:
    newNode = TreeNode(newVal)
    return newNode
  elif newVal < root.val:
    root.left_ = addNode(root.left_, newVal)
  else:
    root.right_ = addNode(root.right_, newVal)
  
  return root

root = TreeNode(5)

addNode(root, 3)

print(root.left_.val)