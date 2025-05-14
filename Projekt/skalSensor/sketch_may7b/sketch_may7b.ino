//setp för led panel
#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"
Adafruit_AlphaNum4 alpha4 = Adafruit_AlphaNum4();
//seter up voc sensern
#include <Wire.h>
#include "Adafruit_SGP30.h"
Adafruit_SGP30 sgp;
//förljande är snut från exempe kåd
uint32_t getAbsoluteHumidity(float temperature, float humidity) {
  // approximation formula from Sensirion SGP30 Driver Integration chapter 3.15
  const float absoluteHumidity = 216.7f * ((humidity / 100.0f) * 6.112f * exp((17.62f * temperature) / (243.12f + temperature)) / (273.15f + temperature));  // [g/m^3]
  const uint32_t absoluteHumidityScaled = static_cast<uint32_t>(1000.0f * absoluteHumidity);                                                                 // [mg/m^3]
  return absoluteHumidityScaled;
}
short counterSGP30 = 0;

uint16_t Co2;
uint16_t TvM;  // TVOC




//För aht20
#include <Adafruit_SH110X.h>
#include <Adafruit_AHTX0.h>
Adafruit_AHTX0 aht;
float temp;
float luftFuktighet;





//setter up variablerna
unsigned long nästa100ms;
unsigned long nästa1s;
unsigned long nästa10s;


//faro nivå
const int maxCo2 = 2000;
const int maxTvM = 200;

const int ledRöd = 9;
const int ledGul = 8;
const int ledGrön = 7;


/* med sett firke vi att 
axeptabelCo2 = 455;
axeptabelTvM = 100;
*/
const int axeptabelCo2 = 900;
const int axeptabelTvM = 100;

const int buttonPin = 12;
const int buzzerPin = 10;

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

  Serial.begin(9600);

  alpha4.begin(0x70);
  alpha4.writeDigitAscii(0, 'T');
  alpha4.writeDigitAscii(1, 'E');
  alpha4.writeDigitAscii(2, 'S');
  alpha4.writeDigitAscii(3, 'T');
  alpha4.writeDisplay();

  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledRöd, OUTPUT);
  pinMode(ledGul, OUTPUT);
  pinMode(ledGrön, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  //ser till att sensorn är upe
  if (!sgp.begin()) {

    while (!sgp.begin()) {
      Serial.println("VOC senor not found ");
      delay(500);
    }
  } else if (!aht.begin()) {

    while (!aht.begin()) {
      Serial.println("luft sensor not find");
      delay(500);
    }
  }
}

void loop() {
  unsigned long Tid = millis();

  if (nästa100ms < Tid) {
    nästa100ms = Tid + 100;
    var100ms();
  }
  if (nästa1s < Tid) {
    nästa1s = Tid + 1000;
    var1s();
  }
  if (nästa10s < Tid) {
    nästa10s = Tid + 10000;
    var10s();
  }

  delay(10);
}

void var100ms() {
  if (digitalRead(buttonPin) == 0) {
    alarmÄrPå = false;
  }
}
void var1s() {
  setBuzzer();
  if (alarmÄrPå) {
    buzzerLow = !buzzerLow;
  }
  Serial.print("--");
  Serial.println(sgp.TVOC);
  
}

void var10s() {

  //sgp30 cod direkt från exemplet
  counterSGP30++;
  if (counterSGP30 == 30) {
    counterSGP30 = 0;

    uint16_t TVOC_base, eCO2_base;
    if (!sgp.getIAQBaseline(&eCO2_base, &TVOC_base)) {
      Serial.println("Failed to get baseline readings");
      return;
    }
    Serial.print("****Baseline values: eCO2: 0x");
    Serial.print(eCO2_base, HEX);
    Serial.print(" & TVOC: 0x");
    Serial.println(TVOC_base, HEX);
  }
  //settre värden
  TvM = sgp.TVOC;
  Co2 = sgp.eCO2;

  //för luft fuktighet
  sensors_event_t humidity, temp;
  aht.getEvent(&humidity, &temp);


  if (Co2 > maxCo2 || TvM > maxTvM) {
    faraNivå = 2;
    alarmÄrPå = true;
    alpha4.writeDigitAscii(0, 'R');
  alpha4.writeDigitAscii(1, 'U');
  alpha4.writeDigitAscii(2, 'N');
  alpha4.writeDigitAscii(3, '!');
  alpha4.writeDisplay();
  } else if (Co2 > axeptabelCo2 || TvM > axeptabelTvM) {
    alpha4.writeDigitAscii(0, 'P');
  alpha4.writeDigitAscii(1, 'R');
  alpha4.writeDigitAscii(2, 'U');
  alpha4.writeDigitAscii(3, 'B');
  alpha4.writeDisplay();
    faraNivå = 1;
    alarmÄrPå = false;
  } else {
    alpha4.writeDigitAscii(0, 'F');
  alpha4.writeDigitAscii(1, 'I');
  alpha4.writeDigitAscii(2, 'N');
  alpha4.writeDigitAscii(3, '');
  alpha4.writeDisplay();
    faraNivå = 0;
    alarmÄrPå = false;
  }



  Serial.println(faraNivå);


  switch (faraNivå) {  //detta är för att välja rät led

    case 0:

      digitalWrite(ledRöd, 0);
      digitalWrite(ledGul, 0);
      digitalWrite(ledGrön, 1);

      break;
    case 1:

      digitalWrite(ledRöd, 0);
      digitalWrite(ledGul, 1);
      digitalWrite(ledGrön, 0);

      break;
    case 2:
      digitalWrite(ledRöd, 1);
      digitalWrite(ledGul, 0);
      digitalWrite(ledGrön, 0);
      break;

    default:

      // statements

      break;
  }
}

void setBuzzer() {
  if (faraNivå == 2 && alarmÄrPå) {
    if (buzzerLow) {
      analogWrite(buzzerPin, 127);
    } else {
      analogWrite(buzzerPin, 254);
    }
  } else {
    analogWrite(buzzerPin, 0);
  }
}