'''
Es02:
  Scrivere una funzione che inverta una coda, ovvero produca una coda invertendo l’ordine
  degli elementi della coda di partenza. Suggerimento: utilizzare una pila.

Author: Andrea Tomatis
'''


def enqueue(queue, element):
    queue.append(element)


def dequeue(queue):
    return queue.pop(0)


def push(stack, element):
    stack.append(element)


def pop(stack):
    return stack.pop()


def main():
    queue = []
    stack = []

    enqueue(queue, int(input('insert a number: ')))

    while input('do you like to continue: ') != 'n':
        enqueue(queue, int(input('insert a number: ')))
    
    for i in range(len(queue)):
        push(stack, dequeue(queue))
    
    for i in range(len(stack)):
        enqueue(queue,pop(stack))

    for element in queue:
        print(element)


if __name__ == "__main__":
    main()