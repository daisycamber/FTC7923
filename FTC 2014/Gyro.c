#pragma config(Sensor, S3,     GYRO,           sensorI2CHiTechnicGyro)

float currHeading = 0;
// Gyro sensor offset
int offset;
// Task to keep track of the current heading using the HT Gyro
task getHeading () {
	float delTime = 0;
	float prevHeading = 0;
	float curRate = 0;
  while (true) {
    time1[T1] = 0;
    curRate = SensorValue[GYRO] - offset;
    if (abs(curRate) > 3) {
      prevHeading = currHeading;
      currHeading = prevHeading + curRate * delTime;
      if (currHeading > 360) currHeading -= 360;
      else if (currHeading < 0) currHeading += 360;
    }
    wait1Msec(5);
    delTime = ((float)time1[T1]) / 1000;
  }
}


task main () {

	PlaySound(soundBeepBeep);
	wait1Msec(1000);
	offset = SensorValue[GYRO];

	PlaySound(soundBeepBeep);
  StartTask(getHeading);
  wait1Msec(500);
  while (true) {

  	nxtDisplayTextLine(2, "Heading: %d", currHeading);
  	nxtDisplayTextLine(3, "Raw: %d", SensorValue[GYRO]);
  	nxtDisplayTextLine(4, "Offset: %d", offset);
  	wait1Msec(200);
  	eraseDisplay();


  }
}
