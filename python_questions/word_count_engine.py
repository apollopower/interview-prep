# Takes in piece of text. returns word
# count, as a string, from most occuring to least
def word_count_engine(text):
  chars = list(text)

  word_count = {}
  current_word = ""

  for c in chars:
    if c.isalpha():
      current_word += c
    else:
      if current_word in word_count:
        word_count[current_word] += 1
      elif current_word != "":
        word_count[current_word] = 1
      current_word = ""
  
  return word_count

text = "Jonas is an awesome person. Jonas loves Jonas because he is cool"

print(word_count_engine(text))
