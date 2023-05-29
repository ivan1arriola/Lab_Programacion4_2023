#ifndef FABRICA
#define FABRICA

#include <string>

#include "../interfaces/ISuscriptor.h"
#include "../interfaces/IControladorCurso.h"
#include "../interfaces/IControladorUsuario.h"
#include "../interfaces/IControladorEstadistica.h"

using namespace std;

class Fabrica {
public:
    Fabrica() {};
    virtual Fabrica* getInstancia() = 0;

    // Controladores
    virtual IControladorCurso getIControladorCurso() = 0;
    virtual IControladorUsuario getIControladorUsuario() = 0;
    virtual IControladorEstadistica getIControladorEstadistica() = 0;
    

    // Interfaces
    virtual ISuscriptor getSuscriptor(string nickname) = 0; //No se si es necesario el nickname


    virtual ~Fabrica() {}
};

#endif 

/*
getIControladorCurso():IControladorCurso
getIControladorUsuario():IControladorUsuario
getSuscriptor():Suscriptor
getIControladorEstadistica():IControladorUsuario
*/