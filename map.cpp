#include "map.hpp"
#include <iostream>

using namespace std;

//Map class default constructor 
Map::Map()
{
    width = 200;
    height = 100;
    border = 5;
}

Map::Map(unsigned int w,unsigned int h)
{
    width = w;
    height = h;
    border = 5;
}

//Map class destructor 
Map::~Map()
{
    cout << "Map just destroyed" << endl;
}

//Auxiliary Map Functions
void Map::drawMap(HDC& hCon,COLORREF col)
{
    //Map drawing
     
    //Drawing in four parts 
    //Up line first, second right wall, third
    //floor, and last left wall

    //Draw horizontal lines of the map
    Sleep(20);
    for(int _x=1; _x < width; _x++)
    {
        for(int i=1; i < border; i++)
        {
            SetPixelV(hCon,_x,i,col); //up Wall
            SetPixelV(hCon,_x,height-i,col);  //down wall
        } 
    }
    
    Sleep(20);
    //Draw Vertical Map Lines
    for(int _y=1; _y < height; _y++)
    {
        for(int i=1; i < border; i++)
        {
            SetPixelV(hCon,i,_y,col); // Left wall
            SetPixelV(hCon,((width/2)-3)+i,_y,col);
            SetPixelV(hCon,width-i,_y,col);  //Right wall
        }
    }

    /*The included sleeps before each for loop
    are helping to draw the map correctly 
    without them the map would have some cuts
    in part of its horizontal lines*/
}

//Get Methods
unsigned int Map::getMapHeight()
{
    return height;
}

unsigned int Map::getMapWidth()
{
    return width;
}