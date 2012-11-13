//
// checkMap.cpp for  in /home/thomas_t//projet/p9_nibbler
// 
// Made by arnaud thomas-desessarts
// Login   <thomas_t@epitech.net>
// 
// Started on  Fri Mar  9 15:45:02 2012 arnaud thomas-desessarts
// Last update Wed Mar 14 10:56:27 2012 arnaud thomas-desessarts
//

#include	<iostream>
#include	"../core/Core.hh"

int		checkMap(int width, int height)
{
  if (width < MIN_WIDTH)
    {
      std::cerr << "Error: map width must be at least " << MIN_WIDTH << std::endl;
      return (-1);
    }
  if (height < MIN_HEIGHT)
    {
      std::cerr << "Error: map height must be at least " << MIN_HEIGHT << std::endl;
      return (-1);
    }
  if (width > MAX_WIDTH)
    {
      std::cerr << "Error: maximum map width is " << MAX_WIDTH << std::endl;
      return (-1);
    }
  if (height > MAX_HEIGHT)
    {
      std::cerr << "Error: maximum map height is " << MAX_HEIGHT << std::endl;
      return (-1);
    }

  return (0);
}
