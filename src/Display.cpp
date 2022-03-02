#include <Display.h>


void Display::begin(){
    tft.begin();    Serial.println("tft Begin");
    ts.begin();     Serial.println("ts Begin");
    tft.fillScreen(ILI9341_BLACK);
    tft.setRotation(DISPLAYROTATION);
    ts.setRotation(DISPLAYROTATION);
}


void Display::startScreen(){
    tft.fillScreen(ILI9341_BLACK);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(4);
    tft.setCursor(50, 3);
    tft.println("Temperatur");
    tft.setCursor(20, 50);
    tft.println("Ueberwachung");
    tft.setTextSize(2);
    tft.setCursor(0, 222);
    tft.println("Jan Jeiziner");
    tft.setCursor(270, 222);
    tft.println("2022");
}

void Display::unPlugsensor(){
    tft.fillScreen(ILI9341_BLACK);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(4);
    tft.setCursor(0, 0);
    tft.println("Alle Sensoren ausstecken.");
}

void Display::plugInSensor(uint sensNr){
    tft.fillScreen(ILI9341_BLACK);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(4);
    tft.setCursor(0, 0);
    tft.print("Sensor ");
    tft.print(sensNr);
    tft.println(" einstecken.");
}

void Display::plugedInSensorAddress(uint sensNr, uint8_t Address){
    tft.fillScreen(ILI9341_BLACK);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(4);
    tft.setCursor(0, 0);
    tft.print("Sensor ");
    tft.println(sensNr);
    tft.println("Addresse: ");
    tft.println(Address);
}

bool Display::JaNein(){
    
}




/* WOOORRRKKSSSS!!!!
void Display::touchTest(){
    
    if (ts.touched()) {
    // do something....
  
    TS_Point p = ts.getPoint();
    Serial.print("x = ");
    Serial.print(p.x);
    Serial.print(", y = ");
    Serial.print(p.y);
    }
}
*/