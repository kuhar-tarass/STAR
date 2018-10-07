#ifndef OBJECT_HPP
#define OBJECT_HPP
#include "Point.hpp"

class Object{
	private:
		Point *arr_;
		int n_;
		Point shift_;
		int health;

	public:
		Object();
		Object(Point const &a);
		virtual ~Object();

		virtual void left();
		virtual void right();
		virtual void up();
		virtual void down();

		Point operator[](int i) const;
		void add_point(Point const &a);
		
		void clearObj();
		virtual void drawObj();
		
		void	set_health(int a);
		void get_damage(int a);
		void teleport(Point const &a);
		Point get_position() const;
		int   get_status() const;

		
		bool colision(Object const &a);
};

#endif