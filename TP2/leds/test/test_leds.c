/*
Lista de pruebas:

    -Al iniciar todos los leds arrancan apagados

    -Con los leds apagados, enciendo el nro 2 y verifico que su valor en memoria sea 1

    -Con el led 2 prendido, apago el led 2, verifico que su valor en memoria sea cero

    -Encender y apagar distintos leds

    -Con todos los leds apagados, los enciendo a todos juntos

    -Con todos los leds encendidos, los apago a todos juntos

    -Pruebo sobre los limites de los argumentos 
    
    -Pruebo con argumentos invalidos

    -Prueba de inicializacion erronea
*/

#include "unity.h"
#include "leds.h"
#include <stdint.h>

static uint16_t PuertoVirtual;

void setUp(){
    ledsInit(&PuertoVirtual); //aca puerto virtual deberia ser igualado a cero
}

//Al iniciar todos los leds arrancan apagados
void test_all_leds_start_off(void){

    uint16_t puertoVirtual = 0xFFFF;
    ledsInit(&puertoVirtual); //aca puerto virtual deberia ser igualado a cero
    TEST_ASSERT_EQUAL_HEX16(0x0000, puertoVirtual); //chequeo si todos los leds estan apagados
}

//Con los leds apagados, enciendo el nro 2 y verifico que su valor en memoria sea 1
void test_turn_on_single_led(void){
    
    ledsTurnOnSingle(2); //tiene que poner en 1 el bit numero 2
    TEST_ASSERT_EQUAL_HEX16(0x0002, PuertoVirtual);
}

//Con el led 2 prendido, apago el led 2, verifico que su valor en memoria sea cero
void test_turn_on_turn_off_single_led(void){
    
    ledsTurnOnSingle(2);
    ledsTurnOffSingle(2); //tiene que poner en cero unicamente el bit numero 2
    TEST_ASSERT_EQUAL_HEX16(0x0000, PuertoVirtual);
}

//Encender y apagar distintos leds
void test_turn_on_turn_off_differents_leds(void){
    ledsTurnOnSingle(3);
    ledsTurnOnSingle(5);
    
    ledsTurnOffSingle(3); 
    ledsTurnOffSingle(7); 

    TEST_ASSERT_EQUAL_HEX16(0x0010, PuertoVirtual);

}

//con todos los leds apagados, los enciendo a todos juntos
void test_turn_on_all_leds_when_all_off(void){

    //Esto realmente no es necesario porque el init los apaga  a todos
    ledsTurnOffAll();
    ledsTurnOnAll();
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, PuertoVirtual);
}

//con todos los leds encendidos, los apago a todos juntos
void test_turn_off_all_leds_when_all_on(void){

    ledsTurnOnAll();
    ledsTurnOffAll();
    TEST_ASSERT_EQUAL_HEX16(0x0000, PuertoVirtual);
}

//pruebo sobre los limites de los argumentos 
void test_check_args_limits(){

    ledsTurnOnSingle(1);
    TEST_ASSERT_EQUAL_HEX16(0x0001, PuertoVirtual); //0b0000 0000 0000 0001
    ledsTurnOffSingle(1);

    ledsTurnOnSingle(16);
    TEST_ASSERT_EQUAL_HEX16(0x8000, PuertoVirtual); //0b1000 0000 0000 0000
    ledsTurnOffSingle(16);

    TEST_ASSERT_EQUAL_HEX16(0x0000, PuertoVirtual); 
}

//argumentos invalidos
void test_check_wrong_args(){
    ledsTurnOnSingle(-10); //Si el argumento es erroneo no deberia cambiar nadad
    TEST_ASSERT_EQUAL_HEX16(0x0000, PuertoVirtual); 
}

//prueba de inicializacion erronea
void test_wrong_init_leds(){
    
    //el unico error de inicializacion que se me ocurre es pasar la direccion null
    bool init = ledsInit(NULL); //aca puerto virtual deberia ser igualado a cero
    TEST_ASSERT_FALSE(init);

}