#pragma config(Hubs,  S1, HTMotor,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     rightM,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     leftM,         tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.

task main()
{
  while (true)
  {
	  getJoystickSettings(joystick);

	  //motor[leftM] = random[200] - 100;
	  //motor[rightM] = random[200] - 100;
	  //wait1Msec(random[800] + 200);
		int rightTurn = joystick.joy1_y2;
		int leftTurn = joystick.joy1_y1;

		if(abs(rightTurn) < 10) rightTurn = 0;
		if(abs(leftTurn) < 10) leftTurn = 0;

		motor[leftM] = rightTurn;
		motor[rightM] = leftTurn;
  }
}
