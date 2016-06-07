#ifndef UsuarioController_h
#define UsuarioController_h

#include "Manejador_Usuario.h"
#include "Usuario.h"
#include "IUsuarioController.h"
#include "DtInteresado.h"
#include "DataInmobiliaria.h"
#include "DataInfoInmobiliaria.h"

#include <set>
#include <string>

class UsuarioController : public IUsuarioController{

private:


	 string *email;
	 string *password;//nose si va como puntero
	 Usuario*usuario;


public:
      UsuarioController();
      virtual ~UsuarioController();

      virtual void IngresarEmail(string& email);
    	virtual void activarSesion();
    	virtual void CancelarInicioSesion();
    	virtual void ConfirmarContrasenia(string& pwd);

    	virtual bool esUsuarioAdmin();

    	virtual void IngresarContrasenia(string& pwd);
    	virtual void IngresarContraseniaNueva(string& pwd);
    	virtual bool PrimeraVez();

      //ALTA INMOBILIARIA
    	virtual void IngresarInmobiliaria(DataInmobiliaria* di);

      //Obtener Reporte de Inmobiliarias
    	virtual set<DataInfoInmobiliaria*>* ObtenerReporte();

      //Cerrar sesion
      virtual void CerrarSesion(string emailUsuario);

      //Alta Interesado
      virtual void IngresarInteresado(DtInteresado*di)


};
#endif
