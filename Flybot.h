#ifndef FLYBOT_H
#define FLYBOT_H

#define FLYBOT_LEN1 10
#define FLYBOT_LEN2 12
#define FLYBOT_LEN3 3
#define FLYBOT_LEN4 3

#define MOTOR1 0
#define MOTOR2 1
#define MOTORB 2

//#include <Arduino.h>
#include <ArdUnix.h>

class Flybot:ArdUnixBase{
private:
	char bStopSwitch;
	char gStopSwitch;
	char motor1, motorDir1;
	char motor2, motorDir2;
	char motorB, motorDirB;
  char motorEna;

	int step1, step2, stepB;
public:
	Flybot();
	Flybot( char b, char g, char m1, char md1, char m2, char md2, char mb, char mdb );

  void init();

	bool moveBaseTo( float theta );
	bool moveHandTo( float x, float y );
	bool moveTo( float x, float y, float theta );

	void aStep( int pin, int steps );
	bool moveMotorTo( int motor, int step );

	virtual void update( String updStr );
	virtual void updateRaw( String updStr );
};

#endif
