# Given a tree where each node represents a cost of traveling there,
# write a function that returns the cheapest path to travel from 
# the root to any leaf node:

class TreeNode:
  def __init__(self, cost):
    self.cost = cost
    self.children = set()
  
  def add_node(self, cost):
    self.children.add(TreeNode(cost))

# Write function here
def get_sales_path(root):
  if len(root.children) == 0:
    return root.cost
  
  cheapest_cost = float('inf')
  # paths = []

  for child in root.children:
    current_cost = get_sales_path(child)
    if current_cost < cheapest_cost:
      cheapest_cost = current_cost
  
  return cheapest_cost + root.cost

root = TreeNode(0)
root.add_node(1)
root.add_node(5)

for c in root.children:
  c.add_node(1)

print(get_sales_path(root))