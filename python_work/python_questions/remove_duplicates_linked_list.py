# Write code to remove duplicate values from an unsorted linked list.

class ListNode:
  def __init__(self, val):
    self.val = val
    self.next_ = None
  
  def add_node(self, new_val):
    current = self
    while current.next_:
      current = current.next_
    current.next_ = ListNode(new_val)
  
  def remove_node(self,remove_val):
    if self.val == remove_val:
      self = self.next_
    else:
      prev = self
      current = self.next_

      while current.val != remove_val:
        prev = current
        current = current.next_
      
      prev.next_ = current.next_

  # WRITE THE METHOD HERE
  def remove_duplicates(self):
    node_count = {}

    current = self
    while current:
      if current.val not in node_count:
        node_count[current.val] = 1
      else:
        node_count[current.val] += 1
      current = current.next_
    
    for val in node_count:
      if node_count[val] > 1:
        self.remove_node(val)


root = ListNode(4)

root.add_node(6)
root.add_node(6)
root.add_node(8)

root.remove_duplicates()

print(root.next_.val) # should print out 6