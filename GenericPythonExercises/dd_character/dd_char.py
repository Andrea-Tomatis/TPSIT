'''
Dangeon & Dragons: generate a random D&D character.

@Andrea-Tomatis
'''

import random

class Character():

    def __init__(self, name):
        self.name = name
        self.abilities = {'strenght' : 0,
                      'dexterity' : 0,
                      'constitution' : 0,
                      'intelligence' : 0,
                      'wisdom' : 0,
                      'charisma' : 0}

        for key,_ in self.abilities.items():
            extraction = [random.randint(1,6) for i in range(4)]
            self.abilities[key] = sum(extraction) - min(extraction)

    def get_initialPoint(self):
        if self.abilities['constitution'] % 2 == 0:
            self.initialHitPoints = int(((self.abilities['constitution'] - 10) / 2) + 10) 
        else:
            self.initialHitPoints = int(((self.abilities['constitution'] - 10) / 2) + 9.5) 
        
        return self.initialHitPoints


def main():
    new_char = Character('Pippo')
    print(new_char.get_initialPoint())


if __name__ == '__main__':
    main()