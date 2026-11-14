
# include "WiFi.h"

int RED_LED = 2;
int WHITE_LED = 4;

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA); // set it to station mode
  WiFi.disconnect();
  pinMode(WHITE_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  delay(100);
  Serial.println("set up done");
}

void loop() {
  Serial.println("Starting...");

  digitalWrite(WHITE_LED, HIGH);
  int n = WiFi.scanNetworks();

  Serial.println("scan done");
  digitalWrite(WHITE_LED, LOW);

  for (int i = 0; i < n; i++) {
    digitalWrite(RED_LED, HIGH);
    Serial.println(WiFi.SSID(i));
    delay(100);
    digitalWrite(RED_LED, LOW);
    delay(100);
  }

  Serial.println(n);
  delay(5000);
}