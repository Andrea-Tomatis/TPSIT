'''
Food Chain: Generate the lyrics of the song 'I Know an Old Lady Who Swallowed a Fly'.

@Andrea-Tomatis
'''

def get_key(dictionary, value):
    for key, val in dictionary.items():
        if value == val:
            return key
    return None



def main():
    animals_name = ['fly', 'spider', 'bird', 'cat', 'dog', 'goat', 'cow']
    animals = {'fly' : '',
                'spider' : 'It wriggled and jiggled and tickled inside her.',
                'bird' : 'How absurd to swallow a bird!',
                'cat' : 'Imagine that, to swallow a cat!',
                'dog' : 'What a hog, to swallow a dog!',
                'goat' : 'Just opened her throat and swallowed a goat!',
                'cow' : 'I don\'t know how she swallowed a cow!'}
    
    for i in range(7):
        print(f'I know an old lady who swallowed a {get_key(animals, animals[animals_name[i]])}.')
        
        if i > 0:
            print(animals[animals_name[i]])
            for j in range(0, i):
                if j == 1:
                    print(f'she shallowed the {get_key(animals, animals[animals_name[j+1]])} to catch the {get_key(animals, animals[animals_name[j]])} that {animals[animals_name[j]][3:]}')
                else:
                    print(f'she shallowed the {get_key(animals, animals[animals_name[j+1]])} to catch the {get_key(animals, animals[animals_name[j]])}.')
        print('I don\'t know why she swallowed the fly. Perhaps she\'ll die.\n')
    
    print('I know an old lady who swallowed a horse.\nShe\'s dead, of course!')


if __name__ == '__main__':
    main()