#include "Ship.hpp"

Ship::Ship(){
	set_health(100);
	add_point(Point(1, 0, '\\'));
	add_point(Point(1, 1, '#'));
	add_point(Point(1, 2, '/'));
	add_point(Point(0, 1, '#'));
	add_point(Point(2, 1, '>'));
}

Ship::~Ship(){
}

Ship::Ship(Ship const &src) {
	*this = src;
}

Ship &Ship::operator=(Ship const &src) {
	
	(void)src;
	return (*this);
}