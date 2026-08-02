#define BUTTON_PIN 2

#define NUM_SENSORS 5
int sensorPins[NUM_SENSORS] = {A6, A3, A2, A1, A0};

bool printing = false;
unsigned long startTime = 0;

void setup() {
  Serial.begin(9600);

  pinMode(BUTTON_PIN, INPUT_PULLUP); 
  // Button: D4 → GND
}

void loop() {

  // Start printing when button is pressed
  if (digitalRead(BUTTON_PIN) == LOW && !printing) {
    printing = true;
    startTime = millis();
    Serial.println("---- Sensor Readings START ----");
  }

  // Print for 2 seconds
  if (printing) {
    if (millis() - startTime <= 2000) {

      for (int i = 0; i < NUM_SENSORS; i++) {
        Serial.print("S");
        Serial.print(i);
        Serial.print(": ");
        Serial.print(analogRead(sensorPins[i]));
        Serial.print("\t");
      }
      Serial.println();

      delay(100);  // readable output, not serial cancer
    } 
    else {
      printing = false;
      Serial.println("---- Sensor Readings END ----");
    }
  }
}
