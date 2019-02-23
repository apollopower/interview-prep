from queue import Queue

class graphNode:

  def __init__(self, val):
    self.val = val
    self.neighbors = set()
  
  def addNode(self, new_val):
    self.neighbors.add(graphNode(new_val))

  def bfs(self):
    graphQueue = Queue()
    graphQueue.put(self)

    while not graphQueue.empty():
      current = graphQueue.get()
      
      print(current.val)

      for node in current.neighbors:
        graphQueue.put(node)
      

root = graphNode(1)

for i in range(2,6):
  root.addNode(i)


for node in root.neighbors:
  for i in range(54,60):
    node.addNode(i)

root.bfs()