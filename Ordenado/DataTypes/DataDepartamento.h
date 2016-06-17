#ifndef DataDepartamento_h
#define DataDepartamento_h

#include <string>
#include <iostream>

using namespace std;

class DataDepartamento{
	private:
		string nombre;
		string letra;
	public:

		DataDepartamento(string name, string letra);
		string& get_nombre();
		string& get_letra();
		virtual ~DataDepartamento();
};

ostream& operator <<(ostream& output, DataDepartamento& de);

#endif
