#include <Arduino.h>
#include <DS18B20.h>
#include <Adafruit_I2CDevice.h>
#include <AddressList.h>
#include <Display.h>
#include <SDhandler.h>
#include <RTClib.h>


//Pins
#define ONEWIREPIN    33    //1Wire BUS
#define SD_CS          4    //SD CS Pin
#define TS_CS         25    //TouchScreen CS Pin
#define TFT_CS         5    //TFT CS Pin
#define TFT_DC        26    //TFT DC Pin
#define TFT_RST       27    //TFT RST Pin

//Konstanten
#define BAUDRATE          115200
#define MAXSENSORS            15
#define DISPLAYROTATION        1   //Display Rotation [0-3]
#define DATETIMEASSORT "DD.MM.YY-hh:mm:ss"
#define MAXSENSORS 15


//Globale Variablen
int numberOfDevices = 0;



//Objekte erstellen
DS18B20 ds(ONEWIREPIN);
AddressList dsAddress(MAXSENSORS);
Display disp(TFT_CS, TFT_DC, TFT_RST, TS_CS, DISPLAYROTATION);
SDhandler SDcard(SD_CS);
RTC_DS3231 rtc;




void setup() {
  Serial.begin(BAUDRATE);
  
  //To be save that all SPI CS are HIGH else it may get Getoiii...
  pinMode(SD_CS, OUTPUT); pinMode(TS_CS, OUTPUT); pinMode(TFT_CS, OUTPUT);
  digitalWrite(SD_CS, HIGH); digitalWrite(TS_CS, HIGH); digitalWrite(TFT_CS, HIGH);
  
  numberOfDevices = ds.getNumberOfDevices(); Serial.println(ds.getNumberOfDevices());

  disp.begin();
  SDcard.begin();
  rtc.begin();
  disp.startScreen();

  delay(1000);

  disp.unPlugsensor();
  delay(1000);
  while (!disp.JaNein("Alle Sensoren ausgesteckt?"));


  bool flag1 = 1;
  uint count = 0;
  do{
    bool flag2 = 1;
    uint errorcount = 0;
    bool maxSensorlocal = 0;   
    disp.plugInSensor(count+1);
    delay(2000);
    while (!disp.JaNein("Sensor eingesteckt?"));
    

    while (flag2){
      ds.selectNext();
      uint8_t address[8];
      ds.getAddress(address);
      if (!dsAddress.addressPresent(address)){
        if (!dsAddress.setAddress(count, address)){
          maxSensorlocal = 1;
          Serial.println("maxSensoren erreicht");
        }
        flag2 = 0;
      }
      else{
        errorcount++;
        if (errorcount > MAXSENSORS * 3){
          if (disp.JaNein("Sensor nicht gefunden. Richtig eingesteckt?")){
          errorcount = 0;
          }
          else{
            flag2 = 0;
          }
        }
      }
    }
    if (maxSensorlocal){   
      break;
    }
    
    if(!disp.JaNein("Weitere Sensor?"))
      flag1 = 0;

    count++;
  }while(flag1);

  disp.sensorReadinComplete(dsAddress.getNumberOfSensors());

}



void loop() {

char DaTim[] = DATETIMEASSORT; //Date Time sortment
DateTime now = rtc.now();





















/*
Serial.println("Which sensor would you like to read? ");

while (Serial.available() == 0) {
}

int menuChoice = Serial.parseInt();
Serial.println(menuChoice);


uint8_t address[8];
dsAddress.getAddress(menuChoice, address);

Serial.print("Address:");
for (uint8_t i = 0; i < 8; i++) {
  Serial.print(" ");
  Serial.print(address[i]);
}
Serial.println("");
delay(500);
*/

}