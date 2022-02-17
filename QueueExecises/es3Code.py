'''
Es03:
  Implementare le pile e i metodi pop() e push() utilizzando una coda con i suoi metodi
  enqueue() and dequeue().

Author: Andrea Tomatis
'''


def enqueue(queue, element):
    queue.append(element)


def dequeue(queue):
    return queue.pop(0)


def push(queue, element):
    queue2 = []
    for i in range(len(queue)):
        enqueue(queue2, dequeue(queue))
    enqueue(queue, element)
    for element in queue2:
        enqueue(queue, element)

def pop(stack):
    return dequeue(stack)


def main():
    stack = []
    for i in range(10):
        push(stack, i)
    print(stack)
    pop(stack)
    print(stack)


if __name__ == '__main__':
    main()