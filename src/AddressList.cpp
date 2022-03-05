#include <AddressList.h>

void AddressList::setAddress(int sensNr,uint8_t address[]){
    for (int i = 0; i < 8; i++){
        addresslist[sensNr][i] = address[i];
    }
    //////////////////////////////////////////
    Serial.print("11Address:");
      for (uint8_t i = 0; i < 8; i++) {
        Serial.print(" ");
        Serial.print(addresslist[sensNr][i]);
      }
    Serial.println("");
    //////////////////////////////////////////
}

void AddressList::getAddress(int sensNr, uint8_t address[]){
    
    //////////////////////////////////////////
    Serial.print("22Address:");
      for (uint8_t i = 0; i < 8; i++) {
        Serial.print(" ");
        Serial.print(addresslist[sensNr][i]);
      }
    Serial.println("");
    //////////////////////////////////////////    
    
    uint8_t tempaddress[8];
    for (int i = 0; i < 8; i++){
        address[i] = addresslist[sensNr][i];
    }
    memcpy(address, tempaddress, 8);
}

bool AddressList::addressPresent(uint8_t address[]){
    int counter;
    for(int i = 0; i < 15; i++){
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