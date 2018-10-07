#include <curses.h>
#include <time.h>
#include <iostream>
#include "Object.hpp"
#include "Point.hpp"
#include "Enemy.hpp"
#include "Bullet.hpp"
#include "Ship.hpp"
#include "Brevno.hpp"


int main(int argc, char const *argv[])
{
	
{
		Ship my;
	clock_t start  =  clock(), start1 =  clock(), start2 =  clock(), start3 =  clock();
	Object * enemy[30];
	Object * freind[30];
	for(int i= 0; i < 30; i++){
		enemy[i] = 0;
		freind[i] = 0;
	}

	int a = 0;

	initscr();
	refresh();
	curs_set(0);
	noecho();
	keypad(stdscr, TRUE);
	srand(time(NULL));
	nodelay(stdscr, true);
	while ((a = getch()))
	{
		move(0,getmaxx(stdscr) - 15);
		printw("HITpoint: %3d", my.get_status());
		move(0,0);
		if (my.get_status() == 0)
			break;
		refresh();
		for (int i = 0; i < 30; i++)
		{
			if (enemy[i])
			{
				for(int j = 0; j < 30; j++)
					if (freind[j])
						if (enemy[i]->colision(*freind[j]))
							{
								enemy[i]->get_damage(1);
								freind[j]->get_damage(2);
								continue;
							}
				if (enemy[i]->colision(my))
				{
					enemy[i]->get_damage(100);
					my.get_damage(15);
				}
				if (enemy[i]->get_status() <= 0){
					delete enemy[i];
					enemy[i] = 0;
				}
				else
					enemy[i]->drawObj();
			}
			if (freind[i])
			{
				if ( freind[i]->get_status() <= 0){
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
				if (rand()%2)
					enemy[i] = new Enemy(Point(140, rand() % 15));
				else
					enemy[i] = new Brevno(Point(120,rand() % 10));
			}
		}
		
		switch (a)
		{
		case KEY_UP: 	my.up(); 	break;
		case KEY_DOWN:	my.down();	break;
		case KEY_RIGHT:	my.right();	break;
		case KEY_LEFT:	my.left();	break;
		case 27:		endwin();	return 0;
		default:					break;
		}
		refresh();
	}
	endwin();
}
	system("leaks a.out");
	return 0;
}
