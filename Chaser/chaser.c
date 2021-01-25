//This is the basic program for LED chaser using 8051, because as you see this program is very large that’s why it is very basic program for easily understanding the Embedded C programming. Before you seeing this program you may know about keil software. Lets see the program..


#include<reg51.h>           // This command is used for including all register file of 8051.
sbit led1=P2^0;                // This is used for initializing single bit of P2.0 to led1.
sbit led2=P2^1;
sbit led3=P2^2;
sbit led4=P2^3;
sbit led5=P2^4;
sbit led6=P2^5;
sbit led7=P2^6;
sbit led8=P2^7;

void delay (unsigned int ms)                   // This loop is used for time taken by each led is ON or OFF.
{
                unsigned int i, j;                                                        
                for (i=0; i<=ms; i++)
                 for (j=0; j<1275; j++);                                 // Here 1275 indicates 1 millisecond.
}
void main ()
{  
                                led1=0;
                                led2=0;                      // Firstly I initialize all leds into OFF state
                                led3=0;                      //          i.e. led (n) =0;
                                led4=0;                      //                   n: - No. of Leds */
                                led5=0;
                                led6=0;
                                led7=0;
                                led8=0;
                while (1)
                {
                               
                                delay (10);                  // delay (10) means led 1 is ON by delay 10 milliseconds.
                                led1=1;
                                delay (10);
                                led1=0;
                                led2=1;
                                delay (10);
                                led2=0;
                                led3=1;
                                delay (10);
                                led3=0;
                                led4=1;
                                delay (10);
                                led4=0;
                                led5=1;
                                delay (10);
                                led5=0;
                                led6=1;
                                delay (10);
                                led6=0;
                                led7=1;
                                delay (10);
                                led7=0;
                                led8=1;
                                delay (10);
                                led8=0;
                                led1=1;
                }
}               

//You can use Arrays concept on this program then shorten the program. But I make this program for easily understanding to every one.