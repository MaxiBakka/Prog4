


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
  	case 2:
  		//etc
  	case 3:
  		//etc
  	case 4:
  		//etc
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
