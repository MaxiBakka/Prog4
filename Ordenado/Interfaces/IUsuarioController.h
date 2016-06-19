#ifndef  IUsuarioController_h
#define  IUsuarioController_h

#include "../DataTypes/DataInmobiliaria.h"
#include "../DataTypes/DataInfoInmobiliaria.h"
#include "../DataTypes/DtInteresado.h"

#include <string>
#include <set>



using namespace std;

class IUsuarioController{

public:
      IUsuarioController();
      virtual ~IUsuarioController();
      //Iniciar sesion
      virtual void activarSesion() = 0;
      virtual void  CancelarInicioSesion() = 0;
      virtual void ConfirmarContrasenia(string& pwd) = 0;
      virtual bool esUsuarioAdmin() = 0;
      virtual void IngresarEmail(string& correo) = 0;
      virtual void IngresarContrasenia(string& pwd)= 0;
      virtual void IngresarContraseniaNueva(string& pwd) = 0;
      virtual bool PrimeraVez() = 0;
      //AltaInmobiliaria
      virtual void IngresarInmobiliaria(DataInmobiliaria*di) = 0;
      //Caso de uso Obtener reporte de Inmobiliarias
      virtual set<DataInfoInmobiliaria*>* ObtenerReporte() = 0;
      //AltaInteresado
      virtual void IngresarInteresado(DtInteresado*di) = 0;
      //Cerrar sesion
      virtual void CerrarSesion() = 0;

};
#endif
