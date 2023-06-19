#include <iostream>
#include <string>

#include "../../../include/system/Sistema.h"

#include "../../../include/system/operaciones.h"

using namespace std;

/**
 * Nombre Suscribirse a notificaciones
Actores Usuario
Sinopsis: El caso de uso comienza cuando un usuario desea suscribirse para recibir notificaciones
relativas a la creación de cursos de uno o más idiomas. Para ello, el Usuario indica un
nickname (de estudiante o profesor) y el Sistema devuelve la lista de todos los idiomas
a los que no está suscrito dicho usuario. Posteriormente, el Usuario indica los idiomas
a los que desea suscribirse y el Sistema lo agrega a la lista de suscriptores.
 * **/

void Sistema::suscribirseANotificaciones() {

    try
    {
        imprimirMensaje("Suscribirse A Notificaciones");

        set<string> nicknames = controladorUsuario->listarNicknameUsuarios();
        string nickname = seleccionarElemento(nicknames, "Nickname");

        if (nickname.empty()) throw invalid_argument("No se seleccionó un nickname");

        set<string> idiomas = controladorUsuario->listarIdiomasNoSuscriptos(nickname);

        if (idiomas.empty()) throw invalid_argument("El usuario ya está suscripto a todos los idiomas");

        bool deseaSuscribirse = true;

        imprimirMensaje("Idiomas a los que no está suscripto:");
        do {
            string idioma = seleccionarElemento(idiomas, "Idioma");
            if (idioma.empty()) throw invalid_argument("No se seleccionó un idioma");
            controladorUsuario->suscribirse(idioma);
            idiomas.erase(idioma);
            if(!idiomas.empty()) {
                deseaSuscribirse = ingresarBooleano("¿Desea suscribirse a otro idioma?");
            } else {
                deseaSuscribirse = false;
            }
        } while (deseaSuscribirse && !idiomas.empty());

        if (idiomas.empty()) {
            imprimirMensaje("El usuario ya se suscribió a todos los idiomas");
        }
    }
    catch(const std::exception& e)
    {
        cancelarOperacion(e.what(), "Suscribirse A Notificaciones");
    }
    
}
