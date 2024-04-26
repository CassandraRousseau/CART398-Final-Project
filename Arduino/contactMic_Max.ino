#define SAMPLES 2
int currSample = 0;
int prevSample = 0;

unsigned long previousMillis = 0;
 unsigned long currentMillis = 0;
// constants won't change:
const long interval = 200;  //  intervals

void setup() {
  Serial.begin(57600);
  currentMillis = millis(); // capture internal timer
}


int getSamples() {
  int _t = 0;
  for (int i = 0; i < SAMPLES; i++) {
    _t = +analogRead(i);
  }
  return (_t / SAMPLES);
}


void loop() {


  

  // check to see if it's time to sample
  // the interval at which you want to blink the LED.
  if (currentMillis - previousMillis >= interval) {
    currSample = getSamples();
    // save the last time
    
    if (currSample != prevSample) {
      // Serial.println(currSample);
      Serial.println(currSample / 4);


      prevSample = currSample;
    }

     previousMillis = currentMillis;
  }
  // Serial.println(analogRead(A0));
  currentMillis = millis();
}
