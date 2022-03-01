#include <AddressList.h>

void AddressList::setAddress(int position,uint8_t address[]){
    for (int i = 0; i < 8; i++){
        addresslist[position][i] = address[i];
    }
}

void AddressList::getAddress(int position, uint8_t address[]){
    uint8_t tempaddress[8];
    for (int i = 0; i < 8; i++){
        address[i] = addresslist[position][i];
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