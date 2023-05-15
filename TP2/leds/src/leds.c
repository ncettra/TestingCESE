#include "leds.h"

static uint16_t * PuertoVirtual;
#define INDEX_OFFSET 1
#define FIRST_BIT 1
#define LAST_BIT 16
#define ALL_LEDS_OFF 0x0000

#define ALL_LEDS_ON 0xFFFF

uint16_t IndexToMask(uint8_t led){
    return ((FIRST_BIT << (led-INDEX_OFFSET)));
}

bool CheckLimits(int led){
    return ((led>=FIRST_BIT) && (led<=LAST_BIT));
}

bool ledsInit(uint16_t * puertoVirtual){
    if(puertoVirtual == NULL){
        return false;
    }else{
        *puertoVirtual = ALL_LEDS_OFF;
        PuertoVirtual = puertoVirtual;
        return true;
    }

    
}

void ledsTurnOnSingle(int led){
    if(CheckLimits(led))
        *PuertoVirtual |= IndexToMask(led);
}

void ledsTurnOffSingle(int led){
    if(CheckLimits(led))
        *PuertoVirtual &= ~IndexToMask(led);
}

void ledsTurnOnAll(void){
    *PuertoVirtual = ALL_LEDS_ON;
}

void ledsTurnOffAll(void){

    *PuertoVirtual = ALL_LEDS_OFF;
}