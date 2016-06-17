#ifndef DataAlquiler_h
#define DataAlquiler_h

#include <iostream>

class DataAlquiler
{
	private: float precio;
	public:
	    DataAlquiler();
		DataAlquiler(float);
		float get_precio();
		DataAlquiler& operator=(DataAlquiler);
		~DataAlquiler();

};

ostream& operator <<(ostream& o, DataAlquiler& N);

#endif
