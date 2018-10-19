/*
 * driver.h
 *
 * Created: 25.03.2018 17:54:33
 *  Author: medlem
 */ 


#ifndef DRIVER_H_
#define DRIVER_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

#define ROWS 8
#define COLUMS 8

#define PMOSROW1 0 //PB0
#define PMOSROW2 1 
#define PMOSROW3 2 
#define PMOSROW4 3 
#define PMOSROW5 0 //PD0
#define PMOSROW6 1
#define PMOSROW7 2
#define PMOSROW8 3

//Pinout for PMOS Transistors (VCC)
uint8_t pinVcc[ROWS]; //PB0-3 -> PD0-3

//Pinout for NMOS Transistors (GND)
uint8_t pinRed[ROWS];  //PA0-7
uint8_t pinGreen[ROWS]; //PC7-0
uint8_t pinBlue[ROWS]; //PD4-7->PE0-3


/*
enum pinRed {P1=0, P2, P3, P4, P5, P6, P7, P8}; //PA0-7
enum pinGreen {P1=7, P2=6, P3=5, P4=4, P5=3, P6=2, P7=1, P8=0}; //PC7-0
enum pinBlue {P1=4, P2=5, P3=6, P4=7, P5=0, P6=1, P7=2, P8=3}; //PD4-7->PE0-3
*/

uint8_t screenBuffer [ROWS][COLUMS][3];




#endif /* DRIVER_H_ */