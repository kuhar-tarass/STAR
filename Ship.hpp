#ifndef SHIP_HPP
#define SHIP_HPP
#include "Point.hpp"
#include "Object.hpp"

class Ship : public Object
{
	
	public:

	Ship();
	~Ship();
	Ship(Ship const &src);

	Ship &operator=(Ship const &src);

};

#endif