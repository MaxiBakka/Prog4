
#include "Menu.h"
#ifndef MENU_ADMINS_H_
#define MENU_ADMINS_H_

class MenuAdministradores: public Menu {
public:
	MenuAdministradores();
	void presentar();
	void ejecutarOpcion(int opc);
	virtual ~MenuAdministradores();
};

#endif /* MENU_ADMINS_H_ */
