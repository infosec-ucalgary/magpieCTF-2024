#!/usr/bin/env python3
from hashlib import sha3_256 as h
from Crypto.Math._IntegerGMP import IntegerGMP as GMP
from signature import ECDSA
import socketserver
import json
import random
import string

def challenge(req):
    while True:
        try:
            curve=ECDSA()
            key = curve.key_gen()
            ALPHABET=string.ascii_letters
            m1=GMP(int(h("".join(random.sample(ALPHABET, 12)).encode()).hexdigest(),16))
            m2=GMP(int(h("".join(random.sample(ALPHABET, 12)).encode()).hexdigest(),16))
            Q = key.public_key().pointQ
            d = key.d

            r1,s1=curve.sig_gen(m1,d)
            r2,s2=curve.sig_gen(m2,d)

            msg = f"public key: ({Q.x}, {Q.y})\n\nhints:\n{m1}\n{m2}\n\nsignatures: ({r1},{s1}), ({r2},{s2})\nprivary key (d): \n"
            req.sendall(msg.encode('utf-8'))

            m3=GMP(int(h("".join(random.sample(ALPHABET, 12)).encode()).hexdigest(),16))
            din=int(req.recv(4096).decode().strip())
            r,s = curve.sig_gen(m3, d)
            if curve.verify(Q,s,r,m3):
                req.sendall(b"flag redacted\n")
            else:
                req.sendall(b"invalid key\n")
            break
        except Exception as e:
            print(f"Exception occurred: {e}")
            return


class MyTCPRequestHandler(socketserver.BaseRequestHandler):

    def handle(self):
        req = self.request
        challenge(req)


class ThreadingTCPServer(socketserver.ThreadingMixIn, socketserver.TCPServer):
    pass


def main():
    socketserver.TCPServer.allow_reuse_address = True
    server = ThreadingTCPServer(("localhost", 1337), MyTCPRequestHandler)
    server.serve_forever()

if __name__ == '__main__':
    main()

