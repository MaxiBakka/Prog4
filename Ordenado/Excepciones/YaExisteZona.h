#ifndef YAEXISTEZONA_H
#define YAEXISTEZONA_H

#include<exception>
#include<iostream>
using namespace std;

class YaExisteZona:public exception{
public:
  YaExisteZona();
  ~YaExisteZona() throw();
  virtual const char* what()const throw();
};

#endif // YAEXISTEZONA_H
