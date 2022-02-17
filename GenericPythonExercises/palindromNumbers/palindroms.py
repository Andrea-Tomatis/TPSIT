'''
Palindrom Number: Detect palindrome products in a given range.

@Andrea-Tomatis
'''

def calc_palindroms(start, end):
    pal = []
    for i in range(start,end):
        for j in range(start,end):
            prod = str(i*j)
            first_half = [digit for digit in prod[:len(prod)//2]]
            second_half = [digit for digit in prod[len(prod)//2:]]
            second_half.reverse()
            if first_half == second_half and int(prod) not in pal:
                pal.append(int(prod))
    return pal



def main():
    print(calc_palindroms(0, 99))

if __name__ == '__main__':
    main()