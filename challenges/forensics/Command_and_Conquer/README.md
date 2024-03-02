
# Command and Conquer
### Category: Forensics+OSINT Hard
### Author: Royce 

## Description
A client of mine recently was hit with some nasty piece of rogue-ware ransomware known as "InfectionVector". This state of the art ransomware spread far and wide, netting Rogueware a handsome amount of Wonero and attention. Unfortunately for Rogueware, this attention I speak of is referring to the Aberrant Watchdogs. The Aberrants quickly seized Rogueware servers and shut down their operations. Anyways, my client is left with a bunch of encrypted files and they will remain encrypted irrespective of who controls the Rogueware servers. So what gives? Well, a little birdy told me that a prominent researcher at Abbarant Watchdogs has just found the master Placeholder decryption key after seizing a Rogueware developer's server. Furthermore, we got a sample which supposedly links back to this aforementioned server. I trust that you won't ask how I got it or why it is coded in JS. Your mission, should you choose to accept it, is to find the researcher and the decryption key via the malware sample we have retrieved. 
Good luck

Bounty Posted By: Agent RazorKrypt

_Disclaimer: The files used in this challenge are designed to mimick real malware. While the files in this challenge will not compromise any system, you should still treat the files as if they are malicious._
## Hints
Sometimes, it is better to just let a file run in a controlled manner than dissecting it. 
Lots of malware will "phone home" before doing any actions.



## Solution
There are two parts to this challgenge. 

#Part 1
main approaches to reverse engineering the malware. Static and Dynamic analysis. Dynamic analysis involves running the malware in a controlled manner, static analysis involves reverse engineering the malware - usually via a debugger of some sort. 
#Dynamic
If you just run the file in windows, then the file terminates itself - the same goes for running in linux. This is usually indicative of some environment check. Inspecting the network requests will reveal that the program sends a request to facebook, twitter and some other non existent domain. If you  use a tool like fakenet you can trick the program into thinking that the domain exists. After doing so, the program will proceed to give you a performance by rick astley. However, if you look at the network requests again you will notice an interesting domain "malware.secard.ca". If you go to this domain you will notice a powershell command and a comment by what looks to be a researcher. From here you can go to secard.ca and begin the second part of the challenge. 

#Static
Painful Debugging, I wont give a full walkthrough because it takes too much time. First you need to deobfuscate the code. Then, you need to remove the antidebugger code. Next remove the network environment check - this is easily done by negating an if statement. Finally you need to just remove the environment check code and bam, you will either get Rick Astley dancing or you will get an error code regarding the malware domain ("malware.secard.ca") in the console. Proceed to step 2. 

#Part 2
In this part you need to find the main researcher who holds the master decryption keys. The website and secard domain reveals a bunch of comments/clues referring to an "Agent Cromwell". A quick google search of agent cromwell with the keyword "Abbarant Watchdogs" will reveal agent cromwell's linkedin page. A curious post of his has the flag encrypted with AES. You can find the AES key and IV in the clues littered across the secard website. From there, you simply decrypt the flag from the linkedin post and bam you got the flag. 
## Flag
magpie{7H3_64UrD_D065_N3V3r_811NK}
