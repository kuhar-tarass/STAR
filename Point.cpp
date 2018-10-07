#include "Point.hpp"
#include <ncurses.h>

Point::Point() : x(0), y(0), k(0){

}

Point::Point(int x, int y) : x(x), y(y) , k(0){
}

Point::Point(int x, int y, char k) : x(x), y(y) , k(k){
}

Point::~Point() {

}
int Point::get_x(){
	return x;
}

int Point::get_y(){
	return y;
}
char Point::get_char() const{
	return k;
}

Point::Point(Point const &a)
{
	*this = a;
}

Point &Point::operator=(Point const &a){
	this->x = a.x;
	this->y = a.y;
	this->k = a.k;
	return *this;
}

Point Point::operator+(Point const &a){
	return Point(x + a.x, y + a.y);
}

bool Point::operator==(Point const &a){
	return x == a.x && y == a.y;
}

Point Point::operator-(Point const &a){
	return Point(x - a.x, y - a.y);
}

void Point::left(){
	x--;
	x = x >= 0 ? x : 0;
}
void Point::right(){
	x++;
	x = x < getmaxx(stdscr) - 10 ? x : getmaxx(stdscr) - 10;
}
void Point::up(){
	y--;
	y = y >= 0 ? y : 0;
}
void Point::down(){
	y++;
	// y = y >= 0 ? y : 0;
	y = y < getmaxy(stdscr) - 10 ? y : getmaxy(stdscr) - 10;
}
