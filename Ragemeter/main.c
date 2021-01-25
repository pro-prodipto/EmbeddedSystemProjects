// Code for 7 Segment Display Interfacing with 8051 Microcontroller (AT89S52)...

//#include<reg51.h>
#include<reg52.h>
#include<stdio.h>
//#include<reg51.h>
sbit LED = P1^0;
sbit sw = P1^5;
sbit seg8 = P2^7;  //the decimal...
//for F
sbit segG = P2^4;
sbit segF = P2^5;
sbit segE = P2^6;
sbit segA = P2^0;

unsigned int k=0;
//k=0;
unsigned char no_code[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90}; //Array for hex values (0-9) for common anode 7 segment
		
void pattern(void);

void msdelay(unsigned int time)  // Function for creating delay in milliseconds.
{
    unsigned i,j ;
    for(i=0;i<time;i++)    
    for(j=0;j<1275;j++);
}

void main()
{
	//P1 = 0x00;  //we're gonna use a switch here at pin 6 so let it be high by default...
	P2 = 0xFF; //going high...for common anode 7-segment display...
	P3 = 0x00; //we don't need it so LOW...
	//P0 does not have any internal pull-up resistor...
	LED = 0; //makes the pin as the output;
	seg8 = 0;
    while(1)
    {
        if(sw == 0)  //if the switch is pressed...
        { //here we have to provides a delay to prevent from switch bouncing
					LED = 1;
					msdelay(20); //Wait time more then bouncing period
					LED = 0;
					if(sw == 0) //still pressed...
					{
						k++;  //increase number by one...	
					}
				}
				
				if(k==10)
				{
					pattern();
					k=0;  //initialising display to '0' again...
					P2 = 0xFF; //making display blank...by making all pins high
					//msdelay(500);
				}
							
					P2=no_code[k];  //increase the display...
					msdelay(5);  //delay for the processor...
        
    }
}

void pattern(void)
{
	int i;
	P2 = 0xFF;
	segG = 0;
	segE = 0;
	segF = 0;
	segA = 0;
	//FUCK YOU..!!
	for(i=1;i<=5;i++)
	{
		//P2 = 0xFF;	
		seg8 = 0;
		msdelay(50);
		seg8 = 1;
		msdelay(50);
	}
	segG = 1;
	segE = 1;
	segF = 1;
	segA = 1;
}