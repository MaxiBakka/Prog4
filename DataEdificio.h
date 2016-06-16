#ifndef DataEdificio_h
#define DataEdificio_h

#include<string>
#include <iostream>

using namespace std;

class DataEdificio{
	private:
		string nombre;
		int cantPisos;
		float gastosComunes;
	public:

		DataEdificio(string name, int cpisos, float gComunes);
		string get_nombre();
		int get_cantPisos();
		float get_gastosComunes();
		virtual ~DataEdificio();
};

ostream& operator <<(ostream &output,DataEdificio &de);

#endif
