
#ifndef DATAINTERESADO_H
#define	DATAINTERESADO_H

#include <string>

using namespace std;

class DataInteresado {
private:
    string nombre;
    string apellido;
    int edad;
    string email;
public:
    DataInteresado(string& n,string& a,int e,string& correo);
    string& getNombre();
    string& getApellido();
    int getEdad();
    string& getEmail();
    ~DataInteresado();

};

#endif	/* DATAINTERESADO_H */

