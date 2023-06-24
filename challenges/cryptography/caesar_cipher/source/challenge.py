#!/usr/bin/env python3
plaintext="magpie"
for i in plaintext:
    print(chr((ord(i)-97-1)%26+97),end="")
