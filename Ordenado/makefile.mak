#mains
MiCasa: MenuPrincipal DatosYaCargados Manejadores
	g++ -o ./bin/MiCasa -Wall ./src/MiCasa.cpp

#DataTypes
DataVenta:
	g++ -Wall -Werror -o ./obj/DataVenta.o -c ./src/DataTypes/DataVenta.cpp
DataZona:
	g++ -Wall -Werror -o ./obj/DataZona.o -c ./src/DataTypes/DataZona.cpp
DtInteresado:
	g++ -Wall -Werror -o ./obj/DtInteresado.o -c ./src/DataTypes/DtInteresado.cpp
Fecha:
	g++ -Wall -Werror -o ./obj/Fecha.o -c ./src/DataTypes/Fecha.cpp
Hora:
	g++ -Wall -Werror -o ./obj/Hora.o -c ./src/DataTypes/Hora.cpp
DataAlquiler:
	g++ -Wall -Werror -o ./obj/DataAlquiler.o -c ./src/DataTypes/DataAlquiler.cpp
DataChat:
	g++ -Wall -Werror -o ./obj/DataChat.o -c ./src/DataTypes/DataChat.cpp
DataDepartamento:
	g++ -Wall -Werror -o ./obj/DataDepartamento.o -c ./src/DataTypes/DataDepartamento.cpp
DataDetallePropiedad:
	g++ -Wall -Werror -o ./obj/DataDetallePropiedad.o -c ./src/DataTypes/DataDetallePropiedad.cpp
DataEdificio:
	g++ -Wall -Werror -o ./obj/DataEdificio.o -c ./src/DataTypes/DataEdificio.cpp
DataPropiedad: DataAlquiler DataVenta
	g++ -Wall -Werror -o ./obj/DataPropiedad.o -c ./src/DataTypes/DataPropiedad.cpp
DataApartamento: DataPropiedad
	g++ -Wall -Werror -o ./obj/DataApartamento.o -c ./src/DataTypes/DataApartamento.cpp
DataCasa: DataPropiedad
	g++ -Wall -Werror -o ./obj/DataCasa.o -c ./src/DataTypes/DataCasa.cpp
DataReportePropiedad: DataZona DataDepartamento
	g++ -Wall -Werror -o ./obj/DataReportePropiedad.o -c ./src/DataTypes/DataReportePropiedad.cpp
DataInfoInmobiliaria: DataReportePropiedad
	g++ -Wall -Werror -o ./obj/DataInfoInmobiliaria.o -c ./src/DataTypes/DataInfoInmobiliaria.cpp
DataInfoPropiedad:
	g++-Wall -Werror  -o ./obj/DataInfoPropiedad.o -c ./src/DataTypes/DataInfoPropiedad.cpp
DataInmobiliaria:
	g++ -Wall -Werror -o ./obj/DataInmobiliaria.o -c ./src/DataTypes/DataInmobiliaria.cpp
DataMensaje: Hora Fecha
	g++ -Wall -Werror -o ./obj/DataMensaje.o -c ./src/DataTypes/DataMensaje.cpp
DataReporteApartamento: DataReportePropiedad
	g++ -Wall -Werror -o ./obj/DataReporteApartamento.o -c ./src/DataTypes/DataReporteApartamento.cpp

DataReporteCasa: DataReportePropiedad
	g++ -Wall -Werror -o ./obj/DataReporteCasa.o -c ./src/DataTypes/DataReporteCasa.cpp



DataTypes: DataVenta DataZona DtInteresado Fecha Hora DataAlquiler DataChat DataDepartamento DataDetallePropiedad DataEdificio DataPropiedad DataApartamento DataCasa DataReportePropiedad DataInfoInmobiliaria DataInfoPropiedad DataInmobiliaria DataMensaje DataReporteApartamento DataReporteCasa

#excepciones










Excepciones:



Mensaje: DataMensaje Hora Fecha
	g++ -Wall -Werror -o ./obj/Mensaje.o -c ./src/ClasesDeDominio/Mensaje.cpp
Usuario:
	g++ -Wall -Werror -o ./obj/Usuario.o -c ./src/ClasesDeDominio/Usuario.cpp
Administrador: Usuario
	g++ -Wall -Werror -o ./obj/Administrador.o -c ./src/ClasesDeDominio/Administrador.cpp

Alquiler: DataAlquiler
	g++ -Wall -Werror -o ./obj/Alquiler.o -c ./src/ClasesDeDominio/Alquiler.cpp

Chat: Mensaje DataChat ExNoHayMensajes
	g++ -Wall -Werror -o ./obj/Chat.o -c ./src/ClasesDeDominio/Chat.cpp
Zona: DataZona Propiedad DataDepartamento NoHayPropiedades ExPropiedadNoExistente
	g++ -Wall -Werror -o ./obj/Zona.o -c ./src/ClasesDeDominio/Zona.cpp

Departamento: ExNoHayZonas NoExisteZona YaExisteZona DataDepartamento Zona
	g++ -Wall -Werror -o ./obj/Departamento.o -c ./src/ClasesDeDominio/Departamento.cpp

Apartamento: Propiedad Oferta DataApartamento Zona DataReporteApartamento
	g++ -Wall -Werror -o ./obj/Apartamento.o -c ./src/ClasesDeDominio/Apartamento.cpp
Casa: Propiedad Oferta DataCasa Zona DataReporteCasa
	g++ -Wall -Werror -o ./obj/Casa.o -c ./src/ClasesDeDominio/Casa.cpp

Edificio: Apartamento DataEdificio ExvaloresNoPositivos
	g++ -Wall -Werror -o ./obj/Edificio.o -c ./src/ClasesDeDominio/Edificio.cpp


#controladores

UsuarioController: IUsuarioController Manejador_Usuario WrongPwd Sesion
	g++ -Wall -Werror -o ./obj/UsuarioController.o -c ./src/Controladores/UsuarioController.cpp
PropiedadController: DataTypes IPropiedadController Clases Manejadores Excepciones
	g++ -Wall -Werror -o ./obj/PropiedadController.o -c ./src/Controladores/PropiedadController.cpp
ModificarPropiedadController:IModificarPropiedadController DataPropiedad ProcesoCancelado Sesion Inmobiliaria ManejadorPropiedades
	g++ -Wall -Werror -o ./obj/ModificarPropiedadController.o -c ./src/Controladores/ModificarPropiedadController.cpp
EnviarMensajeController:IEnviarMensajeController Clases Excepciones
	g++ -Wall -Werror -o ./obj/EnviarMensajeController.o -c ./src/Controladores/EnviarMensajeController.cpp
CargarDatosController: Claes ICargarDatosController Excepciones DataTypes Manejadores
	g++ -Wall -Werror -o ./obj/CargarDatosController.o -c ./src/Controladores/CargarDatosController.cpp

Controladores: PropiedadController UsuarioController EnviarMensajeController ModificarPropiedadController CargarDatosController




#manejadores
ManejadorDepartamentos: Departamento NoHayDepartamentos YaExisteDepartamento ExDptoNoExistente
	g++ -Wall -Werror -o ./obj/ManejadorPropiedades.o -c ./src/Manejadores/ManejadorPropiedades.cpp

Manejador_Usuario: Interesado Inmobiliaria Administrador InmobiliariaNotFound InteresadoNotFound UsuarioNotFound ExisteInteresado InmobiliariaYaExistente
	g++ -Wall -Werror -o ./obj/Manejador_Usuario.o -c ./src/Manejadores/Manejador_Usuario.cpp

ManejadorEdificios: Edificio ExisteEdificio EdificioNoExistente NoExistenEdificios
	g++ -Wall -Werror -o ./obj/ManejadorEdificios.o -c ./src/Manejadores/ManejadorEdificios.cpp

ManejadorPropiedades: Propiedad Zona Oferta Edificio DataCasa DataApartamento Casa Apartamento ExPropiedadNoExistente
	g++ -Wall -Werror -o ./obj/ManejadorPropiedades.o -c ./src/Manejadores/ManejadorPropiedades.cpp

Manejadores: ManejadorPropiedades ManejadorEdificios Manejador_Usuario ManejadorDepartamentos

#interfaces
IPropiedadController:
	g++ -Wall -Werror -o ./obj/IPropiedadController.o -c ./src/Interfaces/IPropiedadController.cpp

IUsuarioController:
	g++ -Wall -Werror -o ./obj/IUsuarioController.o -c ./src/Interfaces/IUsuarioController.cpp

ICargarDatosController:
	g++ -Wall -Werror -o ./obj/ICargarDatosControllerController.o -c ./src/Interfaces/ICargarDatosController.cpp

IEnviarMensajeController:
	g++ -Wall -Werror -o ./obj/IEnviarMensajeController.o -c ./src/Interfaces/IEnviarMensajeController.cpp

IModificarPropiedadController:
	g++ -Wall -Werror -o ./obj/IModificarPropiedadController.o -c ./src/Interfaces/IModificarPropiedadController.cpp


Interfaces: IPropiedadController IUsuarioController IEnviarMensajeController IModificarPropiedadController ICargarDatosController

#fabrica

Factory: PropiedadController UsuarioController EnviarMensajeController ModificarPropiedadController CargarDatosController
	g++ -Wall -Werror -o ./obj/Factory.o -c ./src/Fabrica/Factory.cpp




#componentes ui
UserInterface :
	g++ -o ./obj/UserInterface.o -c ./src/UserInterface.cpp


#rutinas
RutinaAltaEntrevista: IOConsola
	g++ -o ./obj/RutinaAltaEntrevista.o -c ./src/casosDeUso/RutinaAltaEntrevista.cpp

RutinaAltaOfertaLaboral: IOConsola
	g++ -o ./obj/RutinaAltaOfertaLaboral.o -c ./src/casosDeUso/RutinaAltaOfertaLaboral.cpp


RutinaAsignacionOferta: IOConsola
	g++ -o ./obj/RutinaAsignacionOferta.o -c ./src/casosDeUso/RutinaAsignacionOferta.cpp


RutinaCargarDatosPrueba: IOConsola
	g++ -o ./obj/RutinaCargarDatosPrueba.o -c ./src/casosDeUso/RutinaCargarDatosPrueba.cpp


RutinaConsultarDatosEstudiante: IOConsola
	g++ -o ./obj/RutinaConsultarDatosEstudiante.o -c ./src/casosDeUso/RutinaConsultarDatosEstudiante.cpp


RutinaDarDeBajaOfertaLaboral: IOConsola
	g++ -o ./obj/RutinaDarDeBajaOfertaLaboral.o -c ./src/casosDeUso/RutinaDarDeBajaOfertaLaboral.cpp

RutinaInscripcionOfertaLaboral: IOConsola
	g++ -o ./obj/RutinaInscripcionOfertaLaboral.o -c ./src/casosDeUso/RutinaInscripcionOfertaLaboral.cpp

RutinaListarOfertasActivas: IOConsola
	g++ -o ./obj/RutinaListarOfertasActivas.o -c ./src/casosDeUso/RutinaListarOfertasActivas.cpp



RutinaModificarEstudiante: IOConsola
	g++ -o ./obj/RutinaModificarEstudiante.o -c ./src/casosDeUso/RutinaModificarEstudiante.cpp

RutinaVerNotificaciones: IOConsola
	g++ -o ./obj/RutinaVerNotificaciones.o -c ./src/casosDeUso/RutinaVerNotificaciones.cpp


RutinaConfigurarFecha: IOConsola
	g++ -o ./obj/RutinaConfigurarFecha.o -c ./src/casosDeUso/RutinaConfigurarFecha.cpp



Rutinas :


#menues
MenuUtils : Fecha
	g++ -Wall -Werror -o ./obj/MenuUtils.o -c ./src/Menus/MenuUtils.cpp

Menu : UserInterface ExOpcionInvalida MenuUtils
	g++ -Wall -Werror -o ./obj/Menu.o -c ./src/Menus/Menu.cpp

MenuAdministradores : Menu RutinaAltaInmobiliaria RutinaCerrarSesion RutinaAltaInteresado Sesion
	g++ -Wall -Werror -o ./obj/MenuAdministradores.o -c ./src/Menus/MenuAdministradores.cpp

MenuInmobiliarias : Menu Rutinas Sesion
	g++ -Wall -Werror -o ./obj/MenuInmobiliarias.o -c ./src/Menus/MenuInmobiliarias.cpp

MenuInteresados : Menu RutinaConsultarPropiedad RutinaCerrarSesion RutinaEnviarMensajeInteresado Sesion
	g++ -Wall -Werror -o ./obj/MenuInteresados.o -c ./src/Menus/MenuInteresados.cpp

MenuPrincipal : Menu MenuInteresados MenuInmobiliarias MenuAdministradores RutinaInicioSesion Sesion Interesado Inmobiliaria Administrador
	g++ -Wall -Werror -o ./obj/MenuPrincipal.o -c ./src/Menus/MenuPrincipal.cpp




clean:
	rm ./lib/*.lib
	rm ./obj/*.o
	rm ./bin/MiCasa

all: MiCasa
