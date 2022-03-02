#include <SDhandler.h>

void SDhandler::begin(){
  Serial.println("SD Begin");
    if (!SD.begin(SD_PIN)) {
    Serial.println("initialization failed!");
  }
  else{
    Serial.println("initialization Done!");
  }
}

void SDhandler::write(uint sensNr, float temp){
  myFile = SD.open("/LOG.txt", FILE_WRITE);
  if (myFile){
    myFile.print("Sensor Nr: ");
    myFile.print(sensNr);
    myFile.print(" Temperatur: ");
    myFile.println(temp);

    myFile.close();
  }

}
