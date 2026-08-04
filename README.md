## Reaction Timer

![Reaction Timer Circuit](C:\Users\navee\Downloads\20260804_161847.jpg "Circuit picture")



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
