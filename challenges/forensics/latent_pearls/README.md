# <latent_pearls>
### Category: <Forensics> <Easy>
### Author: <Marianna (MariannaFerr)>

## Description
A new strain of malware from the enigmatic group Rogueware has raised an alarm. Affecting some of the older models of BinCortex's android birds, they have taken a liking to theft, pilfering everything from smartphones and wallets to delicate pearl necklaces.

A street camera managed to snap a photo of one of the droids-- but it appears that there was some interference in delivering the image, as part of the image failed to deliver. You're tasked with finding the missing data and reporting it back to us.

 - Bounty posted by *Abberant Watchdogs* and *BinCortex*

## Hints
What we are looking for must be so close-- concealed, yet right **under** our noses! 

## Solution
To find the flag, we must 'uncrop' the image by modifying the bytes that display its height. 
1. open cyberChef, or any hex editor you like. Pull up the hex of the image. 
2. Search (CTRL+F) for *ff c0*. This will help us find the following string of bytes:

ff c0 00 11 08 05 59 04 38

where 08:= data precision, **05 59**:= jpg height, and 04 38:= jpg width.
So, given jpeg height:= *05 59*:

3. change the height to be larger, ie, 06 59.

4. Save the image. You will then be able to see the flag!

## Flag

magpie{Cr0PPy_cR0P}
