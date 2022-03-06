#ifndef DISPLAY_H
#define DISPLAY_H

#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#include <XPT2046_Touchscreen.h>


#define TS_MINX 449
#define TS_MINY 214
#define TS_MAXX 3946
#define TS_MAXY 3837


/*//Pin
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
*/





class Display{
    public:
        Display(uint TFT_CSin, uint TFT_DCin, uint TFT_RSTin, uint TS_CSin, uint DISPLAYROTATIONin){
            TFT_CS = TFT_CSin;
            TFT_DC = TFT_DCin;
            TFT_RST = TFT_RSTin;
            TS_CS = TS_CSin;
            DISPLAYROTATION = DISPLAYROTATIONin;
        }

        void begin();
        void startScreen();
        void unPlugsensor();
        void plugInSensor(uint sensNr);
        void plugedInSensorAddress(uint sensNr, uint8_t Address);
        bool nextSensor();
        void sensorReadinComplete(uint numberOfSensors);
        bool JaNein(String q);

        void touchTest();
    
    
    private:
        uint TFT_CS;
        uint TFT_DC;
        uint TFT_RST;
        uint TS_CS;
        uint DISPLAYROTATION;
        
        Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS = 5, TFT_DC = 26, TFT_RST = 27);
        XPT2046_Touchscreen ts = XPT2046_Touchscreen(TS_CS = 25);

};

#endif