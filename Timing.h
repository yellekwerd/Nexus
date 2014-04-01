/*
 * Drew Kelley
 * Senior Honors Thesis
 * Boston University
 * Electrical and Computer Engineering
 *
 * NEXUS ACTIVE CONTROL FIRMWARE
 * File:   Timing.h
 * Created on April 1, 2014, 3:29 AM
 *
 * Description:
 *
 */

#ifndef TIMING_H
#define	TIMING_H

#define CD_LED_Period 250
#define STAB_LED_Period 250

extern volatile char CD_LED_Flashing;
extern volatile int CD_LED_Counter;

extern volatile int STAB_LED_Counter;
extern volatile char STAB_LED_Flashing;

#endif	/* TIMING_H */

