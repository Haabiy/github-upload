
#ifndef SQUARE_H
#define SQUARE_H

using namespace std ;

#include "Rectangle.h"
#include"Shape.h"

class Square : public Rectangle
{

public :

  Square(int i,int j,int w,RGB c):Rectangle(i,j, w,w,c){;}
  
};

#endif