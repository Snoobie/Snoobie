//
// libSDL.cpp for  in /home/thomas_t//projet/p9_nibbler
// 
// Made by arnaud thomas-desessarts
// Login   <thomas_t@epitech.net>
// 
// Started on  Wed Mar  7 22:43:41 2012 arnaud thomas-desessarts
// Last update Sun Mar 18 21:31:41 2012 arnaud thomas-desessarts
//

#include	<iostream>
#include	"Ncurses.hh"

keys		keydown[NUMBER_KEYS] =
  {
    { KEY_UP, KEY_U },
    { KEY_DOWN, KEY_D },
    { KEY_LEFT, KEY_L },
    { KEY_RIGHT, KEY_R },
    { 27, KEY_ESC },
    { 49, 5}
  };

int		Ncurses::quitLib()
{
  curs_set(1);
  delwin(this->mine);
  clear();
  refresh();
  if (endwin() == ERR)
    return (-1);
  return (0);
}

void		Ncurses::printCurrentScore(const APIDatas& datas_)
{
  init_pair(3, COLOR_BLUE, COLOR_BLACK);
  attron(COLOR_PAIR(3) | A_BOLD | A_UNDERLINE);
  mvwprintw(this->mine, (datas_.height_), 0, "Score %d", datas_.score_);
  attroff(COLOR_PAIR(3) | A_BOLD | A_UNDERLINE);
  init_pair(5, COLOR_RED, COLOR_BLACK);
  attron(COLOR_PAIR(5) | A_BOLD | A_UNDERLINE);
  mvwprintw(this->mine, 10, 85, "/!\\ Nibbler /!\\");
  mvwchgat(this->mine, 10, 85, -1, A_BLINK, 5, NULL);
  wrefresh(this->mine);
  attroff(COLOR_PAIR(5) | A_BOLD | A_UNDERLINE);
}

void		Ncurses::printHighScore(APIDatas& datas_)
{
  int		width = datas_.width_;
  int		height = 0;

  init_pair(3, COLOR_BLUE, COLOR_BLACK);
  attron(COLOR_PAIR(3) | A_BOLD | A_UNDERLINE);
  width += 2;
  mvwprintw(this->mine, height++, width, "High scores :\n");
  attroff(COLOR_PAIR(3) | A_BOLD | A_UNDERLINE);
  attron(COLOR_PAIR(3) | A_BOLD);
  for (std::list<std::string>::iterator it = datas_.highScores_.begin(); it != datas_.highScores_.end(); ++it)
    mvwprintw(this->mine, height++, width, "%s\n", (*it).c_str());
  attroff(COLOR_PAIR(3) | A_BOLD);
}


int		Ncurses::initDisplay(APIDatas datas_)
{
  datas_ = datas_;
  if ((this->mine = initscr()) == NULL)
    return (-1);
  if (start_color() == ERR)
    return (-1);
  curs_set(0);
  if (raw() == ERR)
    return (-1);
  if (noecho() == ERR)
    return (-1);
  this->printHighScore(datas_);
  return (0);
}

int		Ncurses::putColorSnake(const int y, const int x, const int i)
{
  init_pair(1, COLOR_GREEN, COLOR_BLACK);
  attron(COLOR_PAIR(1) | A_BOLD);
  if (mvwaddch(this->mine, y, x, this->_motifs[i].match) == ERR)
    return (-1);
  attroff(COLOR_PAIR(1) | A_BOLD);
  return (0);
}

int		Ncurses::putColorApple(const int y, const int x, const int i)
{
  init_pair(2, COLOR_RED , COLOR_BLACK);
  attron(COLOR_PAIR(2) | A_BOLD | A_UNDERLINE);
  if (mvwaddch(this->mine, y, x, this->_motifs[i].match) == ERR)
    return (-1);
  attroff(COLOR_PAIR(2) | A_BOLD | A_UNDERLINE);
  return (0);
}


int		Ncurses::setPattern(const char letter, const int y, const int x)
{
  for (int i = 0; i < NUMBER_PATTERNS; i++)
    if (this->_motifs[i].letter == letter)
      {
	if (this->_motifs[i].match == 'o')
	  this->putColorSnake(y, x, i);
	else if (this->_motifs[i].match == '@')
	  this->putColorApple(y, x, i);
	else
	  if (mvwaddch(this->mine, y, x, this->_motifs[i].match) == ERR)
	    return (-1);
      }
  if (wrefresh(this->mine) == ERR)
    return (-1);
  return (0);
}

int		Ncurses::drawMap(APIDatas datas_)
{
  this->printCurrentScore(datas_);
  if (wrefresh(this->mine) == ERR)
    return (-1);
  return (0);
}

int		Ncurses::catchKey()
{
  int		ch;

  if (keypad(stdscr, TRUE) == ERR)
    return (-2);
  if (nodelay(this->mine, TRUE) == ERR)
    return (-2);
  ch = wgetch(this->mine);
  for (int i = 0; i < NUMBER_KEYS; ++i)
    if (ch == keydown[i].key)
      return (i);
  return (-1);
}

Ncurses::~Ncurses()
{
}

Ncurses::Ncurses()
{
  this->_motifs[0].letter = '.';
  this->_motifs[1].letter = 'w';
  this->_motifs[2].letter = 's';
  this->_motifs[3].letter = 'a';

  this->_motifs[0].match = ' ';
  this->_motifs[1].match = '#';
  this->_motifs[2].match = 'o';
  this->_motifs[3].match = '@';
}

extern	"C"
{
  IDisplay*	createInstance()
  {
    return (new Ncurses());
  }
}
