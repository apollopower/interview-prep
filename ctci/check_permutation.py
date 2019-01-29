#Given two strings, write a method to decide if one is a permutation of the other

def check_perm(string1, string2):
    pass


# ANSWER

def check_perm(string1, string2):
    char_set = set()
    if len(string1) > len(string2):
        short = string2
        lng = string1
    else:
        short = string1
        lng = string2

    for i,char in enumerate(short):
        char_set.add(char)
