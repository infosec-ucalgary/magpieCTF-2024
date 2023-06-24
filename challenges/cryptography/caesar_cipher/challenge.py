#!/usr/bin/env python3
plaintext="fake_flag_for_testing"
for i in plaintext:
    print(chr((ord(i)-97-1)%26+97),end="")
