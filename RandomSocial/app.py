from flask import Flask, render_template, make_response, redirect, url_for, request
import string
import random
from lib.mail import email_alert
from lib.query import Db_Connection

app = Flask(__name__)
STRING_LENGHT = 30
SERVER_IP = '127.0.0.1'
token = ''.join(random.choice(string.ascii_lowercase) for _ in range(STRING_LENGHT))
registration_token = ''.join(random.choice(string.ascii_lowercase) for _ in range(STRING_LENGHT))
waiting_user_list = {}
username = ''


def validate(username, password):
    completion = False
    db = Db_Connection('./lib/social.db')
    rows = db.findRecords('Users', '*')
    db.close()

    for row in rows:
        dbUser = row[1]
        dbPass = row[2]
        if dbUser==username:
            completion=check_password(dbPass, password)
    return completion

def check_password(hashed_password, user_password):
    return hashed_password == user_password

def check_registration(username, password, email):
    return len(username) > 0 and len(password) > 0 and len(email) > 0 and '@' in email


def getRandomStatus(user_id):
    db = Db_Connection('./lib/social.db')
    stati = db.findRecords('Stati','id_user, status', condition=f'id_user <> "{user_id}"')
    random_user_id, random_status = random.choice(stati)
    
    random_username = db.findRecords('Users','username', condition=f'id = "{random_user_id}"')[0][0]
    random_status = f'{random_username} says: {random_status}'
    db.close()

    return random_status


@app.route('/', methods=['GET', 'POST'])
def login():
    error = None
    if request.method == 'POST':
        if request.form.get('signUp') == 'Sign Up':
            return redirect(url_for('registration_page'))
        
        global username
        username = request.form['username']
        password = request.form['password']
        completion = validate(username, password)
        if completion == False:
            error = 'Invalid Credentials. Please try again.'
        else:
            db = Db_Connection('./lib/social.db')
            id_user = db.findRecords('Users','id',condition=f'username = "{username}" AND password = "{password}"')[0][0]
            db.close()
            
            resp = make_response(redirect(url_for('main_page')))
            resp.set_cookie('username',str(id_user))
            return resp
    return render_template('login.html', error=error)



@app.route(f'/{token}', methods=['GET','POST'])
def main_page():
    user_id = request.cookies.get('username')

    if request.method == 'POST':
        db = Db_Connection('./lib/social.db')

        status = request.form['status']
        username = db.findRecords('Users','username',condition=f'id = "{user_id}"')[0][0]
        
        db.add('Stati', user_id, status, columns='"id_user", "status"')
        db.close()

        random_status = getRandomStatus(user_id)
        resp = make_response(render_template('index.html', msg=random_status))
        resp.set_cookie('username',user_id)
        return resp
        
    elif request.method == 'GET':
        random_status = getRandomStatus(user_id)
        resp = make_response(render_template('index.html',  msg=random_status))
        resp.set_cookie('username',user_id)
        return resp
    
    resp = make_response(render_template('index.html'))
    resp.set_cookie('username',user_id)
    return resp


@app.route(f'/registration_page', methods=['GET','POST'])
def registration_page():
    if request.method == 'POST':
        password = request.form['passwrd']
        username = request.form['name']
        email = request.form['mail']
        msg = None
        if check_registration(username, password, email):
            waiting_user_list[registration_token] = (username,password,email)
            email_alert('Social account verification',
                        f'Hello {username}.\nClick the link below to activate your account:\nhttp://127.0.0.1:5000/{registration_token}/',
                        email)
            msg = 'Data correctly submitted! Check your email to confirm the subscrition.'
        else:
            msg = 'Error. You can\'t leave empty fields.'

    elif request.method == 'GET':
        return render_template('registration.html')
    
    return render_template("registration.html", msg=msg)



@app.route(f'/{registration_token}/', methods=['GET','POST'])
def confermation():
    if request.method == 'POST':
        return redirect(url_for("login"))
    if request.method == 'GET':
        username,password,email = waiting_user_list[registration_token]
        db = Db_Connection('./lib/social.db')
        db.add('Users',username, password, email, columns='"username","password","email"')
        db.close()
        return render_template("confirmation.html")


if __name__ == "__main__":
    app.run(debug=True, host=SERVER_IP)
