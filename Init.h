/*
 * Drew Kelley
 * Senior Honors Thesis
 * Boston University
 * Electrical and Computer Engineering
 *
 * NEXUS ACTIVE CONTROL FIRMWARE
 * File:   init.h
 * Created on March 20, 2014, 1:48 PM
 *
 * Description: Contains function headers for all system initilization:
 * Oscillator
 * UART
 * SPI
 * PWM
 * Timers
 *
 */

#ifndef INIT_H
#define	INIT_H

void init_mcu(void);
void init_pwm(void);
void init_spi(void);
void init_uart(void);
void init_timers(void);
void init_io(void);
void init_fs(void);

#define SERVO_PERIOD 5999
#define DEG_P45    3899
#define DEG_NEU    2999
#define DEG_N45    2099
#endif	/* INIT_H */

