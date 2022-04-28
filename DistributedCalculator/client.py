import requests

SERVER = '127.0.0.1'
CLIENTID = 2

for _ in range(10):
    url = f'http://{SERVER}:5000/api/v1/resources/operation?clientID={CLIENTID}'
    operation = requests.get(url).json()
    if operation['id'] == 'end':
        break
    result = eval(operation['op'])
    print(result)

    url = f'http://{SERVER}:5000/api/v1/resources/write?clientID={CLIENTID}&idOperation={operation["id"]}&result={result}'
    x = requests.get(url).json()
    print(x['esito'])

print('tutte le operazioni risolte')





