'''
Clock: Implement a clock that handles times without dates.
    Two clocks that represent the same time should be equal to each other.

@Andrea-Tomatis
'''

import time
import pygame
import sys
from threading import Thread


DIM_WIN = 400
WHITE = (255,255,255)
BLACK = (0,0,0)


class Clock(Thread):
    def __init__(self):
        Thread.__init__(self)
        self.hour = None
        self.minute = None
        self.second = None
        self.running = True
    
    def get_time(self):
        return f'{str(self.hour).zfill(2)} : {str(self.minute).zfill(2)} : {str(self.second).zfill(2)}'
    
    def run(self):
        while self.running:
            localtime = time.localtime(time.time())
            self.hour = localtime[3]
            self.minute = localtime[4]
            self.second = localtime[5]
    


def text_objects(text, font):
    textSurface = font.render(text, True, BLACK)
    return textSurface, textSurface.get_rect()


def printf(text, x=0, y=0, font='freesansbold.ttf', size = 115):
    largeText = pygame.font.Font(font, size)
    TextSurf, TextRect = text_objects(text, largeText)
    TextRect.center = ((x,y))
    screen.blit(TextSurf, TextRect)



def main():
    pygame.init()
    global screen

    screen = pygame.display.set_mode((DIM_WIN, DIM_WIN))
    screen.fill(WHITE)
    pygame.display.set_caption('pygame clock')

    clk = Clock()
    clk.start()


    while True:
        screen.fill(WHITE)
        printf(clk.get_time(), DIM_WIN//2, DIM_WIN//2, size=50)

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                clk.running = False
                clk.join()
                sys.exit()
        
        pygame.display.update()


if __name__ == '__main__':
    main()