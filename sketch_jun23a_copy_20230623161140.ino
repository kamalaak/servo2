
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
//---------------------------------- ------Include the Servo Library
#include <Servo.h>

#include "Pageindex.h"; //--> Include the contents of the User Interface Web page, stored in the same folder as the .ino file

#define ServoPort D1   //--> Defining Servo Port
#define ServoPort2 D2
//----------------------------------------Make a wifi name and password as access point
const char* ssid = "NodeMCU_ESP8266";
const char* password = "goodluck";
//----------------------------------------

Servo myservo;  //--> create servo object to control a servo
Servo myservo2;  // create servo object to control the second servo


ESP8266WebServer server(80);  //--> Server on port 80

//----------------------------------------This routine is executed when you open NodeMCU ESP8266 IP Address in browser
void handleRoot() {
 String s = String(MAIN_page); //Read HTML contents
 server.send(200, "text/html", s); //Send web page
}
//----------------------------------------

//----------------------------------------Procedure for handling servo control
void handleServo(){
  String servoNumberStr = server.arg("servoNumber");
  int servoNumber = servoNumberStr.toInt();
  
  String POS = server.arg("servoPOS");
  int pos = POS.toInt();
  
  if (servoNumber == 1) {
    myservo.write(pos);   // Move the first servo motor according to the POS value
  } else if (servoNumber == 2) {
    myservo2.write(pos);  // Move the second servo motor according to the POS value
  }
  
  delay(15);
  Serial.print("Servo ");
  Serial.print(servoNumber);
  Serial.print(" Angle:");
  Serial.println(pos);
  
  server.send(200, "text/plain", "");
}
//----------------------------------------
//----------------------------------------Setup----------------------------------------
void setup() {
  Serial.begin(115200);
  delay(500);

  myservo.attach(ServoPort); //--> attaches the servo on D1 to the servo object
  myservo2.attach(ServoPort2);
  WiFi.softAP(ssid, password);  //--> Start Making ESP8266 NodeMCU as an access point

  IPAddress apip = WiFi.softAPIP(); //--> Get the IP server
  Serial.print("Connect your wifi laptop/mobile phone to this NodeMCU Access Point : ");
  Serial.println(ssid);
  Serial.print("Visit this IP : ");
  Serial.print(apip); //--> Prints the IP address of the server to be visited
  Serial.println(" in your browser.");
  //----------------------------------------

  //----------------------------------------Initialize Webserver
  server.on("/",handleRoot);  //--> Routine to handle at root location. This is to display web page.
  server.on("/setPOS",handleServo); //--> Sets servo position from Web request
  server.begin();  
  Serial.println("HTTP server started");
}
//------------------------------------------------------------------------------------
//----------------------------------------Loop----------------------------------------
void loop() {
 server.handleClient();
}
//------------------------------------------------------------------------------------
