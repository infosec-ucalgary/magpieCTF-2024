from Crypto.Util.number import long_to_bytes, bytes_to_long, getPrime, getRandomNBitInteger
from sympy import Poly as P, Symbol as S
from sympy.polys.polymatrix import PolyMatrix as M

x=S('x')

def rand_polynomial(degree, maxrange=64):
    coeff=[]
    for i in range(degree+1):
        coeff.append(getRandomNBitInteger(maxrange))
    return P(coeff, x)

matrix_size=2
flag=b"magpie{test_flag}"
message=[i for i in bin(bytes_to_long(flag))[2:]]
s=M([rand_polynomial(3, 10), rand_polynomial(3,10)])
A=M([[rand_polynomial(3) for x in range(matrix_size)]for y in range(matrix_size)])
q=rand_polynomial(4)
e=M([rand_polynomial(3,2), rand_polynomial(3,2)])
t=A*s+e
print(f"A: {A}")
print(f"t: {t}")
