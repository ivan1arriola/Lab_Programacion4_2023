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
    int tipo; // 0: profesor, 1: estudiante

public:

    // Constructor
    DTUsuario();
    DTUsuario(int tipo);
    DTUsuario(string nickname, string contrasenia, string nombre, string descripcion, int tipo);

    // Getters
    string getNickname();
    string getContrasenia();
    string getNombre();
    string getDescripcion();
    int getTipo() { return this->tipo; }

    // Destructor
    ~DTUsuario();

    virtual void imprimir(ostream& os) = 0;

    friend ostream& operator<<(ostream& os, DTUsuario& dtUsuario);
};

#endif