#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Enter the required details inside the double quaotes
#define FIREBASE_HOST "ghost-1007.firebaseio.com"
#define WIFI_SSID "Ghost 2.0"
#define WIFI_PASSWORD "10071998"

const int trigP = 2;  //D4 Or GPIO-2 of nodemcu
const int echoP = 0;  //D3 Or GPIO-0 of nodemcu

long duration;
int distance;

void setup() {
  pinMode(trigP, OUTPUT);  // Sets the trigPin as an Output
  pinMode(echoP, INPUT);   // Sets the echoPin as an Input
  Serial.begin(9600);      // Open serial channel at 9600 baud rate

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

void loop() {
  // put your main code here, to run repeatedly:
  Firebase.setFloat("number", ultra(trigP, echoP));

}

int ultra(int trig, int echo) {
  
  digitalWrite(trig, LOW);   // Makes trigPin low
  delayMicroseconds(2);       // 2 micro second delay 
  
  digitalWrite(trig, HIGH);  // tigPin high
  delayMicroseconds(10);      // trigPin high for 10 micro seconds
  digitalWrite(trig, LOW);   // trigPin low
  
  duration = pulseIn(echo, HIGH);   //Read echo pin, time in microseconds
  distance= duration*0.034/2;        //Calculating actual/real distance
  
  Serial.print("Distance = ");        //Output distance on arduino serial monitor 
  Serial.println(distance);
  delay(100);                        //Pause for 3 seconds and start measuring distance again

  return distance;
  
}
