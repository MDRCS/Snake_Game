//
//  Game.cpp
//  Snake
//
//  Created by Mohamed El Rahali on 4/22/18.
//  Copyright © 2018 Mohamed El Rahali. All rights reserved.
//

#include "Game.hpp"
#include <OpenGL/gl.h>
#include <GLUT/GLUT.h>
#include <ctime>

int gridX,gridY ;
int snake_length = 5 ;
short sDirection = RIGHT ;
bool Food = true ;
int FoodX,FoodY ;
int posX[60]={20,20,20,20,20} , posY[60]={20,19,18,17,16} ;
extern bool GameOver ;
extern int score ;
void initGrid(int x,int y)
{
    gridX = x ;
    gridY = y ;
}

void Unit(int,int) ;
void drawGrid()
{
    for(int i =0 ; i<gridX ; i++ )
    for(int j =0 ; j<gridY ; j++ )
    Unit(i,j) ;
}


void Unit(int x,int y)
{
    if(x==0 || y==0 || x==gridX-1 || y==gridY-1)
    {
        glLineWidth(1.0) ;
        glColor3f(1.0, 0.0, 0.0) ;
    }
    else
    {
        glLineWidth(1.0) ;
        glColor3f(0.0, 1.0, 0.0) ;
    }
    
    glBegin(GL_LINE_LOOP) ;
    glVertex2f(x,y) ;
    glVertex2f(x+1,y) ;
    glVertex2f(x+1,y+1) ;
    glVertex2f(x,y+1) ;
    glEnd() ;
}

void drawFood()
{
    if(Food)
    {
        random(FoodX, FoodY) ;
    }
    Food=false ;
    glColor3f(1.0, 0.0, 0.0) ;
    glRectf(FoodX,FoodY,FoodX+1,FoodY+1) ;
}

void drawSnake()
{
    for (int i = snake_length-1; i>0 ; i--) {
        posY[i] = posY[i-1] ;
        posX[i] = posX[i-1] ;
    }
    if(sDirection==UP) posY[0]++;
    else if(sDirection==DOWN) posY[0]-- ;
    else if(sDirection==RIGHT) posX[0]++ ;
    else if(sDirection==LEFT) posX[0]-- ;
    for (int i = 0; i< snake_length; i++) {
        if(i==0)
        {
            glColor3f(1.0, 1.0, 0.0) ;
        }
        else
        {
            glColor3f(0.0, 0.0, 1.0) ;
        }
        glColor3f(0.0, 1.0, 0.0) ;
        glRectd(posX[i], posY[i], posX[i]+1, posY[i]+1) ;
    }
    
    if(posX[0]==0 || posY[0]==0 || posY[0]==gridY-1 || posX[0]==gridX-1)
    {
        GameOver=true;
    }

    if(posX[0]==FoodX && posY[0]==FoodY)
    {
        score++ ;
        snake_length++ ;
        if(snake_length>MAX)
            snake_length = MAX ;
        Food = true ;
    }
}



void random(int &x,int &y)
{
    int _maxX = gridX-2 ;
    int _maxY = gridY-2 ;
    int _min = 1 ;
    srand(time(NULL)) ;
    x = _min + rand() % (_maxX-_min) ;
    y = _min + rand() % (_maxY-_min) ;
    
}
