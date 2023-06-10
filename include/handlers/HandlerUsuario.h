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

    // Destructor
    ~HandlerUsuario();

public:
    static HandlerUsuario* getInstancia();
    static void deleteInstancia();

    // Agregar
    void agregarUsuario(Usuario* usuario);

    // Obtener
    set<Usuario*> obtenerUsuarios();
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
