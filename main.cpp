/*
    Game: Pong
    Developer: Juan Alberto Falcon Quezada
    Start date: 05-07-2021
    Last modification: 08-07-2021
    Description: This program recreates the pong videogame in console
*/

#include <iostream>
#include <Windows.h>

#include "player.cpp"
#include "map.cpp"
#include "ball.cpp"

using namespace std;

//Functions prototypes
void ClearScreen();
void ShowConsoleCursor(bool showFlag);

int main()
{
    //We hide cursor 
    ShowConsoleCursor(false);

    //We create game objects
    Map mymap(60,20); //We create map with size of 80x20

    /*Create object player 1
    at middle of the map in the right side,*/
    Player p1(5,((mymap.getMapHeight()/2)-2),0,1);
    Player p2(mymap.getMapWidth()-5,(mymap.getMapHeight()/2)-2,0,2,true);

    /*Create object map on initian position in the middle of the map*/
    Ball b(mymap.getMapWidth()/2,mymap.getMapHeight()/2,1); 

    ClearScreen();
    mymap.drawMap(); //Map drawing
    p1.drawPlayer(); //Player 1 Drawing
    p2.drawPlayer(); //Player 2 drawing
    p1.printScore(mymap.getMapWidth()); // Score player 1 on screen
    p2.printScore(mymap.getMapWidth()); // Score player 2 on screen

    //Main game loop
    while(true)
    {
        //We draw the ball
        b.drawBall();

        if(GetKeyState(VK_UP) & 0x8000)
        {
            //Update player up
            p1.movePlayerPosY(-1,mymap.getMapHeight()); //Move player pos coord by one
        }
        else if(GetKeyState(VK_DOWN) & 0x8000)
        {
            //Move player down
            p1.movePlayerPosY(1,mymap.getMapHeight()); //Move player pos coord by one
        }
        else if(GetKeyState(VK_ESCAPE) & 0x8000)
        {
            //If scape key pressed break cycle
            break;
        }
        else
        {
            //Check collide between players and ball
            if(b.getPosX()+1 == p2.getPlayerPosX() &&
                b.getPosY() <= p2.getPlayerPosY()+p2.getSize() &&
                b.getPosY() >= p2.getPlayerPosY())
            {
                b.invertDir();
                //Ball collides with player 2
                b.generateAngle(); //New angle for ball movement
                
            }
            else if(b.getPosX()-1 == p1.getPlayerPosX() &&
                    b.getPosY() <= p1.getPlayerPosY()+p1.getSize() &&
                    b.getPosY() >= p1.getPlayerPosY())
            {
                b.invertDir();
                //Ball collides with player 1
                b.generateAngle();
            }
            else if(b.getPosY() <= 1 || b.getPosY() >= mymap.getMapHeight()-1)
            {
                //Check if ball arrived to side walls
                //and if so invert the angle so 
                //the ball can invert its movement in y axis
                b.invertAngle();
            }
            else if(b.getPosX() >= mymap.getMapWidth())
            {
                //If ball arrives to right limit
                p1.increaseScore();
                p1.printScore(mymap.getMapWidth());
                b.resetPos();
            }
            else if(b.getPosX() == 1)
            {
                p2.increaseScore();
                p2.printScore(mymap.getMapWidth());
                b.resetPos();
            }
        }

        Sleep(100);
        b.eraseBall(mymap.getMapWidth());
        b.moveBall();
    }

    ClearScreen();
    cout << "\nThanks for playing :3 " << endl;
    return 0;
}

//Assistant Functions
void ClearScreen()
{
    cout << "\033[2J" << endl;
}

/*This functions helps to hide cursor in console*/
/*I got this function from stack overflow (link below)
Special thanks to: Captain Obvlious 
who provided the solution
/*https://stackoverflow.com/questions/18028808/remove-blinking-underscore-on-console-cmd-prompt*/
void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}