#ifndef MOVEMENT_H
#define MOVEMENT_H
#include "struct.h"
#include "Camera.h"

class Movement
{
    public:
        Movement();
        virtual ~Movement();
        void moveForward(Camera** camera,float step);
        void moveSide(Camera** camera,float step);
    protected:

    private:
};

#endif // MOVEMENT_H
