#include "YaExisteZona.h"

YaExisteZona::YaExisteZona(){

}

YaExisteZona::~YaExisteZona(){

}

 const char* YaExisteZona::what()const throw(){
  return "La zona ya existe";
}
