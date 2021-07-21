#include "ball.hpp"

#define PI 3.14159265

using namespace std;

//Parametrized Constructor 
Ball::Ball(unsigned int mapWidth, unsigned int mapHeight,int dir)
{
    this->mapWidth = mapWidth;
    this->mapHeight = mapHeight;
    this->dir = dir;
    bPosX = mapWidth/2 + 10;
    bPosY = mapHeight/2;
    initialX = bPosX;
    initialY = bPosY;
    aux_bPosX = bPosX;
    aux_bPosY = bPosY;
    m = 0; //Pendiente de la recta
    size = 10;
}

//Ball Class Destructor 
Ball::~Ball()
{
    cout << "Ball object destroyed" << endl;
}

//Get Methods
unsigned int Ball::getPosX()
{
    return bPosX;
}

unsigned int Ball::getPosY()
{
    return bPosY;
}

unsigned int Ball::getSize()
{
    return size;
}


//Set Methods 
void Ball::setPosX(unsigned int x)
{
    bPosX = x;
}

void Ball::setPosY(unsigned int y)
{
    bPosY = y;
}

void Ball::setDir(int d)
{
    dir = d;
}
/*  Additional Methods */
void Ball::drawBall(HDC hCon, COLORREF col)
{
    Sleep(1);
    for(int _y=(bPosY-(size/2)), _x=(bPosX-(size/2)); _y <= (bPosY+(size/2)); _y++)
    {
        SetPixelV(hCon, _x, _y, col);
        SetPixelV(hCon, _x+size, _y, col);
    }
    Sleep(1);
    for(int _x=(bPosX-(size/2)), _y=(bPosY-(size/2)); _x <= (bPosX+(size/2)); _x++)
    {
        SetPixelV(hCon, _x, _y, col);
        SetPixelV(hCon, _x, _y+size, col);
    }
}

void Ball::moveBall()
{
    //Ball movement Behavior
    bPosX += dir*10; 
    bPosY = (m*(bPosX - aux_bPosX))+aux_bPosY;

    aux_bPosX = bPosX;
    aux_bPosY = bPosY;
}

void Ball::genSlope()
{
    //Generating line slope

    //Generate the angle that will have 
    //the ball trajectory 
    srand((unsigned)time(0));
    m = tan((1+((rand()%119) - 60))*PI/180); 
}

void Ball::invertDir()
{
    dir = -dir;
}

void Ball::invertSlope()
{
    m = -m;
}

void Ball::resetPos()
{
    bPosX = (dir == 1) ? initialX:initialX-20;
    bPosY = initialY;
    aux_bPosX = bPosX;
    aux_bPosY = bPosY;
    m = 0;
    
}

