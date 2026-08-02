#linclude <SparkFun_TB6612.h>

// Define the number of sensors
#define NUM_SENSORS 5  
int sensorPins[NUM_SENSORS] = {A0, A1, A2, A3, A4};
int sensorMin[NUM_SENSORS];
int sensorMax[NUM_SENSORS];

int startButton = 2; // Using a 4-pin push button on D2
bool running = false;
unsigned long lastDebounceTime = 0;
const int debounceDelay = 50;

// Motor Driver Pins
#define AIN1 7
#define AIN2 8
#define PWMA 5
#define BIN1 9
#define BIN2 10
#define PWMB 11
#define STBY 12

// Create motor objects with correct parameters
Motor motorA(AIN1, AIN2, PWMA, 1, STBY); // Offset = 1 (change to -1 if direction is reversed)
Motor motorB(BIN1, BIN2, PWMB, 1, STBY); // Offset = 1 (change to -1 if needed)

// Last side that was on the line before going off track
enum LastSeen { LEFT, RIGHT, NONE };
LastSeen lastOnTrack = NONE;

void setup() {
  pinMode(startButton, INPUT_PULLUP); // Internal pull-up for the button

  // Initialize sensor min/max values
  for (int i = 0; i < NUM_SENSORS; i++) {
    sensorMin[i] = 1023;
    sensorMax[i] = 0;
  }
}

void loop() {
  checkButton();
  if (running) {
    followLine();
  }
}

// Function to check button with debounce
void checkButton() {
  static bool lastButtonState = HIGH;
  bool buttonState = digitalRead(startButton);

  if (buttonState == LOW && lastButtonState == HIGH) {
    if (millis() - lastDebounceTime > debounceDelay) {
      running = !running; // Toggle the running state
      delay(500); // Prevent accidental double presses
    }
    lastDebounceTime = millis();
  }
  lastButtonState = buttonState;
}

// Line Following Logic
void followLine() {
  int sensorValues[NUM_SENSORS];
  int threshold[NUM_SENSORS];
  bool onTrack = false;

  for (int i = 0; i < NUM_SENSORS; i++) {
    sensorValues[i] = analogRead(sensorPins[i]);
    threshold[i] = (sensorMin[i] + sensorMax[i]) / 2;
  }

  int fullSpeed = 200;  // Normal speed
  int turnSpeed = 230;  // Slight turn speed
  int hardTurnSpeed = 240; // Hard turn speed

  int leftCount = 0, rightCount = 0;

  // Track the last side that was on the line
  if (sensorValues[0] < threshold[0]) leftCount++;
  if (sensorValues[1] < threshold[1]) leftCount++;
  if (sensorValues[3] < threshold[3]) rightCount++;
  if (sensorValues[4] < threshold[4]) rightCount++;

  if (leftCount > rightCount) {
    lastOnTrack = LEFT;
    onTrack = true;
  } else if (rightCount > leftCount) {
    lastOnTrack = RIGHT;
    onTrack = true;
  }

  // Line Following Logic
  if (sensorValues[2] < threshold[2]) { // Center sensor sees black
    moveForward(fullSpeed);
    onTrack = true;
  }
  else if (sensorValues[1] < threshold[1]) { // Slight left
    turnLeft(turnSpeed);
    onTrack = true;
  } 
  else if (sensorValues[3] < threshold[3]) { // Slight right
    turnRight(turnSpeed);
    onTrack = true;
  } 
  else if (sensorValues[0] < threshold[0]) { // Hard left
    turnLeft(hardTurnSpeed);
    onTrack = true;
  } 
  else if (sensorValues[4] < threshold[4]) { // Hard right
    turnRight(hardTurnSpeed);
    onTrack = true;
  }

  // If all sensors are off the track, recover by turning in the last known direction
  if (!onTrack) {
    if (lastOnTrack == LEFT) {
      spinAntiClockwise(hardTurnSpeed);
    } else if (lastOnTrack == RIGHT) {
      spinClockwise(hardTurnSpeed);
    } else {
      // Default recovery action if no last direction is known
      spinClockwise(hardTurnSpeed);
    }
  }
}

// Motor Control Functions using SparkFun TB6612 Library
void moveForward(int speed) {
  motorA.drive(speed);
  motorB.drive(speed);
}

void turnLeft(int speed) {
  motorA.drive(speed / 2); // Reduce speed for smoother turn
  motorB.drive(speed);
}

void turnRight(int speed) {
  motorA.drive(speed);
  motorB.drive(speed / 2); // Reduce speed for smoother turn
}

void spinAntiClockwise(int speed) {
  motorA.drive(-speed);
  motorB.drive(speed);
}

void spinClockwise(int speed) {
  motorA.drive(speed);
  motorB.drive(-speed);
}
