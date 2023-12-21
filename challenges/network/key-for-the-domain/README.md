# Key for the domain
### Category: Network Medium
### Author: Ned Liu

## Description
We received this traffic that contains a key to set an AI to be free. The sender also mentioned some sort of key and told us this is definitely not a domain. I wonder what that means.

## Hints
1. I wonder what the extra file is for? Perhaps a key?
2. Is that another key in the web traffic?
3. There seems to be some weird DNS query. I wonder if it has anything to do with the keys.

## Solution
1. Load the pcap file into Wireshark.
2. Load the session key file into Wireshark. This can be done by going to "Edit" > "Preferences" > "Protocol" > "TLS" and load the key file at "(Pre)-Master-Secret log filename"
3. You will see that the first section of TLS traffic is decrypted and there is some HTTP traffic. Inside the traffic you can see another key "<h1>key</h1><p>1, 4, 8, 10, 11, 16, 19, 20, 23, 25</p>"
4. Search up DNS packets with the string "definitelynotadomain", you will find 25 requests that go to <string>.definitelynotadomain.net.
5. Using the key from step 2: only get the string part from 1st, 4th, 8th, 10th, 11th, 16th, 19th, 20th, 25th request. And concate them. You should have a zip file.
6. Unzip the file for the flag.

## Flag

magpie{d3cryp71n6_7h3_fl46}
