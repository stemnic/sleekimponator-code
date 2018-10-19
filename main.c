/*
 * SleekImponator.c
 *
 * Created: 04.03.2018 22.33.37
 * Author : medlem
 */ 
#define F_CPU 400000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "driver.h"
#include "drawer.h"

/*
void hsi2rgb(float H, float S, float I, int* rgb) {
	int r, g, b;
	H = fmod(H,360); // cycle H around to 0-360 degrees
	H = 3.14159*H/(float)180; // Convert to radians.
	S = S>0?(S<1?S:1):0; // clamp S and I to interval [0,1]
	I = I>0?(I<1?I:1):0;
	
	// Math! Thanks in part to Kyle Miller.
	if(H < 2.09439) {
		r = 255*I/3*(1+S*cos(H)/cos(1.047196667-H));
		g = 255*I/3*(1+S*(1-cos(H)/cos(1.047196667-H)));
		b = 255*I/3*(1-S);
		} else if(H < 4.188787) {
		H = H - 2.09439;
		g = 255*I/3*(1+S*cos(H)/cos(1.047196667-H));
		b = 255*I/3*(1+S*(1-cos(H)/cos(1.047196667-H)));
		r = 255*I/3*(1-S);
		} else {
		H = H - 4.188787;
		b = 255*I/3*(1+S*cos(H)/cos(1.047196667-H));
		r = 255*I/3*(1+S*(1-cos(H)/cos(1.047196667-H)));
		g = 255*I/3*(1-S);
	}
	rgb[0]=r;
	rgb[1]=g;
	rgb[2]=b;
}*/


void initTimer(){
	TCC0.CTRLA |= (0b1 << 0);
	TCC0.CTRLB |= (0 << 0);
	
	PMIC.CTRL |= (0b111);
	TCC0.INTCTRLA |= (0b11 << 0);

	TCC0.PER = 0x90;
}


int main(void)
{
	
	initTimer();
	sei();
	
	//Sets A-E as outputs
	//Pulls all outputs to LOW
	
	//PD0-3 and PB0-3 VCC
	PORTA.DIR = 0xFF;
	PORTA.OUT = 0x00;
	PORTB.DIR = 0xFF;            
	PORTB.OUT = 0x00; //PB0-3 VCC   
	PORTC.DIR = 0xFF;
	PORTC.OUT = 0x00;
	PORTD.DIR = 0xFF;
	PORTD.OUT = 0x00; //PD0-3 VCC
	PORTE.DIR = 0xFF;
	PORTE.OUT = 0x00;
	
	//PORTE.OUT |= (0b1111 << 0);
	//PORTD.OUT |= (0b0001 << 4);
	//PORTD.OUT |= (0b1111 << 0);
	//PORTB.OUT |= (0b1111 << 0);
	
	//PORTE.OUT |= (1 << 3);
	//PORTD.OUT = 0b1;
	
	/*
	for (int x = 0; x < 8; x++ )
	{
		for (int y = 0; y < 8; y++ )
		{
			screenBuffer[x][y][2] = 0;
			screenBuffer[x][y][1] = 0;
			screenBuffer[x][y][0] = 0;
		}
		
	}
	*/
	

	
	
	
	
    while (1) 
    {
		displayImage(OMEGA);
    }
}