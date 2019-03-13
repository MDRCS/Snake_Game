//
//  Game.hpp
//  Snake
//
//  Created by Mohamed El Rahali on 4/22/18.
//  Copyright © 2018 Mohamed El Rahali. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <iostream>
#include <OpenGL/gl.h>
#include <GLUT/GLUT.h>
#include <math.h>

#define UP 1
#define DOWN -1
#define RIGHT 2
#define LEFT -2

#define MAX 60

void initGrid(int,int) ;
void drawGrid() ; 
void drawSnake() ;
void drawFood() ;
void random(int&,int&) ; 
#endif /* Game_hpp */
