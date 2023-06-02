#include "../../include/controllers/ControladorUsuario.h"

#include "../../include/interfaces/IControladorUsuario.h"

#include "../../include/classes/Usuario/Usuario.h"
#include "../../include/classes/Usuario/Estudiante.h"
#include "../../include/classes/Usuario/Profesor.h"

#include "../../include/classes/Idioma.h"

#include "../../include/collections/ColeccionIdioma.h"
#include "../../include/collections/ColeccionUsuario.h"

#include "../../include/datatypes/DTUsuario.h"
#include "../../include/datatypes/DTEstudiante.h"
#include "../../include/datatypes/DTProfesor.h"

#include "../../include/datatypes/DTNotificacion.h"

#include "../../include/datatypes/DTDate.h"


#include <iostream>
#include <string>
#include <set>
#include <map>
#include <stdexcept>


using namespace std;

//Coleccion de punteros a Idiomas
ColeccionIdioma* coleccionIdiomas = ColeccionIdioma::getInstancia();


//Coleccion de punteros a Usuarios
ColeccionUsuario* coleccionUsuarios = ColeccionUsuario::getInstancia();

// Singleton
ControladorUsuario* ControladorUsuario::instancia = NULL;

ControladorUsuario::ControladorUsuario() {}



ControladorUsuario::~ControladorUsuario() {
    // Eliminar los usuarios
    // map<string, Usuario*>::iterator it;
    // for (it = coleccionUsuarios.begin(); it != coleccionUsuarios.end(); it++) {
    //     delete it->second;
    // }
    // coleccionUsuarios.clear();
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
        throw runtime_error("El nickname ya está en uso");
    }
}

void ControladorUsuario::ingresarDatosEstudiante(string pais) {
    this->actual_pais = pais;
}

void ControladorUsuario::altaEstudiante() {
    //Verificar si el nickname ya existe
    if (coleccionUsuarios->existeUsuario(actual_nickname)) {
        throw runtime_error("El nickname ya está en uso");
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
        throw runtime_error("El nickname ya está en uso");
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
    //Profesor(string nickname, string contrasenia, string nombre, string descripcion, string instituto, set<Idioma*> idiomasDeProfesor);
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
    set<string> idiomas; // Valor vacío
    return idiomas;
}

set<string> ControladorUsuario::listarNIcknameProfesores() {
    set<string> nicknames; // Valor vacío
    return nicknames;
}

set<string> ControladorUsuario::listarIdiomasNoSuscriptos(string nickname) {
    set<string> idiomas; // Valor vacío
    return idiomas;
}

set<string> ControladorUsuario::listarIdiomasSuscriptos(string nickname) {
    set<string> idiomas; // Valor vacío
    return idiomas;
}

void ControladorUsuario::seleccionarProfesor(string nicknameProfesor) {
    // Implementación mínima
}

void ControladorUsuario::suscribirse(string nombreIdioma) {
    // Implementación mínima
}

set<DTNotificacion> ControladorUsuario::listarNotificaciones(string nickName) {
    set<DTNotificacion> notificaciones; // Valor vacío
    return notificaciones;
}

void ControladorUsuario::eliminarNotificaciones() {
    // Implementación mínima
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
    delete this -> idiomaActual;
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


