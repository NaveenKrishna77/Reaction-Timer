#include <Arduino.h>
#include <elapsedMillis.h>

//pin definitions

const int leftRed = 18;
const int leftGreen = 19;
const int leftBlue = 21;

const int rightRed = 26;
const int rightGreen = 33;
const int rightBlue = 25;

const int leftButton = 22;
const int rightButton = 23;


//global tracking variables for timing
elapsedMillis timeAtStateChange;
unsigned long randDelay = 0;
unsigned long previousTimeFlashBlue = 0;         //needed to pass as reference,     just an argument to help flashBlue run with millis() for scalability


void turnOffAllLEDs();
void flashBlue(unsigned long &);


//states for the circuit
enum CircuitState {
  IDLE,
  START_ANIMATION,
  RANDOM_DELAY,
  WAIT_FOR_PRESS
};

CircuitState currentState = IDLE;

void setup() {
  Serial.begin(115200);
  //first use pinMode initalize leds as outputs and buttons as input_pullups
  //digitalRead for inputs (returns int of 1 if on or 0 if off-check for button press) use in state checks/conditionals
  //digitalWrite for outputs (when flashing leds because default is LOW-off) use in functions for LED colors
  pinMode(leftRed, OUTPUT);
  pinMode(leftGreen, OUTPUT);
  pinMode(leftBlue, OUTPUT);
  pinMode(rightRed, OUTPUT);
  pinMode(rightGreen, OUTPUT);
  pinMode(rightBlue, OUTPUT);

  pinMode(leftButton, INPUT_PULLUP);
  pinMode(rightButton, INPUT_PULLUP);

  
  
}

void loop() {
  if (currentState == IDLE) {
    turnOffAllLEDs();
    if (digitalRead(leftButton) == LOW || digitalRead(rightButton) == LOW) {
        Serial.println("button pressed");
        currentState = START_ANIMATION;
    }
  }

  else if (currentState == START_ANIMATION) {
    flashBlue(previousTimeFlashBlue);
  }

  else if (currentState == RANDOM_DELAY) {
    if (randDelay = 0) {
        randDelay = random(2000, 4000);
        timeAtStateChange = 0;
    }

    if (timeAtStateChange >= randDelay) {   //Not running properly? (changes state without delay so logic issue (or hardware))
        randDelay = 0;
        currentState = WAIT_FOR_PRESS;
    }
  }

  else if (currentState == WAIT_FOR_PRESS) {
    digitalWrite(leftGreen, HIGH);
  }

}

void turnOffAllLEDs() {
  digitalWrite(leftRed, LOW);
  digitalWrite(leftGreen, LOW);
  digitalWrite(leftBlue, LOW);
  digitalWrite(rightRed, LOW);
  digitalWrite(rightGreen, LOW);
  digitalWrite(rightBlue, LOW);
}

void flashBlue(unsigned long &previousTime) {     //global var passed by reference to make previousTime global (not reset every loop run)
  const unsigned long total_duration = 1500;    //1500 ms
  const unsigned long blink_interval = 150;     //150 ms
  unsigned long currentTime = millis();
  static unsigned long flashStartTime = 0;  //static variable to capture the time the button is pressed (moves the carrot)
  static bool blueOn = false;  //explicit state flag; digitalRead() on an OUTPUT pin isn't a reliable way to infer state on ESP32
  
  /*
  check if it's the first loop run (flash animation just starting) and make the flashStartTime and previousTime catch up with millis(),
  without this step millis() would count from when the ESP32 turns on, not from when the button pressed, we are simply moving the interval along the number line.
  What the statement does simply is sets flashStartTime to the exact second you press the button since millis() doesn't have that functionality
  */
  if (flashStartTime == 0) {
    flashStartTime = currentTime;
    previousTime = currentTime;
  }

  if (currentTime - flashStartTime >= total_duration) {    // if timer interval exceeds total duration
    turnOffAllLEDs();
    currentState = RANDOM_DELAY;
    flashStartTime = 0;        //reset so static variable works in the next loop
    previousTime = 0;
    blueOn = false;
    return;
  }
  

  else if (currentTime - previousTime >= blink_interval) {     // if timer interval exceeds blink time (blink again)
    //turn blue on if off, turn off if on
    blueOn = !blueOn;
    if (blueOn) {
      digitalWrite(leftBlue, HIGH);
      digitalWrite(rightBlue, HIGH);
    }
    else {
      turnOffAllLEDs();
    }

    previousTime = currentTime;
  }
}



