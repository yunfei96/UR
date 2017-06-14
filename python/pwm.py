#!/usr/bin/python
import os
#config and init pwm, only need to do once, max frequency 1Mhz
def initPWM(frequency):
	os.system("sudo modprobe pwm-meson npwm=2")
	os.system("sudo modprobe pwm-ctrl")
	os.system("cd /sys/devices/platform/pwm-ctrl/; echo 1 > enable1")
	buff1 = "cd /sys/devices/platform/pwm-ctrl/; echo "+ str(frequency) + " > freq0"
	buff2 = "cd /sys/devices/platform/pwm-ctrl/; echo "+ str(frequency) + " > freq1"
	os.system (buff1)
	os.system (buff2)

#cycle has a resolution of 1023, pwm is to chose which pwm device 
def setDutyCycle(cycle, pwm):
	buff = "cd /sys/devices/platform/pwm-ctrl/; echo " + str(cycle) + " > duty"+ str(pwm)
	os.system (buff)

#310 full reverse, 620 full forward, 465 for stop
def main():
	initPWM(300)
	setDutyCycle(530,0)
	setDutyCycle(530,1)

if __name__ == "__main__":
    main()
