#ifndef DISPLAY_H
#define DISPLAY_H

#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#include <XPT2046_Touchscreen.h>


//Pin
#define TFT_DC      26
#define TFT_CS      5
#define TFT_MOSI    23
#define TFT_SCLK    18
#define TFT_RST     27
#define TFT_MISO    19
#define T_CS        25
#define T_IRQ       0

//Display Rotation [0-3]
#define DISPLAYROTATION 1





class Display{
    public:
        void begin();
        void startScreen();
        void unPlugsensor();
        void plugInSensor(uint sensNr);
        void plugedInSensorAddress(uint sensNr, uint8_t Address);
        bool nextSensor(); 

        void touchTest();
    
    
    private:
        //ILI9341_t3 tft = ILI9341_t3(TFT_CS, TFT_DC, TFT_RST, TFT_MOSI, TFT_SCLK, TFT_MISO);
        Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);
        XPT2046_Touchscreen ts = XPT2046_Touchscreen(T_CS);

};

#endif