#ifndef Interesado.h
#define Interesado.h

#include Usuario.h
#include Chat.h

class Interesado : public Usuario:
    private:
        string nombre;
        string apellido;
        int edad;
        //Set(Chat) chats;
    public:
        Interesado();
        Interesado(string e,string c,string n,string a,int age);
        virtual string get_email();
        virtual string get_contrasenia();
        virtual void set_email(string &e);
        virtual void set_contrasenia(string &c);
        string get_nombre();
        string get_apellido();
        int get_edad();
        void set_nombre(string &n);
        void set_apellido(string &a);
        void set_edad(int &age);
        //ObtenerDataMensajes():set(DataMensaje);
        //AgregarChat(Chat *chat);
        //EliminarChat(Chat *chat);
        //notify(Mail notificacionMail,int codigo);
        virtual ~Usuario;



#endif // Interesado
