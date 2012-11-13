//
// checkUsage.cpp for  in /home/thomas_t//projet/p9_nibbler
// 
// Made by arnaud thomas-desessarts
// Login   <thomas_t@epitech.net>
// 
// Started on  Fri Mar  9 15:40:40 2012 arnaud thomas-desessarts
// Last update Sun Mar 11 13:57:56 2012 arnaud thomas-desessarts
//

#include	<iostream>
#include	"Errors.hh"

int		checkUsage(int ac, char** av)
{
  if (ac != 4)
    {
      std::cerr << "Usage: ./Nibbler width height lib.so" << std::endl;
      return (-1);
    }
  if (checkMap(stringToInt(av[1]), stringToInt(av[2])) == -1)
    return (-1);
  return (0);
}
