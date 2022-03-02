#include <Arduino.h>
#include <DS18B20.h>
#include <Adafruit_I2CDevice.h>
#include <AddressList.h>
#include <Display.h>
#include <SDhandler.h>


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

//Globale Variablen
int numberOfDevices = 0;



//Objekte erstellen
DS18B20 ds(ONEWIREPIN);
AddressList dsAddress;
Display disp(TFT_CS, TFT_DC, TFT_RST, TS_CS, DISPLAYROTATION);
SDhandler SDcard(SD_CS);




void setup() {
  Serial.begin(BAUDRATE);
  
  //To be save that all SPI CS are HIGH else it may get Getoiii...
  pinMode(SD_CS, OUTPUT); pinMode(TS_CS, OUTPUT); pinMode(TFT_CS, OUTPUT);
  digitalWrite(SD_CS, HIGH); digitalWrite(TS_CS, HIGH); digitalWrite(TFT_CS, HIGH);
  
  numberOfDevices = ds.getNumberOfDevices(); Serial.println(ds.getNumberOfDevices());

  disp.begin();
  SDcard.begin();
  disp.startScreen();

  delay(5000);

  disp.unPlugsensor();
  delay(2000);
  
  
  SDcard.write(1, 24.2);
  
}

void loop() {



}