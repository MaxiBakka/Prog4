
#include "RutinaModificarPropiedad.h"
#include "../Fabrica/Factory.h"
#include "../Excepciones/ExPropiedadNoExistente.h"
#include "../Excepciones/ProcesoCancelado.h"
#include "../DataTypes/DataCasa.h"
#include "../ClasesDeDominio/Casa.h"
#include "../DataTypes/DataApartamento.h"
#include "../ClasesDeDominio/Apartamento.h"

#include <iostream>
#include <map>
#include <set>
#include <string>


#include "../Menus/MenuUtils.h"

using namespace std;

RutinaModificarPropiedad::RutinaModificarPropiedad() {
	propiedad = NULL;
	ctrl = Factory::getIModificarPropiedadController();
}

void RutinaModificarPropiedad::ejecutar() {
	while(true){
		try{
			if(propiedad!=NULL) delete propiedad;
			bool salir = false;
			while(!salir){
				cout << "Menu Modificar Propiedad: " << endl << endl;
				cout << "1 - Modificar Propiedad." << endl;
				cout << "0 - Salir" << endl;
				int opt = MenuUtils::leerInt();

				switch(opt){
					case 0:
						MenuUtils::limpiarConsola();
						salir = true;
						break;

					case 1:
						seleccionarPropiedad();
						modificarDatos();
						MenuUtils::limpiarConsola();
						break;

					default:
						cout<<"Opcion Invalida. Intente nuevamente.";
						MenuUtils::esperarInput();


				}
			}
			//MenuUtils::limpiarConsola();
			if(!MenuUtils::leerOpcion("Desea modificar otra propiedad?")) break;
		}catch(ProcesoCancelado&){
			cout <<"Modificacion cancelada."<< endl;
			if(!MenuUtils::leerOpcion("Desea modificar otra propiedad?")) break;
		}
	}
}

void RutinaModificarPropiedad::seleccionarPropiedad() {
	while(true){
		try{
			cout << "Modificar Propiedad - Ingrese el codigo de la Propiedad" << endl;
			cout<<"Codigo: ";
			int code = MenuUtils::leerInt();
			cout << code <<endl;
			propiedad = ctrl->ObtenerPropiedad(code);
            MenuUtils::limpiarConsola();
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
    bool es_casa=false;
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
    float espVerde;
    float metrosEdificados;
	if(DataCasa*casa=dynamic_cast<DataCasa*>(propiedad)){
		 espVerde = casa->getEspacioVerde();
		 metrosEdificados = casa->getM2edificados();
		 es_casa=true;
	}


    DataPropiedad* propTemp;
	while(!salir){

		cout <<endl<<endl<< "Seleccione que desea editar: " << endl;
		cout << "1 - Cantidad de Ambientes" << endl;
		cout << "2 - Banios" << endl;
		cout << "3 - Dormitorios" <<endl;
		cout << "4 - Garage" << endl;
		cout << "5 - Direccion" << endl;

		if(es_casa){
			cout<< "6 - Metros de Espacio Verde"<<endl;
			cout<< "7 - Metros Edificados"<<endl;
		}else {
			cout << "6 - Metros Totales "<<endl;
		}
		cout << endl << "0 - Guardar" << endl;
		int opt = MenuUtils::leerInt();
		MenuUtils::limpiarConsola();
		switch(opt){

			case 0:

				if (es_casa){
					DataCasa* propTempCasa=  new DataCasa(codigo,cantAmb,dormitorios,banios,dir,garaje,pAlquiler,pVenta,(espVerde+metrosEdificados),metrosEdificados,espVerde);
                    propTemp= dynamic_cast<DataPropiedad*>(propTempCasa);
                    cout<< *propTempCasa <<endl;

				}else{
					DataApartamento* propTempApto = new DataApartamento(codigo,cantAmb,dormitorios,banios,dir,garaje,pAlquiler,pVenta,metrosTotales,metrosTotales);
                    propTemp = dynamic_cast<DataPropiedad*>(propTempApto);
                    cout<< *propTempApto <<endl;

				}


				if(MenuUtils::leerOpcion("Esta seguro que desea guardar estos datos?")){
					ctrl->guardarPropiedad(propTemp);
					delete propTemp;
					cout << "Los datos han sido guardados con exito" << endl;
				}else{
					delete propTemp;
					cout<<"No se ha modificado la Propiedad ";
				}
				salir = true;
				MenuUtils::esperarInput();
				break;

			case 1:
				MenuUtils::limpiarConsola();
				cout << endl <<"Ingrese la nueva Cantidad de Ambientes ";
				cantAmb = MenuUtils::leerInt();
				break;

			case 2:
				MenuUtils::limpiarConsola();
				cout << endl <<"Ingrese la nueva cantidad de Banios: ";
				banios = MenuUtils::leerInt();
				break;

			case 3:
				MenuUtils::limpiarConsola();
				cout << endl <<"Ingrese la nueva cantidad de Dormitorios: ";
				dormitorios = MenuUtils::leerInt();
				break;

			case 4:
				MenuUtils::limpiarConsola();
				cout << endl;
				garaje = MenuUtils::leerOpcion("Ingrese el nuevo estado del Garage:");
				break;

			case 5:
				MenuUtils::limpiarConsola();
				cout << endl <<"Ingrese la nueva Direccion: ";
				dir = MenuUtils::leerString();
				break;

			case 6:
				MenuUtils::limpiarConsola();
				if(DataCasa*casa=dynamic_cast<DataCasa*>(propiedad)){
					cout << endl <<"Ingrese la nueva cantidad de Espacio Verde: ";
					espVerde = MenuUtils::leerFloat();
				}else if(DataApartamento*apto=dynamic_cast<DataApartamento*>(propiedad)){
					cout << endl <<"Ingrese la nueva cantidad de Metros Totales: ";
					metrosTotales = MenuUtils::leerFloat();
				}
				break;

			case 7:
				MenuUtils::limpiarConsola();
				if(es_casa){
					cout << endl <<"Ingrese la nueva cantidad de Espacio Verde: ";
					metrosEdificados = MenuUtils::leerFloat();
				}else{
					cout<< "Opcion invalida. Intente nuevamente.";
					MenuUtils::esperarInput();

				}
                break;
			default:
				cout<< "Opcion invalida. Intente nuevamente.";
				MenuUtils::esperarInput();

		}
	}


}


RutinaModificarPropiedad::~RutinaModificarPropiedad() {
	if (propiedad != NULL) delete propiedad;
	delete ctrl;
}
