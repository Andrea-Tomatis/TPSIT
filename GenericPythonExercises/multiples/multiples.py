'''
Sum of multiples: Given a number, find the sum of all the unique multiples of 
                  particular numbers up to but not including that number.
                
@Andrea-Tomatis
'''

def multiples_sum(limit, base1, base2):
    numbers_lst = []
    for i in range(base1, limit):
        if i % base1 == 0 and i not in numbers_lst: numbers_lst.append(i)
    for i in range(base2, limit):
        if i % base2 == 0 and i not in numbers_lst: numbers_lst.append(i)

    return sum(numbers_lst)


def main():
    print(multiples_sum(20, 3, 5))


if __name__ == '__main__':
    main()