#ifndef BREVNO_HPP
#define BREVNO_HPP
#include "Bullet.hpp"
#include "Object.hpp"

class Brevno : public Bullet
{
	private:
		Brevno();
		Brevno(Brevno const &a);
		Brevno &operator=(Brevno const&a);
	public:
		Brevno(Point const &a);
		~Brevno();
		void left();
};
#endif