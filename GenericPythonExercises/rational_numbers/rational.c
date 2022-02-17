/*
Rational numbers: Implement the following operations:
                  - addition, subtraction, multiplication and division of two rational numbers,
                  - absolute value, 
                  - exponentiation of a given rational number to an integer power, 
                  - exponentiation of a given rational number to a real (floating-point) power, 
                  - exponentiation of a real number to a rational number.

@Andrea-Tomatis
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>


#define NO_ERROR 0

typedef int* array;


//find the greatest common divisor
int find_gcd(int, int);

//absolute value: |a| / |b|
array absolute_value(int, int);

//addiction: (a1 * b2 + a2 * b1) / (b1 * b2)
array addiction(int, int, int, int);

//difference: (a1 * b2 - a2 * b1) / (b1 * b2)
array difference(int, int, int, int);

//moltiplication: (a1 * a2) / (b1 * b2)
array moltiplication(int, int, int, int);

//division: (a1 * b2) / (a2 * b1)
array division(int, int, int, int);

//esponential to int: (a^n)/(b^n)
array esponential(int, int, int);


int main(){

    array test = (array) malloc(sizeof(int) * 2);

    //test absolute value
    test = absolute_value(-4,2);
    printf("%d/%d\n", test[0], test[1]);

    //test sum
    test = addiction(4, 2, 4, 2);
    printf("%d/%d\n", test[0], test[1]);

    //test diff
    test = difference(4, 2, 4, 2);
    printf("%d/%d\n", test[0], test[1]);

    //test prod
    test = moltiplication(4, 2, 4, 2);
    printf("%d/%d\n", test[0], test[1]);

    //test division
    test = division(4, 2, 4, 2);
    printf("%d/%d\n", test[0], test[1]);

    //test esponential
    test = esponential(2,4,2);
    printf("%d/%d\n", test[0], test[1]);

    return NO_ERROR;
}



int find_gcd(int a, int b){
    if (a == b) return a;

    int min = (a < b) ? a : b;
    int gcd = min;
    for(;gcd > 0; --gcd)
        if ((a % gcd == 0) && (b % gcd == 0)) 
            return gcd;
}



array addiction(int a1, int b1, int a2, int b2){
    array result = (array) malloc(sizeof(int) * 2);
    int r1 = a1 * b2 + a2 * b1;
    int r2 = b1 * b2;
    
    if(r1 != 0){
        int gcd = find_gcd(r1, r2);
        r1 /= gcd;
        r2 /= gcd;
    }

    *result = r1;
    *(result+1) = r2;

    return result;
}



array difference(int a1, int b1, int a2, int b2){
    array result = (array) malloc(sizeof(int) * 2);
    int r1 = a1 * b2 - a2 * b1;
    int r2 = b1 * b2;

    if (r1 != 0){
        int gcd = find_gcd(r1, r2);
        r1 /= gcd;
        r2 /= gcd;
    }
    
    *result = r1;
    *(result+1) = r2;

    return result;
}



array moltiplication(int a1, int b1, int a2, int b2){
    array result = (array) malloc(sizeof(int) * 2);
    int r1 = a1 * a1;
    int r2 = b2 * b2;

    if (r1 != 0){
        int gcd = find_gcd(r1, r2);
        r1 /= gcd;
        r2 /= gcd;
    }
    
    *result = r1;
    *(result+1) = r2;

    return result;
}



array absolute_value(int a, int b){
    array result = (array) malloc(sizeof(int) * 2);
    int r1 = (a < 0) ? a * (-1) : a;
    int r2 = (b < 0) ? b * (-1) : b;

    if (r1 != 0){
        int gcd = find_gcd(r1, r2);
        r1 /= gcd;
        r2 /= gcd;
    }
    
    *result = r1;
    *(result+1) = r2;

    return result;
}



array division(int a1, int b1, int a2, int b2){
    array result = (array) malloc(sizeof(int) * 2);
    int r1 = a1 * b2;
    int r2 = a2 * b1;

    if (r1 != 0){
        int gcd = find_gcd(r1, r2);
        r1 /= gcd;
        r2 /= gcd;
    }
    
    *result = r1;
    *(result+1) = r2;

    return result;
}


int power(int a, int b){
    for (int i = 0; i < b; i++)
        a *= a;
    return a;
}



array esponential(int a, int b, int n){
    array result = (array) malloc(sizeof(int) * 2);
    int r1 = (n > 0) ? power(a,n) : a;
    int r2 = (b > 0) ? power(b,n) : b;

    if (r1 != 0){
        int gcd = find_gcd(r1, r2);
        r1 /= gcd;
        r2 /= gcd;
    }
    
    *result = r1;
    *(result+1) = r2;

    return result;
}