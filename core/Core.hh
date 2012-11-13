//
// Core.hh for  in /home/thomas_t//projet/p9_nibbler
// 
// Made by arnaud thomas-desessarts
// Login   <thomas_t@epitech.net>
// 
// Started on  Wed Mar  7 23:01:03 2012 arnaud thomas-desessarts
// Last update Sun Mar 18 21:43:12 2012 arnaud thomas-desessarts
//

#ifndef				__CORE__
#define				__CORE__

#include			<iostream>
#include			<list>
#include			"IDisplay.hh"

#define				NUMBER_LIBS	3
#define				NUMBER_PATTERNS	4
#define				NUMBER_KEYS	6

#define				MIN_WIDTH	15
#define				MIN_HEIGHT	15

#define				MAX_WIDTH	25
#define				MAX_HEIGHT	30

#define				TILE_WIDTH	32
#define				TILE_HEIGHT	32

#define				KEY_U		0
#define				KEY_D		1
#define				KEY_L		2
#define				KEY_R		3
#define				KEY_ESC		4
#define				KEY_NEXT_LIB	5
#define				KEY_PREV_LIB	6

class				Core
{
public:
  struct			Coord
  {
    int				x;
    int				y;
  };

private:
  APIDatas			datas_;
  bool				_error;
  std::string			_currentLib;
  int				_x;
  int				_y;
  std::list<Coord>		_snakePosition;

  struct			actionOnKey
  {
    int				keydown;
    int				(Core::*funcPtr)(IDisplay*, int);
  };

public:
  Core(int, char**);
  ~Core();

  bool				getError() const;
  const APIDatas&		getAPIDatas() const;

  char**			generateMap(const int, const int);
  std::list<std::string>	extractHighScores();
  const Coord			initCoordinates(const int, const int);
  const std::string&		switchLib();
  void				printMap(IDisplay*);
  bool				moveSnake();
  bool				putApple(const char, const Coord);
  void				growQueue(bool&, const Coord);
  int				actionOnKeydown(IDisplay*);
  int				pressEscape(IDisplay*, int);
  int				moveUp(IDisplay*, int);
  int				moveDown(IDisplay*, int);
  int				moveLeft(IDisplay*, int);
  int				moveRight(IDisplay*, int);
  int				saveScore();
};

int				initCore(const int, char**);
int				loadLib(void**, IDisplay* (*)(), IDisplay*, const char*);
int				runGame(Core*, void**, IDisplay**, IDisplay* (*)());
std::list<std::string>		getAvailableLibs();

#endif
