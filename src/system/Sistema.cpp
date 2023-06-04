#include "../../include/system/Sistema.h"
#include "../../include/interfaces/IControladorUsuario.h"
#include "../../include/factory/fabrica.h"

Sistema *Sistema::instancia = NULL;
IControladorUsuario *Sistema::controladorUsuario = NULL;



Sistema::Sistema() {
    controladorUsuario = Fabrica::getInstancia()->getIControladorUsuario();
}

Sistema::~Sistema() {
    if (controladorUsuario != NULL) {
        delete controladorUsuario;
    }
}

Sistema *Sistema::getInstancia() {
    if (instancia == NULL) {
        instancia = new Sistema();
    }
    return instancia;
}

void Sistema::destruirInstancia() {
    if (instancia != NULL) {
        delete instancia;
        instancia = NULL;
    }
}
