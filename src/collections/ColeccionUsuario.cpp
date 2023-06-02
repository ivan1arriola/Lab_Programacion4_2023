#include "../../include/collections/ColeccionUsuario.h"

#include <map>
#include <set>
#include <string>
#include <stdexcept>
#include <iostream>

#include "../../include/classes/Usuario/Usuario.h"

using namespace std;

ColeccionUsuario* ColeccionUsuario::instancia = NULL;

ColeccionUsuario::ColeccionUsuario() {}

ColeccionUsuario* ColeccionUsuario::getInstancia() {
    if (instancia == NULL) {
        instancia = new ColeccionUsuario();
    }
    return instancia;
}

// Agregar

void ColeccionUsuario::agregarUsuario(Usuario* usuario) {
    string nickname = usuario->getNickname();
    usuarios.insert(pair<string, Usuario*>(nickname, usuario));

}

// Obtener

Usuario* ColeccionUsuario::obtenerUsuario(string nickname) {
    return usuarios[nickname];
}

set<string> ColeccionUsuario::obtenerNicknamesUsuarios() {
    set<string> nicknames;
    for (map<string, Usuario*>::iterator it = usuarios.begin(); it != usuarios.end(); ++it) {
        nicknames.insert(it->first);
    }
    return nicknames;
}

// Consultar

bool ColeccionUsuario::existeUsuario(string nickname) {
    return usuarios.find(nickname) != usuarios.end();
}

bool ColeccionUsuario::existeUsuario(Usuario* usuario) {
    return existeUsuario(usuario->getNickname());
}

// Eliminar

void ColeccionUsuario::eliminarUsuario(string nickname) {
    usuarios.erase(nickname);
}

void ColeccionUsuario::eliminarUsuario(Usuario* usuario) {
    eliminarUsuario(usuario->getNickname());
}


