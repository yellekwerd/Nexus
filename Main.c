/*
 * Drew Kelley
 * Senior Honors Thesis
 * Boston University
 * Electrical and Computer Engineering
 *
 * NEXUS ACTIVE CONTROL FIRMWARE
 * File:   includes.h
 * Created on March 20, 2014, 1:44 PM
 *
 * Description:
 *
 */
#define VERBOSE
#include "Includes.h"
#include "Configuration.h"
int main() {
    int offset=0;
    init_mcu();
    init_uart();
    init_pwm();
    //Main Work Loop
#ifdef VERBOSE
    putsUART1((UINT*)"Nexus Control Board Online...\nFirmware Version 1.0\nVerbose Enabled\n\n");
#endif
    CD_LED_Flashing = 1;
    while(1){
        if(UART_Process_Flag){
            if(UART_Buffer[0]=='R'){
#ifdef VERBOSE
                putsUART1((UINT *)"RIGHT\n");
#endif
                OC1RS = DEG_P45;
                OC1CONbits.OCM=6;
                OC2RS = DEG_P45;
                OC2CONbits.OCM=6;
            }
            else if(UART_Buffer[0]=='L'){
#ifdef VERBOSE
                putsUART1((UINT *)"LEFT\n");
#endif
                OC1RS = DEG_N45;
                OC1CONbits.OCM=6;
                OC2RS = DEG_N45;
                OC2CONbits.OCM=6;
            }
            else if(UART_Buffer[0]=='N'){
#ifdef VERBOSE
                putsUART1((UINT *)"NEUTRAL\n");
#endif
                OC1RS=DEG_NEU;
                OC1CONbits.OCM=6;
                OC2RS=DEG_NEU;
                OC2CONbits.OCM=6;
            } else if(UART_Buffer[0]=='+'){
                offset++;
                OC1RS=DEG_NEU+(offset*5);
                OC2RS=DEG_NEU+(offset*5);
                putcUART1((offset+48));
                while(U1STAbits.TRMT);
            } else if(UART_Buffer[0]=='-'){
                offset--;
                OC1RS=DEG_NEU+(offset*5);
                OC2RS=DEG_NEU+(offset*5);
                putcUART1((offset+48));
                while(U1STAbits.TRMT);
            } else if(UART_Buffer[0]=='C'){
                OC1CONbits.OCM=0;
                OC2CONbits.OCM=0;
                offset=0;
                putsUART1((UINT*)"Offset cleared, PWM disabled");
            }

            else
                putsUART1((UINT*)"No cmd\n");
            clear_uart();

        }
    }
    return 0;
}

