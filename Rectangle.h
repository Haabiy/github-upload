
#ifndef RECTANGLE_H
#define RECTANGLE_H

using namespace std ;

#include "Shape.h"

class Rectangle : public Shape
{
  protected:

    int width, height;

  public :

    Rectangle(int i,int j,int w,int h, RGB c):width(w), height(h),Shape(i,j,c) {;}
    void draw(PgmPicture & screen) const;
    void move(int  nx,int ny);
    
};

#endif