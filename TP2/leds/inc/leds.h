#ifndef LEDS_H
#define LEDS_H   

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

bool ledsInit( uint16_t * puertoVirtual);
void ledsTurnOnSingle(int led);
void ledsTurnOffSingle(int led);
void ledsTurnOnAll(void);
void ledsTurnOffAll(void);


#endif