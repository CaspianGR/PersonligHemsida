
#include "Adafruit_APDS9960.h"
Adafruit_APDS9960 apds;
#include <Wire.h>
#include "Adafruit_SGP30.h"
Adafruit_SGP30 sgp;
unsigned long nästa100ms;
unsigned long nästa1s;
unsigned long nästa10s;
unsigned int co2M;
unsigned int tvM;

const int maxCo2 = 100;
const int maxTvM = 100;

const int ledRöd = 5;
const int ledGul = 6;
const int ledGrön = 9;

const int axeptabelCo2 = 50;
const int axeptabelTvM = 50;

const int buttonPin = 2;
const int buzzerPin = 3;

bool alarmÄrPå = false;
short faraNivå = 0;
/*
0 allt är ok      grön led
1 halvt problem   gul led
2 problem         röd led och buzzer
kanske inte fins 3 tystat problem  röd led med ingen buzzer


*/
bool buzzerLow = false;

void setup() {
    // put your setup code here, to run once:
    pinMode(buttonPin, INPUT_PULLUP);
    pinMode(ledRöd, OUTPUT);
    pinMode(ledGul, OUTPUT);
    pinMode(ledGrön, OUTPUT);
    pinMode(buzzerPin, OUTPUT);


    apds.enableColor(true);
    if (! sgp.begin()){
        Serial.println("Sensor not found :(");
        while (1);
    }

}

void loop() {
  unsigned long Tid = millis();

  if(nästa100ms < Tid){
  nästa100ms = Tid+100;
  var100ms();


  }
  if(nästa1s < Tid){
  nästa1s = Tid+1000;
  var1s();


  }
  if(nästa10s < Tid){
  nästa10s = Tid+10000;
  var10s();


  }
      
        
}
        
void var100ms(){
if(digitalRead(buttonPin) == 0){
  alarmÄrPå = false;
}


}
void var1s(){
  if(alarmÄrPå){
    buzzerLow = !buzzerLow;
  } 
}

void var10s(){
  co2M = sgp.eCO2;
  tvM = sgp.TVOC;
  //behöver läga till att den mäter luft fuktigheten

  if(co2M>maxCo2 && tvM > maxTvM){
    faraNivå = 2;
  }
  else if(co2M>axeptabelCo2 && tvM > axeptabelTvM){
   faraNivå = 1;
  }
  else if(co2M<axeptabelCo2 && tvM < axeptabelTvM && faraNivå > 0){
    faraNivå = 0;
  }
  switch (faraNivå) {//detta är för att välja rät led

      case 0:

        digitalWrite(ledRed, 0);
        digitalWrite(ledGul, 0);
        digitalWrite(ledGren, 1);

        break;

      case 1:

        digitalWrite(ledRed, 0);
        digitalWrite(ledGul, 1);
        digitalWrite(ledGren, 0);

        break;
      case 2
      digitalWrite(ledRed, 1);
        digitalWrite(ledGul, 0);
        digitalWrite(ledGren, 10);

      break;

      default:

        // statements

        break;

  }


}

void setBuzzer(){
  if(faraNivå == 3 && alarmÄrPå ){
    if(buzzerLow){
      analogWrite(buzzerPin, 127);
    }
    else{
      analogWrite(buzzerPin, 254);
    }
  }
}


