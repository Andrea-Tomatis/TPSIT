'''
Anagram: Given a word and a list of candidates, 
         select the sublist of anagrams of the given word.

@Andrea-Tomatis
'''

def anagram(word, candidates):
    letters = [l for l in word]
    valid = []
    for name in candidates:
        if len(letters) == len(name):
            test = [l for l in name]
            for letter in letters:
                if letter in test:
                    test.remove(letter)
            if len(test) == 0:
                valid.append(name)
    return valid



def main():
    print(anagram('pasta', ['astap','spaghetti','pizza']))


if __name__ == '__main__':
    main()