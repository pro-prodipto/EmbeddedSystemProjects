// Code for 7 Segment Display Interfacing with 8051 Microcontroller (AT89S52)...
//or NUVOTON's W78E052DDG...
#include<reg52.h>
#include<stdio.h>
sbit LED = P1^0;
sbit sw = P1^5;

//seven segment declarations...
sbit seg8 = P2^7;  //the decimal...
sbit segA = P2^0;
sbit segB = P2^1;
sbit segC = P2^2;
sbit segD = P2^3;
sbit segE = P2^4;
sbit segF = P2^5;
sbit segG = P2^6;

sbit dig1 = P3^6;
sbit dig2 = P3^5;
sbit dig3 = P3^4;
sbit dig4 = P3^3;
sbit dig5 = P3^2;
sbit dig6 = P3^1;

unsigned int copy=0;  //counter variable here...
unsigned int count = 0;
unsigned int a=0;
unsigned int b=0;
unsigned int k=0;
unsigned int j=0; //loop control variable...

//When unsigned variables are made to exceed their maximum capacity they "roll over" back to 0, and also the other way around:

unsigned char no_code[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90}; //Array for hex values (0-9) for common anode 7 segment...

void patterns(void);
		
void main()
{
	//P1 = 0x00;  //we're gonna use a switch here at pin 6 so let it be high by default...
	P2 = 0xFF; //going high...for common anode 7-segment display...
	P3 = 0xFF; //going high for multiplex lines...high means OFF in pnp logic...bc558 used...
	//P0 does not have any internal pull-up resistor...leaving it as it is here...
	LED = 0; //makes the pin as the output...note other pins are high...
    
		while(1)
    {
			if(k==50)
			{
				k=0;
				count++;
				if(count == 100)
				{
					count = 0;
					patterns();
				}
			  copy = count;
				a = (copy%10);
			  copy = copy/10;
				b = (copy%10);				 			
			}
			
			//DIGIT 2
			dig3 = 1; //OFF
			dig2 = 0; //ON
			P2=no_code[a];
		  for(j=0;j<1500;j++); // delay use 1ms for better results...
			k++;
			//DIGIT 3
			dig2 = 1; //OFF
			dig3 = 0; //ON
			P2=no_code[b];
			for(j=0;j<1500;j++); // delay
			k++;
		}         
}

void patterns(void)
{
	int i;
	P3 = 0x00; //all display on...
	P2 = 0xFF;
	for(i=0;i<=4;i++)
	{
		seg8=0;
		for(i=0;i<200;i++)    
    for(j=0;j<1275;j++);  //200ms delay...
		seg8=1;
		for(i=0;i<200;i++)    
    for(j=0;j<1275;j++);  //200ms delay...
	}
}