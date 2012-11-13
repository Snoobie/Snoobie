//
// SDL.cpp for  in /home/thomas_t//projet/p9_nibbler
// 
// Made by arnaud thomas-desessarts
// Login   <thomas_t@epitech.net>
// 
// Started on  Wed Mar  7 22:41:37 2012 arnaud thomas-desessarts
// Last update Sun Mar 18 21:30:16 2012 arnaud thomas-desessarts
//

#ifndef		__LIBNCURSES__
#define		__LIBNCURSES__

#include	<ncurses.h>
#include	"../../core/Core.hh"
#include	"../../core/IDisplay.hh"

struct		keys
{
  int		key;
  int		value;
};

class		IDisplay;

class		Ncurses : public IDisplay
{
public:
  struct	pattern
  {
    char	letter;
    char	match;
  };

private:
  WINDOW	*mine;
  pattern       _motifs[NUMBER_PATTERNS];

public:
  Ncurses();
  virtual ~Ncurses();
  virtual int	catchKey();
  virtual int	initDisplay(APIDatas);
  virtual int	setPattern(const char, const int, const int);
  virtual int	drawMap(APIDatas);
  virtual int	quitLib();

  void		printCurrentScore(const APIDatas&);
  void		printHighScore(APIDatas&);
  int		putColorSnake(const int, const int, const int);
  int		putColorApple(const int, const int, const int);
};

#endif
