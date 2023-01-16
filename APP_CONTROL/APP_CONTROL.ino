const int IN_1= D1;
const int IN_2= D2;
const int IN_3= D3;
const int IN_4= D4;
const int IN_5= D5;
const int IN_6= D6;
const int IN_7= D7;
const int IN_8= D8;

#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

String command;             //String to store app command state.
//int speedCar = 800;         // 400 - 1023.
//int speed_Coeff = 3;

const char* ssid = "CAR";
ESP8266WebServer server(80);

void setup() {
  
 pinMode(IN_1, OUTPUT);
 pinMode(IN_2, OUTPUT);
 pinMode(IN_3, OUTPUT);
 pinMode(IN_4, OUTPUT); 
 pinMode(IN_5, OUTPUT);
 pinMode(IN_6, OUTPUT);
 pinMode(IN_7, OUTPUT);
 pinMode(IN_8, OUTPUT); 
  Serial.begin(115200);
  
// Connecting WiFi

  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
 
 // Starting WEB-server 
     server.on ( "/", HTTP_handleRoot );
     server.onNotFound ( HTTP_handleRoot );
     server.begin();   
}

void goAhead(){ 

      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);

      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
      digitalWrite(IN_5, LOW);
      digitalWrite(IN_6, HIGH);

      digitalWrite(IN_7, LOW);
      digitalWrite(IN_8, HIGH);
  }

void goBack(){ 

      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);

      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
      digitalWrite(IN_5, HIGH);
      digitalWrite(IN_6, LOW);

      digitalWrite(IN_7, HIGH);
      digitalWrite(IN_8, LOW);
  }

void goRight(){ 

      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);

      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
      digitalWrite(IN_5, HIGH);
      digitalWrite(IN_6, LOW);

      digitalWrite(IN_7, LOW);
      digitalWrite(IN_8, HIGH);
  }

void goLeft(){
      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);

      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
      digitalWrite(IN_5, LOW);
      digitalWrite(IN_6, HIGH);

      digitalWrite(IN_7, HIGH);
      digitalWrite(IN_8, LOW);
  }

void goAheadRight(){
      
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);
 
      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
   }

void goAheadLeft(){
      
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);

      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
  }

void goBackRight(){ 

      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);

      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
  }

void goBackLeft(){ 

      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);

      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
  }

void stopRobot(){  

      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, LOW);

      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, LOW);
      digitalWrite(IN_5, LOW);
      digitalWrite(IN_6, LOW);

      digitalWrite(IN_7, LOW);
      digitalWrite(IN_8, LOW);
 }

void loop() {
    server.handleClient();
    
      command = server.arg("State");
      if (command == "F") goAhead();
      else if (command == "B") goBack();
      else if (command == "L") goLeft();
      else if (command == "R") goRight();
      else if (command == "I") goAheadRight();
      else if (command == "G") goAheadLeft();
      else if (command == "J") goBackRight();
      else if (command == "H") goBackLeft();
      else if (command == "0"); //speedCar = 400;
      else if (command == "1"); //speedCar = 470;
      else if (command == "2"); //speedCar = 540;
      else if (command == "3"); //speedCar = 610;
      else if (command == "4"); //speedCar = 680;
      else if (command == "5"); //speedCar = 750;
      else if (command == "6"); //speedCar = 820;
      else if (command == "7"); //speedCar = 890;
      else if (command == "8"); //speedCar = 960;
      else if (command == "9"); //speedCar = 1023;
      else if (command == "S") stopRobot();
}

void HTTP_handleRoot(void) {

if( server.hasArg("State") ){
       Serial.println(server.arg("State"));
  }
  server.send ( 200, "text/html", "" );
  delay(1);
}
