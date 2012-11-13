//
// moveUp.cpp for  in /home/thomas_t//projet/p9_nibbler/nibbler-2015-thomas_t/core
// 
// Made by arnaud thomas-desessarts
// Login   <thomas_t@epitech.net>
// 
// Started on  Mon Mar 12 20:42:28 2012 arnaud thomas-desessarts
// Last update Sun Mar 18 21:40:27 2012 arnaud thomas-desessarts
//

#include		"Core.hh"

const Core::Coord	Core::initCoordinates(const int x, const int y)
{
  Coord			coordinates;

  coordinates.x = x;
  coordinates.y = y;
  this->datas_.snakeMap_[y][x] = 's';
  return (coordinates);
}
