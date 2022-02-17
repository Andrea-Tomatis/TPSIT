'''
Matching Brackets: Given a string containing brackets [], braces {}, parentheses (), or 
                   any combination thereof, verify that any and all pairs are matched 
                   and nested correctly.

@Andrea-Tomatis
'''

def push(stack,element):
    return stack.append(element)
    
def pop(stack):
    return stack.pop()

def indexSymbol(symbol, lista):
    for i in range(len(lista)):
        if lista[i] == symbol:
            return i
    return -1

def main():
    openParenthesis = ['(','[','{']
    closeParenthesis  = [')',']','}']
    pila = []
    ok = True
    espression = input("insert a phrase: ")
    for symbol in espression:
        if symbol in openParenthesis:
            push(pila, symbol)
        if symbol in closeParenthesis:
            try:
                if pop(pila) != openParenthesis[indexSymbol(symbol,closeParenthesis)]:
                    print("wrong")
                    ok = False
                    break;
            except IndexError:
                print("wrong")
                ok = False
                break;
    if ok:
        print("right")


if __name__ == "__main__":
    main()