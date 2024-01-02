# <latent_pearls>
### Category: <Forensics> <Easy>
### Author: <Marianna (MariannaFerr)>

## Description
The enigmatic group, Rogueware, notorious for their advocacy against the malign use of androids and AI, has raised an alarm. Android birds, enticed by the allure of shiny objects, have taken a liking to theft, pilfering everything from smartphones and wallets to delicate pearl necklaces.

In a daring move, a Rogueware agent managed to snap a picture of the avian culprits during their latest heist. However, in a twist of digital ingenuity, the thieving birds tampered with the image, leaving behind a cryptic puzzle for those daring enough to unravel it.

As the ripple effect of these deviant android birds threatens to escalate, urgent intervention is paramount. The clock is ticking, and we must thwart their escalating thievery before it evolves into a more malicious breed of mischief.

## Hints
What we are looking for must be so close-- concealed, yet right under our noses! 

## Solution
To find the flag, we must 'uncrop' the image by modifying the bytes that display its height. 
1. open cyberChef, or any hex editor you like. Pull up the hex of the image. 
2. Search (CTRL+F) for *ff c0*. This will help us find the following string of bytes:

ff c0 00 11 08 05 59 04 38

where 08:= data precision, **05 59**:= jpg height, and 04 38:= jpg width.
So, given jpeg height:= *05 59*.
3. change the height to be larger, ie, 06 59.

4. Save the image. You will then be able to see the flag!

## Flag

magpie{Cr0PPy_cR0P}