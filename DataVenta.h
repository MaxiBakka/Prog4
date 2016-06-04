/*
 * DataInfoVenta.h
 *
 *  Created on: 01/05/2016
 *      Author: mfornara
 */

#ifndef DataInfoVenta_h
#define DataInfoVenta_h

using namespace std;


class DataInfoVenta{

	private:

		float precio;

	public:
	    DataInfoVenta();

		DataInfoVenta(float precio);

		float get_precio();
        DataInfoVenta& operator=(DataInfoVenta);
		~DataInfoVenta();
};
#endif
