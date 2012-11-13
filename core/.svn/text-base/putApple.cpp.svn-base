//
// moveUp.cpp for  in /home/thomas_t//projet/p9_nibbler/nibbler-2015-thomas_t/core
// 
// Made by arnaud thomas-desessarts
// Login   <thomas_t@epitech.net>
// 
// Started on  Mon Mar 12 20:42:28 2012 arnaud thomas-desessarts
// Last update Sun Mar 18 21:41:22 2012 arnaud thomas-desessarts
//

#include	<cstdlib>
#include	"Core.hh"

bool		Core::putApple(const char c, const Core::Coord coordinates)
{
  static bool	grow = false;

  growQueue(grow, coordinates);
  if (c == 'a')
    {
      srand(time(NULL));
      
      int	randX;
      int	randY;

      do
	{
	  randX = rand() % this->datas_.width_;
	  randY = rand() % this->datas_.height_;
	} while (this->datas_.snakeMap_[randY][randX] == 'w' || this->datas_.snakeMap_[randY][randX] == 's' || this->datas_.snakeMap_[randY][randX] == 'a');
      this->datas_.snakeMap_[randY][randX] = 'a';
      this->datas_.score_++;
      grow = true;
    }

  return (true);
}
