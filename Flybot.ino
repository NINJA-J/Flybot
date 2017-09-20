#include "Flybot.h"
Flybot flybot;

#define MOTOR_STP_1 4
#define MOTOR_DIR_1 5
#define MOTOR_STP_2 2
#define MOTOR_DIR_2 3
#define MOTOR_STP_B 6
#define MOTOR_DIR_B 7

#define MOTOR_ENA   8

#define B_STOP_SWITCH 10 //Stop Switch Under Blue  Gear
#define G_STOP_SWITCH 9  //Stop Swtich Under Green Gear

void initPins(){
  pinMode( MOTOR_STP_1, OUTPUT );
  pinMode( MOTOR_STP_2, OUTPUT );
  pinMode( MOTOR_STP_B, OUTPUT );
  pinMode( MOTOR_DIR_1, OUTPUT );
  pinMode( MOTOR_DIR_2, OUTPUT );
  pinMode( MOTOR_DIR_B, OUTPUT );
  pinMode( MOTOR_ENA  , OUTPUT );

  pinMode( B_STOP_SWITCH, INPUT );
  pinMode( G_STOP_SWITCH, INPUT );
}

void setup() {
  initPins();
  flybot.init();
  flybot.moveBaseTo( 90 );
  flybot.moveHandTo( 15, 15 );
}

void loop() {
	
}
