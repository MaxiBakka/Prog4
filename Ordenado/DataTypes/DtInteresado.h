
#ifndef DTINTERESADO_H
#define	DTINTERESADO_H

#include <string>
#include <iostream>

using namespace std;

class DtInteresado {
private:
    string nombre;
    string apellido;
    int edad;
    string email;
public:
    DtInteresado(string& n,string& a,int e,string& correo);
    string& get_Nombre();
    string& get_Apellido();
    int get_Edad();
    string& get_Email();
    ~DtInteresado();

};

ostream& operator<<(ostream& o, const DtInteresado& di);


#endif	/* DTINTERESADO_H */
