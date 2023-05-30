#include "../../include/factory/fabrica.h"

#include "../../include/interfaces/ISuscriptor.h"
#include "../../include/interfaces/IControladorCurso.h"
#include "../../include/interfaces/IControladorUsuario.h"

Fabrica* Fabrica::instancia = NULL;

Fabrica* Fabrica::getInstancia() {
    if (instancia == NULL) {
        instancia = new Fabrica();
    }
    return instancia;
}

IControladorCurso* Fabrica::getIControladorCurso() {
    return IControladorCurso::getInstancia();
}

IControladorUsuario* Fabrica::getIControladorUsuario() {
    return IControladorUsuario::getInstancia();
}

ISuscriptor* Fabrica::getSuscriptor(string nickname) {
    return ISuscriptor::getInstancia(nickname);
}




