#include <iostream>
#include <string>

#include "../../include/CasosDeUso/AltaDeUsuario.h"

#include "../../include/factory/fabrica.h"
#include "../../include/operaciones.h"

#include "../../include/interfaces/IControladorCurso.h"
#include "../../include/interfaces/IControladorEstadistica.h"
#include "../../include/interfaces/IControladorUsuario.h"

using namespace std;



void AltaDeUsuario() {
  Fabrica *fabrica = Fabrica::getInstancia();
  IControladorUsuario *controladorUsuario = fabrica->getIControladorUsuario();

  // Ingresar nickname
  string nickname = ingresarParametro("el nickname");

  // Ingresar password
  string password;
  do {
    password = ingresarParametro("el password");
    if (password.length() < 6) {
      cout << "El password debe tener al menos 6 caracteres" << endl;
    }
  } while (password.length() < 6);

  // Ingresar nombre
  string nombre = ingresarParametro("el nombre");

  // Ingresar descripcion
  string descripcion = ingresarParametro("la descripcion");

  // Imprimir datos ingresados
  cout << "Datos ingresados: " << endl;
  cout << "Nickname: " << nickname << endl;
  cout << "Password: " << password << endl;
  cout << "Nombre: " << nombre << endl;
  cout << "Descripcion: " << descripcion << endl;

  controladorUsuario->ingresarUsuario(nickname, password, nombre, descripcion);
  cout << "Tipo de usuario: " << endl;
  cout << "0. Profesor" << endl;
  cout << "1. Estudiante" << endl;

  int tipoUsuario = ingresarOpcion(1);

  if (tipoUsuario == 0) { // Profesor
    string instituto = ingresarParametro("el instituto");

    controladorUsuario->ingresarDatosProfesor(instituto);

    cout << "Lista de Idiomas disponibles " << endl;
    set<string> idiomas = controladorUsuario->listarNombresDeIdiomasDisponibles();
    imprimirSet(idiomas);

    string idioma = ingresarParametro("el idioma");

    controladorUsuario->seleccionarIdioma(idioma);

    cout << endl << "Profesor creado con exito" << endl;
    
  } else if (tipoUsuario == 1) { // Estudiante
    cout << "Ingrese el pais: ";
    string pais;
    cin >> pais;
    controladorUsuario->ingresarDatosEstudiante(pais);
    controladorUsuario->altaEstudiante();
    cout << endl << "Estudiante creado con exito" << endl;
  }
}
