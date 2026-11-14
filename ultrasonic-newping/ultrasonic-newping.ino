#include "NewPing.h"
#include "SevSeg.h"

#define TRIGGER_PIN 2
#define ECHO_PIN 15
#define MAX_DISTANCE 400  //cm

SevSeg sevseg;

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

float distance, duration;
unsigned long previousMillis = 0;
const long interval = 1000;

// inches / cm 
const int buttonPin = 27;
int buttonState = 0;
bool state = false;
String unit = "in";
const int unitLED = 4;


void setup() {
  Serial.begin(115200);

  byte numDigits = 4;
  
  // Digit pins connected to ESP32 GPIOs: {D1, D2, D3, D4}
  byte digitPins[] = { 13, 33, 25, 26 };
  
  // Segment pins connected to ESP32 GPIOs: {a, b, c, d, e, f, g, dp}
  byte segmentPins[] = { 5, 18, 19, 21, 22, 23, 14, 12 };
  
  bool resistorsOnSegments = false; // 'true' if resistors are on segment pins
  byte hardwareConfig = COMMON_CATHODE; // 5641AS is Common Cathode
  bool updateWithDelays = false; // Recommended 'false'
  bool leadingZeros = true; 
  bool disableDecPoint = false;

  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, 
               resistorsOnSegments, updateWithDelays, leadingZeros, disableDecPoint);
  sevseg.setBrightness(90);

  // button
  pinMode(buttonPin, INPUT);

  pinMode(unitLED, OUTPUT);
  digitalWrite(unitLED, LOW);
  // LOW means blue -> INCHES
}

void loop() {

  buttonState = digitalRead(buttonPin);

    if (buttonState == HIGH){
      state = !state;
    }

  unsigned long currentMillis = millis();
  
  // only do anything every 1 second
  if (currentMillis - previousMillis >= interval) {

    // button BEG
    Serial.print("BUTTON BOOL ");
    Serial.println(state);
    // button END

    previousMillis = currentMillis;
    duration = sonar.ping();
    
    if (state) {
      unit = "cm";
      distance = (duration / 2) * 0.0343;
      digitalWrite(unitLED, HIGH);
    } else {
      unit = "in";
      distance = (duration / 2) * 0.013500;
      digitalWrite(unitLED, LOW);
    }
    String output = "Distance = " + String(distance) + unit + ".";
    Serial.println(output);
    
    int numberOfDecimals = 2;    
    if (distance > 99.99){
      numberOfDecimals = 1;
    }
    sevseg.setNumberF(distance, numberOfDecimals);
  }
  sevseg.refreshDisplay(); 
}
