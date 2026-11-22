
# include "WiFi.h"

void setup() {
  // Serial.begin(115200);
  pinMode(2, OUTPUT);
  // Serial.println("set up done");
}

void loop() {
  // Serial.println("Starting...");

  for (int i = 0; i < 10; i++) {
    digitalWrite(2, HIGH);
    // Serial.println("i = " + i);
    delay(500);
    digitalWrite(2, LOW);
    delay(200);
  }

  Serial.println("DONE ----");
  delay(5000);
}
