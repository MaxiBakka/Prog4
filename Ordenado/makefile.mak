#mains
MiCasa: MenuPrincipal DatosYaCargados Manejadores
	g++ -o ./bin/MiCasa -Wall ./src/MiCasa.cpp

#excepciones

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


#DataTypes
DataVenta:
	g++ -Wall -Werror -o ./obj/DataVenta.o -c ./src/DataTypes/DataVenta.cpp
DataZona:
	g++ -Wall -Werror -o ./obj/DataZona.o -c ./src/DataTypes/DataZona.cpp
DtInteresado:
	g++ -Wall -Werror -o ./obj/DtInteresado.o -c ./src/DataTypes/DtInteresado.cpp
Fecha: FechaInvalida
	g++ -Wall -Werror -o ./obj/Fecha.o -c ./src/DataTypes/Fecha.cpp
Hora: HoraInvalida
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





Mensaje: DataMensaje Hora Fecha
	g++ -Wall -Werror -o ./obj/Mensaje.o -c ./src/ClasesDeDominio/Mensaje.cpp
Usuario:
	g++ -Wall -Werror -o ./obj/Usuario.o -c ./src/ClasesDeDominio/Usuario.cpp
Sesion: Usuario
	g++ -Wall -Werror -o ./obj/Sesion.o -c ./src/ClasesDeDominio/Sesion.cpp

Administrador: Usuario
	g++ -Wall -Werror -o ./obj/Administrador.o -c ./src/ClasesDeDominio/Administrador.cpp

Alquiler: DataAlquiler
	g++ -Wall -Werror -o ./obj/Alquiler.o -c ./src/ClasesDeDominio/Alquiler.cpp
Venta: DataVenta
	g++ -Wall -Werror -o ./obj/Venta.o -c ./src/ClasesDeDominio/Venta.cpp

Propiedad: Zona.h Oferta.h Chat Alquiler Venta DataInfoPropiedad DataReportePropiedad DataPropiedad DataDetallePropiedad
	g++ -Wall -Werror -o ./obj/Propiedad.o -c ./src/ClasesDeDominio/Propiedad.cpp

Chat: Mensaje DataChat ExNoHayMensajes Interesado.h Propiedad.h Inmobiliaria.h
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

Inmobiliaria: Usuario Chat DataInfoInmobiliaria DataInmobiliaria NoExisteChat DataReportePropiedad Oferta.h
	g++ -Wall -Werror -o ./obj/Inmobiliaria.o -c ./src/ClasesDeDominio/Inmobiliaria.cpp

Interesado: Usuario Chat NoExisteChat DtInteresado
	g++ -Wall -Werror -o ./obj/Interesado.o -c ./src/ClasesDeDominio/Interesado.cpp

Oferta: Venta Alquiler Inmobiliaria Propiedad
	g++ -Wall -Werror -o ./obj/Oferta.o -c ./src/ClasesDeDominio/Oferta.cpp


Clases: Venta Usuario Sesion Administrador Alquiler Mensaje Interesado Departamento Zona Edificio Casa Chat Inmobiliaria Oferta Apartamento Propiedad

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
RutinaAltaEdificio: Interfaces DataTypes Menues Excepciones
	g++ -Wall -Werror -o ./obj/RutinaAltaEdificio.o -c ./src/Rutinas/RutinaAltaEdificio.cpp
RutinaAltaInmobiliaria: UserInterface DataTypes Excepciones Factory
	g++ -Wall -Werror -o ./obj/RutinaAltaInmobiliaria.o -c ./src/Rutinas/RutinaAltaInmobiliaria.cpp

RutinaAltaInteresado: Menues Interfaces DataTypes Excepciones Factory
	g++ -Wall -Werror -o ./obj/RutinaAltaInteresado.o -c ./src/Rutinas/RutinaAltaInmobiliaria.cpp

RutinaConsultarPropiedad: Interfaces Excepciones DataTypes Factory Menues
	g++ -Wall -Werror -o ./obj/RutinaConsultarPropiedad.o -c ./src/Rutinas/RutinaConsultarPropiedad.cpp

RutinaAltaPropiedad: Menues DataTypes Excepciones Interfaces Factory RutinaConsultarPropiedad UserInterface
	g++ -Wall -Werror -o ./obj/RutinaCargarDatosPrueba.o -c ./src/Rutinas/RutinaCargarDatosPrueba.cpp

RutinaCargarDatos: Menues Factory Excepciones Interfaces
	g++ -Wall -Werror -o ./obj/RutinaCargarDatos.o -c ./src/Rutinas/RutinaCargarDatos.cpp

RutinaCerrarSesion: Interfaces Menues Factory UserInterface
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

Menues: Menu MenuUtils MenuAdministradores MenuInmobiliarias MenuInteresados MenuPrincipal


clean:
	rm ./obj/*.o
	rm ./bin/MiCasa

all: MiCasa
