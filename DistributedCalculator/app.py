import flask
from flask import jsonify, request
from lib.query import *

app = flask.Flask(__name__)
app.config['DEBUG'] = True


@app.route('/api/v1/resources/operation', methods=['GET'])
def api_operation():
    clientID = int(request.args.get('clientID'))
    
    db = Db_Connection('./lib/client')
    query = db.findRecords('Operazioni', 'idOperation, operation', condition=f"result is NULL AND clientID={clientID} LIMIT 1")
    db.close()
    print(query)
    if len(query) == 0:
        return {'id' : 'end'}
    return {'id' : query[0][0], 'op' : query[0][1]}

@app.route('/api/v1/resources/write', methods=['GET'])
def api_write():
    clientID = int(request.args.get('clientID'))
    idOp = int(request.args.get('idOperation'))
    result = request.args.get('result')
    
    db = Db_Connection('./lib/client')
    query = db.update('Operazioni', f'result="{result}"', condition=f"clientID = '{clientID}' AND idOperation='{idOp}'")
    db.close()
    print('operation completed')

    return {'esito' : 'operation completed'}

@app.route('/',methods=['GET'])
def home():
    return """<h1>Operazioni Online</h1>
              <h4>Prova di web API</h4>
              <p>Api disponibili:</p>
              <ul>
              <li>
              Richiedi un'operazione 
              alla seguente api: /api/v1/resources/result?clientID={clientID}
              </li>
              <li>
              Scrivi il risultato di un'operazione alla seguente api:
              /api/v1/resources/result?clientID={clientID}&idOperation={idOp}&result={result}
              </li></ul"""

app.run()