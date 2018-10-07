#ifndef BREVNO_HPP
#define BREVNO_HPP
#include "Bullet.hpp"
#include "Object.hpp"

class Brevno : public Bullet
{

	public:
		Brevno(Point const &a);
		void left();
		~Brevno();
};
#endif