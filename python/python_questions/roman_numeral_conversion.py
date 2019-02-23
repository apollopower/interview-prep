romans = {
  "M": 1000,
  "D": 500,
  "C": 100,
  "L": 50,
  "X": 10,
  "V": 5,
  "I": 1
}

def convert_to_roman(num):
  answer = ""
  for letter in romans:
    if int(num / romans[letter]) > 0:
      while int(num / romans[letter]) > 0:
        answer += letter
        num -= romans[letter]
    
  if "IIII" in answer:
    answer = answer.replace("IIII", "IV")
  
  if "VIV" in answer:
    answer = answer.replace("VIV", "IX")

  return answer




print(convert_to_roman(9))