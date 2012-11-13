//
// moveUp.cpp for  in /home/thomas_t//projet/p9_nibbler/nibbler-2015-thomas_t/core
// 
// Made by arnaud thomas-desessarts
// Login   <thomas_t@epitech.net>
// 
// Started on  Mon Mar 12 20:42:28 2012 arnaud thomas-desessarts
// Last update Tue Mar 13 10:59:25 2012 arnaud thomas-desessarts
//

#include			"Core.hh"

bool				Core::moveSnake()
{
  std::list<Coord>::iterator	it = this->_snakePosition.end();
  std::list<Coord>::iterator	beginSnake = this->_snakePosition.begin();

  if (this->_snakePosition.empty() == false)
    {
      it--;
      this->datas_.snakeMap_[(*it).y][(*it).x] = '.';
      this->_snakePosition.pop_back();
      putApple(this->datas_.snakeMap_[(*beginSnake).y + this->_y][(*beginSnake).x + this->_x], *it);

      if (this->datas_.snakeMap_[(*beginSnake).y + this->_y][(*beginSnake).x + this->_x] == 'w' || this->datas_.snakeMap_[(*beginSnake).y + this->_y][(*beginSnake).x + this->_x] == 's')
	{
	  std::cout << "Game Over !" << std::endl;
	  return (false);
	}
      this->_snakePosition.push_front(initCoordinates((*beginSnake).x + this->_x, (*beginSnake).y + this->_y));
    }
  return (true);
}
