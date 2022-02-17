'''
Diffie-Hellman: Diffie-Hellman key exchange.
                Alice and Bob use Diffie-Hellman key exchange to share secrets. 
                They start with prime numbers, pick private keys, generate and share 
                public keys, and then generate a shared secret key.

@Andrea-Tomatis
'''

import secrets


class Person():
    def __init__(self, name):
        self.name = name
    
    def set_prime(self, p, g):
        self.p = p 
        self.g = g
        self.a = secrets.randbelow(p) + 1
    
    def generate_public_key(self):
        try:
            self.A = (self.g ** self.a) % self.p
        except AttributeError:
            print('error: p and g don\'t exist')
    
    def get_public_key(self):
        try:
            return self.A
        except AttributeError: print('error: public key doesn\'t already exists')
    
    def generate_secret_key(self, B):
        self.S = (B ** self.a) % self.p



def generate_prime():
    prime_numbers = []
    for x in range(1,101):
        for y in range(2,x):
            if x%y==0:break
        else: prime_numbers.append(x)
    
    return secrets.choice(prime_numbers), secrets.choice(prime_numbers)



def main():
    alice = Person('Alice')
    bob = Person('Bob')

    '''
    step 0: The test program supplies prime numbers p and g.'''
    p, g = generate_prime()


    '''
    step 1: Alice picks a private key, a, greater than 1 and less than p. 
            Bob does the same to pick a private key b.'''
    alice.set_prime(p,g)
    bob.set_prime(p,g)


    '''
    step 2: Alice calculates a public key A.
            A = g**a mod p
            Using the same p and g, Bob similarly calculates a public key B from 
            his private key b.'''
    alice.generate_public_key()
    bob.generate_public_key()


    '''
    step 3: Alice and Bob exchange public keys. Both of them calculate secret key s.'''
    alice.generate_secret_key(bob.get_public_key())
    bob.generate_secret_key(alice.get_public_key())

    print(f"Alice secret key: {alice.S}\nBob secret key: {bob.S}")


if __name__ == '__main__':
    main()