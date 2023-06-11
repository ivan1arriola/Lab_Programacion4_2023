#include <iostream>
#include <set>
#include <string>
#include <vector>


#include "../../../include/system/Sistema.h"

#include "../../../include/system/operaciones.h"

#include "../../../include/datatypes/DTNotificacion.h"

using namespace std;


static void imprimirVector (vector<DTNotificacion *> notificaciones, string titulo) {
  imprimirMensaje(titulo + ":");
  espacioSimple();
  for (long unsigned int i = 0; i < notificaciones.size(); i++) {
    cout << *notificaciones[i] << endl;
    imprimirLinea();
  }
  espacioSimple();
}

void Sistema::consultaDeNotificaciones() {
  imprimirMensaje("Consulta de Notificaciones");
  imprimirLineaDeSeparacion();

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
    set<string>::iterator it = usuarios.begin(); //TODO: Cambiar por la funcion de seleccionar elemento
    advance(it, opcion - 1);
    nickname = *it;
    imprimirMensaje("Usuario seleccionado: " + nickname);
    imprimirLineaDeSeparacion();
  } else {
    imprimirMensaje("Operacion cancelada");
    return;
  }

  // Listar notificaciones
  vector<DTNotificacion *> notificaciones =
      controladorUsuario->listarNotificaciones(nickname);

  // Mostrar notificaciones
  if (notificaciones.size() == 0) {
    imprimirMensaje("No hay notificaciones para mostrar");
  } else {
    imprimirVector(notificaciones, "Notificaciones");
  }

  // Eliminar notificaciones
  controladorUsuario->eliminarNotificaciones();
}
