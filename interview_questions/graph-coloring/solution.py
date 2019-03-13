# Given an undirected graph with maximum degree D, find a graph coloring
# using at most D + 1 colors:

from queue import Queue

class GraphNode:
    def __init__(self):
        self.color = None
        self.neighbors = set()

    def add_neighbor(self):
        self.neighbors.add(GraphNode())

    def count_nodes(self):
        node_count = 0
        # Breadth first search through graph
        node_queue = Queue()
        processed_nodes = set()
        node_queue.put(self)

        while not node_queue.empty():
           current_node = node_queue.get()

           if current_node not in processed_nodes:
               node_count += 1
               processed_nodes.add(current_node)

           for neighbor in current_node.neighbors:
               node_queue.put(neighbor)

        return node_count




node = GraphNode()

for i in range(4):
    node.add_neighbor()

for n in node.neighbors:
    for i in range(4):
        n.add_neighbor()


print(node.count_nodes())
