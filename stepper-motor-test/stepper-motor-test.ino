#include <Stepper.h>

#define STEP_NUMBER 18
const int BUTTON_PIN = 7;

int lastState = HIGH;
int currentState;

int stepperSpeed = 60;
int stepsPerRevolution = 120;

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {

  Stepper stepper_main(STEP_NUMBER, 8, 9, 10, 11);
  currentState = digitalRead(BUTTON_PIN);

  // stepper_main.setSpeed(stepperSpeed);
  // stepper_main.step(stepsPerRevolution);

  if (lastState == LOW && currentState == HIGH) {
    Serial.println("The state changed from LOW to HIGH.");
    stepsPerRevolution = stepsPerRevolution;
    stepper_main.setSpeed(stepperSpeed);
    stepper_main.step(stepsPerRevolution);
  }
lastState = currentState;

  if (lastState == LOW && currentState == HIGH) {
    Serial.println("The state changed from LOW to HIGH again.");
    stepsPerRevolution = stepsPerRevolution * -1;
    stepper_main.setSpeed(stepperSpeed);
    stepper_main.step(stepsPerRevolution);
  }
  lastState = currentState;
}
