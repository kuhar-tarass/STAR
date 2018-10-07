#ifndef BULLET_HPP
#define BULLET_HPP
#include "Point.hpp"
#include "Object.hpp"
#include <iostream>

class Bullet : public Object
{
  public:
	Bullet(Point const &a);
	virtual ~Bullet();

	void right();

	void drawObj();

};

#endif