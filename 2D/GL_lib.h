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

    /*glVertex2i(10,20);
    glVertex2i(10,40);
    glVertex2i(10,250);
    glVertex2i(10,60);*/


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
