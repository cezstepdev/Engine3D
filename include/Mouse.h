#ifndef MOUSE_H
#define MOUSE_H
#define GLUT_DISABLE_ATEXIT_HACK
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

class Mouse
{
    public:
        char grab;
        int x;
        int y;

        Mouse();
        virtual ~Mouse();
        void centerCursor(int centerX, int CenterY);
    protected:

    private:
};

#endif // MOUSE_H
