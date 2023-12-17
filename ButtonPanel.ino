/*
  Button to serial quick thingy
*/

const int buttonPins[] = {2, 3, 4, 5, 6}; // array of button pin numbers
const int ledPin = 13; // LED pin number
const int numButtons = 5; // number of buttons
int buttonState[numButtons]; // array to hold the states of the buttons
bool sent[numButtons]; // array to track if the message was sent for each button

void setup() {
  pinMode(ledPin, OUTPUT); // initialize the LED pin as an output
  Serial.begin(9600); // start serial communication at 9600 bps

  for (int i = 0; i < numButtons; i++) {
    pinMode(buttonPins[i], INPUT); // initialize button pins as input
    sent[i] = false; // initialize all sent states to false
  }
}

void loop() {
  for (int i = 0; i < numButtons; i++) {
    buttonState[i] = digitalRead(buttonPins[i]); // read the state of each button

    if (buttonState[i] == HIGH && !sent[i]) {
      Serial.println(buttonPins[i]); // send pin number over serial
      sent[i] = true; // set sent state to true
      delay(100); // debounce delay
    } else if (buttonState[i] == LOW && sent[i]) {
      sent[i] = false; // reset sent state
      delay(100); // debounce delay
    }
  }
}
