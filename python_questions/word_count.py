# Given a piece of text, return an array containing word counts,
# from greatest count to smallest

# Will return a list of dictionaries:
# [word => count, word => count,...]

def word_count(text):
    word_count = {}
    words = text.split(" ")
    maxCount = 0
    
    for word in words:
        if word in word_count:
            word_count[word] += 1
        else:
            word_count[word] = 1
        
        if word_count[word] > maxCount:
            maxCount = word_count[word]

    sorter = [[]] * (maxCount + 1)


    for word, count in word_count.items():
        sorter[count].append(word)
        print(sorter)
    
    return sorter
    
    


print(word_count("jonas is there a jonas because jonas is here"))
