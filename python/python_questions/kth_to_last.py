# Write an algorithm that finds the kth to last element of a singly linked list.

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
        print("Current value is", current.val)
      
      prev.next_ = current.next_
    
  

# WRITE YOUR FUNCTION HERE
def kth_to_last(root, k):
  list_length = 0
  current = root

  while current:
    list_length += 1
    current = current.next_
  
  target = (list_length - k) + 1

  current_count = 1
  current = root

  while current_count != target:
    current = current.next_
    current_count += 1
  return current
