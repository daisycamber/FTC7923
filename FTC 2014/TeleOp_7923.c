#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Sensor, S1,     controllers,    sensorI2CMuxController)
#pragma config(Sensor, S2,     HTSMUX,         sensorI2CCustom9V)
#pragma config(Sensor, S3,     touchmux1,      sensorHiTechnicTouchMux)
#pragma config(Sensor, S4,     HTSPB,          sensorI2CCustom9V)
#pragma config(Motor,  mtr_S1_C1_1,     flicker1,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     lift1,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     right,         tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_2,     lights,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     left,          tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     lift2,         tmotorTetrix, openLoop, encoder)
#pragma config(Servo,  srvo_S1_C4_1,    holder1,              tServoStandard)
#pragma config(Servo,  srvo_S1_C4_2,    holder2,              tServoStandard)
#pragma config(Servo,  srvo_S1_C4_3,    gate,                 tServoStandard)
#pragma config(Servo,  srvo_S1_C4_4,    blocker,              tServoStandard)
#pragma config(Servo,  srvo_S1_C4_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
#pragma config(Hubs,  S1, HTMotor,  HTServo,  HTMotor,  HTMotor)
#pragma config(Sensor, S1,     controllers,    sensorI2CMuxController)
#pragma config(Sensor, S2,     HTSMUX,         sensorI2CCustom9V)
#pragma config(Sensor, S3,     touchmux1,      sensorHiTechnicTouchMux)
#pragma config(Sensor, S4,     HTSPB,          sensorI2CCustom9V)
#pragma config(Motor,  mtr_S1_C1_1,     flicker1,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     lift1,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     right,         tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C3_2,     lights,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     left,          tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,     lift2,         tmotorTetrix, PIDControl, encoder)
#pragma config(Servo,  srvo_S1_C2_1,    holder1,              tServoStandard)
#pragma config(Servo,  srvo_S1_C2_2,    holder2,              tServoStandard)
#pragma config(Servo,  srvo_S1_C2_3,    gate,                 tServoStandard)
#pragma config(Servo,  srvo_S1_C2_4,    blocker,              tServoStandard)
#pragma config(Servo,  srvo_S1_C2_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_6,    servo6,               tServoNone)
*/

// The protoboard delay
#define protoDelay 10

int power1Up = -66; // Is the right (from sloth side)
int power1Down = 72;
int power2Up = 100;
int power2Down = -100;

#include "drivers/hitechnic-superpro.h"
#include "drivers/hitechnic-sensormux.h"
// CHANGE THIS AND THE NEXT ONE
#define presetLeft            msensor_S2_1
#define presetRight           msensor_S2_3

// THIS!!!! https://github.com/botbench/rdpartyrobotcdr/blob/master/hitechnic-gyro-SMUX-test1.c
// Assuming the Sensor MUX is connected to NXT sensor port 4 (S4)
// Assuming the following sensors are connected to the Sensor MUX ports:
// Port 1: Gyro
// Port 2: Sonar
// Port 3: IRSeeker
// Port 4: Touch
#include "drivers/hitechnic-gyro.h"    //for gyro sensor
#include "JoystickDriver.c"
#define gyroSensor              msensor_S2_2

bool TSreadState(tMUXSensor muxsensor) {
	//nxtDisplayBigStringAt(10,10, "%d", HTSMUXreadAnalogue(muxsensor));
  return (HTSMUXreadAnalogue(muxsensor) < 500) ? true : false;
}



//Bit map definitions
#define mux_button1 0x01
#define mux_button2 0x02
#define mux_button3 0x04
#define mux_button4 0x08


#define BIT1O 1
#define BIT2O 2
#define BIT3O 4
#define BIT4O 8
#define BIT5O 16
#define BIT6O 32
#define BIT7O 64
#define BIT8O 128

#define BIT1A 254
#define BIT2A 253
#define BIT3A 251
#define BIT4A 247
#define BIT5A 239
#define BIT6A 223
#define BIT7A 191
#define BIT8A 127

#define HIGH true
#define LOW false
#define INPUT false
#define OUTPUT true

byte mode = 0;
byte output = 0;

void pinMode(byte pin, bool newMode)
{
	switch (pin)
	{
	case 0:
		if(newMode)
			mode = mode | BIT1O;
		else
			mode = mode & BIT1A;
		break;

	case 1:
		if(newMode)
			mode = mode | BIT2O;
		else
			mode = mode & BIT2A;
		break;

	case 2:
		if(newMode)
			mode = mode | BIT3O;
		else
			mode = mode & BIT3A;
		break;

	case 3:
		if(newMode)
			mode = mode | BIT4O;
		else
			mode = mode & BIT4A;
		break;

	case 4:
		if(newMode)
			mode = mode | BIT5O;
		else
			mode = mode & BIT5A;
		break;

	case 5:
		if(newMode)
			mode = mode | BIT6O;
		else
			mode = mode & BIT6A;
		break;

	case 6:
		if(newMode)
			mode = mode | BIT7O;
		else
			mode = mode & BIT7A;
		break;

	case 7:
		if(newMode)
			mode = mode | BIT8O;
		else
			mode = mode & BIT8A;
		break;

	}
	// UNCOMMENT THIS NGPE[O;ALLIHJK.SDZHJGLASIDJKLGSA
	HTSPBsetupIO(HTSPB, mode);
	wait1Msec(protoDelay); // Wait for a bit
}

void digitalWrite(byte pin, bool newMode)
{
	switch (pin)
	{
	case 0:
		if(newMode)
			output = output | BIT1O;
		else
			output = output & BIT1A;
		break;

	case 1:
		if(newMode)
			output = output | BIT2O;
		else
			output = output & BIT2A;
		break;

	case 2:
		if(newMode)
			output = output | BIT3O;
		else
			output = output & BIT3A;
		break;

	case 3:
		if(newMode)
			output = output | BIT4O;
		else
			output = output & BIT4A;
		break;

	case 4:
		if(newMode)
			output = output | BIT5O;
		else
			output = output & BIT5A;
		break;

	case 5:
		if(newMode)
			output = output | BIT6O;
		else
			output = output & BIT6A;
		break;

	case 6:
		if(newMode)
			output = output | BIT7O;
		else
			output = output & BIT7A;
		break;

	case 7:
		if(newMode)
			output = output | BIT8O;
		else
			output = output & BIT8A;
		break;

	}
	// UNCOMMENT THIS NOW OR BA DTHINGS WITKSD.GKNAJSDNGKASJDIOP;GASNJ.DGHOERJLAKSD
	HTSPBwriteIO(HTSPB, output);
	wait1Msec(protoDelay);// Wait for a bit
}



task phoenix()
{
	// Setup pins
	pinMode(0, OUTPUT);
	pinMode(1, OUTPUT);
	// Switch the functionality off for a bit, just to let the microcontroller know that we are ready for
	// action, in the event that this happened directly after a restart.
	digitalWrite(0, LOW);
	wait1Msec(200);
	// Tell the microcontroller that we want the restart functionality to be on again
	digitalWrite(0, HIGH);
	bool last = false;
	while(nNxtButtonPressed != kExitButton)
	{
		if(last)
		{
			digitalWrite(1, HIGH);
		}
		else
		{
			digitalWrite(1, LOW);
		}
		last = !last;
		wait1Msec(100);
	}
	// Tell the microcontroller that we want the restart functionality to be off
	digitalWrite(0, LOW);
	digitalWrite(1, LOW);
	StopAllTasks();
}





// Simple mapping function
long map(long x, long in_min, long in_max, long out_min, long out_max)
{
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}





int getExtBatLevel()
{
	if(externalBatteryAvg > 9999)
		return map(externalBatteryAvg,10000,13000,0,100);
	return 0;
}
int getIntBatLevel()
{
	return map(nAvgBatteryLevel,3000,9000,0,100); // min 3v
}


// Code for shift registers ////////////////////////////////////////////////////////////////////////////////
int SER_Pin = 2;   //pin 14 on the 75HC595
int RCLK_Pin = 3;  //pin 12 on the 75HC595
int SRCLK_Pin = 4; //pin 11 on the 75HC595

//How many of the shift registers - change this
#define number_of_74hc595s 1

//do not touch
#define numOfRegisterPins number_of_74hc595s * 8

bool registers[numOfRegisterPins];


//set all register pins to LOW
void clearRegisters(){
	for(int i = numOfRegisterPins - 1; i >=  0; i--){
		registers[i] = LOW;
	}
}


//Set and display registers
//Only call AFTER all values are set how you would like (slow otherwise)
void writeRegisters(){

	digitalWrite(RCLK_Pin, LOW);

	for(int i = numOfRegisterPins - 1; i >=  0; i--){
		digitalWrite(SRCLK_Pin, LOW);

		int val = registers[i];

		digitalWrite(SER_Pin, val);
		digitalWrite(SRCLK_Pin, HIGH);

	}
	digitalWrite(RCLK_Pin, HIGH);

}

//set an individual pin HIGH or LOW
void setRegisterPin(int index, int value){
	registers[index] = value;
}

// End shift register code //////////////////////////////////////////////////////////////////////////////////

float currHeading = 0;
int offset = 0;

// Task to keep track of the current heading using the HT Gyro
task getHeading () {
	float delTime = 0;
	float prevHeading = 0;
	float curRate = 0;


	//PlaySound(soundBeepBeep);
	while (true) {
		time1[T1] = 0;
		curRate = HTGYROreadRot(gyroSensor);
		if (abs(curRate) > 3) {
			prevHeading = currHeading;
			currHeading = prevHeading + curRate * delTime;
			if (currHeading > 360) currHeading -= 360;
			else if (currHeading < 0) currHeading += 360;
		}
		wait1Msec(5);
		delTime = ((float)time1[T1]) / 1000;
		//delTime /= 1000;
	}
}


void lift(int position)
{
	// Down
	if(position == 0)
	{
		if(!(SensorValue(touchmux1) & mux_button1))
			motor(lift1) = power1Down;
		else nMotorEncoder[lift1] = 0;
		if(!(SensorValue(touchmux1) & mux_button3))
			motor(lift2) = power2Down;
		else nMotorEncoder[lift2] = 0;
		//place = 1;
	}
	// Up
	else if(position == 1)
	{
		if(!(SensorValue(touchmux1) & mux_button2))
			motor(lift1) = power1Up;
		///else motor(lift1) = 0;
		if(!(SensorValue(touchmux1) & mux_button4))
			motor(lift2) = power2Up;
		//else motor(lift2) = 0;
	}
	// neither
	else
	{
		motor(lift1) = 0;
		motor(lift2) = 0;
	}
}

task displayBattery()
{
	/*for(int i = 0; i <numOfRegisterPins - 1; i++)
	{
	registers[i] = LOW;
	}
	writeRegisters();
	digitalWrite(5, LOW);
	digitalWrite(6, LOW);
	digitalWrite(7, LOW);*/

	while(true)
	{
		if(getExtBatLevel() > 20)
			registers[4] = HIGH;
		else
			registers[4] = LOW;
		if(getExtBatLevel() > 40)
			registers[3] = HIGH;
		else
			registers[3] = LOW;
		if(getExtBatLevel() > 60)
			registers[2] = HIGH;
		else
			registers[2] = LOW;
		if(getExtBatLevel() > 80)
			registers[0] = HIGH;
		else
			registers[0] = LOW;
		if(getExtBatLevel() > 90)
			registers[1] = HIGH;
		else
			registers[1] = LOW;
		writeRegisters();


		if(getIntBatLevel() > 20)
			digitalWrite(7, HIGH);
		else
			digitalWrite(7, LOW);
		if(getIntBatLevel() > 40)
			digitalWrite(6, HIGH);
		else
			digitalWrite(6, LOW);
		if(getIntBatLevel() > 60)
			registers[6] = HIGH;
		else
			registers[6] = LOW;
		if(getIntBatLevel() > 80)
			digitalWrite(5, HIGH);
		else
			digitalWrite(5, LOW);
		if(getIntBatLevel() > 90)
			registers[5] = HIGH;
		else
			registers[5] = LOW;
		writeRegisters();

		wait1Msec(10000);
	}
}

// Code for LEDs
bool readSwitch(int switchToRead)
{
	int succeses = 0;

	if(HTSPBreadADC(HTSPB, switchToRead, 10) > 1000)	succeses++;
	wait1Msec(100);
	if(HTSPBreadADC(HTSPB, switchToRead, 10) > 1000)	succeses++;
	wait1Msec(100);
	if(HTSPBreadADC(HTSPB, switchToRead, 10) > 1000)	succeses++;
	wait1Msec(100);
	if(HTSPBreadADC(HTSPB, switchToRead, 10) > 1000)	succeses++;
	wait1Msec(100);
	if(HTSPBreadADC(HTSPB, switchToRead, 10) > 1000)	succeses++;
	wait1Msec(100);
	if(HTSPBreadADC(HTSPB, switchToRead, 10) > 1000)	succeses++;
	wait1Msec(100);


	return succeses > 4;
}

void strobe(byte data)
{
	memset(HTSPB_I2CRequest, 0, sizeof(tByteArray));
	HTSPB_I2CRequest[0] = 3;                         // Message size
	HTSPB_I2CRequest[1] = HTSPB_I2C_ADDR;             // I2C Address
	HTSPB_I2CRequest[2] = HTSPB_OFFSET + HTSPB_STROBE; // Start digital output read address
	HTSPB_I2CRequest[3] = data;                      // The specified digital ports
	writeI2C(HTSPB, HTSPB_I2CRequest);
	wait1Msec(protoDelay); // Wait for a bit
}
byte strobeData = 0;
void setLed(int led, bool state)
{
	// TOP RED
	if(led == 1)
	{
		if(state)
			strobeData = strobeData | BIT4O;
		else
			strobeData = strobeData & BIT4A;
		strobe(strobeData);
	}
	// TOP GREEN
	if(led == 2)
	{
		if(state)
			strobeData = strobeData | BIT2O;
		else
			strobeData = strobeData & BIT2A;
		strobe(strobeData);
	}
	// TOP BLUE
	if(led == 3)
	{
		if(state)
			strobeData = strobeData | BIT3O;
		else
			strobeData = strobeData & BIT3A;
		strobe(strobeData);
	}

	// BOTTOM RED
	if(led == 4)
	{
	HTSPBwriteAnalog(HTSPB, HTSPB_DACO1,DAC_MODE_DCOUT,1, state ? 1023:0);
	}
	// BOTTOM GREEN
	if(led == 5)
	{
	HTSPBwriteAnalog(HTSPB, HTSPB_DACO0,DAC_MODE_DCOUT,1, state ? 1023:0);
	}

	// BOTTOM BLUE
	if(led == 6)
	{
		if(state)
			strobeData = strobeData | BIT1O;
		else
			strobeData = strobeData & BIT1A;
		strobe(strobeData);
	}


}

task fadeLights()
{
	int min = 3;
	int max = 100;
	int time = 6;
	while(true)
	{
		for(int i = min; i < max; i++)
		{
			motor[lights] = i;
			wait1Msec(time);
		}

		for(int i = max; i > min; i--)
		{
			motor[lights] = i;
			wait1Msec(time);
		}
	}
}


void setup()
{
	setLed(2, false);
	HTGYROstartCal(gyroSensor);
	writeDebugStream("Starting...");
	// Calculate offset
	startTask(getHeading);


	// Preform protoboard setup
	StartTask(phoenix);
	nNxtExitClicks = 5;
	pinMode(SER_Pin, OUTPUT);
	pinMode(RCLK_Pin, OUTPUT);
	pinMode(SRCLK_Pin, OUTPUT);
	pinMode(5, OUTPUT);
	pinMode(6, OUTPUT);
	pinMode(7, OUTPUT);
	//clearRegisters();
	//writeRegisters();
	startTask(displayBattery);
	startTask(fadeLights);
	// Protoboard setup done




	offset = currHeading;

	setLed(2, true);
	// Wait for the start of the match
	//waitForStart(); // THIS SHOULD BE UNCOMMENTED
}


int place = 1;
// 0 = fully down
// 1 = fully up


void block(bool position)
{
	if(position)
		servo[blocker] = 150;
	else
		servo[blocker] = 255;
}

// Like sort of half down position ish
void setHolderCenter()
{
	servo(holder1) = 200;
	servo(holder2) = 255 - 233;
}

// Touch sensors are in port 1

task main()
{

	int mod = 1;
	bool holder = false;
	setup();

	// TEST THIS

	//motor[lights] = 100;
	//while(true){}

	/*while(true){

	nxtDisplayBigStringAt(20,20, "%d", HTSMUXreadAnalogue(presetLeft));
	wait1Msec(10);
	eraseDisplay();
	}*/

	nMotorEncoder[lift1] = 0;
	nMotorEncoder[lift2] = 0;
	//waitForStart();

	while(true)
	{
		getJoystickSettings(joystick);

		if(joy1Btn(1))
		{
			mod = mod * -1;
			while(joy1Btn(1)){}
		}

		if(mod == 1)
		{
		motor[left] = abs(joystick.joy1_y2) < 7 ? 0 : joystick.joy1_y2 * mod;
		motor[right] = abs(joystick.joy1_y1) < 7 ? 0 : joystick.joy1_y1 * mod;
		}
		else
		{
		motor[right] = abs(joystick.joy1_y2) < 7 ? 0 : joystick.joy1_y2 * mod;
		motor[left] = abs(joystick.joy1_y1) < 7 ? 0 : joystick.joy1_y1 * mod;
		}

		int power = 100;
		// For paddle
		if(joy1Btn(4))
		{

			motor(flicker1) = power;
			//motor(flicker2) = -1 * power;
		}
		else
		{
			motor(flicker1) = 0;
			//motor(flicker2) = 0;
		}

		// For gate
		if(joy1Btn(3))
		{

			servo(gate) = 140;
		}
		else
		{
			servo[gate] = 55;
		}

		if(joy1Btn(2))
		{
			holder = !holder;
			while(joy1Btn(2)){}
		}

		if(!SensorValue(touchmux1) & mux_button3 || !SensorValue(touchmux1) & mux_button1)
		{
			setHolderCenter();
		}
		else if(holder)
		{// down position
			servo(holder1) = 185;
			servo(holder2) = 255 - 205;

		}
		else
		{// up position

			servo(holder1) = 225;
			servo(holder2) = 255 - 245;
		}


		// ADJUST THIS

		//writeDebugStream("%d %d \n", nMotorEncoder[lift1], nMotorEncoder[lift2];
		/*wait1Msec(100);
		if(nMotorEncoder[lift1]  < nMotorEncoder[lift2])
		{

		power1 = 50;
		power2 = 100;
		}
		else
		{
		power1 = 100;
		power2 = 50;
		}*/

		if(SensorValue(touchmux1) & mux_button3 || SensorValue(touchmux1) & mux_button1)
		{
			block(true);
		}
		else
		{
			block(false);
		}

		if(joy1Btn(10))
		{
			if(!TSReadState(presetLeft))
			{
				motor(lift1) = power1Up;
			}
			else
			{
				motor(lift1) = 0;
			}
			if(!TSReadState(presetRight))
			{
				motor(lift2) = power2Up;
			}
			else
			{
				motor(lift2) = 0;
			}
		}
		else if(joystick.joy1_TopHat == 2)
		{
			motor(lift1) = power1Down;
		}
		else if(joystick.joy1_TopHat == 6)
		{
			motor(lift2) = power2Down;
		}
		else
		{
			// Down
			if(joy1Btn(5) == true)
			{
				lift(0);
			}
			else if(joy1Btn(6) == true)
			{
				lift(1);
			}
			else
			{
				lift(2);
			}
		}

		// Place is desired position
		// Lift2 is slower
		// For lift up
		/*if(place == 1 && !(SensorValue(touchmux1) & mux_button1))
		motor(lift1) = 50;
		else if(place == 0 && )
		motor(lift1) = -50;
		else
		motor(lift1) = 0;

		if(place == 1 && !(SensorValue(touchmux1) & mux_button3))
		motor(lift2) = -60;
		else if(place == 0 && )
		motor(lift2) = 60;
		else
		motor(lift2) = 0;*/



	}

}
