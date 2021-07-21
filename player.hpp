#include <Windows.h>

#ifndef _PLAYER_
#define _PLAYER_

/* This header files contains the class
definition for the pong player */

class Player
{
    //Player Class Data Members
    private:
        unsigned int playerPosX;
        unsigned int playerPosY;
        unsigned int auxPosX;
        unsigned int auxPosY;
        unsigned int mapWidth;
        unsigned int mapHeight;
        unsigned int playerWidth;
        int score;
        unsigned int playerNum;
        unsigned int size;
        bool machine;
        
    //Class Player Methods 
    public:
        //Constructor
        Player(int playerPosX,int playerPosY, unsigned int playerNum,bool machine=false); // Parametrized constructor 
        //Destructor definition
        ~Player();

        //Set Methods
        void setPlayerPosY(int playerPosY);
        void setScore(int score);

        //Get methods
        int getPlayerPosY();
        int getPlayerPosX();
        int getPlayerWidth();
        int getPlayerHeight();
        int getScore();
        unsigned int getSize();

        //Additional methods
        void movePlayerPosY(int mov); 
        void increaseScore();
        void drawPlayer(HDC& hCon,COLORREF col);
        void erasePlayer(HDC& hCon, COLORREF col,COLORREF erase_col);
        void printScore();
};

#endif