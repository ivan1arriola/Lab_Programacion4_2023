#include "../../include/handlers/HandlerUsuario.h"

#include <map>
#include <set>
#include <string>
#include <stdexcept>
#include <iostream>

#include "../../include/classes/Usuario/Usuario.h"

using namespace std;

HandlerUsuario* HandlerUsuario::instancia = NULL;

HandlerUsuario::HandlerUsuario() {}

HandlerUsuario* HandlerUsuario::getInstancia() {
    if (instancia == NULL) {
        instancia = new HandlerUsuario();
    }
    return instancia;
}

// Agregar

void HandlerUsuario::agregarUsuario(Usuario* usuario) {
    string nickname = usuario->getNickname();
    usuarios.insert(pair<string, Usuario*>(nickname, usuario));

}

// Obtener

Usuario* HandlerUsuario::obtenerUsuario(string nickname) {
    return usuarios[nickname];
}

set<string> HandlerUsuario::obtenerNicknamesUsuarios() {
    set<string> nicknames;
    for (map<string, Usuario*>::iterator it = usuarios.begin(); it != usuarios.end(); ++it) {
        nicknames.insert(it->first);
    }
    return nicknames;
}

// Consultar

bool HandlerUsuario::existeUsuario(string nickname) {
    return usuarios.find(nickname) != usuarios.end();
}

bool HandlerUsuario::existeUsuario(Usuario* usuario) {
    return existeUsuario(usuario->getNickname());
}

// Eliminar

void HandlerUsuario::eliminarUsuario(string nickname) {
    usuarios.erase(nickname);
}

void HandlerUsuario::eliminarUsuario(Usuario* usuario) {
    eliminarUsuario(usuario->getNickname());
}


//Destructor

HandlerUsuario::~HandlerUsuario() {
    for (map<string, Usuario*>::iterator it = usuarios.begin(); it != usuarios.end(); ++it) {
        delete it->second;
    }
}

void HandlerUsuario::deleteInstancia() {
    if (instancia != NULL) {
        delete instancia;
        instancia = NULL;
    }
}