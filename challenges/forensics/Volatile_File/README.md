# Volatile File
### Category: Forensics+RE Hard
### Authors: Royce(Challenge Design & Scripting/Programming) & Ned(VM and Memory Dumping)

## Description
Rogueware is back at it again, and this time they successfully PWND my client and chowed down on his computer like a bag of Meowmix. The intrusion was thankfully detected, but my client is unhappy about the incident to say the least. A memory dump was taken and submitted to Abbarant Watchdogs for analysis. Unfortunately, the dogs (like always) are too busy dealing with dismantling and seizing Rogueware infrastructure to care about our little incident. While the Abbarant Watchdogs may not care about our little incident, my client sure does. Your mission should you choose to accept it, is to find out what file is causing havoc on my client's computer.  
Good luck

Bounty Posted By: Agent RazorKrypt

## Hints
The memory dump was made with DumpIt

Some children sadly die before they can be found with psscan. 
## Solution
A quick volatility PSScan reveals a suspicious powershell process, but that is about it. Performing a process child search reveals that there are two children, one of which is called "OfficeSetup.exe". Why would powershell be needed to setup MS Office? A filesearch of OfficeSetup reveals its location in a hidden directory in appdata with its virtual memory offset. From here you can plug the virtual memory offset into volatility's filedump and obtain the interesting .exe file

From here there are two ways to get the flag. 
 1. Continue to suffer in volatility by dumping and analyzing the original parent Powershell process
 2. Open up cutter/ghidra and start reverse engineering the file. A quick strings search on the file reveals an interesting gibberish text. If you pass this in as an argument then you get the flag. The flag is encoded in ROT 19 and is split up accross different variables, albeit this is easy to spot once you open up your favorite reverse engineering tool, so you can reconstruct the flag by revengineering the binary too. 

This challenge was inspired by PlayCyber's "Infected" Challenge. No code was taken from the PlayCyber Infected CTF challenge whatsoever. The memory dump was created on a VM. The flag executable file and all powershell commands are original creations. 

## Flag

magpie{V0l4tiL3_C0d3_i5_H4rD}
