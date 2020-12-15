#include "Keyboard.h"

Keyboard::Keyboard()
{
    //ctor
}

Keyboard::~Keyboard()
{
    //dtor
}

/*void Keyboard::specialKeys(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		camera->yaw += 2.0f;
		break;
	case GLUT_KEY_RIGHT:
		camera->yaw -= 2.0f;
		break;
	case GLUT_KEY_UP:
		camera->pitch += 2.0f;
		break;
	case GLUT_KEY_DOWN:
		camera->pitch -= 2.0f;
		break;
	case GLUT_KEY_F3:
		dbgScreen = dbgScreen ? 0 : 1;
		break;
	}
	glutPostRedisplay();
}

void Keyboard::keyFunc(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		exit(0);
		break;
	case 'w':case 'W':
		move->moveForward(&camera,0.1f);
		break;
	case 's':case 'S':
		move->moveForward(&camera,-0.1f);
		break;
	case 'a':case 'A':
		move->moveSide(&camera,-0.1f);
		break;
	case 'd':case 'D':
		move->moveSide(&camera,0.1f);
		break;
	case 'j':
		camera->y += 0.1f;
		break;
	case 'k':
		camera->y -= 0.1f;
		break;
	case 'm':	// Toggle mouse grab
		mouse->grab = mouse->grab? 0:1;
	}
	glutPostRedisplay();
}*/
