## July 1st

Goal

- Define and plan the reaction timer.

Questions

- What should the game do and how?
- What hardware is involved (LEDs, buttons, circuits, etc)
- What events happen in what order and what what goes in setup and loop
- What are the rules/scoring (maybe save scoring for after MVP)


Learned

- I need to think in terms of states rather than one long program.
- Stages of the project.

- I defined the system, now I need to build the MVP with core logic, then  improve code structure, add features, and reflect over the final product

- Two LEDs, Press button on correct side in time when one LED lights up, if you don't do it in time, you lose and both LEDs turn red
- If you do it in time, the winning LED turns green for a bit, and the game repeats but faster



Next Session

- Use the breadboard to build hardware MVP

## July 2nd

Goal

- Build hardware

Questions

- When I can't figure out how to wire something or to get the current flowing the way I need to make the circuit work, how should I debug (without AI so I know for the next time)?

Learned

- I should get a bigger breadboard eventually or a soldering kit
- The code is still the hardest part of the project

Next Session

- Try to finish up the hardware, debug so that the current flows correctly and learn how to test it
- Start the software engineering process, use paper to make flowcharts, diagrams, pseudocode


## July 13th

1. Define the behavior ("What should happen?")
2. Sketch the flow or state diagram.
3. Break it into tiny programming tasks.
4. Read the relevant documentation.
5. Write the code yourself.
6. Test one piece at a time.
7. Use AI only when you're stuck or want to deepen your understanding.
8. Commit the working milestone to Git.


Learned

- State machines go in loop
- Flowcharts help break down code into pieces and find what goes in setup vs what goes in loop

Next Session

- Keep working on version 1 of the reaction timer. Light music, enjoy!
- Use documentation to learn what code to initialize pins, do serial work, and setup code
- Use the flowchart to break down steps into states and program the states, build functions, build software MVP
- Document the process

## July 15th

Learned
- Everything in embedded programming is in terms of states and functions.
- Use a flowchart or diagram before starting to code always, it makes it clear what needs to be implemented in functions

## July 16th

Learned
- A little bit about millis() (it starts counting as soon as the ESP32 turns on, it's like a master timer unaware of your code, so you have to do math with time intervals)
- Pass by reference
- millis() better than delay() because it's scalable, doesn't lock out code

Next Session
- Keep working on structure for Start_Animation state, if you have to change up the blink function structure or put it in the if statement in the loop function
- Read the millis() documentation blink without delay page and try to implement a better solution without the Uptime error. (Might need a second argument in the blink function)
- Learn basic design patterns to add to mental arsenal, scope in C++, static, continue learning to think like an embedded software engineer in states, functions, and design patterns

## July 17th

Learned
- Figured out millis() properly, in order to start counting when an event happens, I used a first-run initialization guard that acts like a gatekeeper. it ensures the snapshot of the master stopwatch (millis) only happens at the exact millisecond the states changes

Next Session
- Learn more about PlatformIO
- Debug why it's not visibly flashing, 
- Static, scope in C++, Design patterns
- Continue with reaction timer programming, use states and functions
