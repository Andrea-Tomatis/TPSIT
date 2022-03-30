import requests

GET_QUOTE = "https://api.chucknorris.io/jokes/random"
GET_CATEGORIES = "https://api.chucknorris.io/jokes/categories"
GET_QUOTE_BY_CATEGORY = "https://api.chucknorris.io/jokes/random?category=" # + {category}
GET_FREE_TEXT = "https://api.chucknorris.io/jokes/search?query=" # + {query}


def randomQuote():
    x = requests.get(GET_QUOTE)
    return x.json()['value']

def categoriesList():
    x = requests.get(GET_CATEGORIES)
    return x.json()

def randomCategoryQuote(cat):
    x = requests.get(GET_QUOTE_BY_CATEGORY + cat).json()
    if 'value' in x:
        return x['value']
    else:
        return 'invalid key. Please retry.'

def freeTextSearch(txt):
    x = requests.get(GET_FREE_TEXT + txt).json()
    if 'result' in x:
        return x['result']
    else:
        print('invalid key. Please retry.')
        return {}



def main():
    
    while True:
        print('>>> What do you want to get?\n\
               1) a random quote\n\
               2) a random quote by category\n\
               3) a free text search\n')
        
        choice = int(input('>>> insert the numer: '))
    
        if choice == 1:
            print(randomQuote() + '\n')

        elif choice == 2:
            lst = categoriesList()
            for i, cat in enumerate(lst):
                print(f'{i+1}) {cat}')

            try: 
                chosen_cat = int(input('>>> Insert the chosen category code: ')) 
                print(randomCategoryQuote(lst[chosen_cat]) + '\n')
            except Exception:
                print('Invalid key. Please retry.\n')

        elif choice == 3:
            txt = input('>>> Write the key words: ')
            quotes = freeTextSearch(txt)

            for quote in quotes:
                print(quote['value']) 


if __name__ == '__main__':
    main()

