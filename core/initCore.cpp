//
// initCore.cpp for  in /home/thomas_t//projet/p9_nibbler/nibbler-2015-thomas_t
// 
// Made by arnaud thomas-desessarts
// Login   <thomas_t@epitech.net>
// 
// Started on  Thu Mar 15 11:39:55 2012 arnaud thomas-desessarts
// Last update Sun Mar 18 21:35:23 2012 arnaud thomas-desessarts
//

#include	<dlfcn.h>
#include        <cstdio>
#include	"Core.hh"
#include	"../errors/Errors.hh"

int		initCore(int ac, char** av)
{
  Core		Nibbler(ac, av);
  if (Nibbler.getError() == true)
    return (-1);
  void*       	lib;
  IDisplay*	(*externalCreator)();
  IDisplay*	currentLib;

  if ((lib = dlopen(av[3], RTLD_LAZY)) == NULL)
    {
      std::cerr << "Error: failed to open " << av[3] << std::endl;
      return (-1);
    }
  if ((externalCreator = reinterpret_cast<IDisplay* (*)()>(dlsym(lib, "createInstance"))) == NULL)
    {
      std::cerr << "Error: failed to load program's core" << std::endl;
      dlclose(lib);
      return (-1);
    }
  if ((currentLib = externalCreator()) == NULL)
    {
      std::cerr << "Error: failed to load program's core" << std::endl;
      dlclose(lib);
      return (-1);
    }
  currentLib->initDisplay(Nibbler.getAPIDatas());
  if (runGame(&Nibbler, &lib, &currentLib, externalCreator) == -1)
    return (-1);
  currentLib->quitLib();
  dlclose(lib);

  return (Nibbler.saveScore());
}
