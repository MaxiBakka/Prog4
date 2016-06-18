#ifndef Manejador_Usuario_h_
#define  Manejador_Usuario_h_

#include <map>
#include <string>
#include <set>

#include "../DataTypes/DataInmobiliaria.h"
#include "../DataTypes/../DataTypes/DtInteresado.h"
#include "../DataTypes/DataInfoInmobiliaria.h"
#include "Usuario.h"
#include "Administrador.h"
#include "Interesado.h"
#include "Inmobiliaria.h"


using namespace std;

class Manejador_Usuario {
private:

	static Manejador_Usuario*instancia;
    map<string,Administrador*>*administradores;
    map<string,Interesado*>*interesados;
    map<string,Inmobiliaria*>*inmobiliarias;
    Manejador_Usuario();

public:

    static Manejador_Usuario* getInstancia();

    virtual ~Manejador_Usuario ();

    //getters de usuarios
    Inmobiliaria* getInmobiliaria(string &email);
    Interesado* getInteresado(string &email);
		Usuario* getUsuario(string &email);

	//operaciones del caso AltaInmobiliaria Y AltaInteresado
	void CrearInmobiliaria(DataInmobiliaria*di);
	void CrearInteresado(DtInteresado*di);
	void CrearAdministrador(string &email,string &password);

	//obtencion Datatypes
	set<DataInfoInmobiliaria*>*getDataInfoInmobiliaria();


};

#endif
