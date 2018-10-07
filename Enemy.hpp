#ifndef ENEMY_HPP
#define ENEMY_HPP
#include "Object.hpp"

class Enemy : public Object
{
	public:
	Enemy(Point const &a);
	Enemy(Enemy const &src);
	Enemy();
	~Enemy();
	Enemy &operator=(Enemy const &src);

	void left();
	void drawObj();
};

#endif