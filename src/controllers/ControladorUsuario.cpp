#include "../../include/interfaces/IControladorUsuario.h"
#include "../../include/controllers/ControladorUsuario.h"

#include "../../include/classes/Usuario/Usuario.h"
#include "../../include/classes/Usuario/Estudiante.h"
#include "../../include/classes/Usuario/Profesor.h"

#include "../../include/classes/Idioma.h"

#include "../../include/handlers/HandlerIdioma.h"
#include "../../include/handlers/HandlerUsuario.h"

#include "../../include/datatypes/DTUsuario.h"
#include "../../include/datatypes/DTEstudiante.h"
#include "../../include/datatypes/DTProfesor.h"

#include "../../include/datatypes/DTNotificacion.h"

#include "../../include/datatypes/DTDate.h"

#include "../../include/interfaces/ISuscriptor.h"


#include <iostream>
#include <string>
#include <set>
#include <map>
#include <stdexcept>

#include <iostream>

using namespace std;

//Coleccion de punteros a Idiomas
HandlerIdioma* coleccionIdiomas = HandlerIdioma::getInstancia();

//Coleccion de punteros a Usuarios
HandlerUsuario* coleccionUsuarios = HandlerUsuario::getInstancia();

// Singleton
ControladorUsuario* ControladorUsuario::instancia = NULL;

ControladorUsuario::ControladorUsuario() {}

ControladorUsuario::~ControladorUsuario() {
    if (coleccionIdiomas != NULL) {
        coleccionIdiomas->deleteInstancia();
        coleccionIdiomas = NULL;
    }

    if (coleccionUsuarios != NULL) {
        coleccionUsuarios->deleteInstancia();
        coleccionUsuarios = NULL;
    }

}

IControladorUsuario* ControladorUsuario::getInstancia() {
    if (instancia == NULL) {
        instancia = new ControladorUsuario();
    }
    return instancia;
}


// Operaciones
void ControladorUsuario::ingresarUsuario(string nickname, string password, string name, string desc) {

    // Guardar los datos ingresados en el caso de uso "Alta de Usuario"
    this->actual_nickname = nickname;
    this->actual_password = password;
    this->actual_name = name;
    this->actual_desc = desc;

    // Verificar si el nickname ya existe
    if (coleccionUsuarios->existeUsuario(nickname)) {
        throw invalid_argument("El nickname ya está en uso");
    }
    
}

void ControladorUsuario::ingresarDatosEstudiante(string pais) {
    this->actual_pais = pais;
}

void ControladorUsuario::altaEstudiante() {
    //Verificar si el nickname ya existe
    if (coleccionUsuarios->existeUsuario(actual_nickname)) {
        throw invalid_argument("El nickname ya está en uso");
    }

    // Crear el estudiante
    Estudiante* estudiante = new Estudiante(actual_nickname, actual_password, actual_name, actual_desc, actual_pais);

    // Agregar el estudiante a la colección
    coleccionUsuarios->agregarUsuario(estudiante);

    // Limpiar los datos ingresados
    this->actual_nickname = "";
    this->actual_password = "";
    this->actual_name = "";
    this->actual_desc = "";
    this->actual_pais = "";

}


void ControladorUsuario::ingresarDatosProfesor(string instituto) {
    this->actual_instituto = instituto;
}

void ControladorUsuario::altaProfesor(set<string> idiomas) {
    // Verificar si el nickname ya existe
    if (coleccionUsuarios->existeUsuario(actual_nickname)) {
        throw invalid_argument("El nickname ya está en uso");
    }
   
   // Mapea los nombres de los idiomas a los punteros a los idiomas
    set <Idioma*> idiomasMap;
    set<string>::iterator it;
    for (it = idiomas.begin(); it != idiomas.end(); it++) {
        string nombreIdioma = *it;
        Idioma* idioma = coleccionIdiomas->obtenerIdioma(nombreIdioma);
        idiomasMap.insert(idioma);
    }

    // Crear el profesor
    Profesor* profesor = new Profesor(actual_nickname, actual_password, actual_name, actual_desc, actual_instituto, idiomasMap);

    // Agregar el profesor a la colección
    coleccionUsuarios->agregarUsuario(profesor);
     
    // Limpiar los datos ingresados
    this->actual_nickname = "";
    this->actual_password = "";
    this->actual_name = "";
    this->actual_desc = "";
    this->actual_instituto = "";

}



set<string> ControladorUsuario::seleccionarIdioma(string nombre) {
    set<string> idiomas; // Valor vacío
    return idiomas;
}


set<string> ControladorUsuario::listarNombresDeIdiomasDisponibles() {
    set<string> idiomas = coleccionIdiomas->obtenerNombresIdiomas();
    return idiomas;
}


set<string> ControladorUsuario::listarNombresIdiomasDeProfesor(string nicknameProfesor) {
    if (!coleccionUsuarios->existeUsuario(nicknameProfesor)) {
        throw invalid_argument("El nickname no existe");
    }
    Profesor* profesor = dynamic_cast<Profesor*>(coleccionUsuarios->obtenerUsuario(nicknameProfesor));
    set<Idioma*> idiomas = profesor->getIdiomas();
    set<Idioma*>::iterator it;
    set<string> nombresIdiomas;

    for (it = idiomas.begin(); it != idiomas.end(); it++) {
        Idioma* idioma = *it;
        nombresIdiomas.insert(idioma->getNombre());
    }
    return nombresIdiomas;
}

set<string> ControladorUsuario::listarNIcknameProfesores() {
    set<string> nicknames; 
    set<Usuario*> usuarios = coleccionUsuarios->obtenerUsuarios();
    set<Usuario*>::iterator it;
    for (it = usuarios.begin(); it != usuarios.end(); it++) {
        Usuario* usuario = *it;
        if (usuario->esProfesor()) {
            nicknames.insert(usuario->getNickname());
        }
    }
    return nicknames;
}

set<string> ControladorUsuario::listarIdiomasNoSuscriptos(string nickname) {
    this->actual_nickname = nickname;
    map<string, Idioma*> idiomas = coleccionIdiomas->obtenerIdiomas();
    map<string, Idioma*>::iterator it;
    set<string> nombresIdiomas;
    for (it = idiomas.begin(); it != idiomas.end(); it++) {
        string nombreIdioma = it->first;
        Idioma* idioma = it->second;
        if (!idioma->contieneSuscriptor(nickname)) {
            nombresIdiomas.insert(nombreIdioma);
        }
    }
    return nombresIdiomas;

}

set<string> ControladorUsuario::listarIdiomasSuscriptos(string nickname) {
    set<string> idiomas; // Valor vacío
    return idiomas;
}

void ControladorUsuario::seleccionarProfesor(string nicknameProfesor) { //TODO: Tiene que existir el profesor
    if(!(coleccionUsuarios->existeUsuario(nicknameProfesor))){
        throw invalid_argument("");
    }
}

void ControladorUsuario::suscribirse(string nombreIdioma) {
    ISuscriptor* suscriptor = dynamic_cast<ISuscriptor*>(coleccionUsuarios->obtenerUsuario(actual_nickname));
    coleccionIdiomas->obtenerIdioma(nombreIdioma)->agregarSuscriptor(suscriptor);
}

set<DTNotificacion*> ControladorUsuario::listarNotificaciones(string nickName) {
    this->actual_nickname = nickName;
    set<DTNotificacion*> notificaciones; // Valor vacío
    return notificaciones;
}

void ControladorUsuario::eliminarNotificaciones() {
    // Implementación mínima

    // Limpiar los datos ingresados
    this->actual_nickname = "";
}

void ControladorUsuario::eliminarSuscripcion(string idioma) {
    // Implementación mínima
}

void ControladorUsuario::crearIdioma(string nombre) {
    Idioma *idioma = new Idioma(nombre);
    this->idiomaActual = idioma;
}

void ControladorUsuario::altaIdioma() {
    string nombre = this -> idiomaActual->getNombre();
    if (coleccionIdiomas->existeIdioma(nombre)) {
        delete this -> idiomaActual;
        throw invalid_argument("El idioma ya existe en el sistema");
    }
    coleccionIdiomas->agregarIdioma(this -> idiomaActual);
    this -> idiomaActual = NULL;
}

DTUsuario* ControladorUsuario::getDataUsuarioIngresado() {
    DTUsuario* dtUsuario = NULL;
    return dtUsuario;
}

set<string> ControladorUsuario::listarNicknameUsuarios() {
    set<string> nicknames = coleccionUsuarios -> obtenerNicknamesUsuarios();
    return nicknames;
}

DTUsuario* ControladorUsuario::seleccionarUsuario(string nickname) {
    Usuario * usuario = coleccionUsuarios -> obtenerUsuario(nickname);
    DTUsuario * dtUsuario = usuario -> getDT();
    return dtUsuario;
}


