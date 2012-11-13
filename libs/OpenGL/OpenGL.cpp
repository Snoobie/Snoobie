//
// OpenGL.cpp for  in /home/thomas_t//projet/p9_nibbler/nibbler-2015-thomas_t
// 
// Made by arnaud thomas-desessarts
// Login   <thomas_t@epitech.net>
// 
// Started on  Fri Mar 16 15:24:23 2012 arnaud thomas-desessarts
// Last update Sun Mar 18 21:28:14 2012 arnaud thomas-desessarts
//

#include		<SDL/SDL.h>
#include		<SDL/SDL_image.h>
#include		<SDL/SDL_ttf.h>
#include		"OpenGL.hh"

#define			SQUARE_SIZE 32

keys			keydown[NUMBER_KEYS] =
  {
    { SDLK_UP, KEY_U },
    { SDLK_DOWN, KEY_D },
    { SDLK_LEFT, KEY_L },
    { SDLK_RIGHT, KEY_R },
    { SDLK_ESCAPE, KEY_ESC },
    { SDLK_KP1, 5 },
  };

int			OpenGL::drawMap(APIDatas datas)
{
  (void)datas;
  glFlush();
  SDL_GL_SwapBuffers();
  return (0);
}

int			OpenGL::quitLib()
{
  SDL_Quit();
  return (0);
}

int			OpenGL::setPattern(const char letter, const int y, const int x)
{
  if (!x && !y)
    glClear(GL_COLOR_BUFFER_BIT);
  if (letter != '.')
  {
    if (letter == 'w')
      glColor3ub(219, 121, 17);
    else if (letter == 's')
      glColor3ub(10, 219, 0);
    else if (letter == 'a')
      glColor3ub(219, 26, 29);
    glBegin(GL_QUADS);
    glVertex2d(x * TILE_HEIGHT,
	       y * TILE_WIDTH);
    glVertex2d(x * TILE_HEIGHT,
	       y * TILE_WIDTH + TILE_WIDTH);
    glVertex2d(x * TILE_HEIGHT + TILE_HEIGHT,
	       y * TILE_WIDTH + TILE_WIDTH);
    glVertex2d(x * TILE_HEIGHT + TILE_HEIGHT,
	       y * TILE_WIDTH);
    glEnd();
  }
  if (glGetError() != GL_NO_ERROR)
    return (-1);
  return (0);
}

int			OpenGL::catchKey()
{
  SDL_Event		event;

  SDL_PollEvent(&event);
  if (event.type == SDL_KEYDOWN)
    for (int i = 0; i < NUMBER_KEYS; ++i)
      if (event.key.keysym.sym == keydown[i].key)
	return (i);
  return (-1);
}

int			OpenGL::initDisplay(APIDatas datas_)
{
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    return (-1);
  if ((this->_screen = SDL_SetVideoMode(datas_.width_ * TILE_WIDTH, datas_.height_ * TILE_HEIGHT, 32, SDL_OPENGL)) == NULL)
    return (-1);
  SDL_Surface*		icon;

  if ((icon = IMG_Load("images/logo.png")) != NULL)
    SDL_WM_SetIcon(icon, NULL);
  SDL_WM_SetCaption("Nibbler", NULL);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, datas_.width_ * TILE_WIDTH, datas_.height_ * TILE_HEIGHT, 0, -1, 1);
  return (0);
}

OpenGL::~OpenGL()
{
}

OpenGL::OpenGL()
{
}

extern	"C"
{
  IDisplay*		createInstance()
  {
    return (new OpenGL());
  }
}
