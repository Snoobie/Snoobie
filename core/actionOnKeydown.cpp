//
// actionOnKeydown.cpp for  in /home/thomas_t//projet/p9_nibbler
// 
// Made by arnaud thomas-desessarts
// Login   <thomas_t@epitech.net>
// 
// Started on  Thu Mar  8 14:27:56 2012 arnaud thomas-desessarts
// Last update Fri Mar 16 15:23:02 2012 arnaud thomas-desessarts
//

#include		"Core.hh"

int			Core::actionOnKeydown(IDisplay* interface)
{
  int			keydown = interface->catchKey();
  Core::actionOnKey	keysActions[NUMBER_KEYS] =
    {
      { 0, &Core::moveUp },
      { 1, &Core::moveDown },
      { 2, &Core::moveLeft },
      { 3, &Core::moveRight },
      { 4, &Core::pressEscape },
      { 5, NULL }
    };

  for (int i = 0; i < NUMBER_KEYS; ++i)
    if (keysActions[i].keydown == keydown && i == 5)
      return (5);
    else if (keysActions[i].keydown == keydown)
      return ((this->*keysActions[i].funcPtr)(interface, keydown));
  return (0);
}
