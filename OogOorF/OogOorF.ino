#include "LedControl.h"
#include <Servo.h>
/*
  DIN connects to pin 12
  CLK connects to pin 11
  CS connects to pin 10
*/
LedControl lc = LedControl(10, 9, 8, 1); // create a new LedControl object

Servo oorL;
Servo oorR;

//distSensor
const int echoPinL = 6;
const int trigPinL = 7;
int links = 0;

const int echoPinR = 4;
const int trigPinR = 5;
int rechts = 0;

void setup() {
  lc.shutdown(0, false); // Turn matrix on, no power saving
  lc.setIntensity(0, 8); // Set brightness to a medium value
  lc.clearDisplay(0); // Clear the display

  oorL.attach(11);
  oorR.attach(12); 

  //distSensor
  pinMode(echoPinL, INPUT);
  pinMode(trigPinL, OUTPUT);
  pinMode(echoPinR, INPUT);
  pinMode(trigPinR, OUTPUT);
  Serial.begin (9600);
}

void loop() {

 distSensorLinks();
 distSensorRechts();
  if (links == 1) {
    lookleft();
    oorL.write(40); 
    oorR.write(40);
  }else if (rechts == 1){
    lookright();
     oorL.write(120); 
    oorR.write(120);
  }else{
    eyesopen();
    closeeyes();
    oorL.write(75); 
    oorR.write(85);
    }
}

//
//void oorL() {
//  for(pos = 0; pos < 80; pos += 1){ // Loop, pos is added to (from 0 to 160)
//  myServo.write(pos); // Turn the servo to the position in pos
//  delay(15); // Wait 15ms
//   }
//  for(pos = 80; pos >= 1; pos -= 1){// Loop, pos is deducted from (from 160 to 1)
//  myServo.write(pos); // Turn the servo to the position in pos
//  delay(15); // Wait 15ms
// }
//}

void eyesopen() {                    //  The function to get the eyes to open (draws frame by frame)

  // eyes open
  lc.setRow(0, 0, B00111100);
  lc.setRow(0, 1, B01000010);
  lc.setRow(0, 2, B10000001);
  lc.setRow(0, 3, B10011001);
  lc.setRow(0, 4, B10011001);
  lc.setRow(0, 5, B10000001);
  lc.setRow(0, 6, B01000010);
  lc.setRow(0, 7, B00111100);
  lc.setRow(1, 0, B00111100);
  lc.setRow(1, 1, B01000010);
  lc.setRow(1, 2, B10000001);
  lc.setRow(1, 3, B10011001);
  lc.setRow(1, 4, B10011001);
  lc.setRow(1, 5, B10000001);
  lc.setRow(1, 6, B10000001);
  lc.setRow(1, 7, B00111100);
  delay(2000);

  //OREN bewegen zelf
}

void closeeyes() {                    //  The function to get the eyes to close (draws frame by frame)
  lc.setRow(0, 0, B00011000);
  lc.setRow(0, 1, B00011000);
  lc.setRow(0, 2, B00011000);
  lc.setRow(0, 3, B00011000);
  lc.setRow(0, 4, B00011000);
  lc.setRow(0, 5, B00011000);
  lc.setRow(0, 6, B00011000);
  lc.setRow(0, 7, B00011000);
  lc.setRow(1, 0, B00011000);
  lc.setRow(1, 1, B00011000);
  lc.setRow(1, 2, B00011000);
  lc.setRow(1, 3, B00011000);
  lc.setRow(1, 4, B00011000);
  lc.setRow(1, 5, B00011000);
  lc.setRow(1, 6, B00011000);
  lc.setRow(1, 7, B00011000);
  delay(100);
}


void lookright() {   //  The function to get the eyes to look right (draws frame by frame)
  //slightright
  lc.setRow(0, 0, B00111100);
  lc.setRow(0, 1, B01000010);
  lc.setRow(0, 2, B10000001);
  lc.setRow(0, 3, B10000001);
  lc.setRow(0, 4, B10011001);
  lc.setRow(0, 5, B10011001);
  lc.setRow(0, 6, B01000010);
  lc.setRow(0, 7, B00111100);
  lc.setRow(1, 0, B00111100);
  lc.setRow(1, 1, B01000010);
  lc.setRow(1, 2, B10000001);
  lc.setRow(1, 3, B10000001);
  lc.setRow(1, 4, B10011001);
  lc.setRow(1, 5, B10011001);
  lc.setRow(1, 6, B01000010);
  lc.setRow(1, 7, B00111100);
  delay(150);
  //eyesright
  lc.setRow(0, 0, B00111100);
  lc.setRow(0, 1, B01000010);
  lc.setRow(0, 2, B10000001);
  lc.setRow(0, 3, B10000001);
  lc.setRow(0, 4, B10000001);
  lc.setRow(0, 5, B10011001);
  lc.setRow(0, 6, B01011010);
  lc.setRow(0, 7, B00111100);
  lc.setRow(1, 0, B00111100);
  lc.setRow(1, 1, B01000010);
  lc.setRow(1, 2, B10000001);
  lc.setRow(1, 3, B10000001);
  lc.setRow(1, 4, B10000001);
  lc.setRow(1, 5, B10011001);
  lc.setRow(1, 6, B01011010);
  lc.setRow(1, 7, B00111100);
  delay(150);

  //realright
  lc.setRow(0, 0, B00000000);
  lc.setRow(0, 1, B01111110);
  lc.setRow(0, 2, B10000001);
  lc.setRow(0, 3, B10000001);
  lc.setRow(0, 4, B10000001);
  lc.setRow(0, 5, B10000001);
  lc.setRow(0, 6, B01011010);
  lc.setRow(0, 7, B00111100);
  lc.setRow(1, 0, B00000000);
  lc.setRow(1, 1, B01111110);
  lc.setRow(1, 2, B10000001);
  lc.setRow(1, 3, B10000001);
  lc.setRow(1, 4, B10000001);
  lc.setRow(1, 5, B10000001);
  lc.setRow(1, 6, B01011010);
  lc.setRow(1, 7, B00111100);
  delay(600);

  //right
  lc.setRow(0, 0, B00111100);
  lc.setRow(0, 1, B01000010);
  lc.setRow(0, 2, B10000001);
  lc.setRow(0, 3, B10000001);
  lc.setRow(0, 4, B10000001);
  lc.setRow(0, 5, B10011001);
  lc.setRow(0, 6, B01011010);
  lc.setRow(0, 7, B00111100);
  lc.setRow(1, 0, B00111100);
  lc.setRow(1, 1, B01000010);
  lc.setRow(1, 2, B10000001);
  lc.setRow(1, 3, B10000001);
  lc.setRow(1, 4, B10000001);
  lc.setRow(1, 5, B10011001);
  lc.setRow(1, 6, B01011010);
  lc.setRow(1, 7, B00111100);
  delay(150);
}

void lookleft() {                    //  The function to get the eyes to look left (draws frame by frame)
  //slightleft
  lc.setRow(0, 0, B00111100);
  lc.setRow(0, 1, B01000010);
  lc.setRow(0, 2, B10011001);
  lc.setRow(0, 3, B10011001);
  lc.setRow(0, 4, B10000001);
  lc.setRow(0, 5, B10000001);
  lc.setRow(0, 6, B01000010);
  lc.setRow(0, 7, B00111100);
  lc.setRow(1, 0, B00111100);
  lc.setRow(1, 1, B01000010);
  lc.setRow(1, 2, B10011001);
  lc.setRow(1, 3, B10011001);
  lc.setRow(1, 4, B10000001);
  lc.setRow(1, 5, B10000001);
  lc.setRow(1, 6, B01000010);
  lc.setRow(1, 7, B00111100);
  delay(150);

  //left
  lc.setRow(0, 0, B00111100);
  lc.setRow(0, 1, B01011010);
  lc.setRow(0, 2, B10011001);
  lc.setRow(0, 3, B10000001);
  lc.setRow(0, 4, B10000001);
  lc.setRow(0, 5, B10000001);
  lc.setRow(0, 6, B01000010);
  lc.setRow(0, 7, B00111100);
  lc.setRow(1, 0, B00111100);
  lc.setRow(1, 1, B01011010);
  lc.setRow(1, 2, B10011001);
  lc.setRow(1, 3, B10000001);
  lc.setRow(1, 4, B10000001);
  lc.setRow(1, 5, B10000001);
  lc.setRow(1, 6, B01000010);
  lc.setRow(1, 7, B00111100);
  delay(150);

  //realleft
  lc.setRow(0, 0, B00111100);
  lc.setRow(0, 1, B01011010);
  lc.setRow(0, 2, B10000001);
  lc.setRow(0, 3, B10000001);
  lc.setRow(0, 4, B10000001);
  lc.setRow(0, 5, B01000010);
  lc.setRow(0, 6, B00111100);
  lc.setRow(0, 7, B00000000);
  lc.setRow(1, 0, B00111100);
  lc.setRow(1, 1, B01011010);
  lc.setRow(1, 2, B10000001);
  lc.setRow(1, 3, B10000001);
  lc.setRow(1, 4, B10000001);
  lc.setRow(1, 5, B01000010);
  lc.setRow(1, 6, B00111100);
  lc.setRow(1, 7, B00000000);
  delay(600);

  //left
  lc.setRow(0, 0, B00111100);
  lc.setRow(0, 1, B01011010);
  lc.setRow(0, 2, B10011001);
  lc.setRow(0, 3, B10000001);
  lc.setRow(0, 4, B10000001);
  lc.setRow(0, 5, B10000001);
  lc.setRow(0, 6, B01000010);
  lc.setRow(0, 7, B00111100);
  lc.setRow(1, 0, B00111100);
  lc.setRow(1, 1, B01011010);
  lc.setRow(1, 2, B10011001);
  lc.setRow(1, 3, B10000001);
  lc.setRow(1, 4, B10000001);
  lc.setRow(1, 5, B10000001);
  lc.setRow(1, 6, B01000010);
  lc.setRow(1, 7, B00111100);
  delay(150);
}



void distSensorLinks() {
    // send a pulse
  digitalWrite(trigPinL, LOW);
  //delayMicroseconds(2);
  digitalWrite(trigPinL, HIGH);
  //delayMicroseconds(5);
  digitalWrite(trigPinL, LOW);
  // wait for the echo
  long duration = pulseIn(echoPinL, HIGH);
  // convert the time into a distance, the speed of sound is 29 microseconds per
  // centimeter, the pulse traveled forth and back, so we divided the distance
  // by 2

  int cm = duration / 29 / 2;

    if (cm < 30) {
    links = 1;
  }
  else{
    links = 0;
  }
 // Serial.println(cm);
}


void distSensorRechts(){
  // send a pulse
  digitalWrite(trigPinR, LOW);
  //delayMicroseconds(2);
  digitalWrite(trigPinR, HIGH);
  //delayMicroseconds(5);
  digitalWrite(trigPinR, LOW);
  // wait for the echo
  long duration = pulseIn(echoPinR, HIGH);
  // convert the time into a distance, the speed of sound is 29 microseconds per
  // centimeter, the pulse traveled forth and back, so we divided the distance
  // by 2

  int cmR = duration / 29 / 2;

  if (cmR < 30) {
    rechts = 1;
  }
  else{
    rechts = 0;
  }
  Serial.println(cmR);
}
