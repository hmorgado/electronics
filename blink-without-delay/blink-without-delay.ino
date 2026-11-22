int ledState = LOW;

unsigned long previousMillis = 0;

const long interval = 1000;

void setup() {
  Serial.begin(115200);
  pinMode(2, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    if (ledState == LOW){
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
    digitalWrite(2, ledState);
  }
}
