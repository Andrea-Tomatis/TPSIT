'''
Es01:
  Implementare i metodi enqueue() e dequeue()  e creare un programma che permetta
  all’utente di riempire una coda di numeri interi di lunghezza arbitraria. Successivamente
  testare la funzione dequeue per svuotare la coda.

Author: Andrea Tomatis
'''

def enqueue(queue, element):
    queue.append(element)


def dequeue(queue):
    return queue.pop(0)


def main():
    queue = []

    enqueue(queue, int(input('insert a number: ')))

    while input('do you like to continue: ') != 'n':
        enqueue(queue, int(input('insert a number: ')))

    for i in range(len(queue)):
        print(dequeue(queue))


if __name__ == '__main__':
    main()