#ifndef DataInmobiliaria_h
#define DataInmobiliaria_h

using namespace std;

#include <string>

class DataInmobiliaria {
	private:
			string nombre;
			string email;
			string direccion;
	public:
			DataInmobiliaria(string nombre,string email,string direccion);

			string& get_nombre();
			string& get_direccion();
			string& get_email();

			virtual ~DataInmobiliaria();
};

#endif
