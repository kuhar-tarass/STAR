#include "Bullet.hpp"

Bullet::Bullet () {

}

Bullet::Bullet(Bullet const &src) {
	*this = src;
}

Bullet &Bullet::operator=(Bullet const &src) {
	(void)src;
	return (*this);
}

Bullet::Bullet(Point const &a): Object(a)
{
	set_health(60);
	add_point(Point(0, 0, '-'));
	add_point(Point(1, 0, '-'));
}

void Bullet::right()
{
	Object::right();
	Object::right();
	get_damage(1);
}

void Bullet::drawObj()
{
	if (get_status())
		Object::drawObj();
}

Bullet::~Bullet()
{
	clearObj();
}