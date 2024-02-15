# Arduino Morse Code Transmitter and Decoder
My Final Project for APCS
![029B6167-8884-4C7E-B13A-344FC122A545](https://github.com/beekdorrr/APCS-Final/assets/78626546/abfe011a-97ec-4781-a3e7-761c13e9e5d4)
The goal of my project was to create an arduino morse code transmitter that sends a morse code message through the serial port, and another program to receive and decode it into a readable message. 

Function: 
- A capacitive sensor is used as the button to input the morse code, and the the duration of each press is recorded as either a dot or a dash. (I set the values for the dots and dashes)
- The timing/duration of the press is important as to make sure the correct input is recorded.
- I wasn't sure how to signify when a letter was completed based on timing, so I added a button to be pressed when a letter is completed.
- Another button is pressed to signify when an entire word is done
- When the entire message is done, a third button is pressed to send it over the serial port

morsecode.ino contains all of the code used for this project

Issues I ran into during this project were:
- figuring out how to detect dots, dashes, spaces, etc. Examples online used binary tree methods, which were out of my scope of knowledge. 
- My knowledge of morse code isn't the best, so I wasn't aware that the timing is relative to the user.
- The timing was difficult to calibrate because I have never transmitted morse code before, and didn't have a good feel for how it should be.
- My method would work if my timing was better, but it was not very reliable at transmitting the correct message as some of the letters would be wrong (ex: "HELLO" would be "HEJZK" due to incorrect inputs)

Overall, the project worked okay, but I learned a lot about serial monitors, morse code, capacitive sensors, and electronics. This was one of the most fun projects I have done and I hope to do more electronics projects in the future.
