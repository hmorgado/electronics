#include "SevSeg.h"
SevSeg sevseg; //Instantiate a seven segment controller object

#define MAX_NUMBER_STRINGS 12
#define MAX_STRING_SIZE 8
char testStrings[MAX_NUMBER_STRINGS][MAX_STRING_SIZE];

#define PATTERN_CHANGE_TIME 250
unsigned long timer = millis() - PATTERN_CHANGE_TIME;
byte testStringsPos = 0;

void setup() {
  Serial.begin(115200);

  byte numDigits = 4;
  
  // Digit pins connected to ESP32 GPIOs: {D1, D2, D3, D4}
  byte digitPins[] = { 13, 33, 25, 26 };

  // troubleshooting:
  // 32 seems to be not ok
  // 34 is not working (caused GPIO errors)
  // 12 worked great for the digit pin :)
                    // {a, b,  c,  d,  e,  f,  g,  dp}
  byte segmentPins[] = { 5, 18, 19, 21, 22, 23, 14, 12 };
  
  bool resistorsOnSegments = false; // 'true' if resistors are on segment pins
  byte hardwareConfig = COMMON_CATHODE; // 5641AS is Common Cathode
  bool updateWithDelays = false; // Recommended 'false'
  bool leadingZeros = true; 
  bool disableDecPoint = false; 

  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments, updateWithDelays, leadingZeros, disableDecPoint);
  sevseg.setBrightness(90);

  // Adds set of test strings with periods in various places
  strcpy(testStrings[0], "A..BC.");
  strcpy(testStrings[1], "....");
  strcpy(testStrings[2], ".   ");
  strcpy(testStrings[3], " .  ");
  strcpy(testStrings[4], "  . ");
  strcpy(testStrings[5], "   .");
  strcpy(testStrings[6], ".ABC");
  strcpy(testStrings[7], "A.BCD");
  strcpy(testStrings[8], "A.B.CD");
  strcpy(testStrings[9], "A.B.C.D");
  strcpy(testStrings[10], "A.B.C.D.");
  strcpy(testStrings[11], ". . . .");
}

void loop() {

  // Cycle to the next string every one second
  if (millis() > (timer + PATTERN_CHANGE_TIME)) {
    sevseg.setChars(testStrings[testStringsPos]);
    testStringsPos++;
    if (testStringsPos >= MAX_NUMBER_STRINGS) testStringsPos = 0;
    timer = millis();
  }

  sevseg.refreshDisplay(); // Must run repeatedly
}

/// END ///
