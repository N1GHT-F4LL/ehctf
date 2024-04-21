from Crypto.Util.number import *

flag = b'EHCTF{REDACTED}'

p = getPrime(1024)
q = getPrime(1024)
e = 65537

n = p*q

enc = pow(bytes_to_long(flag), e, n)

n_ = bin(n)[2:-8]
q_ = bin(q)[2:-16]

print(f"enc = {enc}\nn_ = {int(n_, 2)}\nq_ = {int(q_, 2)}")
