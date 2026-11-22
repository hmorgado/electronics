
// Just one wire coming out of PIN D4.
// Don't connect it back to ground!

int RED_LED = 2;
int GREEN_CABLE_INPUT = T0;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("ESP32 Touch test.");
  pinMode(RED_LED, OUTPUT);
  digitalWrite(RED_LED, LOW);
}

void loop() {
  int read_value = touchRead(GREEN_CABLE_INPUT); // green exposed cable
  bool off = read_value >= 1200;
  bool on = read_value <= 300;
  Serial.println(read_value); // D4

  if (on) {
    digitalWrite(RED_LED, HIGH);
  } else {
    digitalWrite(RED_LED, LOW);
  }

  delay(1000);
}
