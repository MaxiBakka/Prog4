
#include "Menu.h"
#ifndef MENU_INMOBILIARIAS_H_
#define MENU_INMOBILIARIAS_H_

class MenuInmobiliarias: public Menu {
public:
	MenuInmobiliarias();
	void presentar();
	void ejecutarOpcion(int opc);
	virtual ~MenuInmobiliarias();
};

#endif /* MENU_INMOBILIARIAS_H_ */
