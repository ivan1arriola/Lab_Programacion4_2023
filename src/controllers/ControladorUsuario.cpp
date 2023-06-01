#include "../../include/controllers/ControladorUsuario.h"

#include "../../include/interfaces/IControladorUsuario.h"

#include "../../include/classes/Usuario/Usuario.h"
#include "../../include/classes/Usuario/Estudiante.h"
#include "../../include/classes/Usuario/Profesor.h"

#include "../../include/classes/Idioma.h"
#include "../../include/collections/ColeccionIdioma.h"

#include "../../include/datatypes/DTUsuario.h"
#include "../../include/datatypes/DTNotificacion.h"

#include "../../include/datatypes/DTDate.h"

#include <string>
#include <set>
#include <map>
#include <stdexcept>


using namespace std;

// Singleton
ControladorUsuario* ControladorUsuario::instancia = NULL;

ControladorUsuario::ControladorUsuario() {}

ControladorUsuario::~ControladorUsuario() {}

IControladorUsuario* ControladorUsuario::getInstancia() {
    if (instancia == NULL) {
        instancia = new ControladorUsuario();
    }
    return instancia;
}


// Operaciones

void ControladorUsuario::ingresarUsuario(string nickname, string password, string name, string desc) {
    this->actual_nickname = nickname;
    this->actual_password = password;
    this->actual_name = name;
    this->actual_desc = desc;
}

void ControladorUsuario::ingresarDatosEstudiante(string pais) {
    this->actual_pais = pais;
}

void ControladorUsuario::altaEstudiante() {
    // Verificar si el nickname ya existe
    // if (coleccionUsuarios.count(actual_nickname) > 0) {
    //     throw runtime_error("El nickname ya está en uso");
    // }

    // // Agregar el nuevo usuario solo si el nickname es único
    // Usuario* nuevoUsuario = new Estudiante(
    //     actual_nickname,
    //     actual_password,
    //     actual_name,
    //     actual_desc,
    //     actual_pais
    // );
    // coleccionUsuarios.insert(pair<string, Usuario*>(this->actual_nickname, nuevoUsuario));


}


void ControladorUsuario::ingresarDatosProfesor(string instituto) {
    this->actual_instituto = instituto;
}

void ControladorUsuario::altaProfesor(set<string> idiomas) {
    // Implementación mínima
}

DTUsuario ControladorUsuario::getDataUsuarioIngresado() {
    DTUsuario dtUsuario; // Valor vacío
    return dtUsuario;
}

set<string> ControladorUsuario::seleccionarIdioma(string nombre) {
    set<string> idiomas; // Valor vacío
    return idiomas;
}

//TODO: Hay que implementar esto
set<string> ControladorUsuario::listarNombresDeIdiomasDisponibles() {
    set<string> idiomas; // Valor vacío
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