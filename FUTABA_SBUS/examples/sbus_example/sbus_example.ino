#include <FUTABA_SBUS.h>
#include <Streaming.h>


FUTABA_SBUS sBus;

const int pwmPins[] = {3, 5, 6, 9};  // Array for PWM pins

void setup(){
  sBus.begin();
  for (int i = 0; i < 4; i++) {
    pinMode(pwmPins[i], OUTPUT);  // Set each pin in pwmPins array as output
  }
  //Serial.begin(115200);
}

void loop(){
  sBus.FeedLine();
  if (sBus.toChannels == 1){
    sBus.UpdateServos();
    sBus.UpdateChannels();
    sBus.toChannels = 0;
    for (int i = 0; i < 4; i++) {
      pwmValues[i] = sBus.channels[i] / 4;
    }
    Serial<<sBus.channels[0]<<","<<sBus.channels[1]<<","<<sBus.channels[2]<<"\r\n";
  }
}
