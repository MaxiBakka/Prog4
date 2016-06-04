#ifndef DataInfoAlquiler_h
#define DataInfoAlquiler_h

class DataInfoAlquiler
{
	private: float precio;
	public:
	    DataInfoAlquiler();
		DataInfoAlquiler(float);
		float get_precio();
		DataInfoAlquiler& operator=(DataInfoAlquiler);
		~DataInfoAlquiler();

};


#endif
