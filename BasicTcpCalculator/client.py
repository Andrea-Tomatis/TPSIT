import socket as sck
import threading as thr

LOCAL = ('localhost', 5001)
NO_ERR = 0

def main():
    s = sck.socket(sck.AF_INET, sck.SOCK_STREAM)
    s.connect(LOCAL)

    data, addr = s.recvfrom(LOCAL[1])
    n_Operations = data.decode()
    print(n_Operations)

    for _ in range(int(n_Operations)):
        data, addr = s.recvfrom(LOCAL[1])
        op = eval(data.decode())
        s.sendall(str(op).encode())

    s.close()
    exit(NO_ERR)

if __name__ == '__main__':
    main()