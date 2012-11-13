//
// OpenGL.hh for  in /home/motmae_a//cpp/Nibbler/nibbler-2015-thomas_t/libs/OpenGL
// 
// Made by adrien motmaenfar
// Login   <motmae_a@epitech.net>
// 
// Started on  Fri Mar 16 21:38:48 2012 adrien motmaenfar
// Last update Sun Mar 18 21:28:38 2012 arnaud thomas-desessarts
//

#ifndef			OPENGL_HH_
#define			OPENGL_HH_

#include		<GL/gl.h>
#include		<GL/glu.h>
#include		"../../core/Core.hh"
#include		"../../core/IDisplay.hh"

struct			keys
{
  unsigned int		key;
  int			value;
};

class			IDisplay;

class			OpenGL : public IDisplay
{
private:
  int			idWindow;
  SDL_Surface*		_screen;

public:
  OpenGL();
  virtual ~OpenGL();
  virtual int		catchKey();
  virtual int		initDisplay(APIDatas);
  virtual int		setPattern(const char, const int, const int);
  virtual int		drawMap(APIDatas);
  virtual int		quitLib();
};

#endif
