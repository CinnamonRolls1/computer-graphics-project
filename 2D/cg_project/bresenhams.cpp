#include <windows.h>

#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
using namespace std;
#include "GL_lib.h"


void setupViewport(int width, int height)
{
   /* Prevent divide by zero --------------------------------------------------------------------*/
   if (height == 0) height = 1;
   /* Calculate aspect ratio --------------------------------------------------------------------*/
   float aspectRatio = (float)width / (float)height;

   /* Set viewport to cover the window ----------------------------------------------------------*/
   glViewport(0, 0, width, height);

   /* Set aspect ratio --------------------------------------------------------------------------*/
   glMatrixMode(GL_PROJECTION); /* switch to projection matrix */
   glLoadIdentity();

if (width >= height)
           gluOrtho2D(-0.1000f*aspectRatio, 1000.0f*aspectRatio, 1000.0f, 1000.0f);
   else
           gluOrtho2D(-1000.0f, 1000.0f, 1000.0, 1000.0/aspectRatio);

   gluOrtho2D(-1000.0, 1000.0, 1000.0, 1000.0);
   glMatrixMode(GL_MODELVIEW);
}


void resizeGL(int width, int height)
{
    setupViewport(width, height);
}



static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    int left_x = 400;
    int left_y  = 250;
    int right_x = 550;
    int right_y = 600;

    //cout<<slope<<endl;
   //glPushMatrix();
    drawLine(left_x, left_y, right_x, right_y);
    //glPopMatrix();

    glFlush();
}

void init()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_MODELVIEW);
    gluOrtho2D(-1000.0,1000.0,-1000.0,1000.0);
}

int main(int argc, char * argv[])
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

    glutCreateWindow("Bresenhams");
    glutInitWindowPosition(10,10);
    glutInitWindowSize(500,500);

    init();

    glutReshapeFunc(resizeGL);
    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}

