#ifndef ENEMY_HPP
#define ENEMY_HPP
#include "Object.hpp"

class Enemy : public Object
{
	public:
	Enemy(Point const &a);
	~Enemy();

	void left();
	void drawObj();
};

#endif