#include "Circle.h"
#include <cmath>

void Circle::draw(PgmPicture & screen) const 
{

  for(int i=0;i<screen.getHeight();i++)
    for(int j=0;j<screen.getWidth();j++)
    {
      if(sqrt(pow(i-y,2)+pow(j-x,2))<radius)
        screen.setColor(i,j,color);
    }
}

void Circle:: move(int  nx,int ny) {
    x=nx;
    y=ny;
}
