//
// stringToInt.cpp for  in /home/thomas_t//projet/p9_nibbler/nibbler-2015-thomas_t/errors
// 
// Made by arnaud thomas-desessarts
// Login   <thomas_t@epitech.net>
// 
// Started on  Sun Mar 11 13:36:41 2012 arnaud thomas-desessarts
// Last update Sat Mar 17 14:07:34 2012 arnaud thomas-desessarts
//

#include		<iostream>
#include		<string>
#include		<sstream>
#include		"Errors.hh"
#include		"../core/Core.hh"

int			stringToInt(char* str)
{
  std::string		strToString;

  strToString.assign(str);
  if (strToString[0] == '-')
    {
      std::cerr << "Error: map size must be positive" << std::endl;
      return (-1);
    }
  if (strToString.size() > 2)
    {
      std::cerr << "Error: maximum map size is " << MAX_WIDTH << "width on " << MAX_HEIGHT << " height" << std::endl;
      return (-1);
    }
  for (int i = 0; strToString[i] != '\0'; i++)
    if (strToString[i] < '0' && strToString[i] > '9')
      {
	std::cerr << "Error: invalid map size" << std::endl;
	return (-1);
      }
  int			number;
  std::istringstream	stringNumber(strToString);
  
  stringNumber >> number;

  return (number);
}
