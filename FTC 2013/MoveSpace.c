#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Sensor, S1,     controllers,    sensorNone)
#pragma config(Sensor, S2,     touch,          sensorTouch)
#pragma config(Sensor, S3,     irSeek,        sensorHiTechnicIRSeeker1200)
#pragma config(Sensor, S4,     ultrasonicSensor, sensorSONAR)
#pragma config(Motor,  motorA,          flickMotor1,   tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,          flickMotor2,   tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     right,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     left,          tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     hangMotor,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     empty1,        tmotorTetrix, PIDControl)
#pragma config(Motor,  mtr_S1_C3_1,     armMotor,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     flagRaiser,    tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C4_1,    releaseServo,         tServoStandard)
#pragma config(Servo,  srvo_S1_C4_2,    pinServo,             tServoStandard)
#pragma config(Servo,  srvo_S1_C4_3,    blockServo,           tServoStandard)
#pragma config(Servo,  srvo_S1_C4_4,    trayR,                tServoStandard)
#pragma config(Servo,  srvo_S1_C4_5,    trayL,                tServoStandard)
#pragma config(Servo,  srvo_S1_C4_6,    flagServo,            tServoStandard)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.

bool useTemplate = true;

// Handy move method with speed and offset.
void move(int speed, int offset)
{
	speed = speed * -1;
	speed = speed - offset;

	// Turn right if offset >0, so power left motor.
	motor[left] = (speed + offset) * -1;
	motor[right] = speed - offset;

}

void stopMoving()
{
	motor[right] = 0;
	motor[left] = 0;
}

void moveUntilSpace(int distance, int speed)
{
	// should be positives
	move(speed,0);
	while(SensorValue[ultrasonicSensor] < distance)
	{
		// do nothing
	}
	stopMoving();
}


long timeMoved = 0;
void moveUntilBeacon(int valueToCompare, int speed)
{
	ClearTimer(T1);
	timeMoved = 0;
	// should be negative
	move(speed,0);
	while(SensorValue[irSeek] != valueToCompare)
	{
		// do nothing
	}

}
int startBlockServo = 220;
int waitTime;

// Bring in color sensor so it can display the status of the robot.
task main()
{
	moveUntilSpace(200, 100);

}
