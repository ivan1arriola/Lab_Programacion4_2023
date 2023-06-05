#include <iostream>
#include <string>

#include "../../../include/system/Sistema.h"

#include "../../../include/factory/fabrica.h"
#include "../../../include/system/operaciones.h"

#include "../../../include/interfaces/IControladorCurso.h"
#include "../../../include/interfaces/IControladorEstadistica.h"
#include "../../../include/interfaces/IControladorUsuario.h"

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

    imprimirSet(nicknames, "Usuarios disponibles" ) ;

    // Seleccionar nickname
    int index = ingresarOpcion(nicknames.size()) - 1 ;

    if (index < 0) {
        return;
    }

    

    // Obtener nickname
    
    string nickname = *next(nicknames.begin(), index);
    imprimirMensaje("A seleccionado el usuario: " + nickname);

    cout << endl;

    // Obtener informacion del usuario
    DTUsuario* dtUsuario = controladorUsuario->seleccionarUsuario(nickname);


    if (dtUsuario->getTipo() == 0) {
        DTProfesor* dtProfesor = dynamic_cast<DTProfesor*>(dtUsuario);
        cout << "Información del profesor:" << endl;
        cout << "Nickname: " << dtProfesor->getNickname() << endl;
        cout << "Nombre: " << dtProfesor->getNombre() << endl;
        cout << "Descripción: " << dtProfesor->getDescripcion() << endl;
        cout << "Instituto: " << dtProfesor->getInstituto() << endl;
        delete dtProfesor; //TODO: Warning: deleting object of polymorphic class type ‘DTProfesor’ which has non-virtual destructor might cause undefined behaviour [-Wdelete-non-virtual-dtor]
    } else {
        DTEstudiante* dtEstudiante = dynamic_cast<DTEstudiante*>(dtUsuario);
        cout << "Información del estudiante:" << endl;
        cout << "Nickname: " << dtEstudiante->getNickname() << endl;
        cout << "Nombre: " << dtEstudiante->getNombre() << endl;
        cout << "Descripción: " << dtEstudiante->getDescripcion() << endl;
        cout << "País: " << dtEstudiante->getPais() << endl;
        delete dtEstudiante; //TODO: Warning: deleting object of polymorphic class type ‘DTEstudiante’ which has non-virtual destructor might cause undefined behaviour [-Wdelete-non-virtual-dtor]
    }
    
}
