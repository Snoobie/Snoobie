//
// moveUp.cpp for  in /home/thomas_t//projet/p9_nibbler/nibbler-2015-thomas_t/core
// 
// Made by arnaud thomas-desessarts
// Login   <thomas_t@epitech.net>
// 
// Started on  Mon Mar 12 20:42:28 2012 arnaud thomas-desessarts
// Last update Sat Mar 17 15:31:27 2012 arnaud thomas-desessarts
//

#include	"Core.hh"

int		Core::moveUp(IDisplay* interface, int number)
{
  interface = interface;
  number = number;

  if (this->_x != 0)
    {
      this->_y = -1;
      this->_x = 0;
    }
  return (0);
}

