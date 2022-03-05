#include <SDhandler.h>

void SDhandler::begin(){
  Serial.println("SD Begin");
    if (!SD.begin(SD_PIN)) {
    Serial.println("initialization failed!");
  }
  else{
    Serial.println("initialization Done!");
    myFile = SD.open("/LOG.txt", FILE_WRITE);
  }
}

void SDhandler::write(uint sensNr, float temp, char time[]){
  if (myFile){
    myFile.print(time);
    myFile.print(" ");
    myFile.print("Sensor Nr: ");
    myFile.print(sensNr);
    myFile.print(" Temperatur: ");
    myFile.println(temp);

    myFile.flush();
  }

}
