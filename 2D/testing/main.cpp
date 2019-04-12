#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include <math.h>
#include <limits>

using namespace std;

#include "GL_lib.h"

int i=0;


void display()
{



    glClear(GL_COLOR_BUFFER_BIT);
    drawArc(200,0,45);


    glFlush();


}

void init()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1000.0,1000.0,-1000.0,1000.0);
}

int main(int argc, char * argv[])
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

    glutCreateWindow("Testing");
    glutInitWindowPosition(10,10);
    glutInitWindowSize(500,500);

    init();
    //glutReshapeFunc(glutReshapeWindow);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
