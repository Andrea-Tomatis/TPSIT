import requests

def main():
    r = requests.get('http://127.0.0.1:5000/api/v1/resources/books/all')
    print(r.json())

if __name__ == '__main__':
    main()