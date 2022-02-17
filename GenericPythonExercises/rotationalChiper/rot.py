'''
Rotational Chiper: Create an implementation of the rotational cipher, also sometimes called the Caesar cipher.

@Andrea-Tomatis
'''
import string

def cript(phrase, rot):
    alphabet = (string.ascii_lowercase)
    new_phrase = []
    phrase.lower()
    for letter in phrase:
        if letter in alphabet:
            new_phrase.append(chr((ord(letter)+ rot) % (ord('a') + 26)))
        else: new_phrase.append(letter)
    
    return ''.join(word for word in new_phrase)

def main():
    print(cript('omg',5))


if __name__ == '__main__':
    main()