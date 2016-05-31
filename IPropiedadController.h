class IpropiedadController{

public:
	IpropiedadController(){}
	virtual ~IpropiedadController(){}

	virtual void confirmarAltaPropiedad() = 0;
	virtual void ingresarNuevaCasa(DataPropiedad* casa) = 0;
	virtual void ingresarPrecioAlquiler(DataAlquiler* pAlquiler) = 0;
	virtual void ingresarNuevoApartamento(DataPropiedad* apartamento)=0;
	virtual void ingresarPrecioVenta() = 0;
	virtual set<DataDepartamento*>* listarDepartamentos() = 0;
	virtual set<DataEdificio*>* listarEdificios() = 0;
	virtual set<DataZona*>* listarZonas() = 0;
	virtual void enviarMensaje(DataMensaje* mensaje) = 0;
	virtual bool tipoPropiedad(int codigo) = 0;
	virtual void eliminarPropiedad(int codigo) = 0;
	virtual set<DataMensaje*>* listarMensajes() = 0;
	virtual set<DataInfoPropiedad*>* obtnerConversaciones() = 0;
	virtual void seleccionarPropiedad(int codigo) = 0; 
}
