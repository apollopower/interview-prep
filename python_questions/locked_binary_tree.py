# locked binary tree problem

class TreeNode:
  def __init__(self, val):
    self.val = val
    self.locked = False
    self.left = None
    self.right = None
  
  def is_locked(self):
    return self.locked
  
  def lock(self):
    if self.left:
      self.left.lock()
    if self.right:
      self.right.lock()
    
    if self.is_locked():
      return False
  
  def unlock(self):
    pass
  

def add_node(root, val):
  if not root:
    return TreeNode(val)
  elif val < root.val:
    root.left = add_node(root.left, val)
  else:
    root.right = add_node(root.right, val)
  return root



root = TreeNode(10)

add_node(root, 5)
add_node(root, 15)

