#include <iostream>
#include <string>

#include "../../include/CasosDeUso/AltaDeIdioma.h"

#include "../../include/factory/fabrica.h"
#include "../../include/operaciones.h"

#include "../../include/interfaces/IControladorCurso.h"
#include "../../include/interfaces/IControladorEstadistica.h"
#include "../../include/interfaces/IControladorUsuario.h"


using namespace std;

/*
    Nombre: Alta de idioma
    Actores: Usuario
    Sinopsis: El caso de uso comienza cuando se desea dar de alta un nuevo idioma en el sistema.
    Para ello, el Usuario ingresa el nombre del idioma y el Sistema da de alta el nuevo
    idioma. En caso de que ya exista un idioma con ese nombre, el Sistema comunica el
    error y no se da de alta el idioma.
*/

void AltaDeIdioma() {
    imprimirMensaje("Alta de Idioma");

    // Obtener instancia de IControladorUsuario
    Fabrica *fabrica = Fabrica::getInstancia();
    IControladorUsuario *controladorUsuario = fabrica->getIControladorUsuario();

    // Ingresar nombre del idioma
    string nombre = ingresarParametro("el nombre del idioma");

    // Crear idioma
    controladorUsuario->crearIdioma(nombre);

    // Imprimir Idioma creado
    imprimirMensaje("Idioma creado: " + nombre);

    // Dar de alta el idioma
    try {
        controladorUsuario->altaIdioma();
        imprimirMensaje("Idioma dado de alta");
    } catch (invalid_argument &e) {
        imprimirMensaje("Error: " + string(e.what()));
    }

}
