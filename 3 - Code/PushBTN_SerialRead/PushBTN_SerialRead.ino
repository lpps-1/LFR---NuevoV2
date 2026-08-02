#define BTN_MOST_LEFT  24
#define BTN_LEFT       25
#define BTN_RIGHT      26
#define BTN_MOST_RIGHT 27

void setup() {
  Serial.begin(9600);

  pinMode(BTN_MOST_LEFT, INPUT_PULLUP);
  pinMode(BTN_LEFT, INPUT_PULLUP);
  pinMode(BTN_RIGHT, INPUT_PULLUP);
  pinMode(BTN_MOST_RIGHT, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(BTN_MOST_LEFT) == LOW) {
    Serial.println("Most Left Button Pressed");
    delay(200);
  }

  if (digitalRead(BTN_LEFT) == LOW) {
    Serial.println("Left Button Pressed");
    delay(200);
  }

  if (digitalRead(BTN_RIGHT) == LOW) {
    Serial.println("Right Button Pressed");
    delay(200);
  }

  if (digitalRead(BTN_MOST_RIGHT) == LOW) {
    Serial.println("Most Right Button Pressed");
    delay(200);
  }
}