from sympy import Poly as P, Symbol as S
from sympy.polys.polymatrix import PolyMatrix as M
x=S('x')
q=P([1,0,0,0,1],x)
s=M([P([-1,-1,1,0],x), P([-1,0,-1,0],x)])
A=M([[P([6,16,16,11],x),P([9,4,6,3],x)],[P([5,3,10,11],x),P([6,1,9,15],x)]])
#e=M[P(x**2), P(x**2-x)]
print(A*s%q)
