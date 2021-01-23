#include <iostream>
#include<cmath>
using namespace std;

#include "Picture.h"
#include "Rectangle.h"
#include "Square.h"
#include "Circle.h"
#include "Random.h"

int main()
{

PgmPicture P(600,400,RGB(255,255,255)); 

    struct Dimension{
           int Xpos=0;
           int Ypos=0; 
           int width, height; 
           int r;
    };

Dimension dimrec,dimsq,dimcircle;

  cout<<"\n----------------------------------";
  cout<<"\n1. Dimensions of the Rectangle"<<endl;
  cout<<"----------------------------------\n"<<endl;

           cout<<"   o Width  = ";
           cin>> dimrec.width;

           cout<<endl;

           cout<<"   o Height = ";
           cin>> dimrec.height;

Rectangle rec(dimrec.Xpos,dimrec.Ypos,abs(dimrec.width),abs(dimrec.height),RGB(255,0,255));

  cout<<"\n----------------------------------";
  cout<<"\n2. Dimension of the Square"<<endl;
  cout<<"----------------------------------\n"<<endl;

           cout<<"   o Width  = ";
           cin>> dimsq.width;

Square sq(dimsq.Xpos,dimsq.Ypos,abs(dimsq.width),RGB(0,0,255));
  
  cout<<"\n----------------------------------";
  cout<<"\n3. Radius of the Circle"<<endl;
  cout<<"----------------------------------\n"<<endl;

           cout<<"   o Radius = ";
           cin>> dimcircle.r;

Circle C(dimcircle.Xpos,dimcircle.Ypos,abs(dimcircle.r),RGB(255,0,0)); 
  
P.loadBMP("lena");

for(int i=0;i<P.getHeight();i++)

  for(int j=0;j<P.getWidth();j++)
    {
      RGB color = P.getColor(i,j);
    #if 0

      if(color.r<=85)
        color.r = 0 ;

      if(color.g>85 && color.g<=170)
        color.g = 0 ;

      if(color.b>170)
        color.b = 0 ;

    #else
      color.r = 0 ;
      color.b = 0 ;

    #endif

      P.setColor(i,j,color);
    }

for(int i=0;i<10;i++)
  {
   rec.move(random(P.getHeight()),random(P.getWidth()));
   rec.draw(P);
  }

for(int i=0;i<10;i++)
  {
   sq.move(random(P.getHeight()),random(P.getWidth()));
   sq.draw(P);
  }

for(int i=0;i<10;i++)
  {
    C.move(random(P.getHeight()),random(P.getWidth()));
    C.draw(P);
  }

P.saveBMP("lena");

cout<<"\n------------------------";
cout<<"\nThe file is ready !\n";
cout<<"------------------------";

}
