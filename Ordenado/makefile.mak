#DataTypes
DataVenta:
	g++ -Wall -Werror -o ./obj/DataVenta.o -c ./src/DataTypes/DataVenta.cpp
	 ./obj/DataVenta.o
DataZona:
	g++ -Wall -Werror -o ./obj/DataZona.o -c ./src/DataTypes/DataZona.cpp
	 ./obj/DataZona.o
DtInteresado:
	g++ -Wall -Werror -o ./obj/DtInteresado.o -c ./src/DataTypes/DtInteresado.cpp
	 ./obj/DtInteresado.o
Fecha:
	g++ -Wall -Werror -o ./obj/Fecha.o -c ./src/DataTypes/Fecha.cpp
	 ./obj/Fecha.o
Hora:
	g++ -Wall -Werror -o ./obj/Hora.o -c ./src/DataTypes/Hora.cpp
	 ./obj/Hora.o
DataAlquiler:
	g++ -Wall -Werror -o ./obj/DataAlquiler.o -c ./src/DataTypes/DataAlquiler.cpp
	 ./obj/DataAlquiler.o 
DataChat: 
	g++ -Wall -Werror -o ./obj/DataChat.o -c ./src/DataTypes/DataChat.cpp
	 ./obj/DataChat.o
DataDepartamento: 
	g++ -Wall -Werror -o ./obj/DataDepartamento.o -c ./src/DataTypes/DataDepartamento.cpp
	 ./obj/DataDepartamento.o
DataDetallePropiedad:
	g++ -Wall -Werror -o ./obj/DataDetallePropiedad.o -c ./src/DataTypes/DataDetallePropiedad.cpp
	 ./obj/DataDetallePropiedad.o
DataEdificio:
	g++ -Wall -Werror -o ./obj/DataEdificio.o -c ./src/DataTypes/DataEdificio.cpp
	 ./obj/DataEdificio.o	
DataPropiedad: DataAlquiler DataVenta
	g++ -Wall -Werror -o ./obj/DataPropiedad.o -c ./src/DataTypes/DataPropiedad.cpp
	 ./obj/DataPropiedad.o
DataApartamento: DataPropiedad
	g++ -Wall -Werror -o ./obj/DataApartamento.o -c ./src/DataTypes/DataApartamento.cpp
	 ./obj/DataApartamento.o
DataCasa: DataPropiedad 
	g++ -Wall -Werror -o ./obj/DataCasa.o -c ./src/DataTypes/DataCasa.cpp
	 ./obj/DataCasa.o
DataReportePropiedad: DataZona DataDepartamento
	g++ -Wall -Werror -o ./obj/DataReportePropiedad.o -c ./src/DataTypes/DataReportePropiedad.cpp
	 ./obj/DataReportePropiedad.o
DataInfoInmobiliaria: DataReportePropiedad
	g++ -Wall -Werror -o ./obj/DataInfoInmobiliaria.o -c ./src/DataTypes/DataInfoInmobiliaria.cpp
	 ./obj/DataInfoInmobiliaria.o
DataInfoPropiedad:
	g++-Wall -Werror  -o ./obj/DataInfoPropiedad.o -c ./src/DataTypes/DataInfoPropiedad.cpp
	 ./obj/DataInfoPropiedad.o
DataInmobiliaria:
	g++ -Wall -Werror -o ./obj/DataInmobiliaria.o -c ./src/DataTypes/DataInmobiliaria.cpp
	 ./obj/DataInmobiliaria.o
DataMensaje: Hora Fecha
	g++ -Wall -Werror -o ./obj/DataMensaje.o -c ./src/DataTypes/DataMensaje.cpp
	 ./obj/DataMensaje.o
DataReporteApartamento: DataReportePropiedad
	g++ -Wall -Werror -o ./obj/DataReporteApartamento.o -c ./src/DataTypes/DataReporteApartamento.cpp
	 ./obj/DataReporteApartamento.o
DataReporteCasa: DataReportePropiedad
	g++ -Wall -Werror -o ./obj/DataReporteCasa.o -c ./src/DataTypes/DataReporteCasa.cpp
	 ./obj/DataReporteCasa.o


	
DataTypes: DataVenta DataZona DtInteresado Fecha Hora DataAlquiler DataChat DataDepartamento DataDetallePropiedad DataEdificio DataPropiedad DataApartamento DataCasa DataReportePropiedad DataInfoInmobiliaria DataInfoPropiedad DataInmobiliaria DataMensaje DataReporteApartamento DataReporteCasa
	
#excepciones
EstudianteNoInscripto: 
	g++ -Wall -Werror -o ./obj/EstudianteNoInscripto.o -c ./src/exceptions/EstudianteNoInscripto.cpp
	 ./obj/EstudianteNoInscripto.o
NoExAsignatura:	
	g++ -Wall -Werror -o ./obj/NoExAsignatura.o -c ./src/exceptions/NoExAsignatura.cpp
	 ./obj/NoExAsignatura.o
NoExEmpresa:
	g++ -Wall -Werror -o ./obj/NoExEmpresa.o -c ./src/exceptions/NoExEmpresa.cpp
	 ./obj/NoExEmpresa.o
NoExEstudiante:	
	g++ -Wall -Werror -o ./obj/NoExEstudiante.o -c ./src/exceptions/NoExEstudiante.cpp
	 ./obj/NoExEstudiante.o
NoExisteSeccion:	
	g++ -Wall -Werror -o ./obj/NoExisteSeccion.o -c ./src/exceptions/NoExisteSeccion.cpp
	 ./obj/NoExisteSeccion.o
NoExisteSucursal:
	g++ -Wall -Werror -o ./obj/NoExisteSucursal.o -c ./src/exceptions/NoExisteSucursal.cpp
	 ./obj/NoExisteSucursal.o
NoExOfertaLaboral:
	g++ -Wall -Werror -o ./obj/NoExOfertaLaboral.o -c ./src/exceptions/NoExOfertaLaboral.cpp
	 ./obj/NoExOfertaLaboral.o
OfertaLaboralVigente:
	g++ -Wall -Werror -o ./obj/OfertaLaboralVigente.o -c ./src/exceptions/OfertaLaboralVigente.cpp
	 ./obj/OfertaLaboralVigente.o
YaExisteOferta:
	g++ -Wall -Werror -o ./obj/YaExisteOferta.o -c ./src/exceptions/YaExisteOferta.cpp
	 ./obj/YaExisteOferta.o
ExOpcionInvalida: 
	g++ -Wall -Werror -o ./obj/ExOpcionInvalida.o -c ./src/exceptions/ExOpcionInvalida.cpp
	 ./obj/ExOpcionInvalida.o
	
Excepciones: 

#manejadores
ManejadorDepartamentos : 
	g++ -Wall -Werror -o ./obj/ManejadorPropiedades.o -c ./src/Manejadores/ManejadorPropiedades.cpp
			./obj/ManejadorPropiedades.o
Manejador_Usuario : 
	g++ -Wall -Werror -o ./obj/Manejador_Usuario.o -c ./src/Manejadores/Manejador_Usuario.cpp
		./obj/Manejador_Usuario.o
ManejadorEdificios: 
	g++ -Wall -Werror -o ./obj/ManejadorEdificios.o -c ./src/Manejadores/ManejadorEdificios.cpp
	 ./obj/ManejadorEdificios.o
ManejadorPropiedades : 
	g++ -Wall -Werror -o ./obj/ManejadorPropiedades.o -c ./src/Manejadores/ManejadorPropiedades.cpp
	 ./obj/ManejadorPropiedades.o

#interfaces
IPropiedadController:
	g++ -Wall -Werror -o ./obj/IPropiedadController.o -c ./src/Interfaces/IPropiedadController.cpp
	 ./obj/IPropiedadController.o
IUsuarioController:
	g++ -Wall -Werror -o ./obj/IUsuarioController.o -c ./src/Interfaces/IUsuarioController.cpp
	 ./obj/IUsuarioController.o
ICargarDatosController: 
	g++ -Wall -Werror -o ./obj/ICargarDatosControllerController.o -c ./src/Interfaces/ICargarDatosController.cpp
	 ./obj/ICargarDatosController.o
IEnviarMensajeController:
	g++ -Wall -Werror -o ./obj/IEnviarMensajeController.o -c ./src/Interfaces/IEnviarMensajeController.cpp
	 ./obj/IEnviarMensajeController.o
IModificarPropiedadController:
	g++ -Wall -Werror -o ./obj/IModificarPropiedadController.o -c ./src/Interfaces/IModificarPropiedadController.cpp
	 ./obj/IModificarPropiedadController.o



#fabrica
Factory: UsuarioController PropiedadController EnviarMensajeController ModificarPropiedadController CargarDatosController 
	g++ -o ./obj/Factory.o -c ./src/Fabrica/Factory.cpp
	 ./obj/Factory.o





#componentes ui
IOConsola : Date
	g++ -o ./obj/IOConsola.o -c ./src/IOConsola.cpp
	 ./obj/IOConsola.o
PantallaUI:
	g++ -o ./obj/PantallaUI.o -c ./src/PantallaUI.cpp
	 ./obj/PantallaUI.o
Menu : PantallaUI ExOpcionInvalida
	g++ -o ./obj/Menu.o -c ./src/Menu.cpp
	 ./obj/Menu.o

#rutinas
RutinaAltaEntrevista: IOConsola
	g++ -o ./obj/RutinaAltaEntrevista.o -c ./src/casosDeUso/RutinaAltaEntrevista.cpp
	 ./obj/RutinaAltaEntrevista.o
	
RutinaAltaOfertaLaboral: IOConsola
	g++ -o ./obj/RutinaAltaOfertaLaboral.o -c ./src/casosDeUso/RutinaAltaOfertaLaboral.cpp
	 ./obj/RutinaAltaOfertaLaboral.o
	
RutinaAsignacionOferta: IOConsola
	g++ -o ./obj/RutinaAsignacionOferta.o -c ./src/casosDeUso/RutinaAsignacionOferta.cpp
	 ./obj/RutinaAsignacionOferta.o
	
RutinaCargarDatosPrueba: IOConsola
	g++ -o ./obj/RutinaCargarDatosPrueba.o -c ./src/casosDeUso/RutinaCargarDatosPrueba.cpp
	 ./obj/RutinaCargarDatosPrueba.o
	
RutinaConsultarDatosEstudiante: IOConsola
	g++ -o ./obj/RutinaConsultarDatosEstudiante.o -c ./src/casosDeUso/RutinaConsultarDatosEstudiante.cpp
	 ./obj/RutinaConsultarDatosEstudiante.o

RutinaDarDeBajaOfertaLaboral: IOConsola
	g++ -o ./obj/RutinaDarDeBajaOfertaLaboral.o -c ./src/casosDeUso/RutinaDarDeBajaOfertaLaboral.cpp
	 ./obj/RutinaDarDeBajaOfertaLaboral.o
	
RutinaInscripcionOfertaLaboral: IOConsola
	g++ -o ./obj/RutinaInscripcionOfertaLaboral.o -c ./src/casosDeUso/RutinaInscripcionOfertaLaboral.cpp
	 ./obj/RutinaInscripcionOfertaLaboral.o
	
RutinaListarOfertasActivas: IOConsola
	g++ -o ./obj/RutinaListarOfertasActivas.o -c ./src/casosDeUso/RutinaListarOfertasActivas.cpp
	 ./obj/RutinaListarOfertasActivas.o
	
RutinaModificarEstudiante: IOConsola
	g++ -o ./obj/RutinaModificarEstudiante.o -c ./src/casosDeUso/RutinaModificarEstudiante.cpp
	 ./obj/RutinaModificarEstudiante.o

RutinaVerNotificaciones: IOConsola
	g++ -o ./obj/RutinaVerNotificaciones.o -c ./src/casosDeUso/RutinaVerNotificaciones.cpp
	 ./obj/RutinaVerNotificaciones.o

RutinaConfigurarFecha: IOConsola
	g++ -o ./obj/RutinaConfigurarFecha.o -c ./src/casosDeUso/RutinaConfigurarFecha.cpp
	 ./obj/RutinaConfigurarFecha.o


Rutinas : RutinaConfigurarFecha RutinaAltaEntrevista RutinaAltaOfertaLaboral RutinaAsignacionOferta RutinaCargarDatosPrueba RutinaConsultarDatosEstudiante RutinaDarDeBajaOfertaLaboral RutinaInscripcionOfertaLaboral RutinaInscripcionOfertaLaboral RutinaListarOfertasActivas RutinaModificarEstudiante RutinaVerNotificaciones 


#menues
MenuUtils : 
	g++ -o ./obj/MenuUtils.o -c ./src/Menus/MenuUtils.cpp
	 ./obj/MenuUtils.o
Menu : UserInterface ExOpcionInvalida MenuUtils
	g++ -o ./obj/Menu.o -c ./src/Menus/Menu.cpp
	 ./obj/Menu.o
MenuAdministradores : ExOpcionInvalida RutinaCerrarSesion RutinaAltaInteresado
	g++ -o ./obj/MenuAdministradores.o -c ./src/Menus/MenuAdministradores.cpp
	 ./obj/MenuAdministradores.o
MenuInmobiliarias : ExOpcionInvalida RutinaCerrarSesion RutinaAltaEdificio RutinaConsultarPropiedad RutinaEnviarMensajeInmobiliaria	RutinaAltaPropiedad
	g++ -o ./obj/MenuInmobiliarias.o -c ./src/Menus/MenuInmobiliarias.cpp
	 ./obj/MenuInmobiliarias.o
MenuInteresados : ExOpcionInvalida RutinaConsultarPropiedad RutinaCerrarSesion RutinaEnviarMensajeInteresado
	g++ -o ./obj/MenuInteresados.o -c ./src/Menus/MenuInteresados.cpp
	 ./obj/MenuInteresados.o
MenuPrincipal : MenuInteresados MenuInmobiliarias MenuAdministradores RutinaInicioSesion Sesion Interesado Inmobiliaria Administrador ExOpcionInvalida
	g++ -o ./obj/MenuPrincipal.o -c ./src/Menus/MenuPrincipal.cpp
	 ./obj/MenuPrincipal.o

	
#mains
MiCasa: MenuPrincipal
	g++ -o ./bin/MiCasa -Wall ./src/MiCasa.cpp ./lib/libTarea2.lib

clean:
	rm ./lib/*.lib
	rm ./obj/*.o
	
all: BuscoFingJobs