#ifndef IUsuarioController.h
#define  IUsuarioController.h

#include "DataInmobiliaria.h"
#include "DataInfoInmobiliaria.h"
#include "DtInteresado.h"

#include <string>
#include <set>



using namespace std;

class IUsuarioController{

public:
      IUsuarioController(){};
      virtual ~IUsuarioController(){};
      //Iniciar sesion
      virtual void activarSesion() = 0;
      virtual void cancelarInicioSesion() = 0;
      virtual ConfirmarContrasenia(string pwd) = 0;
      virtual bool esUsuarioAdmin(string& email) = 0;
      virtual void IngresarEmail(string& email) = 0;
      virtual void IngresarContrasenia(string& pwd)= 0;
      virtual void IngresarContraseniaNueva(string& pwd) = 0;
      virtual bool PrimeraVez() = 0;
      //AltaInmobiliaria
      virtual void IngresarInmobiliaria(DataInmobiliaria*di) = 0;
      //Caso de uso Obtener reporte de Inmobiliarias
      virtual set<DataInfoInmobiliaria*>* ObtenerReporte() = 0;
      //AltaInteresado
      virtual void IngresarInteresado(DataInteresado*di) = 0;
      //Cerrar sesion
      virtual void CerrarSesion(string emailUsuario) = 0;

};
#endif
