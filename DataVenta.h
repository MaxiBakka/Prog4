#ifndef DataVenta_h
#define DataVenta_h

using namespace std;


class DataVenta{

	private:

		float precio;

	public:
	    DataVenta();

		DataVenta(float precio);

		float get_precio();
        DataVenta& operator=(DataVenta);
		~DataVenta();
};
#endif
