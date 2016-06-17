
#include "RutinaModificarPropiedad.h"
#include "Factory.h"
#include "../Excepciones/ExPropiedadNoExistente.h"
#include "../Excepciones/ProcesoCancelado.h"

#include <iostream>
#include <map>
#include <set>
#include <string>


#include "../MenuUtils.h"

using namespace std;

RutinaModificarPropiedad::RutinaModificarPropiedad() {
	propiedad = NULL;
	ctrl = Factory::getIModificarPropiedadController();
}

void RutinaModificarPropiedad::ejecutar() {
	while(true){
		try{
			if(elegido!=NULL) delete elegido;
			bool salir = false;
			while(!salir){
				cout << "Menu Modificar Propiedad: " << endl << endl;
				cout << "1 - Modificar Propiedad." << endl;
				cout << "0 - Salir" << endl;
				int opt = IOConsola::leerInt();
				IOConsola::limpiarConsola();
				switch(opt){
					case 0:{
						IOConsola::limpiarConsola();
						salir = true;
						break;
					}
					case 1:{
						modificarDatos();
						IOConsola::limpiarConsola();
						break;
					}
					default:{
						cout<<"Opcion Invalida. Intente nuevamente.";
						IOConsola::esperarInput();
						break;
					}
				}
			}
			IOConsola::limpiarConsola();
			if(!IOConsola::leerOpcion("Desea modificar otro estudiante?")) break;
		}catch(NoExEstudiante&){
			IOConsola::imprimirError("No existe un estudiante con esa CI.");
			if(!IOConsola::leerOpcion("Desea intentarlo nuevamente?")) break;
		}catch(NoHayEstudiantes&){
			IOConsola::imprimirError("No se puede continuar. No hay Estudiantes en el sistema.");
			IOConsola::esperarInput();
			break;
		}catch(RutinaAbortada&){
			IOConsola::imprimirError("Modificacion cancelada.");
			if(!IOConsola::leerOpcion("Desea modificar otro estudiante?")) break;
		}
	}
}

void RutinaModificarPropiedad::seleccionarPropiedad() {
	while(true){
		try{
			cout << "Modificar Propiedad - Ingrese el codigo de la Propiedad" << endl;
			cout<<"Codigo: ";
			string code = MenuUtils::leerString();
			propiedad = ctrl->ObtenerPropiedad(code);
			cout<< "Detalles de la propiedad:"<<endl;
			if(DataCasa*casa=dynamic_cast<DataCasa*>(propiedad)){
				cout<< *casa;
			}else if(DataApartamento*apto=dynamic_cast<DataApartamento*>(propiedad)){
				cout<< *apto;
			}
			break;
		}catch(ExPropiedadNoExistente& e){
			cout<<e.what()<<endl;
			if(!MenuUtils::leerOpcion("Dese intentarlo nuevamente?")){
				throw ProcesoCancelado();
			}
		}
	}
}

void RutinaModificarPropiedad::modificarDatos() {

	bool salir = false;
	int codigo = propiedad->getCodigo();
	int cantAmb = propiedad->getCantAmbientes();
	int dormitorios = propiedad->getDormitorios();
	int banios = propiedad->getBanios();
	bool garaje = propiedad->getGaraje();
	string dir = propiedad->getDireccion();
	float pVenta = propiedad->getVenta();
	float pAlquiler = propiedad->getAlquiler();
	float metrosTotales = propiedad->getM2totales();

	if(DataCasa*casa=dynamic_cast<DataCasa*>(propiedad)){
		float espVerde = propiedad-getEspacioVerde();
		float metrosEdificados = propiedad->getM2edificados();
	}

	while(!salir){
		IOConsola::limpiarConsola();
		seleccionarPropiedad();
		cout << "Seleccione que desea editar: " << endl;
		cout << "1 - Cantidad de Ambientes" << endl;
		cout << "2 - Banios" << endl;
		cout << "3 - Dormitorios" <<endl;
		cout << "4 - Garage" << endl;
		cout << "5 - Direccion" << endl;

		if(DataCasa*casa=dynamic_cast<DataCasa*>(propiedad)){
			cout<< "6 - Metros de Espacio Verde"<<endl;
			cout<< "7 - Metros Edificados"<<endl;
		}else if(DataApartamento*apto=dynamic_cast<DataApartamento*>(propiedad)){
			cout << "6 - Metros Totales "<<endl;
		}
		cout << endl << "0 - Guardar" << endl;
		int opt = IOConsola::leerInt();
		IOConsola::limpiarConsola();
		switch(opt){
			case 0:{
				if (DataCasa*casa=dynamic_cast<DataCasa*>(propiedad)){
					DataPropiedad* propTemp =  new DataCasa(codigo,cantAmb,dormitorios,banios,dir,garaje,pAlquiler,pVenta,(espVerde+metrosEdificados),metrosEdificados,espVerde);
				}else if (DataApartamento*apto=dynamic_cast<DataAparatamento*>(propiedad)){
					DataPropiedad* propTemp = new DataApartamento(codigo,cantAmb,dormitorios,banios,dir,garaje,pAlquiler,pVenta,metrosTotales,metrosTotales);
				}
				MenuUtils::limpiarConsola();
				cout<< *propTemp <<endl;
				if(MenuUtils::leerOpcion("Esta seguro que desea guardar estos datos?")){
					ctrl->guardarPropiedad(propTemp);
					delete propiedad;
					propiedad = propTemp;
					IOConsola::imprimirConfirmacion("Los datos han sido guardados con exito");
				}else{
					delete propTemp;
					cout<<"No se ha modificado la Propiedad ";
				}
				salir = true;
				IOConsola::esperarInput();
				break;
			}
			case 1:{
				MenuUtils::limpiarConsola()
				cout << endl <<"Ingrese la nueva Cantidad de Ambientes ";
				cantAmb = MenuUtils::leerInt();
				break;
			}
			case 2:{
				MenuUtils::limpiarConsola();
				cout << endl <<"Ingrese la nueva cantidad de Banios: ";
				banios = MenuUtils::leerInt();
				break;
			}
			case 3:{
				MenuUtils::limpiarConsola();
				cout << endl <<"Ingrese la nueva cantidad de Dormitorios: ";
				dormitorios = MenuUtils::leerInt();
				break;
			}
			case 4:{
				MenuUtils::limpiarConsola();
				cout << endl <<"Ingrese el nuevo estado del Garage: ";
				garaje = MenuUtils::leerOpcion();
				break;
			}
			case 5:{
				MenuUtils::limpiarConsola();
				cout << endl <<"Ingrese la nueva Direccion: ";
				dir = MenuUtils::leerString();
				break;
			}
			case 6:{
				MenuUtils::limpiarConsola();
				if(DataCasa*casa=dynamic_cast<DataCasa*>(propiedad)){
					cout << endl <<"Ingrese la nueva cantidad de Espacio Verde: ";
					espVerde = MenuUtils::leerFloat();
				}else if(DataApartamento*apto=dynamic_cast<DataApartamento*>(propiedad)){
					cout << endl <<"Ingrese la nueva cantidad de Metros Totales: ";
					metrosTotales = MenuUtils::leerFloat();
				}
				break;
			}
			case 7:{
				MenuUtils::limpiarConsola();
				if(DataCasa*casa=dynamic_cast<DataCasa*>(propiedad)){
					cout << endl <<"Ingrese la nueva cantidad de Espacio Verde: ";
					metrosEdificados = MenuUtils::leerFloat();
				}else{
					cout<< "Opcion invalida. Intente nuevamente.";
					MenuUtils::esperarInput();
					break;
				}
			}
			default:{
				cout<< "Opcion invalida. Intente nuevamente.";
				MenuUtils::esperarInput();
				break;
			}
		}
	}
}


RutinaModificarPropiedad::~RutinaModificarPropiedad() {
	if (propiedad != NULL) delete propiedad;
	delete ctrl;
}

