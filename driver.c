/*
 * driver.c
 *
 * Created: 25.03.2018 17:54:49
 *  Author: medlem
 */ 

#include "driver.h"

uint8_t pinVcc[ROWS] = {PMOSROW1,PMOSROW2,PMOSROW3,PMOSROW4,PMOSROW5,PMOSROW6,PMOSROW7,PMOSROW8}; //PB0-3 -> PD0-3

uint8_t pinRed[ROWS] = {0,1,2,3,4,5,6,7}; //PA0-7
uint8_t pinGreen[ROWS] = {7,6,5,4,3,2,1,0}; //PC7-0
uint8_t pinBlue[ROWS] = {4,5,6,7,0,1,2,3}; //PD4-7->PE0-3

ISR(TCC0_OVF_vect){
	static int y = 0;

	PORTA.OUT = 0x00;
	PORTB.OUT = 0x00;
	PORTC.OUT = 0x00;
	PORTD.OUT = 0x00;
	PORTE.OUT = 0x00;
	static int xAxis = 0;
	static int color = 0;
	for (xAxis = 0; xAxis<ROWS; xAxis++)
	{
		
		for (color = 0; color < 3; color++)
		{
			if (screenBuffer[xAxis][y][color]!=0)
			{
				if (color==0)
				{
					PORTA.OUT |= (1 << pinRed[xAxis]);
				}
				if (color==1)
				{
					PORTC.OUT |= (1 << pinGreen[xAxis]);
				}
				if (color==2)
				{
					
					if (xAxis < 4)
					{
						PORTD.OUT |= (1 << pinBlue[xAxis]);
						if (y > 3)
						{
							PORTD.OUT |= (1 << pinVcc[y]);
						}
					}
					if (xAxis >= 4){
						PORTE.OUT |= (1 << pinBlue[xAxis]);
					}
				}
			}
		}
	}
	if (y < 4)
	{
		PORTB.OUT = (1 << pinVcc[y]);
	}else
	{
		PORTD.OUT = (1 << pinVcc[y]);
	}
	y++;
	if (y==COLUMS)
	{
		y=0;
		
	}
	
	TCC0.INTFLAGS |= (1 << 0);
}