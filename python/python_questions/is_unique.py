# O(n) space
# O(n) time
def is_unique(string):

  if len(string) < 2:
    return True
  
  charSet = set()

  for idx,char in enumerate(string):
    if char in charSet:
      return False
    else:
      charSet.add(char)
  
  return True

# O(1) space
# O(n^2) time
def is_unique_2(string):
  if len(string) < 2:
    return True
  
  for char_1 in string:
    for char_2 in string:
      if char_1 == char_2:
        return False
  
  return True
    

print(is_unique("jonas"))