#!/usr/bin/env python3
from Crypto.PublicKey import ECC
from Crypto.Math._IntegerGMP import IntegerGMP as GMP
from secret import k


class ECDSA():
    def __init__(self):
        self.p = 1157920892103562487626974469494075735300861434152903141955
        self.G = ECC.EccPoint(0x6b17d1f2e12c4247f8bce6e563a440f277037d812deb33a0f4a13945d898c296, 0x4fe342e2fe1a7f9b8ee7eb4a7c0f9e162bce33576b315ececbb6406837bf51f5, 'P-256')
        self.n = 115792089210356248762697446949407573529996955224135760342422259061068512044369

    def key_gen(self):
        # key-gen
        key=ECC.generate(curve='P-256')
        f=open('priv.pem', 'wt')
        f.write(key.export_key(format='PEM'))
        f.close()
        return key

    def sig_gen(self, m, d):
        r=0
        s=0
        while r==0 or s==0:
            new_coord=k*self.G
            r=new_coord.x%self.n
            k_inv=GMP(pow(k,-1,self.n))
            s=(k_inv*(m+r*d))%self.n
        return (r,s)

    def verify(self, Q, s, r, m):
        O= ECC.EccPoint(0,0,curve='p256')
        if Q==O:
           print("Q is identity, invalid")
           return -1
        if self.n*Q!=O:
           print("invalid n")
           return -1
        s_inv=GMP(pow(int(s),-1,self.n))
        u=m*s_inv%self.n
        v=r*s_inv%self.n
        verify_point=u*self.G+v*Q
        return r%self.n==verify_point.x%self.n

