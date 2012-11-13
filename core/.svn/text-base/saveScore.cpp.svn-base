//
// saveScore.cpp for  in /home/thomas_t//projet/p9_nibbler/nibbler-2015-thomas_t
// 
// Made by arnaud thomas-desessarts
// Login   <thomas_t@epitech.net>
// 
// Started on  Sun Mar 11 20:23:33 2012 arnaud thomas-desessarts
// Last update Sat Mar 17 15:59:14 2012 arnaud thomas-desessarts
//

#include		<iostream>
#include		<fstream>
#include		<list>
#include		"Core.hh"
#include		"../errors/Errors.hh"

static int		getNumberLines(const char* file)
{
  int			numberLines = 0;
  std::ifstream		getHighScores(file);
  std::string		line;

  while (getline(getHighScores, line, '\n'))
    numberLines++;
  getHighScores.close();
  return (numberLines);
}

int			Core::saveScore()
{
  std::string		line;

  if (getNumberLines("highScores.txt") == 10)
    {
      std::list<int>	scores;
      std::fstream	getHighScores("highScores.txt");

      while (getline(getHighScores, line, '\n'))
	scores.push_back(stringToInt(const_cast<char*>(line.data())));
      getHighScores.close();

      for (std::list<int>::iterator it = scores.begin(); it != scores.end(); ++it)
	if (this->datas_.score_ > *it)
	  {
	    if (it == scores.begin())
	      std::cout << "New high score !" << std::endl;
	    *it = this->datas_.score_;
	    break;
	  }
      getHighScores.close();

      std::ofstream	writeBack("highScores.txt", std::ios::in | std::ios::trunc);

      for (std::list<int>::iterator it = scores.begin(); it != scores.end(); ++it)
	writeBack << *it << std::endl;
      writeBack.close();
    }
  else
    {
      std::ofstream	file("highScores.txt", std::ios::in | std::ios::app);

      file << this->datas_.score_ << std::endl;;
      file.close();
    }
  return (0);
}
