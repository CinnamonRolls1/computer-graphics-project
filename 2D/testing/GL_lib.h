#include <iostream>
#include <cmath>


struct point
{
    int x;
    int y;
};

point case1(point p)
{
    return p;
}

point case2(point p)
{
    int a = p.x;
    p.x = p.y;
    p.y = a;

    return p;
}

point case3(point p)
{
    p.x = -p.x;

    return p;
}


point case4(point p)
{
  int a= -p.y;
  p.y = p.x;
  p.x = a;
  return p;
}

point reverse_case4(point p)
{
  int a= -p.x;
  p.x = p.y;
  p.y = a;
  return p;
}


void perform_bresenhams(point left, point right, point translate(point))
{
    if(translate == case4)
    {
        int dy = right.y - left.y;
        int dx = right.x - left.x;
        int p0 = (2 * dy) - dx;
        int constant = 2*dy - 2*dx;

        int pk = p0;
        point k = left;
        //cout<< pk << " " << dy << " " << dx << " " << constant << endl;
        cout<<left.x<<" "<<left.y<<endl;
        cout<<right.x<<" "<<right.y<<endl;


        left = reverse_case4(left);
        right = reverse_case4(right);

        cout<<left.x<<" "<<left.y<<endl;
        cout<<right.x<<" "<<right.y<<endl;

        glVertex2i(left.x,left.y);
        glVertex2i(right.x,right.y);
        cout<<endl;
        for(int i = 1; i < dx; i++)
        {
            if(pk < 0)
            {
                //cout<<"if case"<<endl;
                k.x += 1;
                cout<<k.x<<" "<<k.y<<endl;

                k = reverse_case4(k);
                glVertex2i(k.x, k.y);

                k = translate(k);

                pk = pk + 2*dy;
            }

            else
            {
                //cout<<"else case"<<endl;
                k.x += 1;
                k.y += 1;


                k = reverse_case4(k);
                glVertex2i(k.x, k.y);


                k = translate(k);

                pk = pk + constant;
            }
        }


    }

    else
    {

        int dy = right.y - left.y;
        int dx = right.x - left.x;
        int p0 = (2 * dy) - dx;
        int constant = 2*dy - 2*dx;

        int pk = p0;
        point k = left;
        //cout<< pk << " " << dy << " " << dx << " " << constant << endl;
        cout<<left.x<<" "<<left.y<<endl;
        cout<<right.x<<" "<<right.y<<endl;


        left = translate(left);
        right = translate(right);

        cout<<left.x<<" "<<left.y<<endl;
        cout<<right.x<<" "<<right.y<<endl;

        glVertex2i(left.x,left.y);
        glVertex2i(right.x,right.y);
        cout<<endl;
        for(int i = 1; i < dx; i++)
        {
            if(pk < 0)
            {
                //cout<<"if case"<<endl;
                k.x += 1;
                cout<<k.x<<" "<<k.y<<endl;

                k = translate(k);
                glVertex2i(k.x, k.y);

                k = translate(k);

                pk = pk + 2*dy;
            }

            else
            {
                //cout<<"else case"<<endl;
                k.x += 1;
                k.y += 1;


                k = translate(k);
                glVertex2i(k.x, k.y);


                k = translate(k);

                pk = pk + constant;
            }
        }
    }
}

void align(point &left, point &right)
{
        if(right.y < left.y)
    {
        swap(left, right);
    }
}

void drawCircle(int R, int a, int b)
{
    glBegin(GL_POINTS);
    int x = 0;
    int y = R;

    int h = 1 - R;
    int dE = 3;
    int dSE = (-2 * R) + 5;

    while (x < y)
    {


        if(h < 0)
        {
            h+=dE;
            dE+=2;
            dSE+=2;
        }

        else
        {
            h+=dSE;
            dE+=2;
            dSE+=4;
            y--;
        }
        x++;
        glVertex2i(a+x, b+y);
        glVertex2i(a+y, b+x);
        glVertex2i(a+x, b-y);
        glVertex2i(a-y, b+x);
        glVertex2i(a-x, b+y);
        glVertex2i(a+y, b-x);
        glVertex2i(a-x, b-y);
        glVertex2i(a-y, b-x);
    }
    glEnd();


}

void drawArcPoint(float x, float y, double M1, double M2, bool clockW){
    double m1=y/x;
    double m2=x/y;
    double m3=-y/x;
    double m4=x/-y;
    double m5=y/-x;
    double m6=-x/y;
    double m7=-y/-x;
    double m8=-x/-y;

    double slopes[]={m1,m2,m3,m4,m5,m6,m7,m8};
    //float funcs[][] = {{x, y},{y, x},{x, -y},{-y, x},{-x, y},{y, -x},{-x, -y},{-y, -x}};
    for(int i=0;i<8;i++){
        if(clockW==TRUE){
            if((M1<slopes[i]) && (slopes[i]<M2)){
                switch(i){
                    case 0: glVertex2f(x, y); break;
                    case 1: glVertex2f(y, x); break;
                    case 2: glVertex2f(x, -y); break;
                    case 3: glVertex2f(-y, x); break;
                    case 4: glVertex2f(-x, y); break;
                    case 5: glVertex2f(y, -x); break;
                    case 6: glVertex2f(-x, -y); break;
                    case 7: glVertex2f(-y, -x); break;
                }

            }
        }
        else{
            if((M2<slopes[i]) && (slopes[i]<M1)){
                switch(i){
                    case 0: glVertex2f(x, y); break;
                    case 1: glVertex2f(y, x); break;
                    case 2: glVertex2f(x, -y); break;
                    case 3: glVertex2f(-y, x); break;
                    case 4: glVertex2f(-x, y); break;
                    case 5: glVertex2f(y, -x); break;
                    case 6: glVertex2f(-x, -y); break;
                    case 7: glVertex2f(-y, -x); break;
            }

            }
        }

    }

}

void drawArc(int R, float ang1, float ang2, bool clockW=FALSE)
{
    glBegin(GL_POINTS);

    ang1=ang1 * (M_PI/180.0);
    ang2=ang2 * (M_PI/180.0);

    cout<<ang1<<" "<<ang2<<endl;

    double M1=tan(ang1);

    if((ang1==M_PI_2) || (ang1==3*M_PI_2)){
        M1= std::numeric_limits<double>::infinity();
    }
    double M2=tan(ang2);
    //cout<<M2<<endl;
    if((ang2==M_PI_2) || (ang1==3*M_PI_2)){
        M2= std::numeric_limits<double>::infinity();
    }
    cout<<M1<<" "<<M2<<endl;

    float x = 0;
    float y = R;

    int h = 1 - R;
    int dE = 3;
    int dSE = (-2 * R) + 5;

    while (x < y)
    {


        if(h < 0)
        {
            h+=dE;
            dE+=2;
            dSE+=2;
        }

        else
        {
            h+=dSE;
            dE+=2;
            dSE+=4;
            y--;
        }
        x++;
        drawArcPoint(x,y, M1, M2, clockW);

    }
    glEnd();


}

void draw_ellipse(int x, int y, int coordx, int coordy){
    glBegin(GL_POINTS);
    glVertex2i(x+coordx, y+coordy);
    glVertex2i(x+coordx, coordy-y);
    glVertex2i(coordx-x, coordy+y);
    glVertex2i(coordx-x, coordy-y);
    glEnd();

}

void ellipse(int a, int b, int coordx, int coordy){
    double d2;
    int x = 0;
    int y = b;
    int sa=a*a;
    int sb=b*b;
    double d1 = sb - sa*b + 0.25*sa;
    draw_ellipse(x,y,coordx,coordy);
    while((sa*(y-0.5)) > (sb*(x+1))){  //Region 1
        if (d1<0){ //E
            d1+=sb*(2*x+3);
        }
        else{ //SE
            d1+=sb*(2*x+3)+sa*(-(2*y)+2);
            y=y-1;
        }
        x=x+1;
        draw_ellipse(x,y,coordx,coordy);
    }
    d2 = sb*(x+0.5)*(x+0.5) + sa*(y-1)*(y-1) - sa*sb;
    while (y>0){ //Region 2
        if (d2<0){ //SE
            d2+=sb*(2*x+2) + sa*(-(2*y)+3);
            x=x+1;
        }
        else{ //S
            d2+=sa*(-(2*y)+3);
        }
        y=y-1;
        draw_ellipse(x,y,coordx,coordy);

    }

}


 void bresenhams_decision(point left, point right, double slope)
 {
    if(slope > 0)
    {
        if(slope > 1)
        {
            left = case2(left);
            right = case2(right);

            align(left,right);

            perform_bresenhams(left, right, case2);
        }

        else
        {
            perform_bresenhams(left, right, case1);
        }
    }

    else
    {
        if(abs(slope) < 1)
        {
            left = case3(left);
            right =  case3(right);
            align(left, right);

            perform_bresenhams(right, left, case3);
        }

        else
        {
            left = case4(left);
            right = case4(right);
            align(left, right);

            perform_bresenhams(left,right,case4);
        }
    }

 }


 void drawLine(int point1_x, int point1_y, int point2_x, int point2_y, double pointSize = 1.0, double r = 1.0, double g = 1.0, double b = 1.0)
 {
     point p1 ;
     p1.x = point1_x;
     p1.y = point1_y;

     point p2;
     p2.x = point2_x;
     p2.y = point2_y;

     double slope = (point2_y - point1_y)*1.0 / (point2_x - point1_x);

     glPointSize(pointSize);
     glColor3f(r, g, b);

     glBegin(GL_POINTS);

     bresenhams_decision(p1,p2,slope);

     glEnd();
 }
