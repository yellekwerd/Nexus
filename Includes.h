/*
 * Drew Kelley
 * Senior Honors Thesis
 * Boston University
 * Electrical and Computer Engineering
 *
 * NEXUS ACTIVE CONTROL FIRMWARE
 * File:   includes.h
 * Created on March 20, 2014, 1:43 PM
 *
 * Description:
 *
 */

#ifndef INCLUDES_H
#define	INCLUDES_H
//Required definition for easier use of plib functions
#define USE_AND_OR

#include <xc.h> //Includes pic settings/macros
#include <uart.h>//UART library
#include <spi.h> //SPI Library
#include <outcompare.h>//PWM library
#include <timer.h>
#include <PPS.h> //Peripheral Pin Select library
#include "Init.h"
#include "Comms.h"



#endif	/* INCLUDES_H */

