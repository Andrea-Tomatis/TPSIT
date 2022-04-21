import requests
import os
import string
import threading

SERVER = '192.168.0.127'

#check sensors
class Robot():
    def __init__(self):
        self.prec = None
        response = os.system("ping -c 1 " + SERVER)

        if response == 0: print('is up!')
        else: print('is down!')
    
    def sensors(self):
        url = f'http://{SERVER}:5000/api/v1/sensors/obstacles'
        x = requests.get(url).json()
        print(x)
        return x

    def move(self, pwmL=70, pwmR=-70, time=0.15):
        url = f'http://{SERVER}:5000/api/v1/motors/both?pwmL={pwmL}&pwmR={pwmR}&time={time}'
        x = requests.get(url).json()
        if pwmL + pwmR == 50 or pwmL + pwmR == -50 :
            self.prec = [pwmL, pwmR, time]
        print(x)
    


def main():
    robot = Robot()
    robot.move(pwmL=100, pwmR=-100, time=0.2)
    while True:
        robot.move()
        right_sens, left_sens = robot.sensors().values()

        if not left_sens and not right_sens:
            print('both')
            robot.move(pwmL=-50, pwmR=50, time=0.2)
            try:
                robot.move(pwmL=robot.prec[0],pwmR=robot.prec[1],time=robot.prec[2])
            except:
                pass
        elif not left_sens:
            print('right sense')
            robot.move(pwmL=15, pwmR=35, time=0.5)
        elif not right_sens:
            print('left sense')
            robot.move(pwmL=-35, pwmR=-15, time=0.5)
        


if __name__ == '__main__':
    main()








