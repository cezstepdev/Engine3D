#ifndef DEBUG_H
#define DEBUG_H
#include "struct.h"
#include "Camera.h"
#include "Window.h"
#include "Mouse.h"

class Debug
{
    public:
        Debug();
        virtual ~Debug();
        void showDebugText(Mouse* mouse,Window* window,Camera* camera);
        static void printStringAt(const char *str,int x,int y);
    protected:

    private:
};

#endif // DEBUG_H
