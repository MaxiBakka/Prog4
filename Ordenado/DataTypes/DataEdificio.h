#ifndef DataEdificio_h
#define DataEdificio_h

#include <string>
#include <set>
#include <iostream>
#include <iomanip>

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

ostream& operator<<(ostream& o, DataEdificio& de);
ostream& operator <<(ostream& o, const set<DataEdificio*> sds);

#endif
