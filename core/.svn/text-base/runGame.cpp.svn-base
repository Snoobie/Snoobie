//
// runGame.cpp for  in /home/thomas_t//projet/p9_nibbler/nibbler-2015-thomas_t
// 
// Made by arnaud thomas-desessarts
// Login   <thomas_t@epitech.net>
// 
// Started on  Thu Mar 15 11:45:31 2012 arnaud thomas-desessarts
// Last update Sat Mar 17 15:33:15 2012 arnaud thomas-desessarts
//

#include	<dlfcn.h>
#include	"Core.hh"

int		runGame(Core* Nibbler, void** lib, IDisplay** currentLib, IDisplay* (*externalCreator)())
{
  int		key;

  while (1)
    {
      usleep(50000);
      if ((key = Nibbler->actionOnKeydown(*currentLib)) == 1)
	break;
      else if (key == -2)
	return (-1);
      else if (key == 5)
      	{
      	  if ((*currentLib)->quitLib() == -1)
	    {
	      std::cerr << "Error: library switch failed" << std::endl;
	      return (-1);
	    }
	  dlclose(*lib);
	  if ((*lib = dlopen(Nibbler->switchLib().c_str(), RTLD_LAZY)) == NULL)
	    return (-1);
	  if ((externalCreator = reinterpret_cast<IDisplay* (*)()>(dlsym(*lib, "createInstance"))) == NULL)
	    return (-1);
	  if ((*currentLib = externalCreator()) == NULL)
	    return (-1);
	  if ((*currentLib)->initDisplay(Nibbler->getAPIDatas()) == -1)
	    {
	      std::cerr << "Error: display initialization failed" << std::endl;
	      return (-1);
	    }
	}
      if (Nibbler->moveSnake() == false)
	break;
      Nibbler->printMap(*currentLib);
      if ((*currentLib)->drawMap(Nibbler->getAPIDatas()) == -1)
	{
	  std::cerr << "Error: map display failed" << std::endl;
	  return (-1);
	}
    }
  return (0);
}
