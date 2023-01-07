#include <Stepper.h>

#define STEP_NUMBER 18

Stepper stepper_main(STEP_NUMBER, 8, 9, 10, 11);

void setup() {
stepper_main.setSpeed(60);
stepper_main.step(2048);

}

void loop() {

}
