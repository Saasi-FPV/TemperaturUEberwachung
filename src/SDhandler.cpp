#include <SDhandler.h>

void SDhandler::begin(){
    if (!SD.begin(4)) {
    Serial.println("initialization failed!");
  }
  else{
    Serial.println("initialization Done!");
  }
}