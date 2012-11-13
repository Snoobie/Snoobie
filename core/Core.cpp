//
// Core.cpp for  in /home/thomas_t//projet/p9_nibbler
// 
// Made by arnaud thomas-desessarts
// Login   <thomas_t@epitech.net>
// 
// Started on  Wed Mar  7 19:06:56 2012 arnaud thomas-desessarts
// Last update Sun Mar 18 21:37:12 2012 arnaud thomas-desessarts
//

#include	<stdlib.h>
#include	"Core.hh"
#include	"../errors/Errors.hh"

Core::~Core()
{
}

Core::Core(int ac, char** av)
{
  this->_error = false;
  this->datas_.availableLibs_ = getAvailableLibs();
  this->datas_.snakeMap_ = generateMap(stringToInt(av[1]), stringToInt(av[2]));
  this->datas_.width_ = stringToInt(av[2]);
  this->datas_.height_ = stringToInt(av[1]);
  this->datas_.score_ = 0;
  this->datas_.highScores_ = extractHighScores();
  this->datas_.argc_ = ac;
  this->datas_.argv_ = av;  
  this->_currentLib = av[3];
  this->_x = 1;
  this->_y = 0;
  if (this->_error == false)
    {
      this->_snakePosition.push_front(initCoordinates(this->datas_.width_ / 2 - 2, this->datas_.height_ / 2));
      this->_snakePosition.push_front(initCoordinates(this->datas_.width_ / 2 - 1, this->datas_.height_ / 2));
      this->_snakePosition.push_front(initCoordinates(this->datas_.width_ / 2, this->datas_.height_ / 2));
      this->_snakePosition.push_front(initCoordinates(this->datas_.width_ / 2 + 1, this->datas_.height_ / 2));

      srand(time(NULL));
      
      int	randX;
      int	randY;
      
      do
	{
	  randX = rand() % this->datas_.width_;
	  randY = rand() % this->datas_.height_;
	} while (this->datas_.snakeMap_[randY][randX] == 'w' || this->datas_.snakeMap_[randY][randX] == 's' || this->datas_.snakeMap_[randY][randX] == 'a');
      this->datas_.snakeMap_[randY][randX] = 'a';
    }
}
