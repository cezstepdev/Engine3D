#define GLUT_DISABLE_ATEXIT_HACK
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#define FPS 20
#define GRAVITY	0.02f	// Gravity

#include "Camera.h"
#include "Debug.h"
#include "Window.h"
#include "Movement.h"
#include "Mouse.h"

bool dbgScreen=0;
Window *window;
Debug *debug;
Movement *move;
Camera *camera;
Mouse *mouse;

void drawLevel(void)
{
	glColor3f(0.0f,1.0f,0.0f);
	glutWireSphere(5,100,100);
}

void cross(size_t width,size_t height)
{
	float x1=-window->getScreenDistance(window->width,width/2);
	float y1=window->getScreenDistance(window->height,height/2);
	float x2=window->getScreenDistance(window->width,width/2);
	float y2=-window->getScreenDistance(window->height,height/2);
	glPushMatrix();
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0,window->width,0,window->height);
	glPushMatrix();
	glLoadIdentity();
	glPushAttrib(GL_LINE_BIT);
	glColor3f(1.0f,1.0f,1.0f);
	glLineWidth(2.0f);
	glScalef(0.5f,0.5f,0.5f);
	glBegin(GL_LINES);
	glVertex2f(x1,0.0f);
	glVertex2f(x2,0.0f);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(0.0f,y1);
	glVertex2f(0.0f,y2);
	glEnd();
	glPopAttrib();
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}

void display(void)
{
	glPushMatrix();
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);
	camera->coordinatePerspective();
	drawLevel();
	glPopMatrix();
	cross(50,50);
	if(dbgScreen)
    {
		debug->showDebugText(mouse,window,camera);
	}
	glFlush();
}

void frameFunc(int arg)
{
	glutPostRedisplay();
	if(mouse->grab==1)
    {
		mouse->centerCursor(window->getWindowX(0), window->getWindowY(0));
	}
	glutTimerFunc(1000 / FPS, &frameFunc, 0);
}

void keyFunc(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		exit(0);
		break;
	case 'w':case 'W':
		move->moveForward(&camera,0.5f);
		break;
	case 's':case 'S':
		move->moveForward(&camera,-0.5f);
		break;
	case 'a':case 'A':
		move->moveSide(&camera,-0.5f);
		break;
	case 'd':case 'D':
		move->moveSide(&camera,0.5f);
		break;
	case 'j':
		camera->y += 0.5f;
		break;
	case 'k':
		camera->y -= 0.5f;
		break;
	case 'm':
		mouse->grab = mouse->grab? 0:1;
	}
	glutPostRedisplay();
}

void specialKeys(int key, int x, int y)
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

void reshape(int w, int h) {
	glViewport(0, 0, w, h);
	window->width = w;
	window->height = h;
	window->setWindowSize(w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, ((float)w) / ((float)h), 0, 10);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glutPostRedisplay();
}

void motionFunc(int x, int y)
{
	mouse->x = x;
	mouse->y = y;
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
    window = new Window();
    debug = new Debug();
    move = new Movement();
    camera = new Camera();
    mouse = new Mouse();

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(1000, 600);
	glutCreateWindow("Engine3D");
	glutReshapeFunc(&reshape);
	glutDisplayFunc(&display);
	glutSpecialFunc(&specialKeys);
	glutPassiveMotionFunc(&motionFunc);
	glutKeyboardFunc(&keyFunc);
	glutTimerFunc(1000 / FPS, &frameFunc, 0);
	glutMainLoop();
	return 0;
}
