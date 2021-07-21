//Map definition class
#include <Windows.h>

#ifndef _MAP_
#define _MAP_

class Map
{
    private:
        unsigned int width;
        unsigned int height;
        unsigned int border;
    public:
        Map(); //Default constructor 
        Map(unsigned int w,unsigned int h); //Parametrized Constructor 
        ~Map(); //Class destructor 

        //No GET or SET Methods
        unsigned int getMapHeight();
        unsigned int getMapWidth();

        // Other methods 
        void drawMap(HDC& hCon,COLORREF col);
};

#endif