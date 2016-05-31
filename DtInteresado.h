#ifndef DtInteresado_h
#define DtInteresado_h

#include <string>

using namespace std;

class DtInteresado{
private:
    string nombre;
    string apellido;
    string edad;
    string email;
public:
    DtInteresado(string n,string a,string ed,string em);
    string get_nombre();
    string get_apellido();
    string get_edad();
    string get_email();
    ~DtInteresado;
}

#endif // DtInteresado_h
