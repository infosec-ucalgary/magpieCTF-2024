# Zoo Video
### Category: Forensics Easy
### Author: Emmanuel

## Description
DISCLAIMER: I ended up zipping the file due to it being too big; not completely sure if it will mess up the challenge
I came across this old video on a random disk drive I found on the floor. The audio seems off, is there something behind it?


## Hints
steganography

## Solution
Upon watching the video, there will be weird audio playing within the first <5 seconds.
Extracting the audio and putting it through a spectrogram viewer will yield the following result: "zo0isveryveryfun"
Perform binwalk on the video, you will find that there is a jpeg image embedded within the video
Once the video is extracted, will get an image of an elephant.
Use the phrase found from the spectrogram with steghide --extract in order to get a .txt file with the key in it.


## Flag
magpie{EL3PH4nts_cOoL_VeRy}
