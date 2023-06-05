#include <iostream>
#include <set>
#include <string>


#include "../../../include/system/Sistema.h"

#include "../../../include/system/operaciones.h"

#include "../../../include/datatypes/DTNotificacion.h"

using namespace std;

void Sistema::consultaDeNotificaciones() {
  imprimirMensaje("Consulta de Notificaciones");

  // Listar usuarios
  set<string> usuarios = controladorUsuario->listarNicknameUsuarios();

  if (usuarios.size() == 0) {
    imprimirMensaje("No hay usuarios en el sistema");
    return;
  } else {
    // Mostrar usuarios
    imprimirSet(usuarios, "Usuarios");
  }

  // Seleccionar usuario
  string nickname;
  int opcion = ingresarOpcion(usuarios.size());

  if (opcion != 0) {
    set<string>::iterator it = usuarios.begin();
    advance(it, opcion - 1);
    nickname = *it;
    imprimirMensaje("Usuario seleccionado: " + nickname);
  } else {
    imprimirMensaje("Operacion cancelada");
    return;
  }

  // Listar notificaciones
  set<DTNotificacion *> notificaciones =
      controladorUsuario->listarNotificaciones(nickname);

  // Mostrar notificaciones
  if (notificaciones.size() == 0) {
    imprimirMensaje("No hay notificaciones para mostrar");
  } else {
    for (set<DTNotificacion *>::iterator it = notificaciones.begin();
         it != notificaciones.end(); ++it) {
      DTNotificacion *notificacion = *it;
      cout << notificacion << endl;
    }
  }

  // Eliminar notificaciones
  controladorUsuario->eliminarNotificaciones();
}
