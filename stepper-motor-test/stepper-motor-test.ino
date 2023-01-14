#include <Stepper.h>
#include <string.h>

#define STEP_NUMBER 120
const int RIGHT_BUTTON_PIN = 7;
const int LEFT_BUTTON_PIN = 6;
const int RESET_BUTTON_PIN = 5;

int RightButtonLastState = HIGH;
int LeftButtonLastState = HIGH;
int ResetButtonLastState = HIGH;

int RightButtonCurrentState;
int LeftButtonCurrentState;
int ResetButtonCurrentState;

int stepperSpeed = 60;
int stepsPerRevolutionRight = 240;
int stepsPerRevolutionLeft = -240;
int motorPosition;

void setup() {
  Serial.begin(115200);
  pinMode(RIGHT_BUTTON_PIN, INPUT_PULLUP);
  pinMode(LEFT_BUTTON_PIN, INPUT_PULLUP);
  pinMode(RESET_BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  Stepper stepper_main(STEP_NUMBER, 8, 9, 10, 11);
  stepper_main.setSpeed(stepperSpeed);

  RightButtonCurrentState = digitalRead(RIGHT_BUTTON_PIN);
  if (RightButtonLastState == LOW && RightButtonCurrentState == HIGH) {
    Serial.println("Let's roll RIGHT!");
    stepper_main.step(stepsPerRevolutionRight);
    motorPosition = +stepsPerRevolutionRight;
    Serial.println(motorPosition);
  }
  LeftButtonCurrentState = digitalRead(LEFT_BUTTON_PIN);
  if (LeftButtonLastState == LOW && LeftButtonCurrentState == HIGH) {
    Serial.println("Let's roll LEFT!");
    stepper_main.step(stepsPerRevolutionLeft);
    motorPosition = +stepsPerRevolutionLeft;
    Serial.println(motorPosition);
  }
  if (motorPosition != 0) {
    Serial.println("It's RESET time!");
    stepper_main.step(-motorPosition);
  }
  motorPosition = 0;
  LeftButtonLastState = LeftButtonCurrentState;
  RightButtonLastState = RightButtonCurrentState;
  ResetButtonLastState = ResetButtonCurrentState;
}
