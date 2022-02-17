import socket as sck
import threading as thr
from query import Db_Connection

lstClient = {}

class Client_Manager(thr.Thread):
    def __init__(self, addr, conn, client_id):
        thr.Thread.__init__(self)
        self.addr = addr
        self.conn = conn
        self.id = client_id
        self.running = True
        self.db = Db_Connection('./operations.db')
        self.n_op = self.db.count_recurrences(self.id)
        self.conn.sendall(str(self.n_op).encode())
        self.op_list = self.db.get_operations(self.id) 
        self.db.close()
        
    
    def run(self):
        for op in self.op_list:
            self.conn.sendall(op[0].encode())
            data, addr = self.conn.recvfrom(5000)
            print(f'>>> client {self.id}\n\top: {op[0]}\n\tresult: {data.decode()}')
        self.running = False



class Accettazione(thr.Thread):
    def __init__(self, s):
        thr.Thread.__init__(self)
        self.s = s
        self.id = 1
    
    def run(self):
        while True:
            conn, addr = self.s.accept()
            client = Client_Manager(addr, conn, self.id)
            print(f'new client connected: {self.id}')
            lstClient[self.id] = client
            client.start()
            self.id += 1



def main():
    s = sck.socket(sck.AF_INET, sck.SOCK_STREAM)
    s.bind(('127.0.0.1', 5001))
    s.listen()

    acc = Accettazione(s)
    acc.start()
    
    while True:
        for key, value in lstClient.items():
            if not value.running: 
                value.join()
                lstClient[key] = None
        if input('') == 'exit':
            for key, value in lstClient.items():
                value.join()
                lstClient[key] = None
            s.close()
            exit(0)


if __name__ == "__main__":
    main()