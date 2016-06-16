

#include "MenuUtils.h"

#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <exception>
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;
int IOConsola::leerInt(){
	int num;
	string str = "";
	while(true){
		getline(cin, str);
		stringstream entrada(str);
		if (entrada >> num){
			break;
		}
		cout << "Debe ingresar un entero. Intente nuevamente" << endl;
	}
	return num;
}
//lee un doble de la linea ingresada, vuelve a solicitar en caso de error
double IOConsola::leerDouble(){
	double num;
	string str = "";
	while(true){
		getline(cin, str);
		stringstream entrada(str);
		if (entrada >> num){
			break;
		}
		cout << "Debe ingresar un doble. Intente nuevamente" << endl;
	}
	return num;
}

float IOConsola::leerFloat(){
	float num;
	string str = "";
	while(true){
		getline(cin, str);
		stringstream entrada(str);
		if (entrada >> num){
			break;
		}
		cout << "Debe ingresar un numero de punto flotante. Intente nuevamente" << endl;
	}
	return num;
}

string IOConsola::leerString() {
	string str;
	getline(cin, str);
	return str;
}

void IOConsola::limpiarConsola() {
	system("clear");
}


Date IOConsola::leerDate(){
	Fecha res;
	int dd, mm, aaaa;
	bool error = true;
	while (error){
		cout << "Ingrese Dia: ";
		dd = IOConsola::leerInt();
		cout << "Ingrese Mes: ";
		mm = IOConsola::leerInt();
		cout << "Ingrese año: ";
		aaaa = IOConsola::leerInt();
		cout << endl;
		try{
			res = Fecha(dd, mm, aaaa);
			error = false;
		}catch(exception& e){
			error = true;
			cout << "Error: Fecha ingresada es invalida. " << endl;
		}
	}
	return res;
}

void IOConsola::esperarInput() {
	cout << "Presione enter para continuar..." << endl;
	string dummy;
	getline(cin,dummy);
}

/*bool IOConsola::leerOpcion(const string& msg) {
	bool res = false;
	bool error = false;
	while(true){
		if(error) cout << "[Intente nuevamente] ";
		cout <<  msg << "(S/N):";
		string response = leerString();
		if(response=="S" || response=="s"){
			res = true;
			break;
		}else if(response=="N" || response == "n"){
			res = false;
			break;
		}else{
			error = true;
		}
	}
	return res;
}*/

void IOConsola::imprimirError(const string& msg) {
	limpiarConsola();
	imprimirImagen("error");
	cout << msg << endl;
}
