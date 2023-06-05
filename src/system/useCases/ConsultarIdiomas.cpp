#include <iostream>
#include <string>

#include "../../../include/system/Sistema.h"

#include "../../../include/system/operaciones.h"

using namespace std;

/*
    Nombre: Consultar idiomas
    Actores: Usuario
    Sinopsis: El caso de uso comienza cuando un Usuario desea consultar los idiomas del sistema.
    Para ello, el Sistema lista los nombres de todos los idiomas existentes.
*/

void Sistema::consultarIdiomas() {
    imprimirMensaje("Consultar Idiomas");

    // Obtener coleccion de idiomas
    set<string> nombreIdiomas = controladorUsuario->listarNombresDeIdiomasDisponibles();

    // Imprimir idiomas
    imprimirSet(nombreIdiomas, "Idiomas disponibles" ) ;

}
