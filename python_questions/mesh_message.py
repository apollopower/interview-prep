# Given a network of people, find the shortest path in that network
# between two people and return the path.

# For example, belowe we would like to find the shortest path between
# jonas and mufasa:

# We should get, jonas => bob => phil => mufasa

network = {
  "jonas": ["bob", "alice", "snorlax"],
  "bob": ["jonas", "phil", "jafaar"],
  "alice": ["snorlax", "jonas", "phil"],
  "phil": ["bob", "alice", "mufasa"],
  "jafaar": ["bob", "mufasa"],
  "mufasa": ["phil", "jafaar"],
  "snorlax": ["jonas"],
  "barack": ["joe"],
  "joe": ["barack"]
}

friend_1 = "jonas"
friend_2 = "mufasa"


# ANSWER

# The key to begin working on some kind of solution is framing this
# as a graph problem. Our "network" is the graph, which contains undirected
# nodes connected to each other.

# We can break down our problem as follows:
# 1) Traverse the graph from a start point to an end point
# 2) Guarantee that we have the shortest traversal path possible
# 3) Return the nodes in that path

# So we start with some simple graph traversal. This boils down to 2 approaches we can
# take; depth-first-search (DFS) and breadth-first-search (BFS). Each one has its advantages
# and disadvantages, so we need to choose the one that makes the most sense in this scenario.

# By its own nature, BFS will always provide the shortest traversal path possible. (If this does
# not make sense to you, be sure to brush up on your graph traversal implementations and understand
# the benefits of each one)

# Ok so we'll use BFS! This takes care of the first two parts of our problem.

# Now for the 3rd part. How can we keep track of the path we need to take from one node to another? 
# Verifying that a route exists is one thing, but keeping track of this "shortest path" is a seperate problem
# we need to tackle.

# This can be hard to think up correctly at first glance, so remember some of the rule of thumbs when lost in 
# a problem. Think, "what data structure can solve the problem I'm having now?"

# The solution involves the use of a new data structure, specifically a hash map, where we store a node as a key
# and its "parent" (how we got to this node) as the value

# By implementing this hash map into our BFS traversal, we can build up a "chain" of keys and values, going from the
# end point all the way to the desired starting point!

# Finally, all we have to do is return our keys in an array, showing the path the nodes take to get to one
# from the other!

from queue import Queue

def get_path(network, friend_1, friend_2):
  if friend_1 not in network or friend_2 not in network:
    raise Exception("Person not in network")

  friend_queue = Queue()
  friend_queue.put(friend_1)

  checked_friends = set([friend_1])

  friend_chain = {friend_1: None}

  while not friend_queue.empty():

    current = friend_queue.get()

    for friend in network[current]:
      if friend == friend_2:
        friend_chain[friend] = current
        return friend_chain
      elif friend not in checked_friends:
        friend_queue.put(friend)
        checked_friends.add(friend)
        friend_chain[friend] = current
    
  
  return None

def build_path(friend_chain, friend_1, friend_2):
  if not friend_chain:
      return None

  path = []
 
  current = friend_2
  while current:
     path.append(current)
     current = friend_chain[current]

  path.reverse()

  return path


friend_chain = get_path(network, friend_1, friend_2)

path = build_path(friend_chain, friend_1, friend_2)

print(path)


# Runtime => O(N + M)
# Space => O(N)

# This is a tricky problem. It involves breaking it down into two (technically 3)
# seperate parts. Graph traversal is difficult for those who don't understand it
# very well, so more the more practice you get in with graph problems, the more
# natural traversal will feel. Once you feel more comfortable with traversal, it 
# won't even feel like an "additional" step for solving problems anymore!