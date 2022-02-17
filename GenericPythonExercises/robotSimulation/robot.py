'''
Robot simulator: Write a robot simulator. A robot factory's test facility needs a 
                program to verify robot movements.

@Andrea-Tomatis
'''


def calc_position(pos, movements, pointer):
    robot_dir = 'x'
    directions = {1 : 'north', 2 : 'east', 3 : 'south', 4 : 'west'}
    for m in movements:
        if m == 'R':
            robot_dir = 'x'
            pointer += 1 
            pointer %= 5
        elif m == 'L':
            robot_dir = 'y'
            pointer -= 1
            if pointer < 1: pointer = 4
        elif m == 'A':
            if robot_dir == 'x':
                pos[1] += 1
            else: pos[0] += 1
    
    return pos, directions[pointer]



def main():
    movements = 'RAALAL'
    pos = [7,3]
    pointer = 1
    print(calc_position(pos, movements, pointer))

if __name__ == '__main__':
    main()