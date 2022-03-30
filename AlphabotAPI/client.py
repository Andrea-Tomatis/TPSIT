import requests
import bs4
import string
import threading

#check sensors
url = 'http://192.168.0.127:5000/api/v1/sensors/obstacles'
x = requests.get(url).json()
print(x)

url = 'http://192.168.0.127:5000/api/v1/motors/both?'
obj = {'pwmL': 20, 'pwmR' : 20, 'time' : 5}
x = requests.get(url, data=obj)
print(x)


#obj["password"] = psw






