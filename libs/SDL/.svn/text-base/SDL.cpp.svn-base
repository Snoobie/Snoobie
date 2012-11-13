//
// libSDL.cpp for  in /home/thomas_t//projet/p9_nibbler
// 
// Made by arnaud thomas-desessarts
// Login   <thomas_t@epitech.net>
// 
// Started on  Wed Mar  7 22:43:41 2012 arnaud thomas-desessarts
// Last update Sun Mar 18 21:57:59 2012 arnaud thomas-desessarts
//

#include		<SDL/SDL_image.h>
#include		<SDL/SDL_ttf.h>
#include		"SDL.hh"

keys			keydown[NUMBER_KEYS] =
  {
    { SDLK_UP, KEY_U },
    { SDLK_DOWN, KEY_D },
    { SDLK_LEFT, KEY_L },
    { SDLK_RIGHT, KEY_R },
    { SDLK_ESCAPE, KEY_ESC },
    { SDLK_KP1, 5 },
  };

int			SDL::quitLib()
{
  SDL_Quit();
  return (0);
}

void			SDL::printHighScores(SDL_Surface* screen, APIDatas& datas_)
{
  SDL_Rect		rectDest;

  rectDest.x = (datas_.width_ * TILE_WIDTH) + 60;
  rectDest.y = 20;
  SDL_Surface*		image;
  if ((image = IMG_Load("images/medal.png")) != NULL)
    {
      SDL_BlitSurface(image, NULL, screen, &rectDest);
      SDL_FreeSurface(image);
    }

  TTF_Init();

  int			jump = 90;
  TTF_Font*		font;
  SDL_Color		color = { 255, 255, 255, 0 };
  SDL_Surface*		text = NULL;

  if ((font = TTF_OpenFont("fonts/segoeuil.ttf", 35)) != NULL)
    {
      for (std::list<std::string>::iterator it = datas_.highScores_.begin(); it != datas_.highScores_.end(); ++it)
	{
	  if ((text = TTF_RenderText_Blended(font, (*it).c_str(), color)) != NULL)
	    {
	      rectDest.x = (datas_.width_ * TILE_WIDTH) + 70;
	      rectDest.y = jump;
	      jump += 38;
	      SDL_BlitSurface(text, NULL, screen, &rectDest);
	    }
	}
    }

  TTF_Quit();
}

void			SDL::printCurrentScore(SDL_Surface* screen, const APIDatas& datas_)
{
  SDL_Rect		rectDest;
  rectDest.x = 25;
  rectDest.y = datas_.height_ * TILE_HEIGHT + 15;

  SDL_Surface*		image;
  if ((image = IMG_Load("images/cup.png")) != NULL)
    {
      SDL_BlitSurface(image, NULL, screen, &rectDest);
      SDL_FreeSurface(image);
    }

  TTF_Init();
  char			score[50];
  sprintf(score, "Score %d", datas_.score_);

  TTF_Font*		font;
  if ((font = TTF_OpenFont("fonts/segoeuil.ttf", 50)) != NULL)
    {
      SDL_Color		color = { 255, 255, 255, 0 };
      SDL_Surface*	text = TTF_RenderText_Blended(font, score, color);
      rectDest.x = 80;
      rectDest.y = datas_.height_ * TILE_HEIGHT + 15;
      SDL_BlitSurface(text, NULL, screen, &rectDest);
    }
  TTF_Quit();
}

int			SDL::setPattern(const char letter, const int y, const int x)
{
  SDL_Rect		rectDest;

  for (int i = 0; i < NUMBER_PATTERNS; i++)
    if (this->_motifs[i].letter == letter)
      {
	rectDest.x = x * TILE_HEIGHT;
	rectDest.y = y * TILE_WIDTH;
	if (SDL_BlitSurface(this->_motifs[i].image, NULL, this->_screen, &rectDest) == -1)
	  return (-1);
	break;
      }
  return (0);
}

int			SDL::drawMap(APIDatas datas)
{
  printCurrentScore(this->_screen, datas);
  printHighScores(this->_screen, datas);
  if (SDL_Flip(this->_screen) == -1)
    return (-1);
  if (SDL_FillRect(this->_screen, NULL, SDL_MapRGB(this->_screen->format, 0, 0, 0)) == -1)
    return (-1);
  return (0);
}

int			SDL::catchKey()
{
  SDL_Event		event;

  SDL_PollEvent(&event);
  if (event.type == SDL_KEYDOWN)
    for (int i = 0; i < NUMBER_KEYS; ++i)
      if (event.key.keysym.sym == keydown[i].key)
	return (i);
  return (-1);
}

int			SDL::initDisplay(APIDatas datas_)
{
  if (this->_motifs[0].image == NULL || this->_motifs[1].image == NULL || this->_motifs[2].image == NULL || this->_motifs[3].image == NULL)
    return (-1);
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    return (-1);
  if ((this->_screen = SDL_SetVideoMode(datas_.width_ * TILE_WIDTH + 250, datas_.height_ * TILE_HEIGHT + 100, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL)
    return (-1);
  SDL_Surface*		icon;

  if ((icon = IMG_Load("images/logo.png")) != NULL)
    SDL_WM_SetIcon(icon, NULL);
  SDL_WM_SetCaption("Nibbler", NULL);
  return (0);
}

SDL::~SDL()
{
}

SDL::SDL()
{
  this->_motifs[0].letter = '.';
  this->_motifs[1].letter = 'w';
  this->_motifs[2].letter = 's';
  this->_motifs[3].letter = 'a';

  if ((this->_motifs[0].image = IMG_Load("images/blank.png")) == NULL)
    {
      std::cerr << "Error: failed on loading image" << std::endl;
      exit(-1);
    }
  if ((this->_motifs[1].image = IMG_Load("images/wall.png")) == NULL)
    {
      std::cerr << "Error: failed on loading image" << std::endl;
      exit(-1);
    }
  if ((this->_motifs[2].image = IMG_Load("images/snake.png")) == NULL)
    {
      std::cerr << "Error: failed on loading image" << std::endl;
      exit(-1);
    }
  if ((this->_motifs[3].image = IMG_Load("images/apple.png")) == NULL)
    {
      std::cerr << "Error: failed on loading image" << std::endl;
      exit(-1);
    }
}

extern	"C"
{
  IDisplay*		createInstance()
  {
    return (new SDL());
  }
}
