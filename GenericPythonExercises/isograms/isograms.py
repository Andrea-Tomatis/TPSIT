'''
Isograms: Determine if a word or phrase is an isogram.

@Andrea-Tomatis
'''

def check(phrase):
    return ''.join(i for i in list(dict.fromkeys(phrase))) == phrase

def main():
    print(check('lumberjack'))
    print(check('sassari'))

if __name__ == '__main__':
    main()