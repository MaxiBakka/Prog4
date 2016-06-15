#ifndef YAEXISTEZONA_H
#define YAEXISTEZONA_H

#include<exception>
#include<iostream>

class YaExisteZona:public exception{
public:
  YaExisteZona();
  ~YaExisteZona();
  virtual const char* what()const throw();
}
