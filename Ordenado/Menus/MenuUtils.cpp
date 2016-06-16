

#include "MenuUtils.h"

#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <exception>
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;

int MenuUtils::leerInt(){
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


float MenuUtils::leerFloat(){
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

string MenuUtils::leerString() {
	string str;
	getline(cin, str);
	return str;
}

void MenuUtils::limpiarConsola() {
	system("clear");
}


Fecha MenuUtils::leerFecha(){
	Fecha res;
	int dd, mm, aaaa;
	bool error = true;
	while (error){
		cout << "Ingrese Dia: ";
		dd = MenuUtils::leerInt();
		cout << "Ingrese Mes: ";
		mm = MenuUtils::leerInt();
		cout << "Ingrese año: ";
		aaaa = MenuUtils::leerInt();
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

void MenuUtils::esperarInput() {
	cout << "Presione enter para continuar..." << endl;
	string dummy;
	getline(cin,dummy);
}

bool MenuUtils::leerOpcion(const string& msg) {
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
}


