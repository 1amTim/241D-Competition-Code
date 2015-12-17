/*
 * functions.c
 *
 *  Created on: Dec 17, 2015
 *      Author: tim
 */

#include "main.h"

/**Checks if nautilus is loaded with a ball
 *
 **/
int isLoaded(){
	return !digitalRead(loadSwitch);
}

/**checks if nautilus is cocked
 *
 */
int isCocked(){
	return !digitalRead(launchSwitch);
}

/**runs launcher motors at normal speed
 *
 */
void startLaunchMotors(){
	motorSet(l1, -110);
	motorSet(l2, -110);
}

/**stops launcher motors
 *
 */
void stopLaunchMotors(){
	motorSet(l1, 0);
	motorSet(l2, 0);
}

/**intake balls + load launcher
 *
 **/
void startIntakeMotors(){
	motorSet(intake1, -100);
	motorSet(intake2, 100);
}

/**reverses intake
 *
 **/
void reverseIntakeMotors(){
	motorSet(intake1, 100);
	motorSet(intake2, -100);
}

/**stop intake motors
 *
 **/
void stopIntakeMotors(){
	motorSet(intake1, 0);
	motorSet(intake2, 0);
}

/**loads ball into nautilus from intake
 *
 **/
void loadNautilus(){
	startIntakeMotors(1);
	while(!isLoaded()){
		delay(2);
	}
	stopIntakeMotors();
}

/**Cocks the nautilus but does not fire
 *
 **/
void cockNautilus(){
	startLaunchMotors();
	while(!isCocked()){ //pull back
		delay(2);
	}
	stopLaunchMotors();
}
/** Fires the launcher
 *
 **/
void fireNautilus(){
	startLaunchMotors();
	while(isCocked()){ //fire!
		delay(2);
	}
	stopLaunchMotors();
}

/** Telemetry Display
 *  	Displays Battery voltage, shots fired
 **/
void telemDisp(){
	lcdPrint(uart1, 1, "hi");

}


