#!/usr/bin/env python3

n = 115792089210356248762697446949407573529996955224135760342422259061068512044369

from pwn import *
conn=remote("localhost", 1337)
conn.recvuntil(b"(")
Qx=conn.recvuntil(b",")[:-1]
Qy=conn.recvuntil(b")")[:-1]
conn.recvuntil(b":\n")
m1=int(conn.recvline().decode().strip())
m2=int(conn.recvline().decode().strip())
conn.recvuntil(b"(")
r1=int(conn.recvuntil(b",").decode().strip()[:-1])
s1=int(conn.recvuntil(b")").decode().strip()[:-1])
conn.recvuntil(b"(")
r2=int(conn.recvuntil(b",").decode().strip()[:-1])
s2=int(conn.recvuntil(b")").decode().strip()[:-1])
conn.recv()
k=pow((s1-s2), -1,n)*(m1-m2)%n
d=pow(r1,-1,n)*(s1*k-m1)%n
print(d)
conn.sendline(str(d).encode())
print(conn.recv())
conn.close()
