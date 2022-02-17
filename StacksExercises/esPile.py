'''
Data un'espressione matematica, controllare se tutte le parentesi sono inserite
nell'ordine corretto.

Author: Andrea Tomatis
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
    espression = input("inserisci un'espressione: ")
    for symbol in espression:
        if symbol in openParenthesis:
            push(pila, symbol)
        if symbol in closeParenthesis:
            try:
                if pop(pila) != openParenthesis[indexSymbol(symbol,closeParenthesis)]:
                    print("sbagliato")
                    ok = False
                    break;
            except IndexError:
                print("sbagliato")
                ok = False
                break;
    if ok == True:
        print("giusto")

if __name__ == "__main__":
    main()
