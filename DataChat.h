
#ifndef DATACHAT_H
#define	DATACHAT_H


#include<string>
#include <iostream>

using namespace std;

class DataChat {
private:
    string emailInteresado;
    string nombreInmobiliaria;
    int codigo;
public:
    DataChat(string &ei,string& inm,int cod);
    string getEmailInteresado();
    string getNombreInmobiliaria();
    int getCodigo();
    ~DataChat();
};

ostream& operator <<(ostream& o, DataChat& dc);

#endif	/* DATACHAT_H */
