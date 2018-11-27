# Create a stack that implements a "get min" function,
# which returns the smallest item within it. It should
# also contain the expectes stack methods of "push", "pop",
# and "peek". All methods should take O(1) time.

class MinStack:
    def __init__(self):
        self.main_stack = []
        self.min_stack = []
    
    def push(self, val):
        self.main_stack.append(val)

        if not len(self.min_stack) or val <= self.min_stack[-1]:
            self.min_stack.append(val)
    
    def pop(self, val):
        val = self.main_stack.pop()

        if val == self.min_stack[-1]:
            self.min_stack.pop()
        
        return val
    
    def get_min(self, val):
        if len(self.min_stack):
            return self.min_stack[-1]
        else:
            return None