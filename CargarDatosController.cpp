#include "CargarDatosController.h"

#include "ManejadorEdificios.h"
#include "ManejadorDepartamentos.h"
#include "ManejadorPropiedades.h"
#include "Manejador_Usuario.h"

#include "ExOpcionInvalida.h"
using namespace std;

bool CargarDatosController::DatosCargados = false;

CargarDatosController::CargarDatosController(){

refEdificios= new map<string,Edificio*>;
refApartamentos= new map<string,Apartamento*>;
refCasas= new map<string,Casa*>;
refDepartamentos= new map<string,Departamento*>;
refZonas= new map<string,Zona*>;
refInteresados= new map<string,Interesado*>;
refInmobiliarias= new map<string,Inmobiliaria*>;
refChats= new map<string,Chat*>;
}

Ctrl_CargarDatos::~Ctrl_CargarDatos() {
  
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
  	case 1:
      ref="I2";email="inm2@sis.com";nombre="Garcia";
      password="pass5";direccion="Rivera 1340";
      di= new DataInmobiliaria(nombre,email,direccion);
      i++;
  	case 2:
      ref="I1";email="inm3@sis.com";nombre="Invernissi";
      password="pass6";direccion="Comercio 234";
      di= new DataInmobiliaria(nombre,email,direccion);
      i++;
  	case 3:
      ref="I1";email="inm4@sis.com";nombre="Solei";
      password="pass7";direccion="Inca 3456";
      di= new DataInmobiliaria(nombre,email,direccion);
      i++;
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
      ddpto= new DataDepartamento(letra,nombre);
      i++;
  	case 1:
  		ref="D2";letra="B";nombre="Maldonado";
      ddpto= new DataDepartamento(letra,nombre);
      i++;
  	case 2:
  		ref="D3";letra="C";nombre="Rocha";
      ddpto= new DataDepartamento(letra,nombre);
      i++;
  	case 3:
      ref="D4";letra="D";nombre="Salto";
      ddpto= new DataDepartamento(letra,nombre);
      i++;
  	case 4:
      ref="D5";letra="E";nombre="Montevideo";
      ddpto= new DataDepartamento(letra,nombre);
      i++;
  	default:
  		throw ExOpcionInvalida();
  	}

    md->agregarDepartamento(ddpto);
  			delete ddpto;
  			dpto = md->getDepartamento(letra);
  			refDepartamentos->insert(std::pair<string,Departamento*>(ref,dpto));

}
}

void cargarZonas(){
  Zona* zona;
  Departamento*dpto;
  string ref,nombre;
  int codigo;
  int i=0;
  while (i<5){

    switch (i) {
      case 0:
          ref="Z1";nombre="Zona1";codigo=101;
          dpto= refDepartamentos->find("D1")->second;
          zona = new Zona(codigo,nombre,dpto);
          dpto->AddZona(zona);
          i++;
      case 1:
          ref="Z2";nombre="Zona2";codigo=102;
          dpto= refDepartamentos->find("D1")->second;
          zona = new Zona(codigo,nombre,dpto);
          dpto->AddZona(zona);
          i++;
      case 2:
          ref="Z3";nombre="Zona3";codigo=103;
          dpto= refDepartamentos->find("D2")->second;
          zona = new Zona(codigo,nombre,dpto);
          dpto->AddZona(zona);
          i++;
      case 3:
          ref="Z4";nombre="Zona4";codigo=104;
          dpto= refDepartamentos->find("D4")->second;
          zona = new Zona(codigo,nombre,dpto);
          dpto->AddZona(zona);
          i++;
      case 4:
          ref="Z5";nombre="Zona5";codigo=105;
          dpto= refDepartamentos->find("D4")->second;
          zona = new Zona(codigo,nombre,dpto);
          dpto->AddZona(zona);
          i++;
      default:
        throw ExOpcionInvalida();
    }

    refZonas->insert(std::pair<string,Zona*>(ref,zona));
  }
}

void cargarEdificios(){

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
    case 1:
      ref="E2";nombre="Mebeo";cantidadPisos=20;gCom=755;
      ded= new DataEdificio(nombre,cantidadPisos,gCom);
      i++;
    case 2:
      ref="E3";nombre="Socrates";cantidadPisos=34;gCom=134;
      ded= new DataEdificio(nombre,cantidadPisos,gCom);
      i++;
    case 3:
      ref="E4";nombre="El Burdel";cantidadPisos=12;gCom=450;
      ded= new DataEdificio(nombre,cantidadPisos,gCom);
      i++;
    case 4:
      ref="E5";nombre="Milajo";cantidadPisos=5;gCom=3456;
      ded= new DataEdificio(nombre,cantidadPisos,gCom);
      i++;
    default:
      throw ExOpcionInvalida();
  }

    me->addEdificio(ded);
    delete ded;
    ed = me->getEdificio(nombre);
    refEdificios->insert(std::pair<string,Edificio*>(ref,ed));
}
}

void cargarApartamentos(){
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
          dapto=new DataApartamento(codigo,ambientes,dormitorios,banios,direccion,
                                    garaje,palquiler,pventa,m2totales,m2edificados);
          venta = new Venta(pventa);
          alquiler=NULL;

          zona=refZonas->find("Z1")->second;
          edificio=refEdificios->find("E1")->second;
          inmob=refInmobiliarias->find("I1")->second;

          oferta = new Oferta(venta,alquiler,NULL,inmob);
          i++;
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
      case 3:
        ref="AP4";codigo=1114;ambientes=7;dormitorios=3;banios=2;garaje=true;
        direccion="CORCEGA 3456 AP 2";m2edificados=34;m2totales=34;
        pventa=-1;palquiler=6789;
        dapto=new DataApartamento(codigo,ambientes,dormitorios,banios,direccion,
                                  garaje,palquiler,pventa,m2totales,m2edificados);
        venta = NULL;
        alquiler= new alquiler(palquiler);

        inmob=refInmobiliarias->find("I2")->second;
        zona=refZonas->find("Z3")->second;
        edificio=refEdificios->find("E3")->second;

        oferta = new Oferta(venta,alquiler,NULL,inmob);
        i++;
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
      default:
        throw ExOpcionInvalida();

    }
    inmob->AgregarOferta(oferta);
    apto=mp->crearPropiedad(dapto,zona,oferta,edificio);
    refApartamentos->insert(std::pair<int,Apartamento*>(ref,apto));
    delete dapto;
  }
}

void cargarApartamentos(){
  ManejadorPropiedades* mp = ManejadorPropiedades::getInstancia();
  DataPropiedad* dcasa;
  Oferta* oferta;
  Venta* venta;
  Alquiler* alquiler;
  Propiedad* apto;
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
      case 3:
        ref="C4";codigo=2114;ambientes=6;dormitorios=3;banios=2;garaje=true;
        direccion="JUANICO 456";m2edificados=34;m2totales=34;espacioverde=0;
        pventa=-1;palquiler=20000;
        dcasa=new DataCasa(codigo,ambientes,dormitorios,banios,direccion,
                                  garaje,palquiler,pventa,m2totales,m2edificados,espacioverde);
        venta = NULL;
        alquiler= new alquiler(palquiler);

        inmob=refInmobiliarias->find("I3")->second;
        zona=refZonas->find("Z2")->second;


        oferta = new Oferta(venta,alquiler,NULL,inmob);
        i++;
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
      default:
        throw ExOpcionInvalida();

    }
    inmob->AgregarOferta(oferta);
    casa=mp->crearPropiedad(dcasa,zona,oferta,NULL);
    refCasas->insert(std::pair<int,Casa*>(ref,casa));
    delete dcasa;
  }
}


void cargarAdministrador(){
    Administrador* admin= new Administrador("adm1@sis.com","Pass1");
    ref="UA1";
    refAdministradores->insert<std::pair<string,Administrador*>(ref,admin);
}
