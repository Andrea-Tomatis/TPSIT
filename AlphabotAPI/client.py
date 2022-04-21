import requests
import bs4
import string
import threading

SERVER = '192.168.0.127'

#check sensors
url = f'http://{SERVER}:5000/api/v1/sensors/obstacles'
x = requests.get(url).json()
print(x)

url = f'http://{SERVER}:5000/api/v1/motors/both?pwmL=-20&pwmR=20&time=5'
x = requests.get(url).json()
print(x)


#obj["password"] = psw






