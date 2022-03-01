
/*Test
*/



#include <Arduino.h>
#include <DS18B20.h>
#include <Adafruit_I2CDevice.h>
#include <AddressList.h>
#include <Display.h>
#include <SDhandler.h>


//Pins
#define ONEWIREPIN    33 //1Wire BUS

//Konstanten
#define BAUDRATE 115200
#define MAXSENSORS 15

//Globale Variablen
int numberOfDevices = 0;



//Objekte erstellen
DS18B20 ds(ONEWIREPIN);
AddressList dsAddress;
Display disp;
SDhandler SD;




void setup() {
  Serial.begin(BAUDRATE);
  numberOfDevices = ds.getNumberOfDevices(); Serial.println(ds.getNumberOfDevices());

  disp.begin();
  disp.startScreen();

  delay(5000);

  disp.unPlugsensor();
  delay(2000);
  
}

void loop() {

disp.touchTest();
delay(200);

}