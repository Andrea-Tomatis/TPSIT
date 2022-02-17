'''
Resistor Value: given 2 colors, determine the value of a resistor

@Andrea-Tomatis
'''

def calculate_val(color1, color2):
    colors = {"Black": 0,
              "Brown": 1,
              "Red": 2,
              "Orange": 3,
              "Yellow": 4,
              "Green": 5,
              "Blue": 6,
              "Violet": 7,
              "Grey": 8,
              "White": 9}

    return int(str(colors[color1]) + str(colors[color2]))


def main():
    print(calculate_val("Violet", "Grey"))

if __name__ == '__main__':
    main()