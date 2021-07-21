/*
    Program: Pong V2
    Developer: Juan Alberto Falcon Quezada
    Date: 05-07-2021
    Last modification: 11-07-2021
    Description: This game imitates the leyend pong game by atari
*/

//<----- Headers ----->
#include <iostream>
#include <Windows.h>

//<----- Custom Headers ----->
#include "map.cpp"
#include "player.cpp"
include "ball.cpp"

//<------ Function Prototypes ------>
void HideConsoleCursor();

//Namespace definitions 
using namespace std;

//<----- Main Program ----->
int main()
{
    //Object creation 
    Map map(600,400);
    Player p1(map.getMapWidth(),map.getMapHeight(),1);
    Player p2(map.getMapWidth(),map.getMapHeight(),2);
    Ball ball(map.getMapWidth(),map.getMapHeight(),1);

    //Some Color Variables 
    COLORREF white = RGB(255, 255, 255);
    COLORREF black = RGB(0, 0, 0);
    COLORREF green = RGB(0, 255, 0);
    COLORREF red = RGB(255, 0, 0);

    //Console Resizing Window
    HWND con = GetConsoleWindow(); //Get console Handle
    RECT ConsoleRect; //specify rectangular areas of console screen buffers
    GetWindowRect(con, &ConsoleRect); 
    //the next line resizes the console windows to 640 to 440
    MoveWindow(con, ConsoleRect.left, ConsoleRect.top, 640, 440, TRUE);

    //Get handle to device Context 
    HDC dc = GetDC(con); //Get context from console

    //Cursor Hiding
    HideConsoleCursor();

    //Map Drawing
    map.drawMap(dc, white); 
    p1.drawPlayer(dc,white);
    p2.drawPlayer(dc,white);
    ball.drawBall(dc,red);

    while(true)
    {
        ball.drawBall(dc,green);

        if(GetKeyState(VK_UP) & 8000)
        {
            //Move Player Up
            p1.movePlayerPosY(-40);
            Sleep(1);
        }
        else if(GetKeyState(VK_DOWN) & 8000)
        {
            //Move Player down
            p1.movePlayerPosY(40);
            Sleep(1);
        }
        else if(GetKeyState(VK_ESCAPE) & 8000)
        {
            cout << "------- Exiting Program ----" << endl;
            cin.get();
            break;
        }
        else
        {
            /*---- Game Logic ----*/
            //Check collide between players and ball
            if(ball.getPosX()+ball.getSize() >= p2.getPlayerPosX() &&
                ball.getPosX()+ball.getSize() <= p2.getPlayerPosX()+p2.getPlayerWidth() && 
                ball.getPosY() <= p2.getPlayerPosY()+p2.getPlayerHeight() &&
                ball.getPosY() >= p2.getPlayerPosY())
            {
                //Ball collides with player 2
                ball.genSlope();
                ball.invertDir();
            }
            else if(ball.getPosX() >= p1.getPlayerPosX() &&
                    ball.getPosX() <= p1.getPlayerPosX()+p1.getPlayerWidth() &&
                    ball.getPosY() <= p1.getPlayerPosY()+p1.getPlayerHeight() &&
                    ball.getPosY() >= p1.getPlayerPosY())
            {
                //Ball collides with player 1
                ball.genSlope();
                ball.invertDir();
            }
            else if(ball.getPosY() <= 1 || ball.getPosY() >= map.getMapHeight()-1)
            {
                //Check if ball arrived to side walls
                //and if so invert the slope so 
                //the ball can invert its movement on y axis
                ball.invertSlope();
            }
            else if(ball.getPosX() >= map.getMapWidth())
            {
                //If ball arrives to right limit
                p1.increaseScore();
                p1.printScore();
                ball.resetPos();
            }
            else if(ball.getPosX() <= 10)
            {
                //If ball touches the left limit 
                p2.increaseScore();
                p2.printScore();
                ball.resetPos();
            }
        }

        
        Sleep(20);
        ball.drawBall(dc,black);
        ball.moveBall();
        p1.erasePlayer(dc, white, black);
        p1.erasePlayer(dc, white, black);
    }

    /*The ReleaseDC function releases a 
    device context (DC), freeing it for use 
    by other applications.*/
    ReleaseDC(con,dc); 
    return 0;
}

//<----- Auxiliary Functions ------>

/*This functions helps to hide cursor in console
I got this function from stack overflow (link below)
Special thanks to: Captain Obvlious 
who provided the solution
https://stackoverflow.com/questions/18028808/remove-blinking-underscore-on-console-cmd-prompt*/
void HideConsoleCursor()
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}