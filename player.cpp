#include "player.hpp"
#include <iostream>

//MACROS

using namespace std;

//Class player Parametrized constructor 
Player::Player(int mapWidth,int mapHeight, unsigned int playerNum,bool machine)
{
    this->mapHeight = mapHeight;
    this->mapWidth = mapWidth;
    this->playerNum = playerNum;
    this->machine = machine;
    size = 60;
    playerWidth = 15; 
    playerPosX = (playerNum == 1) ? 25: mapWidth-35; //if player 1 pos to the left else to the right side
    playerPosY = (mapHeight/2)-(size/2); //Player pos at middle of the map 
    auxPosX = playerPosX;
    auxPosY = playerPosY; 
    score = 0;
}

//Class player destructor 
Player::~Player()
{
    //cout << "Destroyed player: " << playerNum << endl;
}

//Get Methods
int Player::getPlayerPosY()
{
    return playerPosY;
}

int Player::getPlayerPosX()
{
    return playerPosX;
}

int Player::getScore()
{
    return score;
}

unsigned int Player::getSize()
{
    return size;
}

int Player::getPlayerWidth()
{
    return playerWidth;
}

int Player::getPlayerHeight()
{
    return size;
}

//Set Methdos 
void Player::setPlayerPosY(int playerPosY)
{
    this->playerPosY = playerPosY;
}

void Player::setScore(int score)
{
    this->score = score;
}

//Other methods of the class
void Player::movePlayerPosY(int mov)
{
    if(((playerPosY+mov) < (mapHeight-size) && (playerPosY+mov) >= 10))
    {
        playerPosY += mov;
    }
}

void Player::increaseScore()
{
    score++;
}

//We draw the player
void Player::drawPlayer(HDC& hCon,COLORREF col)
{
    Sleep(1);
    for(int _y=playerPosY; _y <= (playerPosY+size); _y++)
    {
        for(int i=playerPosX; i<(playerPosX+playerWidth); i++)
        {
            SetPixelV(hCon,i,_y,col);
        }
    }
}

//Erase player
void Player::erasePlayer(HDC& hCon,COLORREF col,COLORREF erase_col)
{
   //Erasing the part of the player 
   if(playerPosY < auxPosY)
   {
       //Player went up

       //We erase the part of the player that we dont need
       //And raw just the part that moved 
       Sleep(5);
       for(int _y=auxPosY+size; _y >= (playerPosY+size); _y--)
       {
           for(int i=playerPosX; i<(playerPosX+playerWidth); i++)
            {
                SetPixelV(hCon,i,_y,erase_col);
                SetPixelV(hCon,i,_y-size,col);
            }
       }
       auxPosY = playerPosY;
   }
   else if(playerPosY > auxPosY)
   {
       //Player went down
       Sleep(5);
       for(int _y=auxPosY; _y <= playerPosY; _y++)
       {
           for(int i=playerPosX; i<(playerPosX+playerWidth); i++)
            {
                SetPixelV(hCon,i,_y,erase_col);
                SetPixelV(hCon,i,_y+size,col);
            }
       }
       auxPosY = playerPosY;
   }
}

void Player::printScore()
{
    //Here we will print player score
    cout << score;
}