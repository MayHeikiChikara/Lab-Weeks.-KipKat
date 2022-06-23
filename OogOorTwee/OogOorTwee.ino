#include "LedControl.h"
/*
  DIN connects to pin 12
  CLK connects to pin 11
  CS connects to pin 10
*/
LedControl lc = LedControl(10, 9, 8, 1); // create a new LedControl object


//sensor
float sensorValue = 0; // variable for sensor value
float sensorValue2 = 0;
float sensorPin = A0; // variable for sensor pin
float sensorPin2 = A1;
int oog = 10;
int bufferArray[7];
int bufferArray2[7];

void setup() {
  // put your setup code here, to run once:
  lc.shutdown(0, false); // Turn matrix on, no power saving
  lc.setIntensity(0, 8); // Set brightness to a medium value
  lc.clearDisplay(0); // Clear the display

  //sensor
  pinMode (sensorPin, INPUT);
  pinMode (sensorPin2, INPUT);
  Serial.begin (9600);
  pinMode (oog, OUTPUT);
}

void loop() {
  eyesopen();
  closeeyes();
  //lookright();
  //lookleft();
  sensor();
  //  ifs();
}

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

void sensor() {
  sensorValue = analogRead (sensorPin); // read the value/voltage on the sensor
  sensorValue2 = analogRead (sensorPin2);
  Serial.println (sensorValue) ; // print out sensorValue to the Serial
  Serial.println (sensorValue2) ;
  // Monitor
  delay (20); // delay for 0.2 seconds
  sensorValue - (sensorValue / 47) * 255;
  sensorValue2 - (sensorValue2 / 47) * 255;
  analogWrite (oog, sensorValue);
  analogWrite (oog, sensorValue2);



  for (int i = 0; i <= 5; i++) {
    bufferArray[i + 1] = bufferArray[i];
  }

  bufferArray[0] = sensorValue - (sensorValue / 47) * 255;
}
float average (int bufferArray, int len) {
  long sum = 0L;
  for (int i = 0; i < len; i++)
    sum += bufferArray [i];
  return ((float) sum) / len;
}


for (int i = 0; i <= 5; i++) {
  bufferArray2[i + 1] = bufferArray2[i];
}

bufferArray2[0] = sensorValue2 - (sensorValue2 / 47) * 255;
}
float average (int*bufferArray2, int len) {
  long sum = 0L;
  for (int i = 0; i < len; i++)
    sum += bufferArray2 [i];
  return ((float) sum) / len;
}
