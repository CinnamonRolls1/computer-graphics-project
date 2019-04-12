#include <windows.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<math.h>
#include<stdio.h>
#include<iostream>
using namespace std;

#include "GL_lib.h"


void display();

int xmin=-100;
int ymin=-100;
int xmax=100;
int ymax=100;
int xd1[10],yd1[10],xd2[10],yd2[10];
int n;



void init(void)
{
    glClearColor(0.0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-300,300,-300,300);
}

void mykey(unsigned char key,int x,int y)
{
    if(key=='c')
    {
        clip_line(xmin, ymin, xmax, ymax, xd1, yd1, xd2, yd2, n);
    }
}



void display()
{
    display_cohen(xmin, ymin, xmax, ymax, xd1, yd1, xd2, yd2, n);
}

int main(int argc,char** argv)
{
    printf("Enter the number of lines to be drawn ( <= 10) : ");
    cin>>n;
    for(int i=0;i<n;i++)
    {
        printf("Enter line %d co-ordinates :  ",(i+1));
        cin>>xd1[i]>>yd1[i]>>xd2[i]>>yd2[i];
    }
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(100,150);
    glutCreateWindow("Cohen-Sutherland Line Clipping(2)");
    glutDisplayFunc(display);
    glutKeyboardFunc(mykey);
    init();
    glutMainLoop();
    return 0;
}

