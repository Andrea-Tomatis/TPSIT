'''
Pythagorean Triplet: Given an input integer N, find all Pythagorean triplets 
                     for which a + b + c = N.

@Andrea-Tomatis
'''

def find_triple(n):
    solutions = []
    for a in range(n):
        for b in range(a+1, n):
            for c in range(b+1, n):
                if a + b + c == n and a**2 + b**2 == c**2:
                    solutions.append((a,b,c))
    
    if len(solutions) == 0:
        return 'nothing'
    else: return solutions


def main():
    print(find_triple(1000))

if __name__ == '__main__':
    main()