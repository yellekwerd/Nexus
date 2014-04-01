/*
 * Drew Kelley
 * Senior Honors Thesis
 * Boston University
 * Electrical and Computer Engineering
 *
 * NEXUS ACTIVE CONTROL FIRMWARE
 * File:   Comms.c
 * Created on March 20, 2014, 3:11 PM
 *
 * Description: This file contains communication functions for the UART and SPI busses
 * That includes RX interrupts or TX interrupts as necessary.
 *
 */

#include "Includes.h"

volatile char UART_Buffer[10];
volatile char UART_Process_Flag=0;
volatile int  UB_Size=0;

void __attribute__ ((interrupt,no_auto_psv)) _U1RXInterrupt(void){
    U1RX_Clear_Intr_Status_Bit;
    if(U1STAbits.OERR){
        U1STAbits.OERR=0;
    }
    UART_Buffer[UB_Size++]= U1RXREG;
    if(UART_Buffer[UB_Size-1]=='\n'||UB_Size==10){
        UART_Process_Flag=1;
    }
}

void clear_uart(void){
    int i=0;
    for(; i<UB_Size; i++){
        UART_Buffer[i]=0;
    }
    UART_Process_Flag=0;
    UB_Size=0;
}