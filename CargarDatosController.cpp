


void CargarDatosController::cargarDepartamentos(){

  ManejadorDepartamentos* md = ManejadorDepartamentos::getInstancia();
  DataDepartamento* dataDepartamento;
  Departamento* emp;
  string ref, letra, nombre;
  DataDepartamento*ddpto;
  Departamento*dpto;
  int i=0;

while (i<5) {

      switch(opc){
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
  	case 5:

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
  string ref,nombre;
  int codigo;
  int i=0;
  while (i<5){

    switch (opc) {
      case 0:
          ref="Z1";nombre="Zona1";codigo=101;
          zona = new Zona(codigo,nombre,refDepartamentos->find("D1"));
          refDepartamentos->find("D1")->AddZona(zona);
          refZonas=->insert(std::pair<string,Zona*>(ref,zona));
          i++;
      case 1:
          ref="Z2";nombre="Zona2";codigo=102;
          zona = new Zona(codigo,nombre,refDepartamentos->find("D1"));
          refDepartamentos->find("D1")->AddZona(zona);
          refZonas=->insert(std::pair<string,Zona*>(ref,zona));
          i++;
      case 2:
          ref="Z3";nombre="Zona3";codigo=103;
          zona = new Zona(codigo,nombre,refDepartamentos->find("D2"));
          refDepartamentos->find("D1")->AddZona(zona);
          refZonas=->insert(std::pair<string,Zona*>(ref,zona));
          i++;
      case 3:
          ref="D4";nombre="Zona4";codigo=104;
          zona = new Zona(codigo,nombre,refDepartamentos->find("D4"));
          refDepartamentos->find("D1")->AddZona(zona);
          refZonas=->insert(std::pair<string,Zona*>(ref,zona));
          i++;
      case 4:
          ref="D5";nombre="Zona5";codigo=105;
          zona = new Zona(codigo,nombre,refDepartamentos->find("D4"));
          refDepartamentos->find("D1")->AddZona(zona);
          refZonas=->insert(std::pair<string,Zona*>(ref,zona));
          i++;

      default:
        throw ExOpcionInvalida();
    }
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

  switch (opc) {
    case 0:
      ref="E1";nombre="Apache Viviente";cantidadPisos=4;gCom=1300;
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
      ref="E1";nombre="Milajo";cantidadPisos=5;gCom=3456;
      ded= new DataEdificio(nombre,cantidadPisos,gCom);
      i++;

    default
      throw ExOpcionInvalida();
  }

    me->addEdificio(ded);
    delete ded;
    ed = getEdificio(nombre);
    refEdificios->insert(std::pair<string,Edificio*>(ref,ed));
}
}

void cargarApartamentos(){
  ManejadorPropiedades* mp = ManejadorPropiedades::getInstancia();
  DataApartamento* dapto;
  Oferta* oferta;
  Venta* venta;
  Alquiler* alquiler;
  Apartamento* apto;
  string ref,direccion;
  bool garaje;
  int codigo,ambientes,dormitorios,banios;
  float m2edificados,m2totales,pventa,paqluiler;
  int i=0;

  while(i<6){
    switch (ocp) {
      case 0:
          ref="AP1";codigo=1111;ambientes=2;dormitorios=1;banios=1;garaje=false;
          direccion="Iturria 1115 AP 104";m2edificados=34;m2totales=34;
          pventa=34567;palquiler=-1;
          dapto=new DataApartamento(codigo,ambientes,dormitorios,banios,direccion,
                                    garaje,palquiler,pventa,m2totales,m2edificados);
          venta = new Venta(pventa);
          alquiler=NULL;
          oferta = new Oferta(venta,alquiler,NULL,refInmobiliarias->find("I1"));
          mp->crearPropiedad(dapto,refZonas->find("Z1"),oferta,refEdificios->find("E1"));
          apto=mp->getPropiedad(codigo);
          refAlquileres->insert(std::pair<int,Apartamento*>(ref,apto));
          delete dapto;
      case 1:
        ref="AP2";codigo=1112;ambientes=3;dormitorios=1;banios=1;garaje=false;
        direccion="Iturria 1115 AP 105";m2edificados=35;m2totales=35;
        pventa=65789;palquiler=-1;
        dapto=new DataApartamento(codigo,ambientes,dormitorios,banios,direccion,
                                  garaje,palquiler,pventa,m2totales,m2edificados);
        venta = new Venta(pventa);
        alquiler=NULL;
        oferta = new Oferta(venta,alquiler,NULL,refInmobiliarias->find("I1"));
        mp->crearPropiedad(dapto,refZonas->find("Z1"),oferta,refEdificios->find("E1"));
        apto=mp->getPropiedad(codigo);
        refAlquileres->insert(std::pair<int,Apartamento*>(ref,apto));
        delete dapto;
      case 2:
        ref="AP3";codigo=1113;ambientes=2;dormitorios=1;banios=1;garaje=true;
        direccion="CALLEJON 456 AP 01";m2edificados=45;m2totales=45;
        pventa=-1;palquiler=7689;
        dapto=new DataApartamento(codigo,ambientes,dormitorios,banios,direccion,
                                  garaje,palquiler,pventa,m2totales,m2edificados);
        venta = NULL;
        alquiler= new Alquiler(palquiler);
        oferta = new Oferta(venta,alquiler,NULL,refInmobiliarias->find("I2"));
        mp->crearPropiedad(dapto,refZonas->find("Z2"),oferta,refEdificios->find("E2"));
        apto=mp->getPropiedad(codigo);
        refAlquileres->insert(std::pair<int,Apartamento*>(ref,apto));
        delete dapto;
      case 3:
        ref="AP4";codigo=1114;ambientes=7;dormitorios=3;banios=2;garaje=true;
        direccion="CORCEGA 3456 AP 2";m2edificados=34;m2totales=34;
        pventa=-1;palquiler=6789;
        dapto=new DataApartamento(codigo,ambientes,dormitorios,banios,direccion,
                                  garaje,palquiler,pventa,m2totales,m2edificados);
        venta = NULL;
        alquiler= new alquiler(palquiler);
        oferta = new Oferta(venta,alquiler,NULL,refInmobiliarias->find("I2"));
        mp->crearPropiedad(dapto,refZonas->find("Z3"),oferta,refEdificios->find("E3"));
        apto=mp->getPropiedad(codigo);
        refAlquileres->insert(std::pair<int,Apartamento*>(ref,apto));
        delete dapto;
      case 4:
        ref="AP5";codigo=1115;ambientes=4;dormitorios=1;banios=1;garaje=false;
        direccion="LUCRECIA 456 AP 3";m2edificados=25;m2totales=25;
        pventa=-1;palquiler=7890;
        dapto=new DataApartamento(codigo,ambientes,dormitorios,banios,direccion,
                                  garaje,palquiler,pventa,m2totales,m2edificados);
        venta = NULL;
        alquiler= new Alquiler(palquiler);
        oferta = new Oferta(venta,alquiler,NULL,refInmobiliarias->find("I3"));
        mp->crearPropiedad(dapto,refZonas->find("Z4"),oferta,refEdificios->find("E4"));
        apto=mp->getPropiedad(codigo);
        refAlquileres->insert(std::pair<int,Apartamento*>(ref,apto));
        delete dapto;
        case 5:
          ref="AP6";codigo=1116;ambientes=2;dormitorios=1;banios=1;garaje=false;
          direccion="LUCRECIA 456 AP 3";m2edificados=17;m2totales=17;
          pventa=-1;palquiler=768;
          dapto=new DataApartamento(codigo,ambientes,dormitorios,banios,direccion,
                                    garaje,palquiler,pventa,m2totales,m2edificados);
          venta = NULL;
          alquiler= new Alquiler(palquiler);
          oferta = new Oferta(venta,alquiler,NULL,refInmobiliarias->find("I4"));
          mp->crearPropiedad(dapto,refZonas->find("Z4"),oferta,refEdificios->find("E4"));
          apto=mp->getPropiedad(codigo);
          refAlquileres->insert(std::pair<int,Apartamento*>(ref,apto));
          delete dapto;

      default
        throw ExOpcionInvalida();

    }
  }
}

void cargarAdministrador(){
    Administrador* admin= new Administrador("adm1@sis.com","Pass1");
    ref="UA1";
    refAdministradores->insert<std::pair<string,Administrador*>(ref,admin);
}
