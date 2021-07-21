#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <windows.h>

#define gotoxy(x,y) (cout <<"\033["<< y <<';'<< x <<'H')

using namespace std;

//Auxiliar functions prototypes
void drawMap(int _w, int _h);
void ballMov(int w, int h);
int genSlope();

int main()
{
    int width = 60;
    int height = 20;
    
    cout << "\033[2J" << endl; //Clear screen
    drawMap(width,height);
    ballMov(width,height);

    return 0;
}

/* ------- FUNCION PARA SIMULAR EL MOVIMIENTO DE LA PELOTA ----- */
void ballMov(int w, int h)
{
    int xi = w/2;
    int yi = h/2;
    int xf = w/2;
    int yf = h/2;
    char ball = 'o';
    int dirX = 1;
    int dirY = 1;
    int m = 0;

    while(true)
    {
        //Dibujamos pelota
        gotoxy(xf,yf);
        cout << ball;
        Sleep(100);
        gotoxy(xf,yf);
        if(xf == w || xf == 1)
        {
            cout << (char)179;
        }
        else if(yf == 1 || yf == h-1)
        {
            
            cout << (char)196;
        }
        else
        {
            cout << " ";
        }
        
        
        //Calculamos nuevas posiciones X y y
        xf += dirX*2;
        yf = (m*(xf - xi))+yi; //Line ecuation

        if(xf <= 0)
        {
            xf = 1;
        }
        else if(xf >= w)
        {
            xf = w-1;
        }
        else if(yf >= h)
        {
            yf = h-1;
        }
        else if(yf <= 0)
        {
            yf = 1;
        }
        
        //Asignamos las posiciones iguales de las posiciones 
        xi = xf;
        yi = yf;
        
        //Preguntamos si hubo colision del lado derecho o izquierdo 
        if(xf >= (w-1) || xf <= 1)
        {
            //Invertimos la direccion 
            dirX = -dirX;
            
            //Generamos una pendiente
            m = genSlope();
        }
        
        //Preguntamos si hubo colision en las paredes superior o inferior
        if(yf == (h-1) || yf == 1)
        {
            //Invertimos la pendiente 
            m = -m;
        } 

        if(xf <= 0 || yf == h || xf==w || yf == 0)
        {
            //Something bad happend
            cout << "Holy crap! :c " << endl;
            cout << "Last pos x: " << xf << endl;
            cout << "Last pos y: " << yf << endl;
            cout << "Last pendiente: " << m << endl;
            break;
        }

        if(GetKeyState(VK_ESCAPE)&0x8000)
        {
            cout << "Last pos x: " << xf << endl;
            cout << "Last pos y: " << yf << endl;
            cout << "Last pendiente: " << m << endl;
            break;
        }
    }
    
}

int genSlope()
{
    srand((unsigned)time(0));
    return 1+((rand()%6) - 3);
}
/* ----- FUNCION PARA DIBUJAR MAPA ----- */
void drawMap(int _w, int _h)
{
    //Horizontal Walls
    //Drawing mhorizontal lines
    for(int i=0;i<_w;i++)
    {
        //Drawing superior line
        gotoxy(i,1);
        cout << (char)196;

        //Drawing inferior line
        gotoxy(i,_h);
        cout << (char)196;
    }
    
    //Vertical lines 
    for(int j=0;j<_h;j++)
    {
        gotoxy(0,j);
        cout << (char)179;
        
        gotoxy(_w,j);
        cout << (char)179;
    }
}