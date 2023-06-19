#include "../../include/system/Sistema.h"

// Interfaces - Controladores
#include "../../include/interfaces/IControladorUsuario.h"
#include "../../include/interfaces/IControladorCurso.h"
#include "../../include/interfaces/IControladorEstadistica.h"

// Fabrica
#include "../../include/factory/Fabrica.h"

Sistema *Sistema::instancia = NULL;

// Fabrica
Fabrica *Sistema::fabricaSistema = NULL;

// Controladores
IControladorUsuario *Sistema::controladorUsuario = NULL;
IControladorCurso *Sistema::controladorCurso = NULL;
IControladorEstadistica *Sistema::controladorEstadistica = NULL;



// Handlers de colecciones
HandlerUsuario *Sistema::handlerUsuario = NULL;
HandlerIdioma *Sistema::handlerIdioma = NULL;
HandlerCurso *Sistema::handlerCurso = NULL;


Sistema::Sistema() {
    fabricaSistema = Fabrica::getInstancia();


    controladorUsuario = fabricaSistema->getIControladorUsuario();
    controladorCurso = fabricaSistema->getIControladorCurso();
    controladorEstadistica = fabricaSistema->getIControladorEstadistica();


    handlerUsuario = HandlerUsuario::getInstancia();
    handlerIdioma = HandlerIdioma::getInstancia();
    handlerCurso = HandlerCurso::getInstancia();
}

Sistema::~Sistema() {
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

    if(controladorCurso != NULL) {
        delete controladorCurso;
        controladorCurso = NULL;
    }

    if(controladorEstadistica != NULL) {
        delete controladorEstadistica;
        controladorEstadistica = NULL;
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

    if(handlerCurso != NULL) {
        handlerCurso->deleteInstancia();
        handlerCurso = NULL;
    }
}

Sistema *Sistema::getInstancia() {
    if (instancia == NULL) {
        instancia = new Sistema();
    }
    return instancia;
}


