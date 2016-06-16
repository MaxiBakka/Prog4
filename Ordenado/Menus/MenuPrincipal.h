
#include "MenuUtils.h"
#include "Menu.h"

#ifndef MENU_PRINCIPAL_H_
#define MENU_PRINCIPAL_H_

class MenuPrincipal: public Menu {
public:
	MenuPrincipal();
	void printMenu();
	void ejecutarOpcion(int opc);
	virtual ~MenuPrincipal();
};

#endif /* MENU_PRINCIPAL_H_ */
