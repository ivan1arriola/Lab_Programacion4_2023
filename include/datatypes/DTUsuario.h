// version provisional

#ifndef DTUSUARIO
#define DTUSUARIO

#include <string>

using namespace std;

/*
DTUsuario
- nickname: string
- contrasenia: string
- nombre: string
- descripcion: string
*/

class DTUsuario {
private:
    string nickname;
    string contrasenia;
    string nombre;
    string descripcion;

public:

    // Constructor
    DTUsuario();
    DTUsuario(string nickname, string contrasenia, string nombre, string descripcion);

    // Getters
    string getNickname();
    string getContrasenia();
    string getNombre();
    string getDescripcion();

    // Destructor
    ~DTUsuario();

    virtual void imprimir(ostream& os) = 0;

    friend ostream& operator<<(ostream& os, DTUsuario& dtUsuario);
};

#endif