#include "inc/leds.h"
#include "/Library/Ruby/Gems/2.6.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"




static uint16_t PuertoVirtual;



void setUp(){

    ledsInit(&PuertoVirtual);

}





void test_all_leds_start_off(void){



    uint16_t puertoVirtual = 0xFFFF;

    ledsInit(&puertoVirtual);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((puertoVirtual)), (((void*)0)), (UNITY_UINT)(38), UNITY_DISPLAY_STYLE_HEX16);

}





void test_turn_on_single_led(void){



    ledsTurnOnSingle(2);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0002)), (UNITY_INT)(UNITY_INT16)((PuertoVirtual)), (((void*)0)), (UNITY_UINT)(45), UNITY_DISPLAY_STYLE_HEX16);

}





void test_turn_on_turn_off_single_led(void){



    ledsTurnOnSingle(2);

    ledsTurnOffSingle(2);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((PuertoVirtual)), (((void*)0)), (UNITY_UINT)(53), UNITY_DISPLAY_STYLE_HEX16);

}





void test_turn_on_turn_off_differents_leds(void){

    ledsTurnOnSingle(3);

    ledsTurnOnSingle(5);



    ledsTurnOffSingle(3);

    ledsTurnOffSingle(7);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0010)), (UNITY_INT)(UNITY_INT16)((PuertoVirtual)), (((void*)0)), (UNITY_UINT)(64), UNITY_DISPLAY_STYLE_HEX16);



}





void test_turn_on_all_leds_when_all_off(void){





    ledsTurnOffAll();

    ledsTurnOnAll();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0xFFFF)), (UNITY_INT)(UNITY_INT16)((PuertoVirtual)), (((void*)0)), (UNITY_UINT)(74), UNITY_DISPLAY_STYLE_HEX16);

}





void test_turn_off_all_leds_when_all_on(void){



    ledsTurnOnAll();

    ledsTurnOffAll();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((PuertoVirtual)), (((void*)0)), (UNITY_UINT)(82), UNITY_DISPLAY_STYLE_HEX16);

}





void test_check_args_limits(){



    ledsTurnOnSingle(1);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0001)), (UNITY_INT)(UNITY_INT16)((PuertoVirtual)), (((void*)0)), (UNITY_UINT)(89), UNITY_DISPLAY_STYLE_HEX16);

    ledsTurnOffSingle(1);



    ledsTurnOnSingle(16);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x8000)), (UNITY_INT)(UNITY_INT16)((PuertoVirtual)), (((void*)0)), (UNITY_UINT)(93), UNITY_DISPLAY_STYLE_HEX16);

    ledsTurnOffSingle(16);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((PuertoVirtual)), (((void*)0)), (UNITY_UINT)(96), UNITY_DISPLAY_STYLE_HEX16);

}





void test_check_wrong_args(){

    ledsTurnOnSingle(-10);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((PuertoVirtual)), (((void*)0)), (UNITY_UINT)(102), UNITY_DISPLAY_STYLE_HEX16);

}





void test_wrong_init_leds(){





    _Bool init = ledsInit(((void*)0));

    do {if (!(init)) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(110)));}} while(0);



}
