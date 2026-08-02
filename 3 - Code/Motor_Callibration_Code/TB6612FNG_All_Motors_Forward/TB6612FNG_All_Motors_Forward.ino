 // TB6612FNG Motor Driver with Arduino Nano
// Motors move forward at full speed

// Motor A (Left Motor)
int pwmA = 5;  // PWM Speed Control
int in1A = 8;  // Direction
int in2A = 7;  // Direction

// Motor B (Right Motor)
int pwmB = 11; // PWM Speed Control
int in1B = 9;  // Direction
int in2B = 10; // Direction

// Standby Pin
int standby = 12; 

void setup() {
  // Set all motor control pins as outputs
  pinMode(pwmA, OUTPUT);
  pinMode(pwmB, OUTPUT);
  pinMode(in1A, OUTPUT);
  pinMode(in2A, OUTPUT);
  pinMode(in1B, OUTPUT);
  pinMode(in2B, OUTPUT);
  pinMode(standby, OUTPUT);

  // Enable the motor driver
  digitalWrite(standby, HIGH);
}

void loop() {
  // Set Motor A forward
  digitalWrite(in1A, HIGH);
  digitalWrite(in2A, LOW);

  // Set Motor B forward
  digitalWrite(in1B, HIGH);
  digitalWrite(in2B, LOW);
  
  // Set motor speeds to maximum (255)
  analogWrite(pwmA, 155);
  analogWrite(pwmB, 155);
}
