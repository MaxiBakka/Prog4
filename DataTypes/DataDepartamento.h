#ifndef DataDepartamento_h
#define DataDepartamento_h

#include <string>

using namespace std;

class DataDepartamento: public DataPropiedad{
	private: 
		string nombre;
		string letra;
	public:
		
		DataDepartamento(string name, string letra);
		string get_nombre();
		string get_letra();
		virtual ~DataDepartamento();
};

#endif