#include "../../include/factory/Fabrica.h"

// interfaces
#include "../../include/interfaces/ISuscriptor.h"
#include "../../include/interfaces/IControladorCurso.h"
#include "../../include/interfaces/IControladorUsuario.h"

// controladores
#include "../../include/controllers/ControladorCurso.h"
#include "../../include/controllers/ControladorUsuario.h"
#include "../../include/controllers/ControladorEstadistica.h"


using namespace std;

Fabrica* Fabrica::instancia = NULL;

Fabrica* Fabrica::getInstancia() {
    if (instancia == NULL) {
        instancia = new Fabrica();
    }
    return instancia;
}

void Fabrica::deleteInstancia() {
    if (instancia != NULL) {
        delete instancia;
        instancia = NULL;
    }
}


IControladorUsuario* Fabrica::getIControladorUsuario() {
    return ControladorUsuario::getInstancia();
}

IControladorCurso* Fabrica::getIControladorCurso() {
    return ControladorCurso::getInstancia();
}