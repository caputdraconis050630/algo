import random, os
from itertools import cycle

def generate_key():
    open('key', 'wb').write(os.urandom(0x20))

class CustomHash():
    def __init__(self, key):
        self.salt = random.randint(0, 0x100)
        self.key = []
        for i in key:
            (self.key).append(i ^ self.salt)

        self.key = self.key[::-1]

    def encrypt(self, msg):
        if len(msg) < len(self.key):
            return None
        else:
            enc = []
            for i,j in zip(msg, cycle(self.key)):
                enc.append(i^j)
            return enc

    def decrypt():
        pass

generate_key()
key = open('./key', 'rb').read()
flag = open('./flag.txt', 'rb').read()

hash = CustomHash(key)
enc = hash.encrypt(flag)
open('flag.enc', 'wb').write(bytearray(enc))