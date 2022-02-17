'''
Bowling: Score a bowling game.
         Bowling is a game where players roll a heavy ball to knock down pins arranged 
         in a triangle.
         Write code to keep track of the score of a game of bowling.

@Andrea-Tomatis
'''


def main():
    score = []
    vantage = 0

    for i in range(10):
        lancio = int(input(f'turno {i+1} > punteggio lancio 1: '))
        if lancio == 10:
            score.append(-1)
        else:
            lancio2 = int(input(f'turno {i+1} > punteggio lancio 2: '))
            if lancio2 + lancio == 10:
                score.append(-2)
            else: 
                score.append(lancio + lancio2)

    total = 0   
    for i, el in enumerate(score):
        if el == -2:
            if score[(i+1) % 10] == -1 or score[(i+1) % 10] == -2: total += 20
            else: total += 10 + score[(i+1) % 10] 
        if el == -1:
            total += 10
            for j in range(i, i+2):
                if score[j % 10] == -1 or score[j % 10] == -2: total += 10
                else: total += score[j % 10]
        else: 
            total += el

    print(f'points: {total}')


if __name__ == '__main__':
    main()