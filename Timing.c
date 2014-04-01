/*
 * Drew Kelley
 * Senior Honors Thesis
 * Boston University
 * Electrical and Computer Engineering
 *
 * NEXUS ACTIVE CONTROL FIRMWARE
 * File:   Timing.c
 * Created on April 1, 2014, 3:29 AM
 *
 * Description:
 *
 */

#include "Includes.h"

volatile int CD_LED_Counter = 0;
volatile char CD_LED_Flashing = 0;

volatile int STAB_LED_Counter=0;
volatile char STAB_LED_Flashing = 1;

void __attribute__((interrupt,no_auto_psv)) _T1Interrupt(void){
    T1_Clear_Intr_Status_Bit;
    if(CD_LED_Flashing){
        if(CD_LED_Counter++==CD_LED_Period){
            Toggle_CD_LED;
            CD_LED_Counter = 0;
        }
    }
    if(STAB_LED_Flashing){
        if(STAB_LED_Counter++==STAB_LED_Period){
            Toggle_STAB_LED;
            STAB_LED_Counter=0;
        }
    }

}