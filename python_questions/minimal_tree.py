# Given a sorted array, write an algorithm to create a tree from the
# array with a minimum height:

class TreeNode:

  def __init__(self, val):
    self.val = val
    self.left = None
    self.right = None


# ANSWER

def add_node(root, val):
  if not root:
    return TreeNode(val)
  elif val < root.val:
    root.left = add_node(root.left, val)
  else:
    root.right = add_node(root.right, val)
  return root

def create_binary_tree(sorted_list):
  target = int(len(sorted_list) / 2)
  median = sorted_list[target]

  root = TreeNode(median)

  for num in sorted_list:
    if num != median:
      add_node(root, num)
  
  return root


def tree_depth(root):
  node_stack = [(root, 0)]

  max_level = 0

  while len(node_stack):

    node, level = node_stack.pop()

    if level < max_level:
      break
    else:
      max_level = level


    if node.left:
      node_stack.append((node.left, level + 1))
    if node.right:
      node_stack.append((node.right, level + 1))
  
  return max_level


sorted_list = [1,2,3,4,5,6,7,8,9,10]

tree = create_binary_tree(sorted_list)

print(tree_depth(tree))