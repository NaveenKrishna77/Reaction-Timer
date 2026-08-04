## Reaction Timer

Circuit: 
<img width="959" height="1412" alt="20260804_161847" src="https://github.com/user-attachments/assets/ee5ddcf3-7cad-4307-b8ad-68110583ad68" />

Flowchart:
<img width="625" height="958" alt="Reaction timer v1" src="https://github.com/user-attachments/assets/56ce7096-abba-4754-a585-eaebb6061bae" />



## Highlights
- Uses common cathode LED, flashes blue on start and green when user guesses
- Hardware First: Always checked physical connections before software bugs (the ESP32 wasn't pushed all the way into the breadboard)
- State Machines: Thinking in states and functions rather than one long program
- Timing: Switched from millis() to elapsedMillis with an initialization guard for non-blocking delays and less math needed to get intervals of time
- Process: Flowcharts and paper planning before coding made implementation much clearer.



## Overview
Project: Reaction timer game using ESP32, LEDs, and buttons.
Core Rules: Press the correct button when an LED lights up green; press button in time to flash it green and get reaction speed in the Serial Monitor
Tech Stack: C++, PlatformIO, elapsedMillis library.
