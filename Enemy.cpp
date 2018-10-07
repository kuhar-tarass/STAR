#include "Enemy.hpp"

Enemy::Enemy() {}
Enemy &Enemy::operator=(Enemy const &src) {
	(void)src;
	return (*this);
}
Enemy::Enemy(Enemy const &src) {
	*this = src;
}
Enemy::Enemy(Point const &a) : Object(a)
{
	int lol;
	lol = (rand() %3);
	switch (lol)
	{
		case 0:
			set_health(40);
			add_point(Point(0, 0, '#'));
			add_point(Point(0, 1, '#'));
			add_point(Point(1, 0, '#'));
			add_point(Point(1, 1, '#'));
			/* code */
			break;
		case 1:
			set_health(80);
			add_point(Point  	(0,3, '-'));
			add_point(Point  	(0,4, '-') );
			add_point(Point  	(0,5, '-') );
			add_point(Point  	(0,6, '-') );
			add_point(Point  	(0,7, '|'));
			add_point(Point  	(1,0, '_'));
			add_point(Point  	(1,1, '/'));
			add_point(Point  	(1,2, 'o'));
			add_point(Point  	(1,3, 'o')  );
			add_point(Point  	(1,4, 'o')  );
			add_point(Point  	(1,5, 'o'));
			add_point(Point  	(1,6, '|'));
			add_point(Point  	(2,1, '\\'));
			add_point(Point  	(2,2, 'o') );
			add_point(Point  	(2,3, 'o'));
			add_point(Point  	(2,4, 'o'));
			add_point(Point  	(2,5, 'o'));
			add_point(Point  	(2,6, '|'));
			add_point(Point  	(3,3, '-'));
			add_point(Point  	(3,4, '-') );
			add_point(Point  	(3,5, '-') );
			add_point(Point  	(3,6, '-') );
			add_point(Point  	(3,7, '|'));
		case 2:
			add_point(Point  	(0,1, '/'));
			add_point(Point  	(0,2, '#'));
			add_point(Point  	(0,3, '#'));
			add_point(Point  	(1,1, '/'));
			add_point(Point  	(1,2, '#'));
			add_point(Point  	(1,3, '#'));
			add_point(Point  	(1,4, '#'));
			add_point(Point  	(1,5, '#'));
			add_point(Point  	(2,1, '\\'));
			add_point(Point  	(2,2, '#'));
			add_point(Point  	(2,3, '#'));
			add_point(Point  	(2,4, '#'));
			add_point(Point  	(2,5, '#'));
			add_point(Point  	(3,1, '\\'));
			add_point(Point  	(3,2, '#'));
			add_point(Point  	(3,3, '#'));
		default:
			break;
	}

}

Enemy::~Enemy()
{
	clearObj();
}

void Enemy::left()
{
	if (get_position().get_x() < 1)
		get_damage(10);
	Object::left();
}

void Enemy::drawObj()
{
	if (get_status())
		Object::drawObj();
}

//
//   __
//    \ \_____
// ###[==_____>
//    /_/      __
//             \ \_____
//          ###[==_____>
//             /_/
// 

//
//
//
//
//