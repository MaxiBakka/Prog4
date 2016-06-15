
#include "Menu.h"
#ifndef MENU_INTERESADOS_H_
#define MENU_INTERESADOS_H_

class MenuInteresados: public Menu {
public:
	MenuInteresados();
	void presentar();
	void ejecutarOpcion(int opc);
	virtual ~MenuInteresados();
};

#endif /* MENU_INTERESADOS_H_ */
