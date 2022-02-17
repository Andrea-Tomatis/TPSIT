'''
All your base: Convert a number, represented as a sequence of digits in one base,
               to any other base.
               Implement general base conversion. Given a number in base a, represented 
               as a sequence of digits, convert it to base b.

@Andrea-Tomatis
'''

def split_digit(num):
    lst = [int(digit) for digit in num]
    lst.reverse()
    return lst


def convert_to(number, base_a, base_b):
    number = split_digit(number)
    
    dec = 0
    for i,digit in enumerate(number):
        dec += digit * pow(base_a, i)
    
    if(base_b == 10): return dec
    else:
        final_number = []
        while dec >= 1:
            final_number.append(dec%base_b)
            dec //= base_b
        final_number.reverse()
    
    return final_number


if __name__ == '__main__':
    print(convert_to('4',10,2))