#ifndef SDHANDLER_H
#define SDHANDLER_H

#include <SPI.h>
#include <SD.h>

class SDhandler{
    

    public:
        SDhandler(uint SD_PINin){
            SD_PIN = SD_PINin;
        }

        
        void begin();
        void write(uint sensNr, float temp);


    
    private:
        File myFile;
        uint SD_PIN;


};





#endif