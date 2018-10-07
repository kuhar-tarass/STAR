#include "Point.hpp"
#include "Object.hpp"
#include <curses.h>

bool Object::colision(Object const &a){
	for (int i = 0; i < n_; i++)
		for (int j = 0; j < a.n_; j++)
			if (arr_[i] == a.arr_[j])
				return true;
	return false;
}


void Object::clearObj(){
		for (int i = 0; i < n_; i++){
			move((arr_[i] + shift_).get_y(), (arr_[i] + shift_).get_x());
			printw(" ");
		}
}
void Object::drawObj(){
		for (int i = 0; i < n_; i++){
			move((*this)[i].get_y(), (*this)[i].get_x());
			printw("%c", arr_[i].get_char());
		}
}

void Object::add_point(Point const &a){
	Point *tmp = new Point[n_ + 1];
	for(int i = 0; i < n_; i++){
		tmp[i] = arr_[i];
	}
	tmp[n_] = a;
	if (arr_)
		delete [] arr_;
	arr_ = tmp;
	n_++;
}


Point Object::operator[](int i) const
{
	if (i < n_)
		return arr_[i] + shift_;
	return Point();
}

Object::Object(){
	arr_ = 0;
	n_ = 0;
	shift_ = Point(0,0);
	health = 0;
}

Object::Object(Point const &a){
	arr_ = 0;
	n_ = 0;
	shift_ = a;
	health = 0;
}

void Object::left(){
	clearObj();
	shift_.left();
	drawObj();
}
void Object::right(){
	clearObj();
	shift_.right();
	drawObj();
}
void Object::up(){
	clearObj();
	shift_.up();
	drawObj();
}
void Object::down(){
	clearObj();
	shift_.down();
	drawObj();
}

Object::~Object(){
	delete [] arr_;
}

void Object::teleport(Point const &a){
	shift_ = a;
}

Point Object::get_position() const {
	return shift_;
}

void Object::get_damage(int a){
	health -= health - a;
	health < 0 ? health = 0 : 0;
}	

int Object::get_status() const {
	return health;
}

void Object::set_health(int a){
	health += a;
}
