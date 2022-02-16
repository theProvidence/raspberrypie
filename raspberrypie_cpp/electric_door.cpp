#include<wiringPi.h>
#include<stdio.h>
#include<stdlib.h>
#include<softPwm.h>

/*Using DC motor rotation*/
#define foreward 29	//wpi 29 pin, GPIO 21
#define backward 28 //wpi 28 pin, GPIO 20

void door_open()
{
	digitalWrite(foreward, 1);//open door
	digitalWrite(backward, 0);//close door
	delay(150);//open for 150ms
	printf("Door opened\n");
	return;
}

void door_close()
{
	digitalWrite(foreward, 0);//open door
	digitalWrite(backward, 1);//close door
	delay(150);//close for 150ms
	printf("Door closed\n");
	return;
}

int main()
{
	if (wiringPiSetup() == -1)return 1; //init wiringPi
	pinMode(foreward, OUTPUT);
	pinMode(backward, OUTPUT);
	for (int i = 0; i < 4; i++)
	{
		door_open();
		delay(1000);
		door_close();
	}
	return 0;
}
