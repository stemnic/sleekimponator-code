/*
 * drawer.c
 *
 * Created: 26.03.2018 01:48:13
 *  Author: medlem
 */ 

#define F_CPU 400000UL

#include <util/delay.h>
#include "driver.h"
#include "drawer.h"

const uint8_t OMEGA[][8] = {
	{
		0b00011000,
		0b01100110,
		0b01000010,
		0b10000001,
		0b10000001,
		0b01000010,
		0b10100101,
		0b11100111
		},{
		0b00001100,
		0b00110011,
		0b00100001,
		0b01000000,
		0b01000000,
		0b00100001,
		0b01010010,
		0b01110011
		},{
		0b00000110,
		0b00011001,
		0b00010000,
		0b00100000,
		0b00100000,
		0b00010000,
		0b00101001,
		0b00111001
		},{
		0b00000011,
		0b00001100,
		0b00001000,
		0b00010000,
		0b00010000,
		0b00001000,
		0b00010100,
		0b00011100
		},{
		0b00000001,
		0b00000110,
		0b00000100,
		0b00001000,
		0b00001000,
		0b00000100,
		0b00001010,
		0b00001110
		},{
		0b00000000,
		0b00000011,
		0b00000010,
		0b00000100,
		0b00000100,
		0b00000010,
		0b00000101,
		0b00000111
		},{
		0b00000000,
		0b00000001,
		0b00000001,
		0b00000010,
		0b00000010,
		0b00000001,
		0b00000010,
		0b00000011
		},{
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000001,
		0b00000001,
		0b00000000,
		0b00000001,
		0b00000001
		},{
		0b00000000,
		0b00000000,
		0b00000000,
		0b10000000,
		0b10000000,
		0b00000000,
		0b10000000,
		0b10000000
		},{
		0b00000000,
		0b10000000,
		0b10000000,
		0b01000000,
		0b01000000,
		0b10000000,
		0b01000000,
		0b11000000
		},{
		0b00000000,
		0b11000000,
		0b01000000,
		0b00100000,
		0b00100000,
		0b01000000,
		0b10100000,
		0b11100000
		},{
		0b10000000,
		0b01100000,
		0b00100000,
		0b00010000,
		0b00010000,
		0b00100000,
		0b01010000,
		0b01110000
		},{
		0b11000000,
		0b00110000,
		0b00010000,
		0b00001000,
		0b00001000,
		0b00010000,
		0b00101000,
		0b00111000
		},{
		0b01100000,
		0b10011000,
		0b00001000,
		0b00000100,
		0b00000100,
		0b00001000,
		0b10010100,
		0b10011100
		},{
		0b00110000,
		0b11001100,
		0b10000100,
		0b00000010,
		0b00000010,
		0b10000100,
		0b01001010,
		0b11001110
		},{
		0b00111100,
		0b01000010,
		0b10100101,
		0b10100101,
		0b10100101,
		0b01011010,
		0b10100101,
		0b11100111
		},{
		0b00111100,
		0b01000010,
		0b10100101,
		0b10100101,
		0b10100101,
		0b01011010,
		0b10100101,
		0b11100111
		},{
	0b00111100,
	0b01000010,
	0b10100101,
	0b10100101,
	0b10100101,
	0b01011010,
	0b10100101,
	0b11100111
	},{
	0b00111100,
	0b01000010,
	0b10100101,
	0b10100101,
	0b10100101,
	0b01011010,
	0b10100101,
	0b11100111
	},{
	0b00111100,
	0b01000010,
	0b10100101,
	0b10100101,
	0b10100101,
	0b01011010,
	0b10100101,
	0b11100111
	},{
	0b00111100,
	0b01000010,
	0b10100101,
	0b10100101,
	0b10100101,
	0b01011010,
	0b10100101,
	0b11100111
	},{
	0b00111100,
	0b01000010,
	0b10100101,
	0b10100101,
	0b10100101,
	0b01011010,
	0b10100101,
	0b11100111
	},{
	0b00111100,
	0b01000010,
	0b10100101,
	0b10100101,
	0b10100101,
	0b01011010,
	0b10100101,
	0b11100111
	},{
		0b00111100,
		0b01000010,
		0b10000001,
		0b10000001,
		0b10000001,
		0b01000010,
		0b10100101,
		0b11100111
		},{
		0b00111100,
		0b01000010,
		0b10000001,
		0b10000001,
		0b10000001,
		0b01000010,
		0b10100101,
		0b11100111
	}
		
		
		
		};
	const int IMAGES_LEN = sizeof(OMEGA)/8;


void displayImage(const uint8_t images[][8]){
	
	
	
	for (int amount=0; amount < IMAGES_LEN; amount++)
	{
		for (int y=0; y < COLUMS; y++)
		{
			
			uint8_t rowBitMask = images[amount][y];	
			for (int x=0; x < ROWS; x++)
			{
				if (rowBitMask & (1 << x))
				{
					screenBuffer[x][y][2]=255;
					screenBuffer[x][y][1]=255;
					//screenBuffer[x][y][0]=255;
				}else
				{
					screenBuffer[x][y][2]=0;
					screenBuffer[x][y][1]=0;
					//screenBuffer[x][y][0]=0;
				}
			}
		}
		//_delay_ms(40);
	}
	
}

