#include <Stepper.h>

#define STEP_NUMBER 18
const int RIGHT_BUTTON_PIN = 7;
const int LEFT_BUTTON_PIN = 6;

int RightButtonLastState = HIGH;
int LeftButtonLastState = HIGH;
int RightButtonCurrentState;
int LeftButtonCurrentState;

int stepperSpeed = 120;
int stepsPerRevolutionRight = 240;
int stepsPerRevolutionLeft = -240;

void setup() {
  Serial.begin(115200);
  pinMode(RIGHT_BUTTON_PIN, INPUT_PULLUP);
  pinMode(LEFT_BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  Stepper stepper_main(STEP_NUMBER, 8, 9, 10, 11);
  stepper_main.setSpeed(stepperSpeed);

  RightButtonCurrentState = digitalRead(RIGHT_BUTTON_PIN);
  if (RightButtonLastState == LOW && RightButtonCurrentState == HIGH) {
    Serial.println("Let's roll RIGHT!");
    stepper_main.step(stepsPerRevolutionRight);
  } else {
    LeftButtonCurrentState = digitalRead(LEFT_BUTTON_PIN);
    if (LeftButtonLastState == LOW && LeftButtonCurrentState == HIGH){
      Serial.println("Let's roll LEFT!");
      stepper_main.setSpeed(stepperSpeed);
      stepper_main.step(stepsPerRevolutionLeft);
    }
  }
  LeftButtonLastState = LeftButtonCurrentState;
  RightButtonLastState = RightButtonCurrentState;
}
