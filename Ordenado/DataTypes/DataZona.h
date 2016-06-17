#ifndef DataZona_h
#define DataZona_h

#include <string>
#include <iostream>

using namespace std;

class DataZona{
	private:
		int codigo;
		string nombre;
	public:
		DataZona(int code, string name);
		int get_codigo();
		string get_nombre();
		~DataZona();
};

ostream & operator <<(ostream &o, DataZona& dz);

#endif
