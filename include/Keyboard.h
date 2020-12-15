#ifndef KEYBOARD_H
#define KEYBOARD_H
#define GLUT_DISABLE_ATEXIT_HACK
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

class Keyboard
{
    public:
        Keyboard();
        virtual ~Keyboard();
        //static void keyFunc(unsigned char key, int x, int y);
        //static void specialKeys(int key, int x, int y);
    protected:

    private:
};

#endif // KEYBOARD_H
