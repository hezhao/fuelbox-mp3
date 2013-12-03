/* TODO
 *
 * 
 * digikey: Web ID 49336054, Access ID 47942	   
 * Reed switch (digikey)
 * CUI inc speaker (digikey)
 * 3.7v LiPo x2 (all-battery.com)
 * IR switch pair
 * arduino sleep mode
 */

/*
 * Push button     http://arduino.cc/en/Tutorial/ButtonStateChange
 * Capitive Sense  http://playground.arduino.cc/Main/CapacitiveSensor
 * Photo Resistor  http://playground.arduino.cc/Learning/PhotoResistor
 */

#include <CapacitiveSensor.h>

const int batNegPin  = 2;
const int switchPin = 4;
const int lightPin  = A3;

const int thresholdCap   = 100;
const int thresholdLight = 200;
const int musicDuration  = 2000;

// send pin = 6, sensor pin = 9
CapacitiveSensor capSensor = CapacitiveSensor(6,9); 
bool shouldPlay     = false;
bool lastShouldPlay = false;

void setup()                    
{
  pinMode(batNegPin, OUTPUT);
  pinMode(switchPin, INPUT);
  pinMode(13, OUTPUT);
  digitalWrite(batNegPin, HIGH);
  Serial.begin(9600);
}

void loop()                    
{
  ////////////////// 1. Switch //////////////////
  int switchVal = digitalRead(switchPin);

  ////////////////// 2. Capacitive Sensor //////////////////
//  int capVal = capSensor.capacitiveSensor(10);
//
//  Serial.print("touch:\t");
//  Serial.println(capVal);

  ////////////////// 3. Light Sensor //////////////////
//
//  int lightVal = analogRead(lightPin);
//  Serial.print("light:\t");
//  Serial.println(lightVal); 

  ////////////////// 4. Logic ////////////////// 
//  if (switchVal == HIGH || capVal > thresholdCap || lightVal > thresholdLight) {
  if (switchVal == HIGH) {
    shouldPlay = true;
  }
  else {
    shouldPlay = false;
  }

  if (shouldPlay != lastShouldPlay) {
    if (shouldPlay == HIGH) {
      digitalWrite(batNegPin, LOW);
      digitalWrite(13, HIGH);
      Serial.println("PLAY!");
      delay(musicDuration + 800);
    }
    else {
      digitalWrite(batNegPin, HIGH);
      digitalWrite(13, LOW);
      Serial.println(".....");
    }
  }

  lastShouldPlay = shouldPlay;

  delay(10);
}


