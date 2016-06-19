#include "CargarDatosController.h"
#include <utility>
#include <map>

#include "../Manejadores/ManejadorEdificios.h"
#include "../Manejadores/ManejadorDepartamentos.h"
#include "../Manejadores/ManejadorPropiedades.h"
#include "../Manejadores/Manejador_Usuario.h"



#include "../DataTypes/DataPropiedad.h"
#include "../DataTypes/DataDepartamento.h"
#include "../DataTypes/DataEdificio.h"
#include "../DataTypes/DataInmobiliaria.h"
#include "../DataTypes/DataCasa.h"
#include "../DataTypes/DataApartamento.h"
#include "../DataTypes/DtInteresado.h"
#include "../DataTypes/DataMensaje.h"
#include "../DataTypes/Hora.h"
#include "../DataTypes/Fecha.h"

#include "../Excepciones/ExOpcionInvalida.h"
#include "../Excepciones/DatosYaCargados.h"



using namespace std;

bool CargarDatosController::DatosCargados = false;

CargarDatosController::CargarDatosController(){

this->refEdificios= new map<string,Edificio*>();
refApartamentos= new map<string,Propiedad*>();
refCasas= new map<string,Propiedad*>();
refDepartamentos= new map<string,Departamento*>();
refZonas= new map<string,Zona*>();
refInteresados= new map<string,Interesado*>();
refInmobiliarias= new map<string,Inmobiliaria*>();
refChats= new map<string,Chat*>();
administrador=NULL;
}

CargarDatosController::~CargarDatosController() {

	delete refEdificios;
	delete refApartamentos;
	delete refCasas;
	delete refInteresados;
	delete refInmobiliarias;
	delete refChats;
	delete refZonas;
	delete refDepartamentos;

}

void CargarDatosController::cargarInmobiliarias(){

  Manejador_Usuario* mu = Manejador_Usuario::getInstancia();
  DataInmobiliaria* di;
  Inmobiliaria* inmobiliaria;
  string ref, email,password,nombre,direccion;
  int i=0;

while (i<4) {

      switch(i){
  	case 0:
  		ref="I1";email="inm1@sis.com";nombre="Selmo";
      password="pass4";direccion="Benitez 1134";
      di= new DataInmobiliaria(nombre,email,direccion);
      i++;
      break;
  	case 1:
      ref="I2";email="inm2@sis.com";nombre="Garcia";
      password="pass5";direccion="Rivera 1340";
      di= new DataInmobiliaria(nombre,email,direccion);
      i++;
      break;
  	case 2:
      ref="I3";email="inm3@sis.com";nombre="Invernissi";
      password="pass6";direccion="Comercio 234";
      di= new DataInmobiliaria(nombre,email,direccion);
      i++;
      break;
  	case 3:
      ref="I4";email="inm4@sis.com";nombre="Solei";
      password="pass7";direccion="Inca 3456";
      di= new DataInmobiliaria(nombre,email,direccion);
      i++;
      break;
  	default:
  		throw ExOpcionInvalida();
  	}

    mu->CrearInmobiliaria(di);
    inmobiliaria=mu->getInmobiliaria(email);
    inmobiliaria->set_contrasenia(password);
  		delete di;
  			refInmobiliarias->insert(std::pair<string,Inmobiliaria*>(ref,inmobiliaria));

}
}

void CargarDatosController::cargarDepartamentos(){

  ManejadorDepartamentos* md = ManejadorDepartamentos::getInstancia();
  string ref, letra, nombre;
  DataDepartamento*ddpto;
  Departamento*dpto;
  int i=0;

while (i<5) {

      switch(i){
  	case 0:
  		ref="D1";letra="A";nombre="Canelones";
      ddpto= new DataDepartamento(nombre,letra);
      i++;
      break;
  	case 1:
  		ref="D2";letra="B";nombre="Maldonado";
      ddpto= new DataDepartamento(nombre,letra);
      i++;
      break;
  	case 2:
  		ref="D3";letra="C";nombre="Rocha";
      ddpto= new DataDepartamento(nombre,letra);
      i++;
      break;
  	case 3:
      ref="D4";letra="D";nombre="Salto";
      ddpto= new DataDepartamento(nombre,letra);
      i++;
      break;
  	case 4:
      ref="D5";letra="E";nombre="Montevideo";
      ddpto= new DataDepartamento(nombre,letra);
      i++;
      break;
  	default:
  		throw ExOpcionInvalida();
  	}

    md->AgregarDepartamento(ddpto);
  			delete ddpto;
  			dpto = md->getDepartamento(letra);
  			refDepartamentos->insert(std::pair<string,Departamento*>(ref,dpto));

}
}

void CargarDatosController::cargarZonas(){
  Zona* zona;
  Departamento* dpto;
  string nombre,ref;
  int codigo;
  int i=0;
  while (i<5){

    switch (i) {
      case 0:
          ref="Z1";nombre="Zona1";codigo=101;
          dpto = refDepartamentos->find("D1")->second;
          zona = new Zona(codigo,nombre,dpto);
          dpto->AddZona(zona);
          i++;
          break;
      case 1:
          ref="Z2";nombre="Zona2";codigo=102;
          dpto= refDepartamentos->find("D1")->second;
          zona = new Zona(codigo,nombre,dpto);
          dpto->AddZona(zona);
          i++;
          break;
      case 2:
          ref="Z3";nombre="Zona3";codigo=103;
          dpto= refDepartamentos->find("D2")->second;
          zona = new Zona(codigo,nombre,dpto);
          dpto->AddZona(zona);
          i++;
          break;
      case 3:
          ref="Z4";nombre="Zona4";codigo=104;
          dpto= refDepartamentos->find("D4")->second;
          zona = new Zona(codigo,nombre,dpto);
          dpto->AddZona(zona);
          i++;
          break;
      case 4:
          ref="Z5";nombre="Zona5";codigo=105;
          dpto= refDepartamentos->find("D4")->second;
          zona = new Zona(codigo,nombre,dpto);
          dpto->AddZona(zona);
          i++;
          break;
      default:
        throw ExOpcionInvalida();
    }

    refZonas->insert(std::pair<string,Zona*>(ref,zona));
  }
}

void CargarDatosController::cargarEdificios(){

ManejadorEdificios* me = ManejadorEdificios::getInstancia();
Edificio* ed;
DataEdificio* ded;
float gCom;
int cantidadPisos;
string nombre,ref;
int i=0;

while(i<5){

  switch (i) {
    case 0:
      ref="E1";nombre="Apache Valiente";cantidadPisos=4;gCom=1300;
      ded= new DataEdificio(nombre,cantidadPisos,gCom);
      i++;
      break;
    case 1:
      ref="E2";nombre="Mebeo";cantidadPisos=20;gCom=755;
      ded= new DataEdificio(nombre,cantidadPisos,gCom);
      i++;
      break;
    case 2:
      ref="E3";nombre="Socrates";cantidadPisos=34;gCom=134;
      ded= new DataEdificio(nombre,cantidadPisos,gCom);
      i++;
      break;
    case 3:
      ref="E4";nombre="El Burdel";cantidadPisos=12;gCom=450;
      ded= new DataEdificio(nombre,cantidadPisos,gCom);
      i++;
      break;
    case 4:
      ref="E5";nombre="Milajo";cantidadPisos=5;gCom=3456;
      ded= new DataEdificio(nombre,cantidadPisos,gCom);
      i++;
      break;
    default:
      throw ExOpcionInvalida();
  }

    me->addEdificio(ded);
    delete ded;
    ed = me->getEdificio(nombre);
    refEdificios->insert(std::pair<string,Edificio*>(ref,ed));
}
}

void CargarDatosController::cargarApartamentos(){
  ManejadorPropiedades* mp = ManejadorPropiedades::getInstancia();
  DataPropiedad* dapto;
  Oferta* oferta;
  Venta* venta;
  Alquiler* alquiler;
  Propiedad* apto;
  Inmobiliaria*inmob;
  Edificio*edificio;
  Zona*zona;
  string ref,direccion;
  bool garaje;
  int codigo,ambientes,dormitorios,banios;
  float m2edificados,m2totales,pventa,palquiler;
  int i=0;

  while(i<6){

    switch (i) {
      case 0:
          ref="AP1";codigo=1111;ambientes=2;dormitorios=1;banios=1;garaje=false;
          direccion="Iturria 1115 AP 104";m2edificados=34;m2totales=34;
          pventa=34567;palquiler=-1;
          dapto = new DataApartamento(codigo,ambientes,dormitorios,banios,direccion,
                                    garaje,palquiler,pventa,m2totales,m2edificados);
          venta = new Venta(pventa);
          alquiler=NULL;

          zona=refZonas->find("Z1")->second;
          edificio=refEdificios->find("E1")->second;
          inmob=refInmobiliarias->find("I1")->second;

          oferta = new Oferta(venta,alquiler,NULL,inmob);
          i++;
          break;
      case 1:
        ref="AP2";codigo=1112;ambientes=3;dormitorios=1;banios=1;garaje=false;
        direccion="Iturria 1115 AP 105";m2edificados=35;m2totales=35;
        pventa=65789;palquiler=-1;

        dapto=new DataApartamento(codigo,ambientes,dormitorios,banios,direccion,
                                  garaje,palquiler,pventa,m2totales,m2edificados);
        venta = new Venta(pventa);
        alquiler=NULL;
        inmob=refInmobiliarias->find("I1")->second;
        zona=refZonas->find("Z1")->second;
        edificio=refEdificios->find("E1")->second;

        oferta = new Oferta(venta,alquiler,NULL,inmob);
        i++;
        break;
      case 2:
        ref="AP3";codigo=1113;ambientes=2;dormitorios=1;banios=1;garaje=true;
        direccion="CALLEJON 456 AP 01";m2edificados=45;m2totales=45;
        pventa=-1;palquiler=7689;
        dapto=new DataApartamento(codigo,ambientes,dormitorios,banios,direccion,
                                  garaje,palquiler,pventa,m2totales,m2edificados);
        venta = NULL;
        alquiler= new Alquiler(palquiler);
        inmob=refInmobiliarias->find("I2")->second;
        zona=refZonas->find("Z2")->second;
        edificio=refEdificios->find("E2")->second;

        oferta = new Oferta(venta,alquiler,NULL,inmob);
        i++;
        break;
      case 3:
        ref="AP4";codigo=1114;ambientes=7;dormitorios=3;banios=2;garaje=true;
        direccion="CORCEGA 3456 AP 2";m2edificados=34;m2totales=34;
        pventa=-1;palquiler=6789;
        dapto=new DataApartamento(codigo,ambientes,dormitorios,banios,direccion,
                                  garaje,palquiler,pventa,m2totales,m2edificados);
        venta = NULL;
        alquiler = new Alquiler(palquiler);

        inmob=refInmobiliarias->find("I2")->second;
        zona=refZonas->find("Z3")->second;
        edificio=refEdificios->find("E3")->second;

        oferta = new Oferta(venta,alquiler,NULL,inmob);
        i++;
        break;
      case 4:
        ref="AP5";codigo=1115;ambientes=4;dormitorios=1;banios=1;garaje=false;
        direccion="LUCRECIA 456 AP 3";m2edificados=25;m2totales=25;
        pventa=-1;palquiler=7890;
        dapto=new DataApartamento(codigo,ambientes,dormitorios,banios,direccion,
                                  garaje,palquiler,pventa,m2totales,m2edificados);
        venta = NULL;
        alquiler= new Alquiler(palquiler);

        inmob=refInmobiliarias->find("I3")->second;
        zona=refZonas->find("Z4")->second;
        edificio=refEdificios->find("E4")->second;
        oferta = new Oferta(venta,alquiler,NULL,inmob);
        i++;
        break;
      case 5:
          ref="AP6";codigo=1116;ambientes=2;dormitorios=1;banios=1;garaje=false;
          direccion="LUCRECIA 456 AP 3";m2edificados=17;m2totales=17;
          pventa=-1;palquiler=768;
          dapto=new DataApartamento(codigo,ambientes,dormitorios,banios,direccion,
                                    garaje,palquiler,pventa,m2totales,m2edificados);
          venta = NULL;
          alquiler= new Alquiler(palquiler);

          inmob=refInmobiliarias->find("I4")->second;
          zona=refZonas->find("Z4")->second;
          edificio=refEdificios->find("E4")->second;
          oferta = new Oferta(venta,alquiler,NULL,inmob);
          i++;
          break;
      default:
        throw ExOpcionInvalida();

    }
    inmob->AgregarOferta(oferta);
    apto=mp->crearPropiedad(dapto,zona,oferta,edificio);
    refApartamentos->insert(std::pair<string,Propiedad*>(ref,apto));
    delete dapto;
  }
}

void CargarDatosController::cargarCasas(){
  ManejadorPropiedades* mp = ManejadorPropiedades::getInstancia();
  DataPropiedad*dcasa;
  Oferta*oferta;
  Venta*venta;
  Alquiler*alquiler;
  Propiedad*casa;
  Inmobiliaria*inmob;
  Zona*zona;
  string ref,direccion;
  bool garaje;
  int codigo,ambientes,dormitorios,banios;
  float m2edificados,m2totales,espacioverde,pventa,palquiler;
  int i=0;

  while(i<5){

    switch (i) {
      case 0:
          ref="C1";codigo=2111;ambientes=12;dormitorios=5;banios=1;garaje=true;
          direccion="Chana 2345";m2edificados=34;m2totales=44;espacioverde=10;
          pventa=45000;palquiler=-1;
          dcasa=new DataCasa(codigo,ambientes,dormitorios,banios,direccion,
                                    garaje,palquiler,pventa,m2totales,m2edificados,espacioverde);
          venta = new Venta(pventa);
          alquiler=NULL;

          zona=refZonas->find("Z5")->second;
          inmob=refInmobiliarias->find("I1")->second;

          oferta = new Oferta(venta,alquiler,NULL,inmob);
          i++;
          break;
      case 1:
        ref="C2";codigo=2112;ambientes=2;dormitorios=1;banios=1;garaje=false;
        direccion="Gloria 345";m2edificados=35;m2totales=55;espacioverde=20;
        pventa=34560;palquiler=-1;

        dcasa=new DataCasa(codigo,ambientes,dormitorios,banios,direccion,
                                  garaje,palquiler,pventa,m2totales,m2edificados,espacioverde);
        venta = new Venta(pventa);

        alquiler=NULL;
        inmob=refInmobiliarias->find("I1")->second;
        zona=refZonas->find("Z4")->second;


        oferta = new Oferta(venta,alquiler,NULL,inmob);
        i++;
        break;
      case 2:
        ref="C3";codigo=2113;ambientes=3;dormitorios=1;banios=1;garaje=false;
        direccion="CHAPAZ 345";m2edificados=12;m2totales=22;espacioverde=10;
        pventa=13000;palquiler=0;
        dcasa=new DataCasa(codigo,ambientes,dormitorios,banios,direccion,
                                  garaje,palquiler,pventa,m2totales,m2edificados,espacioverde);
        venta = new Venta(pventa);
        alquiler= NULL;
        inmob=refInmobiliarias->find("I2")->second;
        zona=refZonas->find("Z1")->second;


        oferta = new Oferta(venta,alquiler,NULL,inmob);
        i++;
        break;
      case 3:
        ref="C4";codigo=2114;ambientes=6;dormitorios=3;banios=2;garaje=true;
        direccion="JUANICO 456";m2edificados=34;m2totales=34;espacioverde=0;
        pventa=-1;palquiler=20000;
        dcasa=new DataCasa(codigo,ambientes,dormitorios,banios,direccion,
                                  garaje,palquiler,pventa,m2totales,m2edificados,espacioverde);
        venta = NULL;
        alquiler= new Alquiler(palquiler);

        inmob=refInmobiliarias->find("I3")->second;
        zona=refZonas->find("Z2")->second;


        oferta = new Oferta(venta,alquiler,NULL,inmob);
        i++;
        break;
      case 4:
        ref="C5";codigo=2115;ambientes=3;dormitorios=1;banios=1;garaje=false;
        direccion="VENECIA 3456";m2edificados=25;m2totales=25;espacioverde=0;
        pventa=-1;palquiler=56789;
        dcasa=new DataCasa(codigo,ambientes,dormitorios,banios,direccion,
                                  garaje,palquiler,pventa,m2totales,m2edificados,espacioverde);
        venta = NULL;
        alquiler= new Alquiler(palquiler);

        inmob=refInmobiliarias->find("I4")->second;
        zona=refZonas->find("Z1")->second;

        oferta = new Oferta(venta,alquiler,NULL,inmob);
        i++;
        break;
      default:
        throw ExOpcionInvalida();

    }
    inmob->AgregarOferta(oferta);
    casa=mp->crearPropiedad(dcasa,zona,oferta,NULL);
    refCasas->insert(std::pair<string,Propiedad*>(ref,casa));
    delete dcasa;
  }
}


void CargarDatosController::cargarAdministrador(){
  string email="adm1@sis.com",pass="Pass1";

    Manejador_Usuario* mu = Manejador_Usuario::getInstancia();
    mu->CrearAdministrador(email,pass);
    this->administrador= dynamic_cast<Administrador*>(mu->getUsuario(email));

}


void CargarDatosController::cargarInteresados(){

  Manejador_Usuario*mu = Manejador_Usuario::getInstancia();
  DtInteresado*di;
  Interesado*interesado;
  string ref,email,password,nombre,apellido;
  int edad;
  int i=0;

  while (i<5) {
    switch (i) {
      case 0:
        ref="T1";email="int1@sis.com";password="passt1";nombre="Julio";apellido="Chaz";edad=34;
        di= new DtInteresado(nombre,apellido,edad,email);
        i++;
        break;
      case 1:
        ref="T2";email="int2@sis.com";password="passt2";nombre="Andrea";apellido="Berruti";edad=56;
        di= new DtInteresado(nombre,apellido,edad,email);
        i++;
        break;
      case 2:
        ref="T3";email="int3@sis.com";password="passt3";nombre="Sonia";apellido="Braga";edad=45;
        di= new DtInteresado(nombre,apellido,edad,email);
        i++;
        break;
      case 3:
        ref="T4";email="int4@sis.com";password="passt4";nombre="Alfonso";apellido="Mier";edad=30;
        di= new DtInteresado(nombre,apellido,edad,email);
        i++;
        break;
      case 4:
        ref="T5";email="int5@sis.com";password="passt5";nombre="Juan";apellido="Alpi";edad=60;
        di= new DtInteresado(nombre,apellido,edad,email);
        i++;
        break;
      default:
        throw ExOpcionInvalida();
    }
    mu->CrearInteresado(di);
    interesado = mu->getInteresado(email);
    interesado->set_contrasenia(password);
    delete di;
    refInteresados->insert(std::pair<string,Interesado*>(ref,interesado));
  }
}

void CargarDatosController::cargarMensajes(){

int h,minutos,segundos;
string fecha,texto,ref;
Hora* hora;
Fecha* fecha_mensaje;
DataMensaje* mensaje;
Interesado* interesado;
Propiedad* prop;
Inmobiliaria* inmob;
int i=0;

  while (i<6) {

    switch(i){

      case 0:
        ref="O1";h=13;minutos=02;segundos=00;
        fecha="25/05/2016";
        texto="Estoy Interesado";
        inmob= refInmobiliarias->find("I1")->second;
        prop= refCasas->find("C1")->second;
        interesado= refInteresados->find("T1")->second;

        i++;
        break;
      case 1:
        ref="O2";h=12;minutos=30;segundos=00;
        fecha="24/05/2016";
        texto="Cuanto cuesta?";
        inmob= refInmobiliarias->find("I3")->second;
        prop= refCasas->find("C4")->second;
        interesado= refInteresados->find("T2")->second;

        i++;
        break;
      case 2:
        ref="O3";h=12;minutos=35;segundos=00;
        fecha="23/05/2016";
        texto="PERDON ME EQUIVOQUE";
        inmob= refInmobiliarias->find("I1")->second;
        prop= refCasas->find("C1")->second;
        interesado= refInteresados->find("T3")->second;

        i++;
        break;
      case 3:
        ref="O4";h=0;minutos=30;segundos=00;
        fecha="1/6/2016";
        texto="Quiero hacer una oferta ya!";
        inmob= refInmobiliarias->find("I1")->second;
        prop= refApartamentos->find("AP1")->second;
        interesado= refInteresados->find("T4")->second;

        i++;
        break;
      case 4:
        ref="O5";h=12;minutos=45;segundos=00;
        fecha="2/6/2016";
        texto="Tiene humedad?";
        inmob= refInmobiliarias->find("I1")->second;
        prop= refApartamentos->find("AP2")->second;
        interesado= refInteresados->find("T1")->second;

        i++;
        break;
      case 5:
        ref="O6";h=2;minutos=05;segundos=00;
        fecha="3/6/2016";
        texto="Cual es el precio?";
        inmob= refInmobiliarias->find("I2")->second;
        prop= refApartamentos->find("AP3")->second;
        interesado= refInteresados->find("T5")->second;

        i++;
        break;
      default:
        throw ExOpcionInvalida();
      }

      hora = new Hora(h,minutos,segundos);
      fecha_mensaje = new Fecha(fecha);
      mensaje= new DataMensaje(*fecha_mensaje,*hora,texto);

      if(prop->ExisteChat(interesado->get_email())){
        prop->ingresarMensaje(mensaje,interesado->get_email());
      }
      else{

        Chat*chat= new Chat(interesado->get_email(),inmob->getNombre(),prop,interesado,inmob);
        chat->nuevoMensaje(mensaje);
        inmob->agregarChat(chat);
        prop->AgregarChat(chat);
        interesado->AgregarChat(chat);

      }
      delete mensaje;delete hora; delete fecha_mensaje;
  }
}

void CargarDatosController::cargarDatosdeSistema(){

  if(CargarDatosController::DatosCargados){
		throw DatosYaCargados();
	}

//eliminar datos que ya existian en el sistema

/*Manejador_Usuario* mu = Manejador_Usuario::getInstancia();
ManejadorDepartamentos* md = ManejadorDepartamentos::getInstancia();
ManejadorEdificios * me= ManejadorEdificios::getInstancia();
ManejadorPropiedades* mp = ManejadorPropiedades::getInstancia();
delete mp; delete md; delete me; delete mu; */
	cargarDepartamentos();
	cargarZonas();
	cargarEdificios();
	cargarAdministrador();
	cargarInmobiliarias();
	cargarInteresados();
	cargarApartamentos();
	cargarCasas();
	cargarMensajes();

	CargarDatosController::DatosCargados = true;
}
