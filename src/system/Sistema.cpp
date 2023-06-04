#include "../../include/system/Sistema.h"
#include "../../include/interfaces/IControladorUsuario.h"
#include "../../include/factory/Fabrica.h"

Sistema *Sistema::instancia = NULL;

// Fabrica
Fabrica *Sistema::fabricaSistema = NULL;

// Controladores
IControladorUsuario *Sistema::controladorUsuario = NULL;

// Handlers de colecciones
HandlerUsuario *Sistema::handlerUsuario = NULL;
HandlerIdioma *Sistema::handlerIdioma = NULL;


Sistema::Sistema() {
    fabricaSistema = Fabrica::getInstancia();
    controladorUsuario = fabricaSistema->getIControladorUsuario();
    handlerUsuario = HandlerUsuario::getInstancia();
    handlerIdioma = HandlerIdioma::getInstancia();
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
    // Liberar memoria de la fabrica
    if(fabricaSistema != NULL) {
        fabricaSistema->deleteInstancia();
        fabricaSistema = NULL;
    }

    // Liberar memoria de los controladores
    if(controladorUsuario != NULL) {
        delete controladorUsuario;
        controladorUsuario = NULL;
    }

    // Liberar memoria de los handlers
    if(handlerUsuario != NULL) {
        handlerUsuario->deleteInstancia();
        handlerUsuario = NULL;
    }

    if(handlerIdioma != NULL) {
        handlerIdioma->deleteInstancia();
        handlerIdioma = NULL;
    }

    // Liberar memoria de la instancia
    if(instancia != NULL) {
        delete instancia;
        instancia = NULL;
    }


}
