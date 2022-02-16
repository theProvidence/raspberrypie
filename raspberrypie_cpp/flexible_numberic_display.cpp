#include<wiringPi.h>
#include<stdio.h>
#include<stdlib.h>

/*allocate GPIO pin*/
#define p_a 2
#define p_b 3
#define p_c 23
#define p_d 24
#define p_e 25
#define p_f 0
#define p_g 7
#define p_dp 22

int duty_c = 50;//initialize duty cycle
char pin[10] = { 0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90 };//Anode number 0,1,2,,,9
char gpiopin[8] = { 2,3,23,24,25,0,7,22 };//gpio

void clear_pin()//init pin
{
	for (int i = 0; i < 8; i++) digitalWrite(gpiopin[i], 1);//Turn off the LED 
	return;
}

int main()
{
	int result;//init variable
	if (wiringPiSetup() == -1) return 1;
	for (int i = 0; i < 8; i++)pinMode(gpiopin[i], OUTPUT);//output gpio

	for (int i = 0; i < 10; i++)
	{
		printf("num=%d, pin=%x\n", i, pin[i]);
		/*num=0, pin=c0	 ->	 num=1, pin=f9...*/
		clear_pin();
		for (int j = 0; j < 8; j++)
		{
			result = pin[i] >> (j);
			digitalWrite(gpiopin[j], (result & 1));//display
			delay(10);
		}
		delay(4000); //display the number for 4s
	}
	clear_pin();
	return 0;
}
