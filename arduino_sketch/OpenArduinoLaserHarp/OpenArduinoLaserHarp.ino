#include <Stepper.h>

const int LASER_PIN = 12;

const int stepsPerRevolution = 200;

Stepper stepperMotor(stepsPerRevolution, 4, 5, 6, 7);

int timeInEachNote = 10;

//int currentAngle = 0.25; //a fraction of 1;
int currentAngleInSteps = 25;
int currentNoteIndex = 1;
int currentStepPosition = 0; //in steps

int directionIncrement = -1;

int notes[] = {
  64, 66, 68, 69, 71 //, 73, 75
};

int notesLength = 5;

void setup() {
  stepperMotor.setSpeed(200); //in RPM
  pinMode(LASER_PIN, OUTPUT);
  changeLaserState(false);
  //Serial.begin(9600);
}

void incrementNoteIndex() {

  if (currentNoteIndex >= notesLength - 1 || currentNoteIndex <= 0) {
    directionIncrement *= -1;
  }
  currentNoteIndex += directionIncrement;
}

int getNotePosition(int noteIndex) {

  return (getStepsByNote() * noteIndex) - (currentAngleInSteps / 2);
}

int getStepsByNote() {

  return currentAngleInSteps / notesLength;
}

int moveMotor(int steps) {

  stepperMotor.step(steps);
  currentStepPosition += steps;
}

int moveMotorTo(int positionInSteps) {

  moveMotor(positionInSteps - currentStepPosition);
}

void goToNextNote() {

  incrementNoteIndex();
  moveMotorTo(getNotePosition(currentNoteIndex));
}

void changeLaserState(boolean turnOn) {

  if(turnOn) {
    digitalWrite(LASER_PIN, LOW);  //** It's not reversed, the 
  } else {                         //** laser is tied to a PNP
    digitalWrite(LASER_PIN, HIGH); //** transistor!
  }
}

void loop() {

  goToNextNote();
  delay(2);
  changeLaserState(true);
  delay(timeInEachNote); //diminuir? motor mais rapido? 12 V? 
  changeLaserState(false);
}

