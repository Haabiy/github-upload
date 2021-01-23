#include "Shape.h"
#include"Rectangle.h"

void Rectangle::draw(PgmPicture & screen) const 
{
    for(int i=0;i<screen.getWidth();i++){
    for(int j=0;j<screen.getHeight();j++)
    {
      if(i>=x && i<=x+ width && j>=y && j<=y+height ){
        screen.setColor(j,i,color);
      }
    }
  }
}

void Rectangle:: move(int  nx,int ny) {
    x=nx;
    y=ny;
}

