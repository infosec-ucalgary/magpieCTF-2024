#!/usr/bin/env python3
import random
from Crypto.PublicKey import ECC
from hashlib import sha3_256 as h
from Crypto.Math._IntegerGMP import IntegerGMP as GMP

def sig_gen(m, G, d, n):
    r=0
    s=0
    while r%p==0 or s%p==0:
        k=random.randint(1, n-1)
        new_coord=k*G
        r=new_coord.x%n
        k_inv=GMP(pow(k,-1,n))
        s=(k_inv*(m+r*d))%n
    return (r,s)

def verify(Q, s, r, n, G, m):
    O= ECC.EccPoint(0,0,curve='p256')
    if Q==O:
       print("Q is identity, invalid")
       return -1
    if n*Q!=O:
       print("invalid n")
       return -1
    s_inv=GMP(pow(int(s),-1,n))
    u=m*s_inv%n
    v=r*s_inv%n
    verify_point=u*G+v*Q
    return r%n==verify_point.x%n

# key-gen
key=ECC.generate(curve='P-256')
f=open('priv.pem', 'wt')
f.write(key.export_key(format='PEM'))
f.close()
# read-key
f=open('priv.pem', 'rt')
key=ECC.import_key(f.read())

print(key.public_key())

# curve parameters
p = 1157920892103562487626974469494075735300861434152903141955
G=ECC.EccPoint(0x6b17d1f2e12c4247f8bce6e563a440f277037d812deb33a0f4a13945d898c296, 0x4fe342e2fe1a7f9b8ee7eb4a7c0f9e162bce33576b315ececbb6406837bf51f5, 'P-256')
n = 115792089210356248762697446949407573529996955224135760342422259061068512044369

Q=key.public_key().pointQ
d=key.d
m=GMP(int(h(b'hello').hexdigest(), 16))

r,s=sig_gen(m,G,d,n)
print(f"signatures: ({r},{s})")
print(verify(Q,s,r,n,G,m))
