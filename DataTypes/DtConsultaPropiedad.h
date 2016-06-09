#ifndef DtConsultaPropiedad_h
#define DtConsultaPropiedad_h

#include <string>

using namespace std;

class DtConsultaPropiedad{
	private:
		int codigo;
		string direccion;
		bool venta;
		bool alquiler;
	public:
		DtConsultaPropiedad();
		DtConsultaPropiedad(int code, string dir, bool v, bool a);
		int get_codigo();
		string get_direccion();
		bool get_venta();
		bool get_alquiler();
		~DtConsultaPropiedad();
}

#endif