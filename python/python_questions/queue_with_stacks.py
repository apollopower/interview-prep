# Implement a special StackQueue class where it operates like 
# a queue but utilizes two stacks:

class StackQueue:
    def __init__(self):
        self.stack_1 = []
        self.stack_2 = []
    
    def push(self, val):
        self.stack_1.append(val)
    
    def queue_pop(self):
        if len(self.stack_2):
            return self.stack_2.pop()
        elif len(self.stack_1):
            while len(self.stack_1):
                self.stack_2.append(self.stack_1.pop())
            return self.stack_2.pop()
        else:
            # Nothing to pop, return None
            return None