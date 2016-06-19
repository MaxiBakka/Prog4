#DataTypes
DataVenta:
	g++ -Wall -Werror -o ./obj/DataVenta.o -c ./src/DataTypes/DataVenta.cpp
	ar rvs ./lib/libTarea2.lib ./obj/DataVenta.o
DataZona:
	g++ -Wall -Werror -o ./obj/DataZona.o -c ./src/DataTypes/DataZona.cpp
	ar rvs ./lib/libTarea2.lib ./obj/DataZona.o
DtInteresado:
	g++ -Wall -Werror -o ./obj/DtInteresado.o -c ./src/DataTypes/DtInteresado.cpp
	ar rvs ./lib/libTarea2.lib ./obj/DtInteresado.o
Fecha:
	g++ -Wall -Werror -o ./obj/Fecha.o -c ./src/DataTypes/Fecha.cpp
	ar rvs ./lib/libTarea2.lib ./obj/Fecha.o
Hora:
	g++ -Wall -Werror -o ./obj/Hora.o -c ./src/DataTypes/Hora.cpp
	ar rvs ./lib/libTarea2.lib ./obj/Hora.o
DataAlquiler:
	g++ -Wall -Werror -o ./obj/DataAlquiler.o -c ./src/DataTypes/DataAlquiler.cpp
	ar rvs ./lib/libTarea2.lib ./obj/DataAlquiler.o 
DataChat: 
	g++ -Wall -Werror -o ./obj/DataChat.o -c ./src/DataTypes/DataChat.cpp
	ar rvs ./lib/libTarea2.lib ./obj/DataChat.o
DataDepartamento: 
	g++ -Wall -Werror -o ./obj/DataDepartamento.o -c ./src/DataTypes/DataDepartamento.cpp
	ar rvs ./lib/libTarea2.lib ./obj/DataDepartamento.o
DataDetallePropiedad:
	g++ -Wall -Werror -o ./obj/DataDetallePropiedad.o -c ./src/DataTypes/DataDetallePropiedad.cpp
	ar rvs ./lib/libTarea2.lib ./obj/DataDetallePropiedad.o
DataEdificio:
	g++ -Wall -Werror -o ./obj/DataEdificio.o -c ./src/DataTypes/DataEdificio.cpp
	ar rvs ./lib/libTarea2.lib ./obj/DataEdificio.o	
DataPropiedad: DataAlquiler DataVenta
	g++ -Wall -Werror -o ./obj/DataPropiedad.o -c ./src/DataTypes/DataPropiedad.cpp
	ar rvs ./lib/libTarea2.lib ./obj/DataPropiedad.o
DataApartamento: DataPropiedad
	g++ -Wall -Werror -o ./obj/DataApartamento.o -c ./src/DataTypes/DataApartamento.cpp
	ar rvs ./lib/libTarea2.lib ./obj/DataApartamento.o
DataCasa: DataPropiedad 
	g++ -Wall -Werror -o ./obj/DataCasa.o -c ./src/DataTypes/DataCasa.cpp
	ar rvs ./lib/libTarea2.lib ./obj/DataCasa.o
DataReportePropiedad: DataZona DataDepartamento
	g++ -Wall -Werror -o ./obj/DataReportePropiedad.o -c ./src/DataTypes/DataReportePropiedad.cpp
	ar rvs ./lib/libTarea2.lib ./obj/DataReportePropiedad.o
DataInfoInmobiliaria: DataReportePropiedad
	g++ -Wall -Werror -o ./obj/DataInfoInmobiliaria.o -c ./src/DataTypes/DataInfoInmobiliaria.cpp
	ar rvs ./lib/libTarea2.lib ./obj/DataInfoInmobiliaria.o
DataInfoPropiedad:
	g++-Wall -Werror  -o ./obj/DataInfoPropiedad.o -c ./src/DataTypes/DataInfoPropiedad.cpp
	ar rvs ./lib/libTarea2.lib ./obj/DataInfoPropiedad.o
DataInmobiliaria:
	g++ -Wall -Werror -o ./obj/DataInmobiliaria.o -c ./src/DataTypes/DataInmobiliaria.cpp
	ar rvs ./lib/libTarea2.lib ./obj/DataInmobiliaria.o
DataMensaje: Hora Fecha
	g++ -Wall -Werror -o ./obj/DataMensaje.o -c ./src/DataTypes/DataMensaje.cpp
	ar rvs ./lib/libTarea2.lib ./obj/DataMensaje.o
DataReporteApartamento: DataReportePropiedad
	g++ -Wall -Werror -o ./obj/DataReporteApartamento.o -c ./src/DataTypes/DataReporteApartamento.cpp
	ar rvs ./lib/libTarea2.lib ./obj/DataReporteApartamento.o
DataReporteCasa: DataReportePropiedad
	g++ -Wall -Werror -o ./obj/DataReporteCasa.o -c ./src/DataTypes/DataReporteCasa.cpp
	ar rvs ./lib/libTarea2.lib ./obj/DataReporteCasa.o


	
DataTypes: DataVenta DataZona DtInteresado Fecha Hora DataAlquiler DataChat DataDepartamento DataDetallePropiedad DataEdificio DataPropiedad DataApartamento DataCasa DataReportePropiedad DataInfoInmobiliaria DataInfoPropiedad DataInmobiliaria DataMensaje DataReporteApartamento DataReporteCasa
	
#excepciones
EstudianteNoInscripto: 
	g++ -Wall -Werror -o ./obj/EstudianteNoInscripto.o -c ./src/exceptions/EstudianteNoInscripto.cpp
	ar rvs ./lib/libTarea2.lib ./obj/EstudianteNoInscripto.o
NoExAsignatura:	
	g++ -Wall -Werror -o ./obj/NoExAsignatura.o -c ./src/exceptions/NoExAsignatura.cpp
	ar rvs ./lib/libTarea2.lib ./obj/NoExAsignatura.o
NoExEmpresa:
	g++ -Wall -Werror -o ./obj/NoExEmpresa.o -c ./src/exceptions/NoExEmpresa.cpp
	ar rvs ./lib/libTarea2.lib ./obj/NoExEmpresa.o
NoExEstudiante:	
	g++ -Wall -Werror -o ./obj/NoExEstudiante.o -c ./src/exceptions/NoExEstudiante.cpp
	ar rvs ./lib/libTarea2.lib ./obj/NoExEstudiante.o
NoExisteSeccion:	
	g++ -Wall -Werror -o ./obj/NoExisteSeccion.o -c ./src/exceptions/NoExisteSeccion.cpp
	ar rvs ./lib/libTarea2.lib ./obj/NoExisteSeccion.o
NoExisteSucursal:
	g++ -Wall -Werror -o ./obj/NoExisteSucursal.o -c ./src/exceptions/NoExisteSucursal.cpp
	ar rvs ./lib/libTarea2.lib ./obj/NoExisteSucursal.o
NoExOfertaLaboral:
	g++ -Wall -Werror -o ./obj/NoExOfertaLaboral.o -c ./src/exceptions/NoExOfertaLaboral.cpp
	ar rvs ./lib/libTarea2.lib ./obj/NoExOfertaLaboral.o
OfertaLaboralVigente:
	g++ -Wall -Werror -o ./obj/OfertaLaboralVigente.o -c ./src/exceptions/OfertaLaboralVigente.cpp
	ar rvs ./lib/libTarea2.lib ./obj/OfertaLaboralVigente.o
YaExisteOferta:
	g++ -Wall -Werror -o ./obj/YaExisteOferta.o -c ./src/exceptions/YaExisteOferta.cpp
	ar rvs ./lib/libTarea2.lib ./obj/YaExisteOferta.o
ExOpcionInvalida: 
	g++ -Wall -Werror -o ./obj/ExOpcionInvalida.o -c ./src/exceptions/ExOpcionInvalida.cpp
	ar rvs ./lib/libTarea2.lib ./obj/ExOpcionInvalida.o
	
Excepciones: 

#manejadores
ManejadorTiempo : Date
	g++ -Wall -Werror -o ./obj/ManejadorTiempo.o -c ./src/manejadores/ManejadorTiempo.cpp
	ar rvs ./lib/libTarea2.lib ./obj/ManejadorTiempo.o



#interfaces
IPropiedadController:
	g++ -Wall -Werror -o ./obj/IPropiedadController.o -c ./src/Interfaces/IPropiedadController.cpp
	ar rvs ./lib/libTarea2.lib ./obj/IPropiedadController.o
IUsuarioController:
	g++ -Wall -Werror -o ./obj/IUsuarioController.o -c ./src/Interfaces/IUsuarioController.cpp
	ar rvs ./lib/libTarea2.lib ./obj/IUsuarioController.o
ICargarDatosController: 
	g++ -Wall -Werror -o ./obj/ICargarDatosControllerController.o -c ./src/Interfaces/ICargarDatosController.cpp
	ar rvs ./lib/libTarea2.lib ./obj/ICargarDatosController.o
IEnviarMensajeController:
	g++ -Wall -Werror -o ./obj/IEnviarMensajeController.o -c ./src/Interfaces/IEnviarMensajeController.cpp
	ar rvs ./lib/libTarea2.lib ./obj/IEnviarMensajeController.o
IModificarPropiedadController:
	g++ -Wall -Werror -o ./obj/IModificarPropiedadController.o -c ./src/Interfaces/IModificarPropiedadController.cpp
	ar rvs ./lib/libTarea2.lib ./obj/IModificarPropiedadController.o



#fabrica
Factory: UsuarioController PropiedadController EnviarMensajeController ModificarPropiedadController CargarDatosController 
	g++ -o ./obj/Factory.o -c ./src/Fabrica/Factory.cpp
	ar rvs ./lib/libTarea2.lib ./obj/Factory.o





#componentes ui
IOConsola : Date
	g++ -o ./obj/IOConsola.o -c ./src/IOConsola.cpp
	ar rvs ./lib/libTarea2.lib ./obj/IOConsola.o
PantallaUI:
	g++ -o ./obj/PantallaUI.o -c ./src/PantallaUI.cpp
	ar rvs ./lib/libTarea2.lib ./obj/PantallaUI.o
Menu : PantallaUI ExOpcionInvalida
	g++ -o ./obj/Menu.o -c ./src/Menu.cpp
	ar rvs ./lib/libTarea2.lib ./obj/Menu.o

#rutinas
RutinaAltaEntrevista: IOConsola
	g++ -o ./obj/RutinaAltaEntrevista.o -c ./src/casosDeUso/RutinaAltaEntrevista.cpp
	ar rvs ./lib/libTarea2.lib ./obj/RutinaAltaEntrevista.o
	
RutinaAltaOfertaLaboral: IOConsola
	g++ -o ./obj/RutinaAltaOfertaLaboral.o -c ./src/casosDeUso/RutinaAltaOfertaLaboral.cpp
	ar rvs ./lib/libTarea2.lib ./obj/RutinaAltaOfertaLaboral.o
	
RutinaAsignacionOferta: IOConsola
	g++ -o ./obj/RutinaAsignacionOferta.o -c ./src/casosDeUso/RutinaAsignacionOferta.cpp
	ar rvs ./lib/libTarea2.lib ./obj/RutinaAsignacionOferta.o
	
RutinaCargarDatosPrueba: IOConsola
	g++ -o ./obj/RutinaCargarDatosPrueba.o -c ./src/casosDeUso/RutinaCargarDatosPrueba.cpp
	ar rvs ./lib/libTarea2.lib ./obj/RutinaCargarDatosPrueba.o
	
RutinaConsultarDatosEstudiante: IOConsola
	g++ -o ./obj/RutinaConsultarDatosEstudiante.o -c ./src/casosDeUso/RutinaConsultarDatosEstudiante.cpp
	ar rvs ./lib/libTarea2.lib ./obj/RutinaConsultarDatosEstudiante.o

RutinaDarDeBajaOfertaLaboral: IOConsola
	g++ -o ./obj/RutinaDarDeBajaOfertaLaboral.o -c ./src/casosDeUso/RutinaDarDeBajaOfertaLaboral.cpp
	ar rvs ./lib/libTarea2.lib ./obj/RutinaDarDeBajaOfertaLaboral.o
	
RutinaInscripcionOfertaLaboral: IOConsola
	g++ -o ./obj/RutinaInscripcionOfertaLaboral.o -c ./src/casosDeUso/RutinaInscripcionOfertaLaboral.cpp
	ar rvs ./lib/libTarea2.lib ./obj/RutinaInscripcionOfertaLaboral.o
	
RutinaListarOfertasActivas: IOConsola
	g++ -o ./obj/RutinaListarOfertasActivas.o -c ./src/casosDeUso/RutinaListarOfertasActivas.cpp
	ar rvs ./lib/libTarea2.lib ./obj/RutinaListarOfertasActivas.o
	
RutinaModificarEstudiante: IOConsola
	g++ -o ./obj/RutinaModificarEstudiante.o -c ./src/casosDeUso/RutinaModificarEstudiante.cpp
	ar rvs ./lib/libTarea2.lib ./obj/RutinaModificarEstudiante.o

RutinaVerNotificaciones: IOConsola
	g++ -o ./obj/RutinaVerNotificaciones.o -c ./src/casosDeUso/RutinaVerNotificaciones.cpp
	ar rvs ./lib/libTarea2.lib ./obj/RutinaVerNotificaciones.o

RutinaConfigurarFecha: IOConsola
	g++ -o ./obj/RutinaConfigurarFecha.o -c ./src/casosDeUso/RutinaConfigurarFecha.cpp
	ar rvs ./lib/libTarea2.lib ./obj/RutinaConfigurarFecha.o


Rutinas : RutinaConfigurarFecha RutinaAltaEntrevista RutinaAltaOfertaLaboral RutinaAsignacionOferta RutinaCargarDatosPrueba RutinaConsultarDatosEstudiante RutinaDarDeBajaOfertaLaboral RutinaInscripcionOfertaLaboral RutinaInscripcionOfertaLaboral RutinaListarOfertasActivas RutinaModificarEstudiante RutinaVerNotificaciones 


#menues
MenuUtils : 
	g++ -o ./obj/MenuUtils.o -c ./src/Menus/MenuUtils.cpp
	ar rvs ./lib/libTarea2.lib ./obj/MenuUtils.o
Menu : UserInterface ExOpcionInvalida MenuUtils
	g++ -o ./obj/Menu.o -c ./src/Menus/Menu.cpp
	ar rvs ./lib/libTarea2.lib ./obj/Menu.o
MenuAdministradores : ExOpcionInvalida RutinaCerrarSesion RutinaAltaInteresado
	g++ -o ./obj/MenuAdministradores.o -c ./src/Menus/MenuAdministradores.cpp
	ar rvs ./lib/libTarea2.lib ./obj/MenuAdministradores.o
MenuInmobiliarias : ExOpcionInvalida RutinaCerrarSesion RutinaAltaEdificio RutinaConsultarPropiedad RutinaEnviarMensajeInmobiliaria	RutinaAltaPropiedad
	g++ -o ./obj/MenuInmobiliarias.o -c ./src/Menus/MenuInmobiliarias.cpp
	ar rvs ./lib/libTarea2.lib ./obj/MenuInmobiliarias.o
MenuInteresados : ExOpcionInvalida RutinaConsultarPropiedad RutinaCerrarSesion RutinaEnviarMensajeInteresado
	g++ -o ./obj/MenuInteresados.o -c ./src/Menus/MenuInteresados.cpp
	ar rvs ./lib/libTarea2.lib ./obj/MenuInteresados.o
MenuPrincipal : MenuInteresados MenuInmobiliarias MenuAdministradores RutinaInicioSesion Sesion Interesado Inmobiliaria Administrador ExOpcionInvalida
	g++ -o ./obj/MenuPrincipal.o -c ./src/Menus/MenuPrincipal.cpp
	ar rvs ./lib/libTarea2.lib ./obj/MenuPrincipal.o

	
#mains
MiCasa: MenuPrincipal
	g++ -o ./bin/MiCasa -Wall ./src/MiCasa.cpp ./lib/libTarea2.lib

clean:
	rm ./lib/*.lib
	rm ./obj/*.o
	
all: BuscoFingJobs