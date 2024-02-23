# PDForensics

### Category: Forensics Easy

### Author: Royce

## Description

A client of mine claims that they are the subject of a targeted operation from advanced adversaries, namely Rogueware. My client is no QuantumLock specialist and is probably being paranoid, but nonetheless I have to take my client's concerns seriously. My client recently received a highly anticipated PDF file via email, but he is too scared to open it lest he risk being compromised. Attached is the aforementioned PDF file, your mission, should you choose to accept it, is to find out if my client has been "doomscrolling" on eKs or if Rogueware has their sights trained on my client.

Bounty Posted By: Agent RazorKrypt

_Disclaimer: The files used in this challenge are designed to mimick real malware. While the files in this challenge will not compromise any system, you should still treat the files as if they are malicious._

## Hints

Lots of business oriented malware is focused on infecting the Microsoft Windows platform. This challenge becomes a lot easier if you use MS Windows. If you cannot use MS Windows, you can use lnkinfo to help with this challenge.

## Solution

The zip folder contains a PDF file with a link to some zip file. The zip file in question has a .lnk file that is disguised as a PDF. Opening any .lnk inspector will show that the .lnk runs a CMD payload, which stages "malware" through a commanding CNC server distributing commands over a DNS TXT record. A quick look at said DNS record reveals that the CNC commands the stager to download a suspicious file with a name like "notavirus.exe" to the user's temp directory. If you open the .exe in a note editor you will find that this notavirus.exe is in fact not a virus, but just a flag in disguise. Renaming the .exe to a .txt will allow you to open the file and obtain the flag without issue. Or... you could just visit the website (github) hosting notavirus.exe and find the flag right there.

## Flag

magpie{D0n't_cl1ck_0n_L1nk5}
