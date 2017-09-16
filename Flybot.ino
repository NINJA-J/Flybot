//#include <ArdUnix.h>
//Flybot.ino
#include <ArdUnix.h>
#include "Flybot.h"
Flybot flybot;

int led = 13;

void setup() {
  char bStopSwitch;
  char gStopSwitch;
  char motor1, motorDir1;
  char motor2, motorDir2;
  char motorB, motorDirB;
  char motorEna;

  bStopSwitch = 10;
  gStopSwitch = 9;
  //y -- motor1
  //x -- motor2
  //z -- motorB
  motor1 = 4;
  motorDir1 = 5;
  
  motor2 = 2;
  motorDir2 = 3;

  motorB = 6;
  motorDirB = 7;

  motorEna = 8;

  pinMode( motor1, OUTPUT );
  pinMode( motor2, OUTPUT );
  pinMode( motorB, OUTPUT );
  pinMode( motorDir1, OUTPUT );
  pinMode( motorDir2, OUTPUT );
  pinMode( motorDirB, OUTPUT );
  pinMode( motorEna,  OUTPUT );

  pinMode( bStopSwitch, INPUT );
  pinMode( gStopSwitch, INPUT );

  flybot.init();
	Console.begin(9600);
  flybot.moveBaseTo( 90 );
}

void loop() {
	
}
