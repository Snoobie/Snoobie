//
// SDL.cpp for  in /home/thomas_t//projet/p9_nibbler
// 
// Made by arnaud thomas-desessarts
// Login   <thomas_t@epitech.net>
// 
// Started on  Wed Mar  7 22:41:37 2012 arnaud thomas-desessarts
// Last update Sun Mar 18 21:25:41 2012 arnaud thomas-desessarts
//

#ifndef			__SDL__
#define			__SDL__

#include		<SDL/SDL.h>
#include		"../../core/Core.hh"
#include		"../../core/IDisplay.hh"

struct			keys
{
  unsigned int		key;
  int			value;
};

class			IDisplay;

class			SDL : public IDisplay
{
public:
  struct		pattern
  {
    char		letter;
    SDL_Surface*	image;
  };

private:
  SDL_Surface*		_screen;
  pattern		_motifs[NUMBER_PATTERNS];

public:
  SDL();
  virtual ~SDL();
  virtual int		catchKey();
  virtual int		initDisplay(APIDatas);
  virtual int		setPattern(const char, const int, const int);
  virtual int		drawMap(APIDatas);
  virtual int		quitLib();

  void			printCurrentScore(SDL_Surface*, const APIDatas&);
  void			printHighScores(SDL_Surface*, APIDatas&);
};

#endif
