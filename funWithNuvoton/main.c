#include<reg52.h>
#include<stdio.h>

sbit LED = P1^0;
sbit sw = P1^5;
//declaring 7-segment here...not needed if you're writing hex codes...
sbit seg1 = P2^0; 
sbit seg2 = P2^1; 
sbit seg3 = P2^2; 
sbit seg4 = P2^3; 
sbit seg5 = P2^4; 
sbit seg6 = P2^5; 
sbit seg7 = P2^6; 
sbit seg8 = P2^7;
//done!!

void delay(unsigned int count);

void display(unsigned int num);

void pattern(void);

void main()
{
	//P1 = 0x00;  //we're gonna use a switch here at pin 6  
	P2 = 0xFF; //going high.
	P3 = 0x00;
	//P0 does not have any internal pull-up resistor...
	LED = 0; //makes the pin as the output;
	
	while(1)
	{
		int i;
		if(sw == 0)  //if the switch is pressed...
		{
		for(i=9;i>=0;i--)
		{				
			LED = 1;
			display(i); //uses the 7-segment...
			delay(400);
			LED = 0;
			delay(400);
		}		
		}
		else
		{
			pattern();
		}
	}
}
//standard delay function...
void delay(unsigned int count)
{
	unsigned int i;
	while(count)
	{
		i=115;
		while(i>0)
		{
			i--;
		}
		count--;
	}
}
//end of delay
		
void display(unsigned int num)
{
	
	switch(num)
	{
		case 1:
		{
			P2 = 0xF9;
			break;
		}
		case 2:
		{
			P2 = 0xA4;
			break;
		}
		case 3:
		{
			P2 = 0xB0;
			break;
		}
		case 4:
		{
			P2 = 0x99;
			break;
		}
		case 5:
		{
			P2 = 0x92;
			break;
		}
		case 6:
		{
			P2 = 0x82;
			break;
		}
		case 7:
		{
			P2 = 0xF8;
			break;
		}
		case 8:
		{
			P2 = 0x80;
			break;
		}
		case 9:
		{
			P2 = 0x90;
			break;
		}
		case 0:
		{
			P2 = 0xC0;
			break;
		}
	}
	
}   //7-segment interfacing with 8051 microcontroller nuvoton 78e052ddg 

void pattern(void)
{
		P2 = 0xFF;
		
		seg8 = 0;
		delay(100);
		seg8 = 1;
		delay(100);
			
}