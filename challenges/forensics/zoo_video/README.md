# Zoo Video
### Category: Forensics Easy
### Author: Emmanuel

## Description
We've obtained some peculiar file that we believe has some important information regarding Rogueware's recent activities. This bounty is for anyone who can uncover any important data from the file.
- Bounty posted by *Abberant Watchdogs*
## Hints
steganography

## Solution
- Upon watching the video, there will be weird audio playing within the first <5 seconds.
- Extracting the audio and putting it through a spectrogram viewer will yield the following result: `zo0isveryveryfun`
- Perform binwalk on the video, you will find that there is a jpeg image embedded within the video
- Once the video is extracted, will get an image of an elephant.
- Use the phrase found from the spectrogram with steghide `--extract` in order to get a .txt file with the key in it.

## Flag
magpie{EL3PH4nts_cOoL_VeRy}
