#define BUTTON_PIN 2

#define NUM_SENSORS 5
int sensorPins[NUM_SENSORS] = {A6, A3, A2, A1, A0};

bool printing = false;
unsigned long startTime = 0;

long sensorSums[NUM_SENSORS] = {0, 0, 0, 0, 0};
long sampleCount = 0;

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP); 
}

void loop() {

  if (digitalRead(BUTTON_PIN) == LOW && !printing) {
    printing = true;
    startTime = millis();
    sampleCount = 0;
    for (int i = 0; i < NUM_SENSORS; i++) {
      sensorSums[i] = 0;
    }
    Serial.println("---- Gathering Sensor Readings (5 Seconds) ----");
  }

  if (printing) {
    if (millis() - startTime <= 5000) {

      for (int i = 0; i < NUM_SENSORS; i++) {
        sensorSums[i] += analogRead(sensorPins[i]);
      }
      sampleCount++;

      delay(100);  
    } 
    else {
      printing = false;
      Serial.println("---- Final Averages ----");
      
      for (int i = 0; i < NUM_SENSORS; i++) {
        float average = (float)sensorSums[i] / sampleCount;
        Serial.print("S");
        Serial.print(i);
        Serial.print(" Avg: ");
        Serial.print(average);
        Serial.print("\t");
      }
      Serial.println();
      Serial.println("------------------------");
    }
  }
}