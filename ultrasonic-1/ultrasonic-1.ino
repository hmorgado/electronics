#define trigPin 2
#define echoPin 4

#define redLED 5
#define yellowLED 18
#define greenLED 19
#define whiteLED 21

float duration, distance;

void setup() {
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(whiteLED, OUTPUT);
}

void loop() {
  // digitalWrite(redLED, LOW);
  // digitalWrite(yellowLED, LOW);

  //write a pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // measures the response
  duration = pulseIn(echoPin, HIGH);

  // determine distance from duration
  distance = (duration / 2) * 0.0343;
  
  Serial.print("Distance = ");
  if (distance >= 400 || distance <= 2) {
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
    delay(500);
  }

  delay(500);
}
