# Create a stack such that the smallest items are on the top. You can use a temporary stack to
# help out with this.

# ANSWER

class SortStack:
  def __init__(self):
    self.main_stack = []
  
  def push(self, val):
    if len(self.main_stack) == 0 or val <= self.main_stack[-1]:
      self.main_stack.append(val)
    else:
      temp_stack = []
      while len(self.main_stack):
        temp_stack.append(self.main_stack.pop())
      
      self.main_stack.append(val)

      while len(temp_stack):
        self.main_stack.append(temp_stack.pop())
  
  def pop(self):
    if len(self.main_stack):
      return self.main_stack.pop()
    else:
      return None
  
  def peek(self):
    if len(self.main_stack):
      return self.main_stack[-1]
  
  def is_empty(self):
    return len(self.main_stack) == 0

stack = SortStack()

stack.push(4)
stack.push(3)
stack.push(5)
stack.push(1)
stack.push(2)

print(stack.peek())