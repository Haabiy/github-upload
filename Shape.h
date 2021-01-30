#ifndef SHAPE_H
#define SHAPE_H

#include <string>
using namespace std ;

#include "RGB.h"
#include "Picture.h"


class Shape
{
protected :

  int x,y;
  RGB color;
  
public :

  Shape(){;}
  Shape(int i,int j, RGB c) : x(i), y(j), color(c) {;} 
  int getX() const { return x ; } 
  int getY() const { return y ; } 
  void draw(PgmPicture & screen) const ;
  void move(int nx,int ny);
 
};


#endif
