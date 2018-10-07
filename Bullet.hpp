#ifndef BULLET_HPP
#define BULLET_HPP
#include "Point.hpp"
#include "Object.hpp"
#include <iostream>

class Bullet : public Object
{
  public:
  	Bullet();
  	Bullet(Bullet const &src);
	Bullet(Point const &a);
	virtual ~Bullet();

	Bullet &operator=(Bullet const &src);
	void right();

	void drawObj();

};

#endif