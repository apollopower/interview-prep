words = [
    'ptolemaic',
    'retrograde',
    'supplant',
    'undulate',
    'xenoepist',
    'asymptote',  # <-- rotates here!
    'babka',
    'banoffee',
    'engender',
    'karpatka',
    'othellolagkage',
]

def rotation_point(words):
  first_word = words[0]
  floor_idx = 0
  ceiling_idx = len(words) - 1

  while floor_idx < ceiling_idx:
    target_idx = floor_idx + ((ceiling_idx - floor_idx) // 2)
    # If guess comes after first word or is first word
    if words[target_idx] >= first_word:
      # Go right
      floor_idx = target_idx
    else:
      # Go left
      ceiling_idx = target_idx
    
    # If floor and ceiling have converged:
    if floor_idx + 1 == ceiling_idx:
      return ceiling_idx

print(rotation_point(words))