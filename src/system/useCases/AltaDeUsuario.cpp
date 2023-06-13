#include <iostream>
#include <string>

#include "../../../include/system/Sistema.h"

#include "../../../include/system/operaciones.h"


using namespace std;

/*
  Nombre **Alta de usuario**
  Actores **Usuario**
  Sinopsis: El caso de uso comienza cuando se desea dar de alta un usuario en el sistema.
  El Usuario ingresa un nickname (pseudónimo), una contraseña (de al menos 6 caracteres), un nombre y una descripción.
  En caso de tratarse de un estudiante, se ingresa también el nombre del país donde reside,
  mientras que, si se trata de un profesor, se ingresa el nombre del instituto donde trabaja.
  Además, el Sistema lista los idiomas disponibles para que el Usuario seleccione aquellos en los que se especializa el profesor.
  El Usuario debe seleccionar al menos un idioma.
  Finalmente, el Sistema da de alta el nuevo usuario con los datos ingresados.
  En caso de que ya exista en el sistema un usuario con el nickname ingresado,
  el Sistema comunica el error y no se da de alta el usuario.
*/

void Sistema::altaDeUsuario() {
  imprimirMensaje("Alta de Usuario");

  // Ingresar nickname 
  string nickname = ingresarParametro("el nickname");

  espacioSimple();

  // Ingresar password
  string password;
  do {
    password = ingresarParametro("el password");
    if (password.length() < 6) {
      cout << "El password debe tener al menos 6 caracteres" << endl;
    }
  } while (password.length() < 6);

  espacioSimple();

  // Ingresar nombre
  string nombre = ingresarParametro("el nombre");

  espacioSimple();

  // Ingresar descripcion
  string descripcion = ingresarParametro("la descripcion");

  espacioSimple();

  // Imprimir datos ingresados
  cout << "Datos ingresados: " << endl;
  cout << "Nickname: " << nickname << endl;
  cout << "Password: " << password << endl;
  cout << "Nombre: " << nombre << endl;
  cout << "Descripcion: " << descripcion << endl;

  espacioSimple();

  try {
    controladorUsuario->ingresarUsuario(nickname, password, nombre, descripcion);
  } catch (invalid_argument &e) {
    cancelarOperacion(e.what(), "Alta de usuario");
    return;
  }


  cout << "Tipo de usuario: " << endl;
  cout << endl;
  cout << "1. Profesor" << endl;
  cout << "2. Estudiante" << endl;
  cout << "0. Para cancelar" << endl;
  cout << endl;

  int tipoUsuario = ingresarOpcion(2);

  if (tipoUsuario == 0) {
    cancelarOperacion("Se ha seleccionado cancelar", "Alta de usuario");
    return;
  }

  espacioSimple();

  // Profesor
  if (tipoUsuario == 1) { 
  
    string instituto = ingresarParametro("el instituto");
    controladorUsuario->ingresarDatosProfesor(instituto);

    imprimirMensaje("Lista de Idiomas disponibles");
    set<string> idiomasDisponibles = controladorUsuario->listarNombresDeIdiomasDisponibles();
    

    if(idiomasDisponibles.size() == 0){
      imprimirMensaje("No hay idiomas disponibles");
      imprimirMensaje("No se puede crear un profesor");
      imprimirMensaje("Cancelando alta de usuario");
      return;
    }

    

    //TODO: Deberia ser un set de idiomas
    set<string> idiomasSeleccionados;

    imprimirMensaje("Seleccione los idiomas en los que se especializa el profesor");

    do
    {
      string idioma = seleccionarElemento(idiomasDisponibles, "Idiomas");
      if (idioma == "") {
        break;
      }
      idiomasSeleccionados.insert(idioma);
      idiomasDisponibles.erase(idioma);

      espacioSimple();

    } while (idiomasDisponibles.size() > 0);



    if (idiomasSeleccionados.size() == 0) {
      cancelarOperacion("Se debe seleccionar al menos un idioma", "Alta de usuario");
      return;
    } 

    imprimirSet(idiomasSeleccionados, "Idiomas seleccionados");

    controladorUsuario->altaProfesor(idiomasSeleccionados);
    
    imprimirMensaje("Profesor creado con exito");
    
  }
  
  if (tipoUsuario == 2) { // Estudiante
    string pais = ingresarParametro("el pais");
    controladorUsuario->ingresarDatosEstudiante(pais);
    controladorUsuario->altaEstudiante();
    imprimirMensaje("Estudiante creado con exito");
  }
}
