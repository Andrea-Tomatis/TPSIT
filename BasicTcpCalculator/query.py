import sqlite3
from sqlite3 import Error

class Db_Connection():
    def __init__(self, db_file):
        self.db_file = db_file
        self.conn = self.create_connection(db_file)
        self.cur = self.conn.cursor()
        
    def create_connection(self, db_file):
        conn = None
        try:
            conn = sqlite3.connect(db_file)
        except Error as e:
            print(e)
        return conn
        
    def get_operations(self, client_id):
        self.cur.execute(f'SELECT operation FROM operations WHERE client = "{client_id}"')
        op_list = self.cur.fetchall()
        return op_list
    
    def count_recurrences(self, client_id):
        self.cur.execute(f'SELECT client, COUNT(*) FROM operations GROUP BY client')
        view = self.cur.fetchall()
        for line in view:
            if line[0] == client_id:
                return line[1]
        return -1
    
    def close(self):
        self.cur.close()
        self.conn.close()