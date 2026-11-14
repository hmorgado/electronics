
//LED on GPIO2


void setup() {
  // Set LED as output
  pinMode(4, OUTPUT);
  pinMode(2, OUTPUT);

  // Serial Monitor setup
  Serial.begin(115200);
  digitalWrite(4, LOW);
  digitalWrite(2, LOW);
}

void loop() {
  
}
