/*

#ifndef ICONTROLADORUSUARIO
#define ICONTROLADORUSUARIO

#include <string>
#include <set>

#include "../datatypes/DTUsuario.h"
#include "../datatypes/DTNotificacion.h"

using namespace std;

class IControladorUsuario {
    public:
        virtual IControladorUsuario* getInstancia() = 0;
        virtual void ingresarUsuario(string nickname, string password, string name, string desc) = 0;
        virtual void ingresarDatosEstudiante(string pais) = 0;
        virtual void altaProfesor(set<string> idiomas) = 0;
        virtual DTUsuario getDataUsuarioIngresado() = 0;
        virtual set<string> seleccionarIdioma(string nombre) = 0;
        virtual set<string> listarNombresDeIdiomasDisponibles() = 0;
        virtual void altaEstudiante() = 0;
        virtual void ingresarDatosProfesor(string instituto) = 0;
        virtual set<string> listarNombresIdiomasDeProfesor(string nicknameProfesor) = 0;
        virtual set<string> listarNIcknameProfesores() = 0;
        virtual set<string> listarIdiomasNoSuscriptos(string nickname) = 0;
        virtual set<string> listarIdiomasSuscriptos(string nickname) = 0;
        virtual void seleccionarProfesor(string nicknameProfesor) = 0;
        virtual void suscribirse(string nombreIdioma) = 0;
        virtual set<DTNotificacion> listarNotificaciones(string nickName) = 0;
        virtual void eliminarNotificaciones() = 0;
        virtual void eliminarSuscripcion(string idioma) = 0;
};

#endif
*/

#include "../../include/controllers/ControladorUsuario.h"

#include "../../include/interfaces/IControladorUsuario.h"

#include "../../include/classes/Usuario/Usuario.h"
#include "../../include/classes/Usuario/Estudiante.h"
#include "../../include/classes/Usuario/Profesor.h"

#include "../../include/classes/Idioma.h"

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
    if (coleccionUsuarios.count(actual_nickname) > 0) {
        throw runtime_error("El nickname ya está en uso");
    }

    // Agregar el nuevo usuario solo si el nickname es único
    Usuario* nuevoUsuario = new Estudiante(
        actual_nickname,
        actual_password,
        actual_name,
        actual_desc,
        actual_pais
    );
    coleccionUsuarios.insert(pair<string, Usuario*>(this->actual_nickname, nuevoUsuario));
}


void ControladorUsuario::ingresarDatosProfesor(string instituto) {
    this->actual_instituto = instituto;
}
