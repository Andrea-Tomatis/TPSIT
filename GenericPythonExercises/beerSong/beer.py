'''
Beer Song: Recite the beer song

@Andrea-Tomatis
'''


def main():
    main_phrase = 'bottles of beer on the wall'
    for i in range(1,100):
        print(f"{100-i} {main_phrase}, {100-i} bottles of beer. Take one down and pass it around, {99-i} {main_phrase}.")
    print(f"No more {main_phrase}, no more bottles of beer. Go to the store and buy some more, 99 {main_phrase}.")

   
    
if __name__ == "__main__":
    main()