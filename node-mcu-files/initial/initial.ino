#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Enter the required details inside the double quaotes
#define FIREBASE_HOST "intipark.firebaseio.com"
#define WIFI_SSID "Ghost 2.0"
#define WIFI_PASSWORD "10071998"

void setup() {
  Serial.begin(9600);

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST);
}

int n = 0;
void loop() {
  if(n==0)
  n = 1;
  else
  n = 0;

// Reading from Ultrasonic Sensor 1
  Firebase.setFloat("sense1", n);
//  Reading from Ultrasonic Sensor 2
  Firebase.setFloat("sense2", abs(1-n));
  delay(1000);
}
