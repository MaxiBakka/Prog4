#ifndef DataAlquiler_h
#define DataAlquiler_h

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

#endif
