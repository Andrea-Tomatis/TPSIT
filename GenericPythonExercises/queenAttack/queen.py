'''
Queen attack: Given the positions of 2 queens on a chess table, determine if both of them
              sees each other

@Andrea-Tomatis
'''

def check(x1,y1,x2,y2):
    return x1 == x2 or y1 == y2 or x1+y1 == x2+y2 or abs(y2 - y1) == abs(x2 - x1)
    
def main():
    print(check(0,0,9,9))


if __name__ == '__main__':
    main()