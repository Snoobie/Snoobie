//
// extractHighScores.cpp for  in /home/thomas_t//projet/p9_nibbler/nibbler-2015-thomas_t
// 
// Made by arnaud thomas-desessarts
// Login   <thomas_t@epitech.net>
// 
// Started on  Mon Mar 12 21:03:56 2012 arnaud thomas-desessarts
// Last update Mon Mar 12 21:12:12 2012 arnaud thomas-desessarts
//

#include			<fstream>
#include			"Core.hh"

std::list<std::string>		Core::extractHighScores()
{
  std::list<std::string>	highScores;

  std::string			line;
  std::fstream			getHighScores("highScores.txt");

  while (getline(getHighScores, line, '\n'))
    highScores.push_back(line);

  getHighScores.close();
  return (highScores);
}
