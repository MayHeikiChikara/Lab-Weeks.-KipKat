/*Kipkat snavel*/


//============================

// ----------LIBRARIES---------

#include <CapacitiveSensor.h>
#include <TimerFreeTone.h>
#define TONE_PIN 13

// ---------CONSTANTS (won't change)--------------

CapacitiveSensor touchSwitch = CapacitiveSensor(3, 2); // the pin numbers for the capacitive sensor, 3 being the send pin and 2 being the receive pin

//speaker setup
const int speakerPin = 13; // the pin number for the speaker

const long cryInterval = 360000;  // interval at which to cry (milliseconds)
const long cryDuration = 10000; // interval for the length of a cry (milliseconds)

const long chirpInterval = 15000; // interval at which to chirp
const long chirpDuration = 2500; // interval for the length of a chirp

const long chirp2Interval = 10000; // interval at which to chirp
const long chirp2Duration = 1500; // interval for the length of a chirp

const long chirp3Interval = 19000; // interval at which to chirp
const long chirp3Duration = 1500; // interval for the length of a chirp

const long sadInterval = 35000;
const long sadDuration = 2000;

const long ringtone1Interval = 61000;
const long ringtone1Duration = 5000;

const long ringtone2Interval = 93000;
const long ringtone2Duration = 5000;

const long ringtone3Interval = 78000;
const long ringtone3Duration = 5000;

//melody setup (mr. lonely)
int song1MelodyNotes[] = { 658, 986, 830, 880, 986, 622, 986, 830, 880, 986, 554, 880, 986, 1108, 986 };
int song1MelodyDuration[] = { 500, 1000, 200, 200, 200, 500, 1000, 200, 200, 200, 500, 1000, 350, 225, 1000 };

//touchNoise setup
int touchMelodyNotes[] = {932, 0, 932, 0, 932, 1046, 0};
int touchMelodyDuration[] = {100, 10, 100, 10, 100, 500, 1000};

//chirp setup
int chirpMelodyNotes[] = {523, 1046, 523};
int chirpMelodyDuration[] = {150,300, 200};

//chirp2 setup
int chirp2MelodyNotes[] = {1480, 0, 1480, 0, 1480, 0};
int chirp2MelodyDuration[] = {75, 50, 75, 50, 75, 1000};

//chirp3 setup
int chirp3MelodyNotes[] = {988, 0, 784, 0, 988, 0, 784};
int chirp3MelodyDuration[] = {75, 50, 75, 50, 75, 50, 75};

//sad melody setup
int sadMelodyNotes[] = {311, 0, 246, 233};
int sadMelodyDuration[] = {200, 100, 150, 500};

//nokia ringtone
int ringtone1MelodyNotes[] {1318, 1174, 740, 830, 1109, 988, 587, 659, 988, 880, 554, 659, 880};
int ringtone1MelodyDuration[] {100, 100, 200, 200, 100, 100, 200, 200, 100, 100, 200, 200, 600};

//samsung ringtone
int ringtone2MelodyNotes[] {494, 622, 988, 932, 0, 740 };
int ringtone2MelodyDuration[] {100, 100, 100, 100, 100, 150};

//apple ringtone
int ringtone3MelodyNotes[] {784, 0, 932, 0, 880, 0, 784, 0, 932, 0, 932, 880, 880, 784};
int ringtone3MelodyDuration[] {200, 200, 200, 200, 200, 400, 200, 200, 200, 200, 200, 200, 200, 200};

//-----------VARIABLES (will change)--------------

// int x = 1;

boolean speakerState = false; // used to record whether the speaker is on or off

unsigned long currentMillis = 0; // stores the value of millis() in each iteration of loop()

unsigned long previousSpeakerMillis = 0; // will store the last time the speaker was updated
unsigned long previousCryMillis = 0;
unsigned long previousChirpMillis = 0;
unsigned long previousSadMillis = 0;
unsigned long previousRingtoneMillis = 0;
unsigned long previousCapSensorMillis = 0; // will store the last time the capacitive sensor was triggered


//============================================

void setup() {
  
  Serial.begin(9600);
  Serial.println("Starting snavel.ino"); // so we know what sketch is running

  // set the speaker pin as output
  pinMode(speakerPin, OUTPUT);
}


//===========================================

void loop() {
  
  currentMillis = millis(); // capture the latest value of millis()
  // this is equivalent to noting the time from a clock
  // use the same time for all actuators to keep them synchronized

  cry();
  sad();
  touchNoise();
  chirp();
  chirp2();
  chirp3();
  ringtone1();
  ringtone2();
  ringtone3();
}


//===========================================

void cry() {

  //Check to see if it's time to make a noise. If the difference between the current time and the last time 
  //you made a noise is bigger than the interval at which you want to make a noise, make a noise.
  
  if (speakerState == false) { // if the speaker is off
    
    if (currentMillis - previousCryMillis >= cryInterval) { // wait until cryInterval has elapsed
      for (int thisNote = 0; thisNote <15; thisNote++) { // play a melody (using TimerFreeTone)
        TimerFreeTone (TONE_PIN, song1MelodyNotes[thisNote], song1MelodyDuration[thisNote]);
      }
      previousCryMillis += cryInterval; // save the last time when the speaker made a noise
      speakerState = true;  
    }    
  }
  else { // if the speaker is on
    if (currentMillis - previousCryMillis >= cryDuration) { // wait until cryDuration has elapsed
      noTone(speakerPin); //stop the noise
      previousCryMillis += cryDuration; // save the time when we made the change
      speakerState = false; // then turn the speaker off
    }
  }
}

//===========================================

void touchNoise() {
  
 // touch sensor triggering a noise
 
  long val = touchSwitch.capacitiveSensor(100);
   if (val > 120) {
    Serial.println(val); // print sensor output
    for (int thisNote = 0; thisNote <7; thisNote++) { // play a melody (using TimerFreeTone)
        TimerFreeTone (TONE_PIN, touchMelodyNotes[thisNote], touchMelodyDuration[thisNote]);
      }
   } else {
   noTone(speakerPin);
   }
   Serial.println(val); // print sensor output
}

//===========================================

void chirp() {

//int chirpInterval = random(28000, 29000);

  if (speakerState == false) { // if the speaker is off
    
    if (currentMillis - previousSpeakerMillis >= chirpInterval) { // wait until cryInterval has elapsed
      for (int thisNote = 0; thisNote <3; thisNote++) { // play a melody (using TimerFreeTone)
        TimerFreeTone (TONE_PIN, chirpMelodyNotes[thisNote], chirpMelodyDuration[thisNote]);
      }
      previousSpeakerMillis += chirpInterval; // save the last time when the speaker made a noise
      speakerState = true;  
    }    
  }
  else { // if the speaker is on
    if (currentMillis - previousSpeakerMillis >= chirpDuration) { // wait until cryDuration has elapsed
      noTone(speakerPin); //stop the noise
      previousSpeakerMillis += chirpDuration; // save the time when we made the change
      speakerState = false; // then turn the speaker off
    }
  }
}

void chirp2() {

//int chirp2Interval = random(15000, 17000);

  if (speakerState == false) { // if the speaker is off
    
    if (currentMillis - previousChirpMillis >= chirp2Interval) { // wait until cryInterval has elapsed
      for (int thisNote = 0; thisNote <6; thisNote++) { // play a melody (using TimerFreeTone)
        TimerFreeTone (TONE_PIN, chirp2MelodyNotes[thisNote], chirp2MelodyDuration[thisNote]);
      }
      previousChirpMillis += chirp2Interval; // save the last time when the speaker made a noise
      speakerState = true;  
    }    
  }
  else { // if the speaker is on
    if (currentMillis - previousChirpMillis >= chirp2Duration) { // wait until cryDuration has elapsed
      noTone(speakerPin); //stop the noise
      previousChirpMillis += chirp2Duration; // save the time when we made the change
      speakerState = false; // then turn the speaker off
    }
  }

  
}

void chirp3() {

  if (speakerState == false) { // if the speaker is off
    
    if (currentMillis - previousChirpMillis >= chirp3Interval) { // wait until cryInterval has elapsed
      for (int thisNote = 0; thisNote <7; thisNote++) { // play a melody (using TimerFreeTone)
        TimerFreeTone (TONE_PIN, chirp3MelodyNotes[thisNote], chirp3MelodyDuration[thisNote]);
      }
      previousChirpMillis += chirp3Interval; // save the last time when the speaker made a noise
      speakerState = true;  
    }    
  }
  else { // if the speaker is on
    if (currentMillis - previousChirpMillis >= chirp3Duration) { // wait until cryDuration has elapsed
      noTone(speakerPin); //stop the noise
      previousChirpMillis += chirp3Duration; // save the time when we made the change
      speakerState = false; // then turn the speaker off
    }
  }

  
}


void sad() {

 // int sadInterval = random(20000, 22000);

  if (speakerState == false) { // if the speaker is off
    
    if (currentMillis - previousSadMillis >= sadInterval) { // wait until cryInterval has elapsed
      for (int thisNote = 0; thisNote <4; thisNote++) { // play a melody (using TimerFreeTone)
        TimerFreeTone (TONE_PIN, sadMelodyNotes[thisNote], sadMelodyDuration[thisNote]);
      }
      previousSadMillis += sadInterval; // save the last time when the speaker made a noise
      speakerState = true;  
    }    
  }
  else { // if the speaker is on
    if (currentMillis - previousSadMillis >= sadDuration) { // wait until cryDuration has elapsed
      noTone(speakerPin); //stop the noise
      previousSadMillis += sadDuration; // save the time when we made the change
      speakerState = false; // then turn the speaker off
    }
  }
  
  
}

void ringtone1() {

  if (speakerState == false) { // if the speaker is off
    
    if (currentMillis - previousRingtoneMillis >= ringtone1Interval) { // wait until cryInterval has elapsed
      for (int thisNote = 0; thisNote <13; thisNote++) { // play a melody (using TimerFreeTone)
        TimerFreeTone (TONE_PIN, ringtone1MelodyNotes[thisNote], ringtone1MelodyDuration[thisNote]);
      }
      previousRingtoneMillis += ringtone1Interval; // save the last time when the speaker made a noise
      speakerState = true;  
    }    
  }
  else { // if the speaker is on
    if (currentMillis - previousRingtoneMillis >= ringtone1Duration) { // wait until cryDuration has elapsed
      noTone(speakerPin); //stop the noise
      previousRingtoneMillis += ringtone1Duration; // save the time when we made the change
      speakerState = false; // then turn the speaker off
    }
  }
}

void ringtone2() {

  if (speakerState == false) { // if the speaker is off
    
    if (currentMillis - previousRingtoneMillis >= ringtone2Interval) { // wait until cryInterval has elapsed
      for (int thisNote = 0; thisNote <6; thisNote++) { // play a melody (using TimerFreeTone)
        TimerFreeTone (TONE_PIN, ringtone2MelodyNotes[thisNote], ringtone2MelodyDuration[thisNote]);
      }
      previousRingtoneMillis += ringtone2Interval; // save the last time when the speaker made a noise
      speakerState = true;  
    }    
  }
  else { // if the speaker is on
    if (currentMillis - previousRingtoneMillis >= ringtone2Duration) { // wait until cryDuration has elapsed
      noTone(speakerPin); //stop the noise
      previousRingtoneMillis += ringtone2Duration; // save the time when we made the change
      speakerState = false; // then turn the speaker off
    }
  }
}

void ringtone3() {

  if (speakerState == false) { // if the speaker is off
    
    if (currentMillis - previousRingtoneMillis >= ringtone3Interval) { // wait until cryInterval has elapsed
      for (int thisNote = 0; thisNote <14; thisNote++) { // play a melody (using TimerFreeTone)
        TimerFreeTone (TONE_PIN, ringtone3MelodyNotes[thisNote], ringtone3MelodyDuration[thisNote]);
      }
      previousRingtoneMillis += ringtone3Interval; // save the last time when the speaker made a noise
      speakerState = true;  
    }    
  }
  else { // if the speaker is on
    if (currentMillis - previousRingtoneMillis >= ringtone3Duration) { // wait until cryDuration has elapsed
      noTone(speakerPin); //stop the noise
      previousRingtoneMillis += ringtone3Duration; // save the time when we made the change
      speakerState = false; // then turn the speaker off
    }
  }
}
