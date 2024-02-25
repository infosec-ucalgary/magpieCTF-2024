# Morning Announcement

### Category: Forensics

### Author: Amna Adnan

## Description

An announcement was transmitted to all human-owned devices and androids this morning, it was also broadcasted over all transit lines, apologizing for a disturbance. There was no mention of what the disturbance was. Rogueware has come to believe that this announcement was a front for a secret message sent to androids. Who knows what affect this would have on abberrants as well. We have posted a bounty for the discovery if there was a secret message concealed within this announcement and the content of this message. If you find that there is a message concealed in the announcement, please send it to us in the form magpie{concealed_message}.

Thank you for supporting us in our mission,  
Sincerely,  
Rogueware Inc.

## Hints

## Solution

The intended solution involved writing a program to extract the message from the WAV file. You could use the wave module, which is the standard library for reading and writing WAV files.

The extract_message function would take the audio file as an arguement and read and convert the frames into an array of signed short integers. More information on this can be found here: https://dsp.stackexchange.com/questions/61996/what-are-the-semantics-of-wav-file-sample-values.

Using audio.readframes(audio.getnframes()): will return the number of frames in the audio file.

Then you can use samples = array.array('h', frames) to convert to an array of signed short integers ('h'), where each sample is represented as a 16-bit integer.

You can write a for loop to then examine the LSB of each sample in groups of 8. In the case that the byte string is a null character, it signifies the end of the message and the loop breaks, otherwise the variable for the length of the message is incremented to account for another character in the message.

Then finally you extract the hidden message from the LSBs by joining the characters.

## Flag

magpie{all_androids_tune_in_to_1061_AM}
