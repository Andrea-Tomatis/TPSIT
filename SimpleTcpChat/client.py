'''
Chat in python

client
'''

import socket as sck
import threading as thr
SERVER = ('localhost',5000)


def main():
    s = sck.socket(sck.AF_INET, sck.SOCK_STREAM)
    s.connect(SERVER)
    while True:
        s.sendall('crash test'.encode())
    s.close()
    client.join()


if __name__ == '__main__':
    main()
