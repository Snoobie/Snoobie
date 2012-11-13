//
// switchLib.cpp for  in /home/thomas_t//projet/p9_nibbler/nibbler-2015-thomas_t
// 
// Made by arnaud thomas-desessarts
// Login   <thomas_t@epitech.net>
// 
// Started on  Thu Mar 15 18:22:49 2012 arnaud thomas-desessarts
// Last update Sun Mar 18 21:42:10 2012 arnaud thomas-desessarts
//

#include				<list>
#include				"Core.hh"

const std::string&			Core::switchLib()
{
  bool					nextOne = false;
  std::list<std::string>::iterator	it = this->datas_.availableLibs_.begin();
  std::list<std::string>::iterator	itCheck = it;

  while (it != this->datas_.availableLibs_.end())
    {
      itCheck++;
      if (nextOne == true)
	{
	  this->_currentLib = *it;
	  break;
	}
      if (this->_currentLib == *it)
      	nextOne = true;
      it++;
      if (itCheck == this->datas_.availableLibs_.end())
	{
	  itCheck = this->datas_.availableLibs_.begin();
	  it = this->datas_.availableLibs_.begin();
	}
    }

  return (this->_currentLib);
}
