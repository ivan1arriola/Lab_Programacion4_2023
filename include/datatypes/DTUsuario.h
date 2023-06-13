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
    string getNickname() const;
    string getContrasenia() const;
    string getNombre() const;
    string getDescripcion() const;
    int getTipo() const;

    // Destructor
    virtual ~DTUsuario();
};

#endif
