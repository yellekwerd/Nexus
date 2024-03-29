/*
 * Drew Kelley
 * Senior Honors Thesis
 * Boston University
 * Electrical and Computer Engineering
 *
 * NEXUS ACTIVE CONTROL FIRMWARE
 * File:   Comms.h
 * Created on March 20, 2014, 3:10 PM
 *
 * Description: This file contains function headers for any communication functionality.
 * This includes UART comms and SPI comms. Additionally it provides the prototyping for
 * the UART data buffer.
 *
 */

#ifndef COMMS_H
#define	COMMS_H

extern volatile char UART_Buffer[10];
extern volatile int  UB_Size;
extern volatile char UART_Process_Flag;

void clear_uart(void);

#endif	/* COMMS_H */

