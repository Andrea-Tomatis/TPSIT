'''
ISBN Verifier: Given a string the program should check if the provided string 
               is a valid ISBN-10.

@Andrea-Tomatis
'''

def verify(isbn):
    convert = {str(i):i for i in range(0,10)}
    convert['X'] = 10
    number = [convert[x] for x in isbn if x != '-']
    return sum(digit * (10-i) for i,digit in enumerate(number)) % 11 == 0

def main():
    print(verify('3-598-21508-8'))

if __name__ == '__main__':
    main()