import sys
import time
import random
from Crypto.Cipher import AES
from binascii import b2a_hex, a2b_hex
plaintext="255044462d312e350a25d0d4c5d80a34"
ciphertext="d06bf9d0dab8e8ef880660d2af65aa82"
iv = "09080706050403020100A2B2C2D2E2F2"

def getST(string):
    timeArray = time.strptime(string, "%Y-%m-%d %H:%M:%S")
    timestamp = time.mktime(timeArray)
    return timestamp

dt1 = getST("2018-04-17 21:08:49")
dt2 = getST("2018-04-17 23:08:49")


class prpcrypt():
    def __init__(self, key,iv):
        self.key = key
        self.iv =iv
        self.mode = AES.MODE_CBC
        
    def encrypt(self, text):
        cryptor = AES.new(self.key, self.mode, self.iv)
        length = 16
        count = len(text)
        if(count % length != 0) :
            add = length - (count % length)
        else:
            #add = 0
            #text = text + ('\0' * add)
            self.ciphertext = cryptor.encrypt(text)
        return b2a_hex(self.ciphertext)
    def decrypt(self, text):
        cryptor = AES.new(self.key, self.mode, self.iv)
        plain_text = cryptor.decrypt(a2b_hex(text))
        return plain_text.rstrip('\0')
    
if __name__ == '__main__':
    for i in range(int(dt1),int(dt2)):
        try:
            #print(i)
            random.seed(int(i))
            key = int(random.random()*10000000000000000)
            pc = prpcrypt(str.encode(str(key)),str.encode(iv[:16]))
            e = pc.encrypt(str.encode(plaintext))
            if e == ciphertext:
                break
        except Exception as e:
            print(e)
    print(key)


