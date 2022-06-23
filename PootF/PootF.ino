/*
  Walking Arduino Robot
  A simple project to use 4 micro servo motors attached to arduino as a walking robot. 
  Servo signals are connected to pins 9-12
  created   Aug 2017
  by CheapskateProjects
  ---------------------------
  The MIT License (MIT)
  Copyright (c) 2017 CheapskateProjects
  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
  The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <Servo.h>

Servo servo4; // front left 
Servo servo3; //rear left
Servo servo2; // front right
Servo servo1; // rear right

int middle = 90;
int endPoint = 80;
int stepDelay = 200;
int rotationDelay = 5;

void setup()
{
  servo1.attach(8); 
  servo2.attach(9);
  servo3.attach(10);
  servo4.attach(11);
}

void loop() {
  for (int pos = 0; pos <= endPoint; pos += 1){
    servo3.write((middle + endPoint) - pos);
    servo1.write((middle - endPoint) + pos);
    servo4.write(middle - pos);
    servo2.write(middle + pos);
    delay(rotationDelay);
  }
  delay(stepDelay);
  for (int pos = 0; pos <= endPoint; pos += 1){
    servo4.write((middle - endPoint) + pos);
    servo2.write((middle + endPoint) - pos);
    servo3.write(middle + pos);
    servo1.write(middle - pos);
    delay(rotationDelay);
  }
  delay(stepDelay);
}
  
