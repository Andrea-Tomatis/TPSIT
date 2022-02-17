'''
Word Search: In word search puzzles you get a square 
             of letters and have to find specific words in them.

@Andrea-Tomatis
'''

#read puzzle matrix from file
def read_puzzle(file_name):
    fp = open(file_name,'r')
    matrix = []
    for line in fp:
        row = []
        for char in line:
            if char != '\n': row.append(char)
        matrix.append(row)
    fp.close()
    return matrix


#read the words to find in the puzzle
def read_patterns(file_name):
    fp = open(file_name,'r')
    words = []
    for word in fp:
        if word[-1] == '\n':
            words.append(word[:-1])
        else: words.append(word)
    fp.close()
    return words


def main():
    matrix = read_puzzle('puzzle.txt')
    words = read_patterns('words.txt')

    #search all possible word
    possible_words = []

    for row in matrix:
        possible_words.append(''.join(char for char in row))
    
    for i in range(len(matrix[0])):
        col = ''
        for row in matrix:
            col += row[i]
        possible_words.append(col)
    

    for word in words:
        for row in possible_words:
            if row.startswith(word):
                print(f'I found: {word}')


if __name__ == '__main__':
    main()