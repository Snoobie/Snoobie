//
// IDisplay.hh for  in /home/thomas_t//projet/p9_nibbler
// 
// Made by arnaud thomas-desessarts
// Login   <thomas_t@epitech.net>
// 
// Started on  Thu Mar  8 10:39:02 2012 arnaud thomas-desessarts
// Last update Sun Mar 18 21:25:51 2012 arnaud thomas-desessarts
//

#ifndef				__IDISPLAY__
#define				__IDISPLAY__

struct				APIDatas
{
  int				argc_;
  char**			argv_;
  std::list<std::string>	availableLibs_;
  char**			snakeMap_;
  int				width_;
  int				height_;
  int				score_;
  std::list<std::string>	highScores_;
};

class				IDisplay
{
public:
  virtual ~IDisplay() {};
  virtual int			initDisplay(APIDatas) = 0;
  virtual int			setPattern(const char, const int, const int) = 0;
  virtual int			drawMap(APIDatas) = 0;
  virtual int			catchKey() = 0;
  virtual int			quitLib() = 0;
};

#endif
