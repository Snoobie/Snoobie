//
// printMap.cpp for  in /home/thomas_t//projet/p9_nibbler/nibbler-2015-thomas_t
// 
// Made by arnaud thomas-desessarts
// Login   <thomas_t@epitech.net>
// 
// Started on  Tue Mar 13 12:57:03 2012 arnaud thomas-desessarts
// Last update Tue Mar 13 15:46:55 2012 arnaud thomas-desessarts
//

#include	"Core.hh"

void		Core::printMap(IDisplay* currentLib)
{
  for (int y = 0; this->datas_.snakeMap_[y] != NULL; y++)
    for (int x = 0; this->datas_.snakeMap_[y][x] != '\0'; x++)
	currentLib->setPattern(this->datas_.snakeMap_[y][x], y, x);
}
