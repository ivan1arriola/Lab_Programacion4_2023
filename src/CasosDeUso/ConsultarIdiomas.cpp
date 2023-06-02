#include <iostream>
#include <string>

#include "../../include/CasosDeUso/ConsultarIdiomas.h"

#include "../../include/factory/fabrica.h"
#include "../../include/operaciones.h"

#include "../../include/interfaces/IControladorCurso.h"
#include "../../include/interfaces/IControladorEstadistica.h"
#include "../../include/interfaces/IControladorUsuario.h"

using namespace std;

/*
    Nombre: Consultar idiomas
    Actores: Usuario
    Sinopsis: El caso de uso comienza cuando un Usuario desea consultar los idiomas del sistema.
    Para ello, el Sistema lista los nombres de todos los idiomas existentes.
*/

void ConsultarIdiomas() {
    imprimirMensaje("Consultar Idiomas");

    // Obtener instancia de IControladorUsuario
    Fabrica *fabrica = Fabrica::getInstancia();
    IControladorUsuario *controladorUsuario = fabrica->getIControladorUsuario();

    // Obtener coleccion de idiomas
    set<string> nombreIdiomas = controladorUsuario->listarNombresDeIdiomasDisponibles();

    // Imprimir idiomas
    imprimirSet(nombreIdiomas, "Idiomas disponibles" ) ;

}
