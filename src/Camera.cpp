#include "Camera.h"

Camera::Camera()
{
    //ctor
}

Camera::~Camera()
{
    //dtor
}

void Camera::coordinatePerspective(void)
{
	yaw = (float)(((int)yaw) % 360);
	pitch = pitch >= 90.0f ? pitch=90.0f : pitch;
	pitch = pitch <= -90.0f ? pitch=-90.0f : pitch;
	glRotatef(-pitch, 1.0f, 0.0f, 0.0f);
	glRotatef(-yaw, 0.0f, 1.0f, 0.0f);
	glTranslatef(-x, -y, -z);
}
