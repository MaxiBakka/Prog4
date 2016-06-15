
#ifndef SESION_H
#define	SESION_H

#include "Usuario.h"
 

class Sesion {
private:
    static Sesion* instancia;
    Sesion();
    Usuario* usuario;
public:
    static Usuario* getInstancia();
    
    //Iniciar Sesion
    void iniciarSesion(Usuario* &user);
    //Cerrar Sesion
    void cerrarSesion();
    //obtener Usuario
    Usuario* getUsuario();
    //destructor 
    virtual ~Sesion();

};

#endif	/* SESION_H */

