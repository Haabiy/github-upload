#ifndef CIRCLE_H
#define CIRCLE_H

#include <string>
using namespace std ;

#include "Picture.h"
#include "Shape.h"

class Circle : public Shape
{

protected :

  int radius ;

public :

  Circle(int i,int j,int r, RGB c) : Shape(i,j,c), radius(r) {;}
  void draw(PgmPicture & screen) const  ;
  void move(int  nx,int ny);

};

#endif
