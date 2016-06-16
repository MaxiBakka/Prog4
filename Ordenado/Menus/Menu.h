

#include "UserInterface.h"
#ifndef MENU_H_
#define MENU_H_


class Menu : public UserInterface {
private:
	bool salir;
public:
	Menu();
	virtual void presentar() = 0;
	void leerOpcion();
	void ejecutar();
	void salirDelSistema();
	virtual void ejecutarOpcion(int opc) = 0;
	virtual ~Menu();
};

#endif /* MENU_H_ */
