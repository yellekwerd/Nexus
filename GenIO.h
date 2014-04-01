/*
 * Drew Kelley
 * Senior Honors Thesis
 * Boston University
 * Electrical and Computer Engineering
 *
 * NEXUS ACTIVE CONTROL FIRMWARE
 * File:   GenIO.h
 * Created on April 1, 2014, 3:34 AM
 *
 * Description:
 *
 */

#ifndef GENIO_H
#define	GENIO_H

#define CD_LED_OUT LATBbits.LATB15
#define STAB_LED_OUT LATAbits.LATA3

#define Toggle_CD_LED CD_LED_OUT^=1
#define Toggle_STAB_LED STAB_LED_OUT^=1;

#endif	/* GENIO_H */

