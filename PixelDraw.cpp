/*
    Add to the Linker flags to compile 
     -lgdi32 
*/

#include <Windows.h>
#include <iostream>

int main()
{
    //Get Console Handle
    HWND con = GetConsoleWindow();
    //Get handle to device Context
    HDC hdc = GetDC(con);

    //A way to set color
    //COLORREF COLOR = RGB(255,255,255);

    for(int x=0;x<256;x++)
    {
        for(int y=0;y<256;y++)
        {
            SetPixel(hdc,x,y,RGB(127,x,y));
        }
    }

    ReleaseDC(con,hdc);
    std::cin.get();
    return 0;
}