# Patch or Pass
### Category: Reverse Engineering Medium
### Author: Yanbo Liu

## Description
While we are patching this AI, we realize that it telling us there is a flag. However, we cannot find it anywhere in the program. Perhaps it is a mistake?
File Hash: 40b88dc7e685ce58be5c231ab258c20dd1b083b5e431e81ed4e6340aba432104
The file may get picked up by anti-virus. If the downloaded file has the hash above, it is safe to run.

## Hints
1. I knew a spy with the code "D.N.". Maybe he/she can help me with the task?
2. It looks like some variable values are not used. I wonder why.

## Solution
1. String the binary and you will realize it is a .NET binary.
2. Download DnSpy (or equivalent) to debug the program.
3. Run the executable and you will realize it says "The truth is hidden at the place where the program DOES NOT care about!"
4. Looking at the program you will see that there are classes from 1 - 20 that have 5 different fields. However, only 4 fields are used.
5. Use DnSpy to edit the code so it returns the field that is NOT used. Do the same for all 20 classes.
6. Export the new executable and run it. You will see the flag.

## Flag

magpie{d1d_y0u_533_7h3_fl46}
