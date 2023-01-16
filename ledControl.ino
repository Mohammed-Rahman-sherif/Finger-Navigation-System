/* LED CONTROLLING WITH PYTHON
 * Written by Junicchi
 * https://github.com/Kebablord 
 *
 * It's a ESP management through Python example
 * It simply fetches the path from the request
 * Path is: https://example.com/this -> "/this"
 * You can command your esp through python with request paths
 * You can read the path with getPath() function
 */


#include "ESP_MICRO.h"

const int IN_1= D1;
const int IN_2= D2;
const int IN_3= D3;
const int IN_4= D4;
const int IN_5= D5;
const int IN_6= D6;
const int IN_7= D7;
const int IN_8= D8;

void setup(){
  Serial.begin(9600);
  start("Rahman","MOHAMMED"); // Wifi details connec to

  pinMode(LED_BUILTIN, OUTPUT);

  pinMode(IN_1,OUTPUT);
    pinMode(IN_2,OUTPUT);
      pinMode(IN_3,OUTPUT);
        pinMode(IN_4,OUTPUT);
  pinMode(IN_5,OUTPUT);
    pinMode(IN_6,OUTPUT);
      pinMode(IN_7,OUTPUT);
        pinMode(IN_8,OUTPUT);
}

void loop(){
  waitUntilNewReq();  //Waits until a new request from python come

  if (getPath()=="/FORWARD"){

      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);

      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
      
      digitalWrite(IN_5, LOW);
      digitalWrite(IN_6, HIGH);

      digitalWrite(IN_7, LOW);
      digitalWrite(IN_8, HIGH);
  }
  
  if (getPath()=="/BACKWARD"){

      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);

      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
      
      digitalWrite(IN_5, HIGH);
      digitalWrite(IN_6, LOW);

      digitalWrite(IN_7, HIGH);
      digitalWrite(IN_8, LOW); 
  }
  
  if (getPath()=="/RIGHT"){

      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);

      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
      
      digitalWrite(IN_5, HIGH);
      digitalWrite(IN_6, LOW);

      digitalWrite(IN_7, LOW);
      digitalWrite(IN_8, HIGH);
  }
  
  if (getPath()=="/LEFT"){
    
      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);

      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
      
      digitalWrite(IN_5, LOW);
      digitalWrite(IN_6, HIGH);

      digitalWrite(IN_7, HIGH);
      digitalWrite(IN_8, LOW);
  }
  
    if (getPath()=="/CENTER"){
          
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, LOW);

      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, LOW);
      
      digitalWrite(IN_5, LOW);
      digitalWrite(IN_6, LOW);

      digitalWrite(IN_7, LOW);
      digitalWrite(IN_8, LOW);
  }
}
