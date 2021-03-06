
#include "Fecha.h"
#include <string>


#ifndef MENU_UTILS_H_
#define MENU_UTILS_H_

using namespace std;

class MenuUtils {
public:
	static void limpiarConsola();
	static int leerInt();
	static double leerDouble();
	static float leerFloat();
	static string leerString();
	static void esperarInput();
	static Date leerDate();
	static bool leerOpcion(const string& msg);
};

#endif /* MENU_UTILS_H_ */
