#ifndef RANDOM_H
#define RANDOM_H
using namespace std;
#include <cstdlib>
	
int random(int max)
{
  int value = rand()%max ;
  return value ;
}

#endif
