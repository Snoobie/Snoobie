//
// generateMap.cpp for  in /home/thomas_t//projet/p9_nibbler/nibbler-2015-thomas_t
// 
// Made by arnaud thomas-desessarts
// Login   <thomas_t@epitech.net>
// 
// Started on  Sun Mar 11 15:04:23 2012 arnaud thomas-desessarts
// Last update Sun Mar 18 21:39:30 2012 arnaud thomas-desessarts
//

#include		<iostream>
#include		<string>
#include		"Core.hh"

char**			Core::generateMap(const int height, const int width)
{
  int			i = 0;
  int			j = 0;
  char**		snakeMap;

  if ((snakeMap = new(std::nothrow) char * [height + 1]) == NULL)
    {
      std::cerr << "Error: memory allocation problem" << std::endl;
      this->_error = true;
      return (NULL);
    }

  for (i = 0; i < height; i++)
    {
      snakeMap[i] = new char[width + 1];
      for (j = 0; j < width; j++)
	if (j == 0 || j == (width - 1) || i == 0 || i == (height - 1))
	  snakeMap[i][j] = 'w';
	else
	  snakeMap[i][j] = '.';
      snakeMap[i][j] = '\0';
    }
  snakeMap[i] = NULL;
  return (snakeMap);
}
