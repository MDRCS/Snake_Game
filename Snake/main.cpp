//
//  main.cpp
//  Snake
//
//  Created by Mohamed El Rahali on 4/21/18.
//  Copyright © 2018 Mohamed El Rahali. All rights reserved.
//

#include <iostream>
#include <OpenGL/gl.h>
#include <GLUT/GLUT.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "Game.hpp"
#include <CoreFoundation/CoreFoundation.h>

#define COLUMNS 40
#define ROWS 40
#define FPS 20

extern short sDirection ;
bool GameOver=false ;
int score = 0 ;
void draw() ;
void reshape(int,int) ;
void timer_FPS(int) ;
void Keyboard_func(int,int,int);

void init()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    initGrid(COLUMNS,ROWS) ; 
}

int main(int argc,const char* argv[]) {
    // insert code here...
    glutInit(&argc,(char**)argv) ;
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE) ;
    glutInitWindowSize(500, 500) ;
    glutCreateWindow("Play Snake") ;
    glutDisplayFunc(draw) ;
    glutReshapeFunc(reshape) ;
    glutTimerFunc(0,timer_FPS,0) ;
    glutSpecialFunc(Keyboard_func) ;
    init() ;
    glutMainLoop() ;
    return 0;
}


void draw()
{
    glClear(GL_COLOR_BUFFER_BIT) ;
    drawGrid() ;
    drawSnake() ;
    drawFood() ; 
    glutSwapBuffers() ;
    if(GameOver)
    {
        char _score[10] ;
        sprintf(_score,"%d",score);
        char text[50] = "Your Score : " ;
        strcat(text, _score) ;
        SInt32 nRes = 0;
        CFUserNotificationRef pDlg = NULL;
        const void* keys[] = { kCFUserNotificationAlertHeaderKey,
            kCFUserNotificationAlertMessageKey };
        const void* vals[] = {
            CFSTR("Game Over"),
            CFSTR("Your Score is :")
        };
        
        CFDictionaryRef dict = CFDictionaryCreate(0, keys, vals,sizeof(keys)/sizeof(*keys),&kCFTypeDictionaryKeyCallBacks,&kCFTypeDictionaryValueCallBacks);
        
        pDlg =CFUserNotificationCreate(kCFAllocatorDefault, 0,kCFUserNotificationPlainAlertLevel,&nRes, dict);
        exit(0) ;
    }
}

void reshape(int w,int h)
{
    glViewport(0,0,(GLsizei) w,(GLsizei) h) ;
    glMatrixMode(GL_PROJECTION) ;
    glLoadIdentity() ;
    glOrtho(0.0, COLUMNS, 0.0,ROWS, -1.0, 1.0) ;
    glMatrixMode(GL_MODELVIEW);
}

void timer_FPS(int)
{
    glutPostRedisplay() ;
    glutTimerFunc(1000/FPS, timer_FPS, 0) ;
}

void Keyboard_func(int key,int,int)
{
    switch(key)
    {
            case GLUT_KEY_UP:
            if (sDirection!=DOWN) {
                sDirection = UP ;
                break ;
            }
           case GLUT_KEY_DOWN:
            if (sDirection!=UP) {
                sDirection = DOWN ;
                break ;
            }
            case GLUT_KEY_RIGHT:
            if (sDirection!=LEFT) {
                sDirection = RIGHT ;
                break ;
            }
            case GLUT_KEY_LEFT:
            if (sDirection!=RIGHT) {
                sDirection = LEFT ;
                break ;
            }
    }
}





