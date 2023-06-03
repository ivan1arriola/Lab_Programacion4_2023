#ifndef HANDLERUSUARIO
#define HANDLERUSUARIO

#include <map>
#include <set>
#include <string>

#include "../classes/Usuario/Usuario.h"

using namespace std;

class HandlerUsuario {
private:
    map<string, Usuario*> usuarios; // Colección de punteros a Usuario
    HandlerUsuario();
    static HandlerUsuario* instancia;

public:
    static HandlerUsuario* getInstancia();

    // Agregar
    void agregarUsuario(Usuario* usuario);

    // Obtener
    Usuario* obtenerUsuario(string nickname);
    set<string> obtenerNicknamesUsuarios();

    // Consultar
    bool existeUsuario(string nickname);
    bool existeUsuario(Usuario* usuario);

    // Eliminar
    void eliminarUsuario(string nickname);
    void eliminarUsuario(Usuario* usuario);
};

#endif
