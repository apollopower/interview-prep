# Linked List Node Class
class ListNode:

  # Private (__) Class Variable, counting num of nodes
  __total = 0

  def __init__(self,val):
    self.val = val
    self.next_ = None
  
  # method to add node to list
  def addNode(self, newVal):
    current = self
    while current.next_:
      current = current.next_
    current.next_ = ListNode(newVal)
    ListNode.__total += 1
  
  # print all nodes
  def printNodes(self):
    current = self
    while current:
      print(current.val)
      current = current.next_

  # Class method to return total count of
  # nodes
  @classmethod
  def howMany(cls):
    print(cls.__total)
  
node = ListNode(3)

node.addNode(5)
node.addNode(90)

