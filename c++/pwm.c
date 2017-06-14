#include <cstdio>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;


void initPWM(int frequency) //config and init pwm, only need to do once, max frequency 1Mhz
{
	system("sudo modprobe pwm-meson npwm=2");
	system("sudo modprobe pwm-ctrl");
	system("cd /sys/devices/platform/pwm-ctrl/; echo 1 > enable0");
	system("cd /sys/devices/platform/pwm-ctrl/; echo 1 > enable1");
	char buffer1[100];
	char buffer2[100];
	sprintf(buffer1, "cd /sys/devices/platform/pwm-ctrl/; echo %d > freq0", frequency);
	sprintf(buffer2, "cd /sys/devices/platform/pwm-ctrl/; echo %d > freq1", frequency);
	system (buffer1);
	system (buffer2);
}

void SetDutyCycle(int cycle, int pwm) //cycle has a resolution of 1023, pwm is to chose which pwm device 
{
	char buffer[100];
	sprintf(buffer, "cd /sys/devices/platform/pwm-ctrl/; echo %d > duty%d", cycle,pwm);
	system(buffer);
} 

int main() //310 full reverse, 620 full forward, 465 for stop
{
	initPWM(300);
	SetDutyCycle(530,0);
	SetDutyCycle(530,1);
	return 0;
}


