//
// getAvailableLibs.cpp for  in /home/thomas_t//projet/p9_nibbler/nibbler-2015-thomas_t
// 
// Made by arnaud thomas-desessarts
// Login   <thomas_t@epitech.net>
// 
// Started on  Thu Mar 15 15:11:40 2012 arnaud thomas-desessarts
// Last update Thu Mar 15 20:20:18 2012 arnaud thomas-desessarts
//

#include			<list>
#include			<dirent.h>
#include			<string.h>
#include			"Core.hh"

std::list<std::string>		getAvailableLibs()
{
  std::string			concat;
  std::list<std::string>	list;
  struct dirent**		directory;
  int				fd = scandir(".", &directory, 0, alphasort);
  
  while (fd--)
    if (directory[fd]->d_name[strlen(directory[fd]->d_name) - 1] == 'o' &&
	directory[fd]->d_name[strlen(directory[fd]->d_name) - 2] == 's')
      {
	concat = "./";
	concat += directory[fd]->d_name;
	list.push_back(concat);
      }

  return (list);
}
