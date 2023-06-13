#include <iostream>
#include <string>
#include <set>

#include "../../../include/system/Sistema.h"
#include "../../../include/system/operaciones.h"


using namespace std;

void Sistema::eliminarSuscripciones() {
    imprimirMensaje("Eliminar Suscripciones");

    set<string> usuarios = controladorUsuario->listarNicknameUsuarios();

    if (usuarios.empty()) {
        imprimirMensaje("No hay usuarios registrados en el sistema");
        return;
    }

    string nickname = seleccionarElemento(usuarios, "Seleccione el usuario del cual desea eliminar sus suscripciones");
    if (nickname == "") {
        imprimirMensaje("No se selecciono ningun usuario");
        return;
    }

    

    bool quiereEliminarUnaSuscripcion = true;
    
    do {
        set<string> suscripciones = controladorUsuario->listarIdiomasSuscriptos(nickname); // Guarda el nickname del usuario seleccionado
        
        if (suscripciones.empty()) {
            imprimirMensaje("El usuario no tiene suscripciones");
            return;
        }

        string id = seleccionarElemento(suscripciones, "Seleccione el idioma del cual desea eliminar la suscripcion");
        if (id == "") {
            imprimirMensaje("No se selecciono ningun idioma");
            return;
        }

        controladorUsuario->eliminarSuscripcion(id);

        imprimirMensaje("Se elimino la suscripcion al idioma " + id);

        quiereEliminarUnaSuscripcion = deseaContinuar("¿Desea eliminar otra suscripcion? (S/N)");

    } while (quiereEliminarUnaSuscripcion);

    imprimirMensaje("Se eliminaron todas las suscripciones solicitadas de  " + nickname);

    imprimirMensaje("Finalizando Eliminar Suscripciones");

}
