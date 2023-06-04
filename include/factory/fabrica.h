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

    /*Devuelve un puntero la instancia de Fabrica. si no existe, la crea*/
    static Fabrica* getInstancia();
    static void deleteInstancia();

    // Controladores
    IControladorCurso* getIControladorCurso();
    IControladorUsuario* getIControladorUsuario();
    IControladorEstadistica* getIControladorEstadistica();
    

    // Interfaces
    ISuscriptor* getSuscriptor(string nickname);

};

#endif 