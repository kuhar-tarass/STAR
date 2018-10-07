#ifndef SHIP_HPP
#define SHIP_HPP
#include "Point.hpp"
#include "Object.hpp"

class Ship : public Object
{
	
	private:
		int		AP;

	public:

	Ship();
	~Ship();

};

#endif