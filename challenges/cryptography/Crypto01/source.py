from Crypto.Cipher import AES 
from Crypto.Util import Counter
import os

flag = b'EHCTF{REDACTED}'

key = os.urandom(16)

def encrypt(pt):
    cipher = AES.new(key, AES.MODE_CTR, counter=Counter.new(128))
    ct = cipher.encrypt(pt)
    return ct

qoute = b'What has two eyes but can not see? It is you!'

print(encrypt(qoute))
print(encrypt(flag))