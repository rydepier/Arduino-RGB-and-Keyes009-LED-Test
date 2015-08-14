/***********************************************************
RGB LED Test
This sketch checks a RGB LED to ensure that PWM can be used
to produce a complete range of colours
For best colour mixing results use a diffuser
by Chris Rouse Aug 2015
************************************************************/

int gndPin = 2; // the RGB LED common connection
int redLed = 3; // the Red LED
int greenLed = 4; // the green LED
int blueLed = 5; // the blue LED
int brightness = 0; // how bright the LED is
int fadeAmount = 5; // how many points to fade the LED by
//
// set either of these to false to disable the effect
boolean rainbow = true; // enable the rainbow display
boolean fader = true; // enable the fade display
//

void setup() {
// declare pin 2 and 3 to be an output:
  pinMode(gndPin, OUTPUT);
  digitalWrite(gndPin, LOW);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
}

void loop(){
  if (rainbow){
  // Rainbow
    for(int r=0; r<3; r++){
      analogWrite(redLed, 255); // Red
      delay(2000);
      analogWrite(greenLed, 255); // Yellow
      delay(2000);
      analogWrite(redLed, 0); // Green
      delay(2000);
      analogWrite(blueLed, 128); //Blue/Green
      delay(2000);
      analogWrite(blueLed, 255); //Blue/Green
      analogWrite(greenLed, 0); //Blue
      delay(2000);
      analogWrite(redLed, 255); // Violet
      delay(2000);
      analogWrite(redLed, 0); // LEDs all OFF
      analogWrite(blueLed, 0);
    }
  }

// the fader effect
  if(fader){
    brightness = 0;
    fadeAmount = 5;
    redLedLoop();
    analogWrite(redLed, 0);
    //
    brightness = 0;
    fadeAmount = 5;
    greenLedLoop();
    //
    analogWrite(greenLed, 0);
    //
    brightness = 0;
    fadeAmount = 5;
    blueLedLoop();
    analogWrite(blueLed, 0);
  }
}

// the fade routines
//
void redLedLoop() {
  for(int i=0; i<255; i++){
    analogWrite(redLed, brightness);
    // change the brightness for next time through the loop:
    brightness = brightness + fadeAmount;
    // reverse the direction of the fading at the ends of the fade:
    if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ;
  } 
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
  }
}
//
void greenLedLoop(){
  //
  for(int i=0; i<255; i++){
    analogWrite(greenLed, brightness);
    // change the brightness for next time through the loop:
    brightness = brightness + fadeAmount;
    // reverse the direction of the fading at the ends of the fade:
    if (brightness == 0 || brightness == 255) {
      fadeAmount = -fadeAmount ;
    }
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
  }
}
//
void blueLedLoop(){
  for(int i=0; i<255; i++){
    analogWrite(blueLed, brightness);
    // change the brightness for next time through the loop:
    brightness = brightness + fadeAmount;
    // reverse the direction of the fading at the ends of the fade:
    if (brightness == 0 || brightness == 255) {
      fadeAmount = -fadeAmount ;
    }
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }
}
