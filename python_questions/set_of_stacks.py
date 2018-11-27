# Given a limit to a size for a stack, implement a class, SetOfStacks,
# which is composed of several stacks and should create a new stack
# once the previous one exceeds the capacity given at initialization:

# ANSWER:

class SetOfStacks:
  def __init__(self, max_size):
    self.stacks = []
    self.max_size = max_size
  
  def push(self, val):
    if not len(self.stacks) or len(self.stacks[-1]) >= self.max_size:
      new_stack = [val]
      self.stacks.append(new_stack)
    else:
      current_stack = self.stacks[-1]
      current_stack.append(val)
  
  def pop(self):
    if not len(self.stacks):
      return None

    current_stack = self.stacks[-1]
    val = current_stack.pop()

    if not len(current_stack):
      self.stacks.pop()
    
    return val
  
  def pop_at(self, index):
    if self.stacks[index]:
      val = self.stacks[index].pop()
    
      if not len(self.stacks[index]):
        self.stacks.pop(index)
      
      return val
    else:
      return None
    
  
  def peek(self):
    return self.stacks[-1][-1]

