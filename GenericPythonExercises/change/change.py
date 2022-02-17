'''
Change: Correctly determine the fewest number of coins to be given to a customer 
        such that the sum of the coins' value would equal the correct amount of change.

@Andrea-Tomatis
'''

def main():
    values = [1,5,10,25,100]
    change = int(input("what's the change? "))

    if change < 0:
        print('impossible change')
    elif change == 0:
        print('there\'s no change')
    else:
        i = len(values) - 1
        while i >= 0 and change > 0:
            if values[i] <= change:
                change -= values[i]
                print(values[i])
            else:
                i -= 1
            

if __name__ == '__main__':
    main()