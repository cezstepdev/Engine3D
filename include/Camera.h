#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED
#define GLUT_DISABLE_ATEXIT_HACK
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

class Camera
{
    public:
        float pitch;
        float yaw;
        float x;
        float y;
        float z;

        Camera();
        virtual ~Camera();
        void coordinatePerspective(void);
    protected:

    private:
};
#endif // CAMERA_H_INCLUDED
