#ifndef ADDRESSLIST_H
#define ADDRESSLIST_H

#include "Arduino.h"


class AddressList{
    public:
        void setAddress(int sensNr,uint8_t address[]);
        void getAddress(int sensNr, uint8_t address[]);
        bool addressPresent(uint8_t address[]);
    
    
    private:
        uint8_t addresslist[15][8];

};

#endif