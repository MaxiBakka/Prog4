
#ifndef DATACHAT_H
#define	DATACHAT_H

#include "DataMensaje.h"


#include<string>
#include<vector>

using namespace std;

class DataChat {
private:
    string emailInteresado;
    string nombreInmobiliaria;
    vector<DataMensaje*>* mensajes;
public:
    DataChat(string &ei,string& inm,vector<DataMensaje*>* m);
    string getEmailInteresado();
    string getNombreInmobiliaria();
    vector<DataMensaje*>* getDataMensajes();
    ~DataChat();
};

#endif	/* DATACHAT_H */

