/*
#ifndef FABRICA
#define FABRICA

#include <string>

#include "../interfaces/ISuscriptor.h"
#include "../interfaces/IControladorCurso.h"
#include "../interfaces/IControladorUsuario.h"
#include "../interfaces/IControladorEstadistica.h"

using namespace std;

// Singleton
class Fabrica {

private:
    Fabrica() {};

    static Fabrica* instancia;

     ~Fabrica() {}
public:

    // Getters
    static Fabrica* getInstancia();

    // Controladores
    IControladorCurso getIControladorCurso();
    IControladorUsuario getIControladorUsuario();
    IControladorEstadistica getIControladorEstadistica();
    

    // Interfaces
    ISuscriptor getSuscriptor(string nickname);

};

#endif 
*/

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
    return NULL;
}

IControladorUsuario* Fabrica::getIControladorUsuario() {
    return NULL;
}

ISuscriptor* Fabrica::getSuscriptor(string nickname) {
    return NULL;
}




