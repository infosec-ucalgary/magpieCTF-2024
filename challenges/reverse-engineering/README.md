# <SpaceEscape>
### Category: <Reverse Engineering> <Easy>
### Author: <Paige So’Brien>

## Description
A mini text adventure game executable where you explore rooms on a ship taken over by the definitely-not-a-knockoff AI supercomputer HOL 8000 and need to find the password to the mainframe terminal. 

## Hints
Remember the ship layout is an upside-down BST, so the highest value leaf will be to the left and lowest to the right. 

The password may not seem like the password even if you find it—make sure to follow the decompiled if-statements closely. Also, you can’t find the password by playing the game itself. 

The strings command may or may not help you. A decompiler like Ghidra may help you. 

## Solution
Use a decompiler to view the source code and navigate the functions making up each room on the correct path (functions named “correctpath”). Upon reaching correctpath3, look at the if statements to identify the password. The password is “r4r2”. Go back into the text-adventure game and travel left-left-right. Insert the password to retrieve the flag. 


## Flag

magpie{1M_S0rRY_dAv3}
