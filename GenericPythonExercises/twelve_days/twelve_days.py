'''
Twelve days: Output the lyrics to 'The Twelve Days of Christmas'.

@Andrea-Tomatis
'''

song_text_part1 = 'On the' 
song_text_part2 = 'day of Christmas my true love gave to me:'
song_text_part3 = ['twelve Drummers Drumming', 
                    'eleven Pipers Piping', 
                    'ten Lords-a-Leaping', 
                    'nine Ladies Dancing', 
                    'eight Maids-a-Milking', 
                    'seven Swans-a-Swimming', 
                    'six Geese-a-Laying', 
                    'five Gold Rings', 
                    'four Calling Birds', 
                    'three French Hens', 
                    'two Turtle Doves', 
                    'and a Partridge in a Pear Tree.']
numberToString = ['first','second','third','fourth','fifth',
                'sixth','seventh','eighth','ninth','tenth',
                'eleventh','twelfth']


def main():
    print('On the first day of Christmas my true love gave to me: a Partridge in a Pear Tree.')
    for i in range(1,12):
        print(f'{song_text_part1} {numberToString[i]} {song_text_part2} {",".join(song_text_part3[(j)*-1] for j in range(i+1,0,-1))}')


if __name__ == '__main__':
    main()