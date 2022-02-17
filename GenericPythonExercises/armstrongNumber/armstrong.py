'''
Armstrong number: An Armstrong number is a number that is the sum of its own digits 
                  each raised to the power of the number of digits.
                  Write some code to determine whether a number is an Armstrong number.

@Andrea-Tomatis
'''

def check(number):
    number = str(number)
    return int(number) == sum(int(digit)**len(number) for digit in number)


def main():
    print(check(9))
    print(check(10))
    print(check(153))

if __name__ == '__main__':
    main()