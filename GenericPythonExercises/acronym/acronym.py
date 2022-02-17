'''
Acronym: Convert a phrase to its acronym.

@Andrea-Tomatis
'''

def convert(phrase):
    return ''.join(word[0].upper() for word in phrase.split(' '))


def main():
    print(convert('Hello, World'))

if __name__ == '__main__':
    main()