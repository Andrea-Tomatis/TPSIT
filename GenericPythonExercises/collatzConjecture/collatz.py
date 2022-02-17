'''
Collatz Conjecture: Given a number n, return the number of steps required to reach 1 
                    using the Collatz conjecture 

@Andrea-Tomatis
'''

def collatz(num):
    cnt = 0
    while num != 1:
        if num % 2 == 0: num /= 2
        else: num = num * 3 + 1
        cnt += 1
    return cnt


def main():
    print(collatz(9))

if __name__ == '__main__':
    main()