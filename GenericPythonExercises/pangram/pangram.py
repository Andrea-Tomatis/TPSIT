'''
Pangram: determine if wheter a phrase is a pangram or not.

@Andrea-Tomatis
'''

import string

def check(phrase):
    alphabet = list(string.ascii_lowercase)
    for letter in phrase:
        if letter in alphabet:
            alphabet.remove(letter)
    
    return len(alphabet) == 0


def main():
    print(check('The quick brown fox jumps over the lazy dog'))


if __name__ == '__main__':
    main()