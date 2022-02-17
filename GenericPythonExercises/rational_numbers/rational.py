'''
Rational numbers: Implement the following operations:
                  - addition, subtraction, multiplication and division of two rational numbers,
                  - absolute value, 
                  - exponentiation of a given rational number to an integer power, 
                  - exponentiation of a given rational number to a real (floating-point) power, 
                  - exponentiation of a real number to a rational number.

@Andrea-Tomatis
''' 

import math

def find_gcd(a, b):
    if a == b: return a 
    gcd = min(a,b)
    for i in range(gcd, 1, -1):
        if a % i == 0 and b % i == 0:
            return i


def addiction(a1, b1, a2, b2):
    r1 = a1 * b2 + a2 * b1
    r2 = b1 * b2
    
    if(r1 != 0):
        gcd = find_gcd(r1, r2)
        r1 /= gcd
        r2 /= gcd
    
    if r2 == 1:
        return str(r1)
    else: return str(r1) + '/' + str(r2)


def difference(a1, b1, a2, b2):
    r1 = a1 * b2 - a2 * b1
    r2 = b1 * b2
    
    if(r1 != 0):
        gcd = find_gcd(r1, r2)
        r1 /= gcd
        r2 /= gcd
    
    if r2 == 1:
        return str(r1)
    else: return str(r1) + '/' + str(r2)


def moltiplication(a1, b1, a2, b2):
    r1 = a1 * a2
    r2 = b1 * b2
    
    if(r1 != 0):
        gcd = find_gcd(r1, r2)
        r1 /= gcd
        r2 /= gcd
    
    if r2 == 1:
        return str(r1)
    else: return str(r1) + '/' + str(r2)


def absolute(a, b):
    r1 = abs(a)
    r2 = abs(b)
    
    if(r1 != 0):
        gcd = find_gcd(r1, r2)
        r1 /= gcd
        r2 /= gcd
    
    if r2 == 1:
        return str(r1)
    else: return str(r1) + '/' + str(r2)


def division(a1, b1, a2, b2):
    r1 = a1 * b2
    r2 = a1 * b2
    
    if(r1 != 0):
        gcd = find_gcd(r1, r2)
        r1 /= gcd
        r2 /= gcd
    
    if r2 == 1:
        return str(r1)
    else: return str(r1) + '/' + str(r2)


def power(a,b):
    return math.pow(a,b)


def esponential_to_int(a, b, n):
    if a < 0 or b < 0:
        return -1
    
    r1 = pow(a,n)
    r2 = pow(b,n)
    
    if(r1 != 0):
        gcd = find_gcd(r1, r2)
        r1 /= gcd
        r2 /= gcd
    
    if r2 == 1:
        return str(r1)
    else: return str(r1) + '/' + str(r2)


def esponential_to_neg(a, b, n):
    n = abs(n)
    r1 = pow(a,n)
    r2 = pow(b,n)
    
    if(r1 != 0):
        gcd = find_gcd(r1, r2)
        r1 /= gcd
        r2 /= gcd
    
    if r2 == 1:
        return str(r1)
    else: return str(r1) + '/' + str(r2)


def main():
    test = absolute(-4,2)
    print(test)
    
    test = addiction(4, 2, 4, 2)
    print(test)
    
    test = difference(4, 2, 4, 2)
    print(test)
    
    test = moltiplication(4, 2, 4, 2)
    print(test)
    
    test = division(4, 2, 4, 2)
    print(test)
    
    test = esponential_to_int(2,4,2)
    print(test)

    test = esponential_to_neg(2,4,-2)
    print(test)


if __name__ == "__main__":
    main()