'''
Grep: Search a file for lines matching a regular expression pattern. Return the 
    line number and contents of each matching line.

@Andrea-Tomatis
'''


def main():
    fp = open('input.txt','r')
    pattern = input('what pattern are you searching for?\n')
    i = 1

    for line in fp:
        if pattern in line:
            print(f'line {i}: {line[:-1]}')
        i += 1

if __name__ == '__main__':
    main()