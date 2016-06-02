#ifndef UsuarioController.h
#define UsuarioController.h

#include "Manejador_Usuario.h"
#include "Usuario.h"
#include "IUsuarioController.h"
#include "DataInmobiliaria.h"
#include "DataInfoInmobiliaria.h"

#include <set>
#include <string>
 
class UsuarioController : public IUsuarioController{

private:

	//No se si va pero por las dudas lo dejo por aca
	string* email;
	string* password;
	string* passwordPrimVez;

public:

	virtual void activarSesion();
	virtual void cancelarInicioSesion();
	virtual void confirmarContrasena(string pwd);
	virtual bool esUsuarioAdmin(const string& email);
	virtual void ingresarContrasena(string pwd);
	virtual void ingresarContrasenaNueva(string pwd);
	virtual bool primeraVez();
	virtual void ingresarInmobiliaria(DataInmobiliaria* I);
	virtual <DataInfoInmobiliaria*>* obtenerReporte();


}
