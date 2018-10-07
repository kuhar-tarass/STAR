#include "Brevno.hpp"

Brevno::Brevno(){}
Brevno::Brevno(Brevno const &a){*this = a;}
Brevno &Brevno::operator=(Brevno const &a){(void)a;return *this;}
Brevno::~Brevno(){
	clearObj();
}


Brevno::Brevno(Point const &a) : Bullet(a){
	set_health(300);
	add_point(Point(1, 0, '#'));
	add_point(Point(2, 0, '#'));
	add_point(Point(3, 0, '#'));
	add_point(Point(4, 0, '#'));
}
void Brevno::left(){
	Object::left();
	Object::left();
	Object::left();
	get_damage(1);
	if (get_position().get_x() < 1)
		get_damage(1000);
}
