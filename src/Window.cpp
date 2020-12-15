#include "Window.h"

Window::Window()
{
    width = 0;
    height = 0;
}

Window::~Window()
{
    //dtor
}

void Window::setWindowSize(int w,int h)
{
	width=(float)w;
	height=(float)h;
}

float Window::getScreenX(int x)
{
	assert(width!=0.0f);
	return (((float)x)/(width/2))-1.0f;
}

float Window::getScreenY(int y)
{
	assert(height!=0.0f);
	return (((float)-y)/(height/2))+1.0f;
}

int Window::getWindowX(float x)
{
	assert(width!=0.0f);
	return (int)((x+1.0f)*width/2);
}

int Window::getWindowY(float y)
{
	assert(height!=0.0f);
	return (int)(-(y-1.0f)*height/2);
}

int Window::getWindowDistance(int dim,float screenDistance)
{
	assert(dim!=0);
	return screenDistance*dim/2;
}

float Window::getScreenDistance(int dim,int windowDistance)
{
	assert(dim!=0);
	return ((float)windowDistance)/(dim/2);
}
