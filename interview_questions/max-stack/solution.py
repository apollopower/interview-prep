# Implement a Max Stack class, with a get_max() function, based on a pre-existing stack class:

class Stack(object):
  def __init__(self):
    self.items = []
  
  def push(self, val):
    self.items.append(val)
  
  def pop(self):
    if not self.items:
      return None

    return self.items.pop()
  
  def peek(self):
    if not self.items:
      return None

    return self.items[-1]

class MaxStack:
  def __init__(self):
    self.stack = Stack()
    self.max_stack = Stack()
  
  def push(self, val):
      self.stack.push(val)
      if self.max_stack.peek() is None or self.max_stack.peek() < val:
        self.max_stack.push(val)
            
  
  def pop(self):
    if not self.stack:
      return None
    
    popped_val = self.stack.pop()
    if self.max_stack.peek() == popped_val:
      self.max_stack.pop()
    
    return popped_val
  
  def get_max(self):
    return self.max_stack.peek()


max_stack = MaxStack()
max_stack.push(0)
max_stack.push(-1)
max_stack.push(25)
max_stack.pop()
print(max_stack.get_max())