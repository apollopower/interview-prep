# Write a function to color all nodes in an undirected graph. No two 
# neighbor nodes should have the same color

class GraphNode:
  def __init__(self, val):
    self.val = val
    self.neighbors = set()
    self.color = None

def color_graph(graph_node, colors):
  graph_queue = []

  graph_queue.append(graph_node)

  while not graph_queue.empty():
    
    node = graph_queue.pop(0)

    current_colors = set()

    for neighbor in node.neighbors:
      if neighbor.color:
        current_colors.add(neighbor.color)
      else:
        graph_queue.append(neighbor)
    
    for color in colors:
      if color not in current_colors:
        node.color = color
        break
  