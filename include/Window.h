#ifndef WINDOW_H
#define WINDOW_H
#include <assert.h>

class Window
{
    public:
        float width;
        float height;

        Window();
        virtual ~Window();
        void setWindowSize(int width,int height);
        float getScreenX(int windowx);
        float getScreenY(int windowy);
        int getWindowX(float screenx);
        int getWindowY(float screeny);
        int getWindowDistance(int dimension,float screenDistance);
        float getScreenDistance(int dimension,int windowDistance);
    protected:

    private:
};

#endif // WINDOW_H
