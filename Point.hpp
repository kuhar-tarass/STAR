#ifndef POINT_HPP
#define POINT_HPP
#include <iostream>

class Point{
	private:
		int x;
		int y;
		char k;

	public:
	
	Point();
	Point(int x, int y);
	Point(int x, int y, char k);
	Point(Point const &a);
	int get_x();
	int get_y();
	char get_char() const;
	Point & operator=(Point const &a);
	Point operator+(Point const &a);
	bool operator==(Point const &a);
	Point operator-(Point const &a);
	void left();
	void right();
	void up();
	void down();

};

#endif