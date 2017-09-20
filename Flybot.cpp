#include "Flybot.h"
#include <math.h>
#include <Arduino.h>

#define THETA_TO_STEP 1

Flybot::Flybot(){
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

	step1 = step2 = 15;
	stepB = 0;
}

Flybot::Flybot( char b, char g, char m1, char md1, char m2, char md2, char mb, char mdb ){

}

void Flybot::init(){
  digitalWrite( motorEna, LOW );
  digitalWrite( motorDir1, HIGH );
  aStep( motor1, 10 );

  digitalWrite( motorDir2, HIGH );
  aStep( motor2, 10 );

  digitalWrite( motorDirB, HIGH );
  aStep( motorB, 10 );
}

bool Flybot::moveBaseTo( float theta ){
	return moveMotorTo( motorB, theta * THETA_TO_STEP );
}
bool Flybot::moveHandTo( float x, float y ){
	float l1 = FLYBOT_LEN1;
	float l2 = FLYBOT_LEN2;
	float l3 = FLYBOT_LEN3;
	float l4 = sqrt( pow(x - l3,2) + pow( y, 2 ) );

	float beta  = acos( ( pow( l1, 2 ) + pow( l2, 2 ) - pow( l4, 2 ) ) / 2 * l1 * l2 );
	float omiga = atan( y / ( x - l3 ) );
	float theta = acos( ( pow( l1, 2 ) + pow( l4, 2 ) - pow( l2, 2 ) ) / 2 * l1 * l4 );
	float alpha = 3.1415926 - omiga - theta;
	float fai   = alpha - beta;

	int stepS1 = alpha * THETA_TO_STEP;
	int stepS2 = beta  * THETA_TO_STEP;

	return moveMotorTo( MOTOR1, stepS1 ) && moveMotorTo( MOTOR2, stepS2 );
}
void Flybot::aStep( int pin, int steps ){
	for( int i = 0; i < steps; i++ ){
		digitalWrite( pin, HIGH );
		delay(10);
		digitalWrite( pin, LOW );
		delay(10);
	}
}
bool Flybot::moveMotor( int motor, int step ){
	switch(motor){
		case MOTOR1:
			if( step + step1 < 0 ) return false;
			digitalWrite( motor1, step > 0 ? HIGH : LOW ); 
			aStep( motor1, abs( step ) );
			step1 += step;
			return true;
		case MOTOR2:
			if( step + step2 < 0 ) return false;
			digitalWrite( motor2, step > 0 ? HIGH : LOW ); 
			aStep( motor2, abs( step ) );
			step2 += step;
			return true;
		case MOTORB: 
			if( step + stepB < 0 ) return false;
			digitalWrite( motorB, step > 0 ? HIGH : LOW ); 
			aStep( motorB, abs( step ) );
			stepB += step;
			return true;
	}
	return false;
}
bool Flybot::moveMotorTo( int motor, int step ){
	if( step < 0 )
		return false;
	switch(motor){
		case MOTOR1: return moveMotor( motor, step - step1 );
		case MOTOR2: return moveMotor( motor, step - step2 );
		case MOTORB: return moveMotor( motor, step - stepB );
	}
	return false;
}
bool Flybot::moveTo( float x, float y, float theta ){
	return moveHandTo( x, y ) && moveBaseTo( theta );
}

// void Flybot::update( String updStr ){
// 	String cmd = Console.strSplict( updStr );
// 	if( cmd == "-forward-1" ) moveMotor( MOTOR1,  100 );
// 	if( cmd == "-back-1" )    moveMotor( MOTOR1, -100 );

// 	if( cmd == "-forward-2" ) moveMotor( MOTOR2,  100 );
// 	if( cmd == "-back-2" )    moveMotor( MOTOR2, -100 );

// 	if( cmd == "-forward-b" ) moveMotor( MOTORB,  100 );
// 	if( cmd == "-back-b" )    moveMotor( MOTORB, -100 );
// }
// void Flybot::updateRaw( String updStr ){

// }
