/*Class for ball behavior and properties*/
#include <Windows.h>
#include <stdlib.h>
#include <ctime>
#include <cmath>
#include <iostream>

#ifndef _BALL_
#define _BALL_

class Ball
{
    private:
        unsigned int bPosX;
        unsigned int bPosY;
        unsigned int aux_bPosX; //this variables will help us
        unsigned int aux_bPosY; //To sabe the previous position of ball
        unsigned int initialX;
        unsigned int initialY;
        unsigned int mapWidth;
        unsigned int mapHeight;
        int dir;
        double m;
        int size;
    public:
        Ball(unsigned int mapWidth, unsigned int mapHeight, int dir); //Parametrized constructor
        ~Ball(); //Ball destructor

        //Get Methods
        unsigned int getPosX();
        unsigned int getPosY();
        unsigned int getSize();

        //Set Methods
        void setPosX(unsigned int x);
        void setPosY(unsigned int y);
        void setDir(int d);
        void resetBallPos();
        
        //Aditional methods
        void drawBall(HDC hcon, COLORREF col);
        void moveBall();
        void invertDir();
        void invertSlope();
        void resetPos();
        void genSlope();
};

#endif