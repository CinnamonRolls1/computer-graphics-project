#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#ifdef _WIN32
  #include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif
#include<stdio.h>
#include<stdlib.h>
#include <iostream>



using namespace std;


#include "GL_lib.h"

GLfloat x[10],y[10];
int n;



void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINE_LOOP);
    for(int k=0;k<n;k++)
    {
        glVertex2f(x[k],y[k]);
    }
    glEnd();

    scanfill(x,y,n);

    glFlush();
}

void init()
{
    glClearColor(1.0,1.0,1.0,1.0);
    glColor3f(0.0,0.0,1.0);
    glPointSize(1.0);
    gluOrtho2D(0,499,0,499);
}

using namespace std;

int main(int argc,char **argv)
{
    cout<<"Enter the number of edges of the polygon : ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        printf("Enter line %d co-ordinates :  ",(i+1));
        cin>>x[i]>>y[i];
    }
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Scaline Polyfill");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}
