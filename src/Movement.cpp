#include "Movement.h"
#include <cmath>
#define M_PI 3.14

Movement::Movement()
{
    //ctor
}

Movement::~Movement()
{
    //dtor
}

void Movement::moveForward(Camera** camera,float step)
{
	float yaw = (*camera)->yaw;
	float stepx=-step*sin(yaw*M_PI/180.0f);
	float stepz=-step*cos(yaw*M_PI/180.0f);
	(*camera)->x+=stepx;
	(*camera)->z+=stepz;
}

void Movement::moveSide(Camera** camera,float step)
{
	float yaw = (*camera)->yaw-90.0f;
	float stepx=-step*sin(yaw*M_PI/180.0f);
	float stepz=-step*cos(yaw*M_PI/180.0f);
	(*camera)->x+=stepx;
	(*camera)->z+=stepz;
}
