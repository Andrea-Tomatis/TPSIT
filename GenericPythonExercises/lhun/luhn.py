'''
Luhn: Given a number determine whether or not it is valid per the Luhn formula.

@Andrea-Tomatis
'''

def main():
    code = input('insert a credit card number: ')

    #remove white space
    code = code.replace(' ','')

    if len(code) <= 1:
        exit(0)

    #convert into decimal and multiply even numbers per 2
    digit_num = [] 
    for i in range(len(code)):
        if i % 2 == 0: digit_num.append((int(code[i]) * 2) % 9)
        else: digit_num.append(int(code[i]))
    
    #sum the numbers
    final_value = sum(digit_num)

    #control if the final value is valid
    if final_value % 10 == 0: print(f'{code} is valid')
    else: print(f'{code} is invalid')


if __name__ == '__main__':
    main()