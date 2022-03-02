#ifndef SDHANDLER_H
#define SDHANDLER_H

#include <SPI.h>
#include <SD.h>

class SDhandler{
    public:
        void begin();

    
    private:
        File myFile;


};





#endif