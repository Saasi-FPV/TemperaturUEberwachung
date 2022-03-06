#include <AddressList.h>

bool AddressList::setAddress(int sensNr,uint8_t address[]){
    if (numberOfSensors <= maxSensors){
        for (int i = 0; i < 8; i++){
            addresslist[sensNr][i] = address[i];
        }
        Serial.println("Address to Array");
        numberOfSensors = numberOfSensors + 1;
        Serial.println(numberOfSensors);
        return 1;
    }
    else
        return 0;
}

void AddressList::getAddress(int sensNr, uint8_t address[]){ 
    uint8_t tempaddress[8];
    for (int i = 0; i < 8; i++){
        tempaddress[i] = addresslist[sensNr][i];
    }
    memcpy(address, tempaddress, 8);
}

uint AddressList::getNumberOfSensors(){
    return numberOfSensors;
}

bool AddressList::addressPresent(uint8_t address[]){
    int counter;
    Serial.println("probe");
    for(int i = 0; i < numberOfSensors; i++){
        for(int k = 0; k < 8; k++){
            if(address[k] == addresslist[i][k]){
                counter ++;
                if (counter == 8)
                    return 1;
            }
        }
        counter = 0;
    }
    return 0;
}