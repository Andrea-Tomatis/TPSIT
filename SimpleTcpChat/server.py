'''
Chat in python

server
'''

import socket as sck
import threading as thr
import logging
import time

LOCAL_HOST = ('0.0.0.0', 5000)
BUF_DIM = 4096


def main():
    s = sck.socket(sck.AF_INET, sck.SOCK_STREAM)
    s.bind(('0.0.0.0',5000))
    s.listen()

    logging.info('server started...')
    conn, address = s.accept()
    
    while True:
        msg = conn.recv(BUF_DIM).decode()
        print(msg)


if __name__ == '__main__':
    main()
