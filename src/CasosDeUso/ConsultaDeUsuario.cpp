#include <iostream>
#include <string>

#include "../../include/CasosDeUso/ConsultaDeUsuario.h"

#include "../../include/factory/fabrica.h"
#include "../../include/operaciones.h"

#include "../../include/interfaces/IControladorCurso.h"
#include "../../include/interfaces/IControladorEstadistica.h"
#include "../../include/interfaces/IControladorUsuario.h"

using namespace std;

/*
    Nombre: Consulta de usuario
    Actores: Usuario
    Sinopsis: El caso de uso comienza cuando se desea consultar la información de los usuarios del
    sistema. Para esto, el Sistema lista los nicknames (pseudónimos) de todos los usuarios.
    Luego, el Usuario selecciona uno y el Sistema muestra la información correspondiente:
    nombre y descripción. En caso de que el nickname pertenezca a un estudiante,
    adicionalmente se muestra el país donde reside, mientras que, si se trata de un profesor,
    se muestra el nombre del instituto donde trabaja y la lista de idiomas en los que se
    especializa.
*/

void ConsultaDeUsuario() {
    imprimirMensaje("Consulta de Usuario");

    // Obtener instancia de IControladorUsuario
    Fabrica *fabrica = Fabrica::getInstancia();
    IControladorUsuario *controladorUsuario = fabrica->getIControladorUsuario();

    // Obtener coleccion de usuarios
    set<string> nicknames = controladorUsuario->listarNicknameUsuarios();

    // Imprimir usuarios

    if (nicknames.size() == 0) {
        imprimirMensaje("No hay usuarios registrados");
        return;
    }

    imprimirSet(nicknames, "Usuarios disponibles" ) ;

    // Ingresar nickname
    string nickname = ingresarParametro("el nickname del usuario");

    // Obtener informacion del usuario
    
    
    
}
