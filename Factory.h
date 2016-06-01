#ifndef Factory.h
#define Factory.h

class Factory {
	private:
		static Factory* instancia;
		Factory(){}

	public:
		~Factory(){}
		static Factory getInstance();
		IPropiedadController getIPropiedadController();
		IUsuarioController getIUsuarioController();

}
