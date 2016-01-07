/** @file functions.c
 * @brief General functions to be used in the rest of the code
 *
 *
 *  Created on: Dec 17, 2015
 *      Author: tim
 **/

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
	motorSet(l1, -launcherSpeed);
	motorSet(l2, -launcherSpeed);
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
	motorSet(inL, -intakeSpeed);
	motorSet(inR, intakeSpeed);
}

/**reverses intake
 *
 **/
void reverseIntakeMotors(){
	motorSet(inL, intakeSpeed);
	motorSet(inR, -intakeSpeed);
}

/**stop intake motors
 *
 **/
void stopIntakeMotors(){
	motorSet(inL, 0);
	motorSet(inR, 0);
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



