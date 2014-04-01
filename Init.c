/*
 * Drew Kelley
 * Senior Honors Thesis
 * Boston University
 * Electrical and Computer Engineering
 *
 * NEXUS ACTIVE CONTROL FIRMWARE
 * File:   init.c
 * Created on March 20, 2014, 1:50 PM
 *
 * Description:
 *
 */

#include "Includes.h"

/**
 * init_mcu
 *
 * This function initializes the oscillator settings required for operation. The
 * primary and secondary oscillators are both set to FRCPLL, giving a Fosc of 32Mhz
 *
 * Doze and RCDIV are disabled to provided a 32Mhz Fosc (16Mhz Fcy) to all peripherals
 *
 * AD1PCFG is set to all 1s, disabling analog inputs on all pins. That was determined
 * to be an issue with peripheral usage on certain RP pins by default.
 */
void init_mcu(void){
    OSCCONbits.COSC = 0b001; //Enable FRCPLL for 32MHz Fosc
    OSCCONbits.NOSC = 0b001; //Secondary oscillator same as first
    CLKDIVbits.RCDIV = 0;    //No RC clock post scaler
    CLKDIVbits.DOZE = 0;     //No Division of Fosc to peripherals.
    AD1PCFG=0xFFFF;
}

/**
 * init_uart
 *
 * This function initializes the UART peripheral used for communicating with the
 * board during development. Note, when the board is actually in proper use, the UART
 * will not actually be connected. This is primarily for ease of development.
 */
void init_uart(void){
    long config1 = UART_EN|UART_BRGH_FOUR|UART_UEN_00;
    long config2 = UART_TX_ENABLE;
    OpenUART1(config1,config2,68);
    IN_FN_PPS_U1RX=IN_PIN_PPS_RP14 ;
    OUT_PIN_PPS_RP13=OUT_FN_PPS_U1TX;
    EnableIntU1RX;
}

void init_timers(void){
    long T1_Config = T1_ON | T1_IDLE_CON | T1_PS_1_64 | T1_SOURCE_INT | T1_SYNC_EXT_OFF;
    OpenTimer1(T1_Config,250); //One ms interrupts
    EnableIntT1;
}

void init_io(void){
    TRISBbits.TRISB15 = 0;
    TRISAbits.TRISA3 = 0;
}

void init_pwm(void){
    T2CONbits.TON=1;
    T2CONbits.TCKPS=1;
    T2CONbits.T32=0;
    T2CONbits.TCS=0;

    PR1 = SERVO_PERIOD;
    OC1R=DEG_NEU;
    OC1CONbits.OCTSEL=0;
    OC1CONbits.OCM=0;
    OUT_PIN_PPS_RP11 = OUT_FN_PPS_OC1;

    PR2 = SERVO_PERIOD;
    OC2R=DEG_NEU;
    OC2CONbits.OCTSEL=0;
    OC2CONbits.OCM=0;
    OUT_PIN_PPS_RP12 = OUT_FN_PPS_OC2;
}
