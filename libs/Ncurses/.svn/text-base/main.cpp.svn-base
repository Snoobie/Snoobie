//
// main.cpp for  in /home/pons_c//projet/nibbler/backup/libs/Ncurse
// 
// Made by christophe pons
// Login   <pons_c@epitech.net>
// 
// Started on  Mon Mar 12 00:45:47 2012 christophe pons
// Last update Mon Mar 12 00:47:09 2012 christophe pons
//

#include <iostream>
#include <string>
#include <ncurses.h>

int	main(void)
{
  WINDOW *vin;

  initscr();
  start_color();
  init_pair(1,COLOR_YELLOW,COLOR_BLUE);
  init_pair(2,COLOR_BLUE,COLOR_YELLOW);
  init_pair(3,COLOR_BLUE,COLOR_WHITE);
  vin=newwin(12,40,13,0);
  wmove(vin,0,5);
  wprintw(vin,"Hello, World." );
  wbkgd(vin,COLOR_PAIR(1));
  wrefresh(vin);
  getch();
  delwin(vin);
  endwin();
  return 0;

}
