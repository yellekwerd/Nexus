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
#include "Includes.h"
#include "Configuration.h"

int main() {
    init_mcu();
    init_uart();
    init_pwm();
    init_io();
    init_timers();
    init_spi();
    //Main Work Loop
#ifdef VERBOSE
    putsUART1((UINT*) "Nexus Control Board Online...\nFirmware Version 1.0\nVerbose Enabled\n\n");
#endif
    init_fs();
   
    CD_LED_Flashing = 1;
    while (1) {
        if (!MDD_MediaDetect()) {
            CD_LED_Flashing = 0;
            if (CD_LED_OUT == 0) {
                Toggle_CD_LED;
            }
            CD_LED_Counter = 0;
        } else {
            CD_LED_Flashing = 1;
        }

        if (UART_Process_Flag) {
            if (cmd_equals(SERVO_RIGHT, 2)) {
#ifdef VERBOSE
                putsUART1((UINT *) "RIGHT\n");
#endif
                OC1RS = DEG_P45;
                OC1CONbits.OCM = 6;
                OC2RS = DEG_P45;
                OC2CONbits.OCM = 6;
            } else if (cmd_equals(SERVO_LEFT, 2)) {
#ifdef VERBOSE
                putsUART1((UINT *) "LEFT\n");
#endif
                OC1RS = DEG_N45;
                OC1CONbits.OCM = 6;
                OC2RS = DEG_N45;
                OC2CONbits.OCM = 6;
            } else if (cmd_equals(SERVO_NEUTRAL, 2)) {
#ifdef VERBOSE
                putsUART1((UINT *) "NEUTRAL\n");
#endif
                OC1RS = DEG_NEU;
                OC1CONbits.OCM = 6;
                OC2RS = DEG_NEU;
                OC2CONbits.OCM = 6;
            } else if(cmd_equals(FILESYS_INIT,3)){
                init_fs();
            } else
                putsUART1((UINT*) "Invalid Command\n");
            clear_uart();

        }
    }
    return 0;
}

