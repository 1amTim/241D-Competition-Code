/** @file functions.c
 *
 *  Created on: Dec 8, 2015
 *      Author: tim
 */
//functions to be used in opcontrol.c and auto.c

#include "main.h"
#include <API.h>


//Checks if nautilus is loaded with a ball
int isLoaded(){
	return !digitalRead(loadSwitch);
}

//checks if nautilus is cocked
int isCocked(){
	return !digitalRead(launchSwitch);
}

//runs launcher motors at normal speed
void startLaunchMotors(){
	motorSet(l1, -110);
	motorSet(l2, -110);
}

//stops launcher motors
void stopLaunchMotors(){
	motorSet(l1, 0);
	motorSet(l2, 0);
}

//starts intake in given direction
void startIntakeMotors(){
	motorSet(intake1, -100);
	motorSet(intake2, 100);
}

void reverseIntakeMotors(){
	motorSet(intake1, 100);
	motorSet(intake2, -100);
}

void stopIntakeMotors(){
	motorSet(intake1, 0);
	motorSet(intake2, 0);
}

//loads ball into nautilus from intake
void loadNautilus(){
	startIntakeMotors(1);
	while(!isLoaded()){
		delay(2);
	}
	stopIntakeMotors();
}

//Cocks the nautilus but does not fire
void cockNautilus(){
	startLaunchMotors();
	while(!isCocked()){ //pull back
		delay(2);
	}
	stopLaunchMotors();
}

void fireNautilus(){
	startLaunchMotors();
	while(isCocked()){ //fire!
		delay(2);
	}
	stopLaunchMotors();
}




