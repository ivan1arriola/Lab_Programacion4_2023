#include <iostream>
#include <string>

#include "../../../include/system/Sistema.h"

#include "../../../include/system/operaciones.h"

#include "../../../include/datatypes/DTUsuario.h"
#include "../../../include/datatypes/DTProfesor.h"
#include "../../../include/datatypes/DTEstudiante.h"

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

void Sistema::consultaDeUsuario() {
    imprimirMensaje("Consulta de Usuario");

    // Obtener coleccion de usuarios
    set<string> nicknames = controladorUsuario->listarNicknameUsuarios();

    // Imprimir usuarios

    if (nicknames.size() == 0) {
        imprimirMensaje("No hay usuarios registrados");
        return;
    }

    

    // Seleccionar nickname
    string nickname = seleccionarElemento(nicknames, "usuario");
    imprimirMensaje("A seleccionado el usuario: " + nickname);

    espacioSimple();

    // Obtener informacion del usuario
    DTUsuario* dtUsuario = controladorUsuario->seleccionarUsuario(nickname);


    if (dtUsuario->getTipo() == 1) {
        DTEstudiante* dtEstudiante = dynamic_cast<DTEstudiante*>(dtUsuario);
        cout << *dtEstudiante << endl;
    } else {
        DTProfesor* dtProfesor = dynamic_cast<DTProfesor*>(dtUsuario);
        cout << *dtProfesor << endl;
    }

    delete dtUsuario;
    
}
