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
<<<<<<< HEAD
DataChat: 
	g++ -Wall -Werror -o ./obj/DataChat.o -c ./src/DataTypes/DataChat.cpp
DataDepartamento: 
=======
DataChat:
	g++ -Wall -Werror -o ./obj/DataChat.o -c ./src/DataTypes/DataChat.cpp
DataDepartamento:
>>>>>>> fa2d8ddbb7f1e71eefc34a50ac328f7cdaecf96e
	g++ -Wall -Werror -o ./obj/DataDepartamento.o -c ./src/DataTypes/DataDepartamento.cpp
DataDetallePropiedad:
	g++ -Wall -Werror -o ./obj/DataDetallePropiedad.o -c ./src/DataTypes/DataDetallePropiedad.cpp
DataEdificio:
	g++ -Wall -Werror -o ./obj/DataEdificio.o -c ./src/DataTypes/DataEdificio.cpp
DataPropiedad: DataAlquiler DataVenta
	g++ -Wall -Werror -o ./obj/DataPropiedad.o -c ./src/DataTypes/DataPropiedad.cpp
DataApartamento: DataPropiedad
	g++ -Wall -Werror -o ./obj/DataApartamento.o -c ./src/DataTypes/DataApartamento.cpp
<<<<<<< HEAD
DataCasa: DataPropiedad 
=======
DataCasa: DataPropiedad
>>>>>>> fa2d8ddbb7f1e71eefc34a50ac328f7cdaecf96e
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
<<<<<<< HEAD
=======

>>>>>>> fa2d8ddbb7f1e71eefc34a50ac328f7cdaecf96e
DataReporteCasa: DataReportePropiedad
	g++ -Wall -Werror -o ./obj/DataReporteCasa.o -c ./src/DataTypes/DataReporteCasa.cpp



DataTypes: DataVenta DataZona DtInteresado Fecha Hora DataAlquiler DataChat DataDepartamento DataDetallePropiedad DataEdificio DataPropiedad DataApartamento DataCasa DataReportePropiedad DataInfoInmobiliaria DataInfoPropiedad DataInmobiliaria DataMensaje DataReporteApartamento DataReporteCasa

#excepciones
<<<<<<< HEAD
DatosYaCargados: 
	g++ -Wall -Werror -o ./obj/DatosYaCargados.o -c ./src/Excepciones/DatosYaCargados.cpp
EdificioNoExistente:	
	g++ -Wall -Werror -o ./obj/EdificioNoExistente.o -c ./src/Excepciones/EdificioNoExistente.cpp
ExDptoNoExistente:
	g++ -Wall -Werror -o ./obj/ExDptoNoExistente.o -c ./src/Excepciones/ExDptoNoExistente.cpp
ExisteEdificio:	
	g++ -Wall -Werror -o ./obj/ExisteEdificio.o -c ./src/Excepciones/ExisteEdificio.cpp
ExisteInteresado:	
	g++ -Wall -Werror -o ./obj/ExisteInteresado.o -c ./src/Excepciones/ExisteInteresado.cpp
ExNoHayMensajes:
	g++ -Wall -Werror -o ./obj/ExNoHayMensajes.o -c ./src/Excepciones/ExNoHayMensajes.cpp
ExNoHayZonas:
	g++ -Wall -Werror -o ./obj/ExNoHayZonas.o -c ./src/Excepciones/ExNoHayZonas.cpp
ExOpcionInvalida:
	g++ -Wall -Werror -o ./obj/ExOpcionInvalida.o -c ./src/Excepciones/ExOpcionInvalida.cpp
ExPropiedadNoExistente:
	g++ -Wall -Werror -o ./obj/ExPropiedadNoExistente.o -c ./src/Excepciones/ExPropiedadNoExistente.cpp
ExvaloresNoPositivos: 
	g++ -Wall -Werror -o ./obj/ExValoresNoPositivos.o -c ./src/Excepciones/ExValoresNoPositivos.cpp
FechaInvalida: 
	g++ -Wall -Werror -o ./obj/FechaInvalida.o -c ./src/Excepciones/FechaInvalida.cpp
HoraInvalida: 
	g++ -Wall -Werror -o ./obj/HoraInvalida.o -c ./src/Excepciones/HoraInvalida.cpp
InmobiliariaNotFound: 
	g++ -Wall -Werror -o ./obj/InmobiliariaNotFound.o -c ./src/Excepciones/InmobiliariaNotFound.cpp
InmobiliariaYaExistente: 
	g++ -Wall -Werror -o ./obj/InmobiliariaYaExistente.o -c ./src/Excepciones/InmobiliariaYaExistente.cpp
InteresadoNotFound: 
	g++ -Wall -Werror -o ./obj/InteresadoNotFound.o -c ./src/Excepciones/InteresadoNotFound.cpp
NoExisteChat: 
	g++ -Wall -Werror -o ./obj/NoExisteChat.o -c ./src/Excepciones/NoExisteChat.cpp
NoExistenEdificios: 
	g++ -Wall -Werror -o ./obj/NoExistenEdificios.o -c ./src/Excepciones/NoExistenEdificios.cpp
NoExisteZona: 
	g++ -Wall -Werror -o ./obj/NoExisteZona.o -c ./src/Excepciones/NoExisteZona.cpp
NoHayChatEnMemoria: 
	g++ -Wall -Werror -o ./obj/NoHayChatEnMemoria.o -c ./src/Excepciones/NoHayChatEnMemoria.cpp
NoHayConversaciones: 
	g++ -Wall -Werror -o ./obj/NoHayConversaciones.o -c ./src/Excepciones/NoHayConversaciones.cpp
NoHayDepartamentoEnMemoria: 
	g++ -Wall -Werror -o ./obj/NoHayDepartamentoEnMemoria.o -c ./src/Excepciones/NoHayDepartamentoEnMemoria.cpp
NoHayDepartamentos: 
	g++ -Wall -Werror -o ./obj/NoHayDepartamentos.o -c ./src/Excepciones/NoHayDepartamentos.cpp
NoHayPropiedades: 
	g++ -Wall -Werror -o ./obj/NoHayPropiedades.o -c ./src/Excepciones/NoHayPropiedades.cpp
PrecioInvalido: 
	g++ -Wall -Werror -o ./obj/PrecioInvalido.o -c ./src/Excepciones/PrecioInvalido.cpp
ProcesoCancelado: 
	g++ -Wall -Werror -o ./obj/ProcesoCancelado.o -c ./src/Excepciones/ProcesoCancelado.cpp
UsuarioNotFound: 
	g++ -Wall -Werror -o ./obj/UsuarioNotFound.o -c ./src/Excepciones/UsuarioNotFound.cpp
ValoresInvalidos: 
	g++ -Wall -Werror -o ./obj/ValoresInvalidos.o -c ./src/Excepciones/ValoresInvalidos.cpp
WrongPwd: 
	g++ -Wall -Werror -o ./obj/WrongPwd.o -c ./src/Excepciones/WrongPwd.cpp
YaExisteDepartamento: 
	g++ -Wall -Werror -o ./obj/YaExisteDepartamento.o -c ./src/Excepciones/YaExisteDepartamento.cpp
YaExistePropiedad: 
	g++ -Wall -Werror -o ./obj/YaExistePropiedad.o -c ./src/Excepciones/YaExistePropiedad.cpp
YaExisteZona: 
	g++ -Wall -Werror -o ./obj/YaExisteZona.o -c ./src/Excepciones/YaExisteZona.cpp
	
Excepciones: DatosYaCargados EdificioNoExistente ExDptoNoExistente ExisteEdificio ExisteInteresado ExNoHayMensajes ExNoHayZonas ExOpcionInvalida ExPropiedadNoExistente ExvaloresNoPositivos FechaInvalida HoraInvalida InmobiliariaNotFound InmobiliariaYaExistente InteresadoNotFound NoExisteChat NoExistenEdificios NoExisteZona NoHayChatEnMemoria NoHayConversaciones NoHayDepartamentoEnMemoria NoHayDepartamentos NoHayPropiedades PrecioInvalido ProcesoCancelado UsuarioNotFound ValoresInvalidos WrongPwd YaExisteDepartamento YaExistePropiedad YaExisteZona

#manejadores
ManejadorDepartamentos : Excepciones DataTypes Clases
	g++ -Wall -Werror -o ./obj/ManejadorPropiedades.o -c ./src/Manejadores/ManejadorPropiedades.cpp

Manejador_Usuario : Excepciones DataTypes Clases
	g++ -Wall -Werror -o ./obj/Manejador_Usuario.o -c ./src/Manejadores/Manejador_Usuario.cpp

ManejadorEdificios: Excepciones DataTypes Clases
	g++ -Wall -Werror -o ./obj/ManejadorEdificios.o -c ./src/Manejadores/ManejadorEdificios.cpp

ManejadorPropiedades : Excepciones DataTypes Clases
	g++ -Wall -Werror -o ./obj/ManejadorPropiedades.o -c ./src/Manejadores/ManejadorPropiedades.cpp

=======










Excepciones:



Mensaje: DataMensaje Hora Fecha
	g++ -Wall -Werror -o ./obj/Mensaje.o -c ./src/ClasesDeDominio/Mensaje.cpp
Usuario:
	g++ -Wall -Werror -o ./obj/Usuario.o -c ./src/ClasesDeDominio/Usuario.cpp
Administrador: Usuario
	g++ -Wall -Werror -o ./obj/Administrador.o -c ./src/ClasesDeDominio/Administrador.cpp

Alquiler: DataAlquiler
	g++ -Wall -Werror -o ./obj/Alquiler.o -c ./src/ClasesDeDominio/Alquiler.cpp

Apartamento: Propiedad Oferta DataApartamento Zona DataReporteApartamento
	g++ -Wall -Werror -o ./obj/Apartamento.o -c ./src/ClasesDeDominio/Apartamento.cpp
Casa: Propiedad Oferta DataApartamento Zona DataReporteApartamento
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
>>>>>>> fa2d8ddbb7f1e71eefc34a50ac328f7cdaecf96e

#interfaces
IPropiedadController:
	g++ -Wall -Werror -o ./obj/IPropiedadController.o -c ./src/Interfaces/IPropiedadController.cpp

IUsuarioController:
	g++ -Wall -Werror -o ./obj/IUsuarioController.o -c ./src/Interfaces/IUsuarioController.cpp

<<<<<<< HEAD
ICargarDatosController: 
=======
ICargarDatosController:
>>>>>>> fa2d8ddbb7f1e71eefc34a50ac328f7cdaecf96e
	g++ -Wall -Werror -o ./obj/ICargarDatosControllerController.o -c ./src/Interfaces/ICargarDatosController.cpp

IEnviarMensajeController:
	g++ -Wall -Werror -o ./obj/IEnviarMensajeController.o -c ./src/Interfaces/IEnviarMensajeController.cpp

IModificarPropiedadController:
	g++ -Wall -Werror -o ./obj/IModificarPropiedadController.o -c ./src/Interfaces/IModificarPropiedadController.cpp
<<<<<<< HEAD
=======


Interfaces: IPropiedadController IUsuarioController IEnviarMensajeController IModificarPropiedadController ICargarDatosController
>>>>>>> fa2d8ddbb7f1e71eefc34a50ac328f7cdaecf96e

UserInterface:
	g++ -Wall -Werror -o ./obj/UserInterface.o -c ./src/Interfaces/UserInterface.cpp
	
#fabrica
<<<<<<< HEAD
Factory: UsuarioController PropiedadController EnviarMensajeController ModificarPropiedadController CargarDatosController 
	g++ -Wall -Werror -o ./obj/Factory.o -c ./src/Fabrica/Factory.cpp

#Clases
Venta: DataTypes 
	g++ -Wall -Werror -o ./obj/Venta.o -c ./src/Clases/Venta.cpp
Usuario: 
	g++ -Wall -Werror -o ./obj/Usuario.o -c ./src/Clases/Usuario.cpp
Sesion: Usuario
	g++ -Wall -Werror -o ./obj/Sesion.o -c ./src/Clases/Sesion.cpp
Administrador: 
	g++ -Wall -Werror -o ./obj/Administrador.o -c ./src/Clases/Administrador.cpp
Alquiler: DataTypes
	g++ -Wall -Werror -o ./obj/Alquiler.o -c ./src/Clases/Alquiler.cpp
Mensaje: DataTypes
	g++ -Wall -Werror -o ./obj/Mensaje.o -c ./src/Clases/Mensaje.cpp
Interesado: Usuario Chat DataTypes
	g++ -Wall -Werror -o ./obj/Interesado.o -c ./src/Clases/Interesado.cpp
Departamento: DataTypes Excepciones Zona
	g++ -Wall -Werror -o ./obj/Departamento.o -c ./src/Clases/Departamento.cpp
Zona: Propiedad Departamento Excepciones DataTypes
	g++ -Wall -Werror -o ./obj/Mensaje.o -c ./src/Clases/Mensaje.cpp
Apartamento: Zona Edificio Propiedad Oferta DataTypes  
	g++ -Wall -Werror -o ./obj/Apartamento.o -c ./src/Clases/Apartamento.cpp
Edificio: Apartamento Excepciones DataTypes
	g++ -Wall -Werror -o ./obj/Edificio.o -c ./src/Clases/Edificio.cpp
Casa: Zona Propiedad Oferta DataTypes
	g++ -Wall -Werror -o ./obj/Casa.o -c ./src/Clases/Casa.cpp
Chat: Interesado Propiedad Inmobiliaria Excepciones Mensaje DataTypes
	g++ -Wall -Werror -o ./obj/Chat.o -c ./src/Clases/Chat.cpp
Inmobiliaria: Usuario Chat Oferta Excepciones DataTypes
	g++ -Wall -Werror -o ./obj/Inmobiliaria.o -c ./src/Clases/Inmobiliaria.cpp
Oferta: Venta Alquiler Inmobiliaria Propiedad 
	g++ -Wall -Werror -o ./obj/Oferta.o -c ./src/Clases/Oferta.cpp
Propiedad: Zona Oferta Chat Alquiler Venta DataTypes
	g++ -Wall -Werror -o ./obj/Propiedad.o -c ./src/Clases/Propiedadopiedad.cpp


Clases: Venta Usuario Sesion Administrador Alquiler Mensaje Interesado Departamento Zona Edificio Casa Chat Inmobiliaria Oferta Propiedad

#rutinas
RutinaAltaEdificio: Interfaces DataTypes Menues Excepciones
	g++ -Wall -Werror -o ./obj/RutinaAltaEdificio.o -c ./src/Rutinas/RutinaAltaEdificio.cpp
	
RutinaAltaInmobiliaria: UserInterface DataTypes Excepciones Factory
	g++ -Wall -Werror -o ./obj/RutinaAltaInmobiliaria.o -c ./src/Rutinas/RutinaAltaInmobiliaria.cpp
	
RutinaAltaInteresado: Menues Interfaces DataTypes Excepciones Factory
	g++ -Wall -Werror -o ./obj/RutinaAltaInteresado.o -c ./src/Rutinas/RutinaAltaInmobiliaria.cpp
	
RutinaConsultarPropiedad: Interfaces Excepciones DataTypes Factory Menues
	g++ -Wall -Werror -o ./obj/RutinaConsultarPropiedad.o -c ./src/Rutinas/RutinaConsultarPropiedad.cpp
	
RutinaAltaPropiedad: Menues DataTypes Excepciones Interfaces Factory RutinaConsultarPropiedad
	g++ -Wall -Werror -o ./obj/RutinaCargarDatosPrueba.o -c ./src/Rutinas/RutinaCargarDatosPrueba.cpp
	
RutinaCargarDatos: Menues Factory Excepciones Interfaces 
	g++ -Wall -Werror -o ./obj/RutinaCargarDatos.o -c ./src/Rutinas/RutinaCargarDatos.cpp
	
RutinaCerrarSesion: Interfaces Menues Factory
	g++ -Wall -Werror -o ./obj/RutinaCerrarSesion.o -c ./src/Rutinas/RutinaCerrarSesion.cpp
	
RutinaEliminarPropiedad: Interfaces Excepciones Menues Factory
	g++ -Wall -Werror -o ./obj/RutinaEliminarPropiedad.o -c ./src/Rutinas/RutinaEliminarPropiedad.cpp
	
RutinaEnviarMensajeInmobiliaria: Interfaces Clases DataTypes Factory Excepciones Menues
	g++ -Wall -Werror -o ./obj/RutinaEnviarMensajeInmobiliaria.o -c ./src/Rutinas/RutinaEnviarMensajeInmobiliaria.cpp

RutinaEnviarMensajeInteresado: Interfaces Clases DataTypes Factory Excepciones
	g++ -Wall -Werror -o ./obj/RutinaEnviarMensajeInteresado.o -c ./src/Rutinas/RutinaEnviarMensajeInteresado.cpp

RutinaInicioSesion: Interfaces Manejadores Excepciones Menues DataTypes Factory
	g++ -Wall -Werror -o ./obj/RutinaInicioSesion.o -c ./src/Rutinas/RutinaInicioSesion.cpp
	
RutinaModificarPropiedad: Excepciones DataTypes Factory
	g++ -Wall -Werror -o ./obj/RutinaInicioSesion.o -c ./src/Rutinas/RutinaInicioSesion.cpp
	
RutinaObtenerReporteInmobiliaria: Interfaces Manejadores Excepciones Menues DataTypes Factory
	g++ -Wall -Werror -o ./obj/RutinaInicioSesion.o -c ./src/Rutinas/RutinaInicioSesion.cpp


Rutinas :  RutinaAltaEdificio RutinaAltaInmobiliaria RutinaAltaInteresado RutinaAltaPropiedad RutinaCargarDatos RutinaCerrarSesion RutinaConsultarPropiedad RutinaEliminarPropiedad RutinaEnviarMensajeInmobiliaria RutinaEnviarMensajeInteresado RutinaInicioSesion RutinaModificarPropiedad RutinaModificarPropiedad RutinaObtenerReporteInmobiliaria


#menues
MenuUtils : 
	g++ -Wall -Werror -o ./obj/MenuUtils.o -c ./src/Menus/MenuUtils.cpp
Menu : UserInterface ExOpcionInvalida MenuUtils
	g++ -Wall -Werror -o ./obj/Menu.o -c ./src/Menus/Menu.cpp
MenuAdministradores : ExOpcionInvalida RutinaCerrarSesion RutinaAltaInteresado
	g++ -Wall -Werror -o ./obj/MenuAdministradores.o -c ./src/Menus/MenuAdministradores.cpp
MenuInmobiliarias : ExOpcionInvalida RutinaCerrarSesion RutinaAltaEdificio RutinaConsultarPropiedad RutinaEnviarMensajeInmobiliaria	RutinaAltaPropiedad
	g++ -Wall -Werror -o ./obj/MenuInmobiliarias.o -c ./src/Menus/MenuInmobiliarias.cpp
MenuInteresados : ExOpcionInvalida RutinaConsultarPropiedad RutinaCerrarSesion RutinaEnviarMensajeInteresado
	g++ -Wall -Werror -o ./obj/MenuInteresados.o -c ./src/Menus/MenuInteresados.cpp
MenuPrincipal : MenuInteresados MenuInmobiliarias MenuAdministradores RutinaInicioSesion Sesion Interesado Inmobiliaria Administrador ExOpcionInvalida
	g++ -Wall -Werror -o ./obj/MenuPrincipal.o -c ./src/Menus/MenuPrincipal.cpp
	
Menues: MenuUtils UserInterface MenuAdministradores MenuInmobiliarias MenuInteresados MenuPrincipal	
	
#mains
MiCasa: MenuPrincipal
	g++ -Wall -Werror -o ./bin/MiCasa -Wall ./src/MiCasa.cpp ./lib/libTarea2.lib
=======

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



#mains
MiCasa: MenuPrincipal DatosYaCargados Manejadores
	g++ -o ./bin/MiCasa -Wall ./src/MiCasa.cpp
>>>>>>> fa2d8ddbb7f1e71eefc34a50ac328f7cdaecf96e

clean:
	rm ./lib/*.lib
	rm ./obj/*.o
	rm ./bin/MiCasa

all: MiCasa
