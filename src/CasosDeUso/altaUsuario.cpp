#include <iostream>
#include <string>


#include "../../include/factory/fabrica.h"
#include "../../include/operaciones.h"

#include "../../include/interfaces/IControladorCurso.h"
#include "../../include/interfaces/IControladorEstadistica.h"
#include "../../include/interfaces/IControladorUsuario.h"


using namespace std;

void altaUsuario() {
  Fabrica *fabrica = Fabrica::getInstancia();
  IControladorUsuario *controladorUsuario = fabrica->getIControladorUsuario();

  cout << "Alta de usuario" << endl;

  cout << "Ingrese el nickname: ";
  string nickname;
  cin >> nickname;
  cout << endl;

  string password;
  do {
    cout << "Ingrese el password: ";
    cin >> password;
    cout << endl;
    if (password.length() < 6) {
      cout << "El password debe tener al menos 6 caracteres" << endl;
    }
  } while (password.length() < 6);

  cout << "Ingrese el nombre: ";
  string name;
  cin >> name;
  cout << endl;
  cout << "Ingrese la descripcion: ";
  string descripcion;
  cin >> descripcion;
  cout << endl;

  cout << nickname << " - " << password << " - " << name << " - " << descripcion
       << endl;
  //

  controladorUsuario->ingresarUsuario(nickname, password, name, descripcion);
  cout << "Tipo de usuario: " << endl;
  cout << "0. Profesor" << endl;
  cout << "1. Estudiante" << endl;

  int tipoUsuario = ingresarOpcion(1);
  cout << endl;

  if (tipoUsuario == 0) {
    cout << "Ingrese el instituto: ";
    string instituto;
    cin >> instituto;
    cout << endl;
    controladorUsuario->ingresarDatosProfesor(instituto);

    cout << "Lista de Idiomas disponibles " << endl;
    set<string> idiomas =
        controladorUsuario->listarNombresDeIdiomasDisponibles();
    imprimirSet(idiomas);

    cout << "Ingrese el idioma: ";
    string idioma;

    controladorUsuario->seleccionarIdioma(idioma);
    
  } else {
    cout << "Ingrese el pais: ";
    string pais;
    cin >> pais;
    cout << endl;
    controladorUsuario->ingresarDatosEstudiante(pais);
    controladorUsuario->altaEstudiante();
    cout << "Estudiante creado con exito" << endl;
  }
}