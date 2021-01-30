#ifndef PICTURE_H
#define PICTURE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std ;

#include "RGB.h"

class PgmPicture
{
public :

  PgmPicture(int w,int h,RGB c) ;
  
  int getWidth() const { return width ; }
  int getHeight() const { return height ; }
  void setColor(int i,int j, RGB c) { pixels[i*width+j]=c; }
  RGB getColor(int i,int j) const { return pixels[i*width+j]; }

  void save(const string &name) const ;
  void load(const string &name) ;

  void saveBMP(const string &name) const ;
  void loadBMP(const string &name) ;

protected :
  int width,height;
  vector<RGB> pixels ; 
  
};

#endif
