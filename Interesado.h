#ifndef Interesado.h
#define Interesado.h

#include "Usuario.h"
#include "Chat.h"

#include <set>
#include <string>

class DtInteresado;
class DataMensaje;

class Interesado : public Usuario{
    private:
        string nombre;
        string apellido;
        int edad;
        set<Chat*>*chats;
    public:
        Interesado();
        Interesado(string& e,string& c,string& n,string& a,int age);
        //getters y setters
        string& get_nombre();
        string& get_apellido();
        int get_edad();
        void set_nombre(string &n);
        void set_apellido(string &a);
        void set_edad(int &age);

        //obtencion datatype
        set<DataMensaje*>* ObtenerDataMensajes();
        //operaciones de chat
        void AgregarChat(Chat *chat);
        void EliminarChat(Chat *chat);
        bool ExisteChat(Chat&* chat);


        virtual ~Interesado();

};

#endif // Interesado
