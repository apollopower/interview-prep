from queue import Queue

class TreeNode:
  def __init__(self, val):
    self.val = val
    self.children = set()
  
  def add_node(self, val):
    self.children.add(TreeNode(val))


def findTotalSum(root):
  total_sum = 0

  sum_queue = Queue()
  sum_queue.put(root)

  while not sum_queue.empty():

    current_node = sum_queue.get()

    total_sum += current_node.val

    for child in current_node.children:
      sum_queue.put(child)
  
  return total_sum

root = TreeNode(1)

root.add_node(2)
root.add_node(2)
root.add_node(2)
root.add_node(2)

print(findTotalSum(root))