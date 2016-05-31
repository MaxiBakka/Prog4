#ifndef Sistema_h
#define Sistema_h

#include "DataDepartamento.h"
#include "DataZona.h"
#include "DataEdificio.h"
#include "DataPropiedad.h"
#include "DataCasa.h"
#include "DataApartamento.h"
#include "DataInfoAlquiler.h"
#include "DataInfoVenta.h"
#include "DataInmobiliaria.h"
namespace AltaPropiedad{

	class Sistema{
		private:
			static string DepartamentoElegido;//departemento recordado por el sistema
			static string ZonaElegida;//zona elegida por el sistema
			DataPropiedad*Propiedad;
			DataInfoVenta*Venta;
			DataInfoAlquiler*Alquiler;
			
			static int codigoPropiedad;


		public:
			set<DataDepartamento*>* listarDepartamentos();
			void seleccionarDepartamentos(string letra);
			set<DataZona*>* listarZonasDepartamento();
			void seleccionarZona(int codigo);
			string tipoPropiedad(string p);
			set<DataEdificio*>* listarEdificiosZona();
			void ingresarNuevoApartamento(DataPropiedad apartamento);
			void ingresarNuevaCasa(DataPropiedad casa);
			void ingresarPrecioAlquiler(float a);
			void ingresarPrecioVenta(float v);
			void confirmarAltaPropiedad();
	};
}


namespace AltaInmobiliaria{

	class Sistema{
		private:
				DataInmobiliaria*Inmobiliaria;

		public:
				IngresarInmobiliaria(DataInmobiliaria Inmobiliaria);
				ConfirmarAltaInmobiliaria();

	};

}

#endif

