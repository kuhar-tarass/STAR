#include <curses.h>
#include <time.h>
#include <iostream>
#include "Object.hpp"
#include "Point.hpp"
#include "Enemy.hpp"
#include "Bullet.hpp"
#include "Ship.hpp"



class Brevno : public Bullet
{

	public:
		Brevno(Point const &a): Bullet(a){
			set_health(300);
			add_point(Point(1, 0, '#'));
			add_point(Point(2, 0, '#'));
			add_point(Point(3, 0, '#'));
			add_point(Point(4, 0, '#'));
		}

		void left(){
			Object::left();
			Object::left();
			Object::left();
			get_damage(1);
			if (get_position().get_x() < 1)
				get_damage(1000);
		}
		~Brevno(){
			clearObj();
		};
};

void menu() {
	srand(time(NULL));
	initscr();
	clear();
	start_color();
	use_default_colors();
	noecho();
	cbreak();
	mvwprintw(stdscr, 1, 40, "HELLO MY LITTLI FRIEND\n");
	refresh();
	keypad(stdscr, true);
	std::string ch[] = {
	"    _   _                                            \n",
	"   | \\ | |                                           \n",
	"   |  \\| | _____      __   __ _  __ _ _ __ ___   ___ \n",
	"   | . ` |/ _ \\ \\ /\\ / /  / _` |/ _` | '_ ` _ \\ / _ \\\n",
	"   | |\\  |  __/\\ V  V /  | (_| | (_| | | | | | |  __/\n",
	"   |_| \\_|\\___| \\_/\\_/    \\__, |\\__,_|_| |_| |_|\\___|\n",
	"                           __/ |                     \n",
	"                          |___/ ",
	"                _ _   \n", //8
	"               (_| |  \n",
	"     __ _ _   _ _| |_ \n",
	"    / _` | | | | | __|\n",
	"   | (_| | |_| | | |_ \n",
	"    \\__, |\\__,_|_|\\__|\n",
	"       | |            \n",
	"       |_|"};
	int choice;
	int highlight = 0;
	int i;
	init_pair(1, COLOR_RED,  -1);//COLOR_BLUE);
	init_pair(2, COLOR_BLUE, -1);//COLOR_CYAN);
	init_pair(3, COLOR_CYAN, -1);//COLOR_YELLOW);
	init_pair(4, COLOR_YELLOW,-1);//COLOR_GREEN);
	init_pair(5, COLOR_GREEN, -1);//COLOR_RED);
	while (1) {
		nodelay(stdscr, true);
		srand(time(0));
		for (i = 0; i < 2; i++) {
			if (i == highlight)
				wattron(stdscr, A_REVERSE);
			int col = rand() % 5;
			attron(COLOR_PAIR(col));
			mvwprintw(stdscr, i*9+2, 60, ch[i*8].c_str());
			mvwprintw(stdscr, i*9+3, 60, ch[i*8+1].c_str());
			mvwprintw(stdscr, i*9+4, 60, ch[i*8+2].c_str());
			mvwprintw(stdscr, i*9+5, 60, ch[i*8+3].c_str());
			mvwprintw(stdscr, i*9+6, 60, ch[i*8+4].c_str());
			mvwprintw(stdscr, i*9+7, 60, ch[i*8+5].c_str());
			mvwprintw(stdscr, i*9+8, 60, ch[i*8+6].c_str());
			mvwprintw(stdscr, i*9+9, 60, ch[i*8+7].c_str());
			wattroff(stdscr, A_REVERSE);
			attroff(COLOR_PAIR(col));
			
		}
		choice = wgetch(stdscr);
		switch(choice) {
			case KEY_UP:
				highlight--;
				if(highlight == -1)
					highlight = 0;
				break;
			case KEY_DOWN:
				highlight++;
				if (highlight == 2)
					highlight = 1;
				break;
			default:
				break;
		}
		if (choice == 10)
			break ;
	}
	if (highlight == 0) {
		clear();
		return ;
	}
	else {
		clear();
		while (1) {
		 	int col = rand() % 5;
		 	attron(COLOR_PAIR(col));
			mvwprintw(stdscr,20, 0,
					 "                      ::::::::   ::::::::   ::::::::  :::::::::        :::::::::  :::   ::: :::::::::: \n"
					 "                     :+:    :+: :+:    :+: :+:    :+: :+:    :+:       :+:    :+: :+:   :+: :+:        \n"
					 "                     +:+        +:+    +:+ +:+    +:+ +:+    +:+       +:+    +:+  +:+ +:+  +:+        \n"
					 "                     :#:        +#+    +:+ +#+    +:+ +#+    +:+       +#++:++#+    +#++:   +#++:++#   \n"
					 "                     +#+   +#+# +#+    +#+ +#+    +#+ +#+    +#+       +#+    +#+    +#+    +#+        \n"
					 "                     #+#    #+# #+#    #+# #+#    #+# #+#    #+#       #+#    #+#    #+#    #+#        \n"
					 "                      ########   ########   ########  #########        #########     ###    ########## ");
			attroff(COLOR_PAIR(col));
			nodelay(stdscr, true);
			if (getch() != -1) {
				system("clear");
				exit(EXIT_SUCCESS);
			}
			refresh();
		}
		getch();
		endwin();
	}
	exit(EXIT_SUCCESS);
}

int main(int argc, char const *argv[])
{
	menu();
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
	keypad(stdscr, TRUE);
	srand(time(NULL));
	start = 
	nodelay(stdscr, true);
	while ((a = getch()))
	{
		move(0,100);
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
	menu();
	system("leaks a.out");
	return 0;
}
