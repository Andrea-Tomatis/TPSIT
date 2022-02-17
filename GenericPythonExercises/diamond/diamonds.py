'''
Diamonds: The diamond kata takes as its input a letter, and outputs it in a diamond shape. 

@Andrea-Tomatis
'''

import string

def diamond(letter):
    alphabet = (string.ascii_uppercase)
    for i in range(len(alphabet)-1):
        if alphabet[i] == letter:
            spacing = i * 2 - 1
            alphabet = list(alphabet[:i+1])
            break
    
    print(''.join(' ' for i in range(spacing//2)), 'A')
    sp = 1
    for l in alphabet:
        if l != alphabet[0]:
            print(''.join(' ' for i in range((spacing//2) -1 -(sp//2))), l, ''.join(' ' for i in range(sp)), l)
            sp += 2
            
        if l == letter:
            sp -= 2
            break
    alphabet.reverse()
    for l in alphabet:
        if l != alphabet[0]:
            print(''.join(' ' for i in range((spacing//2) -1 -(sp//2))), l, ''.join(' ' for i in range(sp)), l)
            sp -= 2
            
        if l == alphabet[-1]: break

def main():
    diamond(input('letter: ').upper())

if __name__ == '__main__':
    main()