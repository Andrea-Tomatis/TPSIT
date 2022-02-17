'''
Tournament: Tally the results of a small football competition.
            Based on an input file containing which team played against which and what the outcome was, create a file with a table like this:

            Team                           | MP |  W |  D |  L |  P
            Devastating Donkeys            |  3 |  2 |  1 |  0 |  7
            Allegoric Alaskans             |  3 |  2 |  0 |  1 |  6
            Blithering Badgers             |  3 |  1 |  0 |  2 |  3
            Courageous Californians        |  3 |  0 |  1 |  2 |  1

@Andrea-Tomatis
'''

import csv


result = {'win' : 3, 'draw' : 1, 'loss' : 0}


def main():
    data_reader = csv.reader(open('./matches.csv'), delimiter=';')
    next(data_reader)

    #teams dictionary:
    #{nameTeam : [MP, W, D, L, P], ...} 
    teams = {}


    for row in data_reader:
        if row[0] not in teams:
            teams[row[0]] = [0,0,0,0,0]
        if row[1] not in teams:
            teams[row[1]] = [0,0,0,0,0]
        
        teams[row[0]][0] += 1
        teams[row[1]][0] += 1

        if row[2] == 'win':
            teams[row[0]][1] += 1
            teams[row[1]][3] += 1
            teams[row[0]][4] += 3
        elif row[2] == 'loss':
            teams[row[0]][3] += 1
            teams[row[1]][1] += 1
            teams[row[1]][4] += 3
        else:
            teams[row[0]][2] += 1
            teams[row[1]][2] += 1
            teams[row[0]][4] += 1
            teams[row[1]][4] += 1
        
    print('team   | matches | win | draw | loss | points')
    for team, stat in teams.items():
        print(f'{team}   | {stat[0]} | {stat[1]} | {stat[2]} | {stat[3]} | {stat[4]}')

if __name__ == '__main__':
    main()