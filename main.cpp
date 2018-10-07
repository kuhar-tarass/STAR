#include <iostream>
#include <curses.h>
#include <time.h>
#include "Object.hpp"
#include "Point.hpp"


class Enemy : public Object
{
	public:
	Enemy(){
		set_health(10);
		add_point(Point(0,0, '#'));
		add_point(Point(0,1, '#'));
		add_point(Point(1,0, '#'));
		add_point(Point(1,1, '#'));
	}

	~Enemy(){
		Object::~Object();
		clearObj();
	}

	void left(){
		if (get_position().get_x() == 0)
			set_health(0);
		else
			Object::left();
	}
};

class Bullet: public Object
{
	public:
		Bullet(Point const &a) : Object(a)
		{
			set_health(5);
			add_point(Point(0,0, '-'));
			add_point(Point(1,0, '-'));
		}

		void right(){
			if (!get_status())
				return ;
			Object::right();
			get_damage(1);
		}
		void drawObj()
		{
			if (get_status())
				Object::drawObj();
		}

		~Bullet(){
			clearObj();
		}

};

class Ship : public Object
{
	
	private:
		int		npoints;
		int		AP;

	public:

	Ship(){
		AP = 0;
		add_point(Point(1,0, '\\'));
		add_point(Point(1,1,'#'));
		add_point(Point(1,2, '/'));
		add_point(Point(0,1, '#'));
		add_point(Point(2,1, '>'));
	}

};


// void destroyer(Object *enemy[30], Object *fre)
// {


// }



int main(int argc, char const *argv[])
{

	// Ship hueta;
	
	Ship my;
	clock_t start;
	clock_t start1;
	clock_t start2;
	clock_t start3;
	Object * enemy[30];
	Object * freind[30];
	for(int i= 0; i < 30; i++){
		enemy[i] = 0;
		freind[i] = 0;
	}

	initscr();
	refresh();
	curs_set(0);
		int a = 0;
	keypad(stdscr, TRUE);
	srand(time(NULL));
	start = clock();
	start1 = clock();
	start2 = clock();
	start3 = clock();
	nodelay(stdscr, true);
	while ((a = getch()))
	{
		for (int i = 0; i < 30; i++)
		{
			if (enemy[i])
			{
				if (enemy[i]->get_status() <= 0){
					delete enemy[i];
					enemy[i] = 0;
				}
				else
					enemy[i]->drawObj();
			}
			if (freind[i])
			{
				if (!(freind[i]->get_status())){
					delete freind[i];
					freind[i] = 0;
				}
				else
					freind[i]->drawObj();
			}
			my.drawObj();
		}

		if ((clock() - start3 > CLOCKS_PER_SEC))
		{
			start3 = clock();
			int i = -1;
			while(freind[++i]);
			if (i < 30){
				freind[i] = new Bullet((my.get_position()+Point(3,1)));
			}
		}
		if ((clock() - start1 > (CLOCKS_PER_SEC / 10)))
		{
			start1 = clock();
			for (int i = 0; i < 30; i++){
				if (enemy [i])
					enemy[i]->left();
				if (freind [i])
					freind[i]->right();
			}
		}
		if (clock() - start2 > 5 * CLOCKS_PER_SEC)
		{
			start2 = clock();
			int i = -1;
			while(enemy[++i]);
			if (i < 30){
				enemy[i] = new Enemy();
				enemy[i]->teleport(Point(70, rand() % 15));
			}
		}
		switch (a)
		{
		case KEY_UP:
			my.up();
			break;
		case KEY_DOWN:
			my.down();
			break;
		case KEY_RIGHT:
			my.right();
			break;
		case KEY_LEFT:
			my.left();
			break;
		case 27:
		{
			endwin();
			return 0;
		}
		default:
			break;
		}

		
		move(0, 0);
		refresh();
	}
	endwin();


	return 0;
}
