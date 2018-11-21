from queue import Queue

class TreeNode:
  def __init__(self, val):
    self.val = val
    self.left = None
    self.right = None
    

def add_node(root, val):
  if not root:
    return TreeNode(val)
  elif val < root.val:
    root.left = add_node(root.left, val)
  else:
    root.right = add_node(root.right, val)
  
  return root

def bfs(root):

  node_queue = Queue()

  node_queue.put((root, 0))

  while not node_queue.empty():
    node, level = node_queue.get()

    print(node.val, level)

    if node.left:
      node_queue.put((node.left, level + 1))
    if node.right:
      node_queue.put((node.right, level + 1))


def dfs(root):

  node_stack = [(root, 0)]

  while len(node_stack):
    node, level = node_stack.pop()

    print(node.val, level)

    if node.left:
      node_stack.append((node.left, level + 1))
    if node.right:
      node_stack.append((node.right, level + 1))


def pre_order_traversal(root):

  if root.left:
    pre_order_traversal(root.left)
  
  print(root.val)

  if root.right:
    pre_order_traversal(root.right)

def post_order_traversal(root):

  if root.right:
    post_order_traversal(root.right)
  
  print(root.val)

  if root.left:
    post_order_traversal(root.left)


root = TreeNode(5)

add_node(root, 3)
add_node(root, 8)
add_node(root, 11)
add_node(root, 2)
add_node(root, 9)
add_node(root, 1)

dfs(root)