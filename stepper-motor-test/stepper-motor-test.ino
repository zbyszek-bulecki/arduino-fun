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
int counter;
char lastUsed[2];

void setup() {
  Serial.begin(115200);
  pinMode(RIGHT_BUTTON_PIN, INPUT_PULLUP);
  pinMode(LEFT_BUTTON_PIN, INPUT_PULLUP);
  pinMode(RESET_BUTTON_PIN, INPUT_PULLUP);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop() {
  Stepper stepper_main(STEP_NUMBER, 8, 9, 10, 11);
  stepper_main.setSpeed(stepperSpeed);

  RightButtonCurrentState = digitalRead(RIGHT_BUTTON_PIN);
  if (RightButtonLastState == LOW && RightButtonCurrentState == HIGH) {
    digitalWrite(2, HIGH);
    stepper_main.step(stepsPerRevolutionRight);
    digitalWrite(2, LOW);
    motorPosition = +stepsPerRevolutionRight;
    counter++;
    lastUsed[0] = 'r';
  }
  LeftButtonCurrentState = digitalRead(LEFT_BUTTON_PIN);
  if (LeftButtonLastState == LOW && LeftButtonCurrentState == HIGH) {
    digitalWrite(3, HIGH);
    stepper_main.step(stepsPerRevolutionLeft);
    digitalWrite(3, LOW);
    motorPosition = +stepsPerRevolutionLeft;
    counter++;
    lastUsed[1] = 'l';
  }
  ResetButtonCurrentState = digitalRead(RESET_BUTTON_PIN);
  if (ResetButtonLastState == LOW && ResetButtonCurrentState == HIGH) {
    if(lastUsed[0] == 'r' && lastUsed[1] == 'l')
    motorPosition = 0;
    digitalWrite(4, HIGH);
    stepper_main.step(-motorPosition * counter);
    digitalWrite(4, LOW);
    counter = 0;
    motorPosition = 0;
    lastUsed[0] = NULL;
    lastUsed[1] = NULL;
  }

  LeftButtonLastState = LeftButtonCurrentState;
  RightButtonLastState = RightButtonCurrentState;
  ResetButtonLastState = ResetButtonCurrentState;
}
