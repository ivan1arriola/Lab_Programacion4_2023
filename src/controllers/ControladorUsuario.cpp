/*
#ifndef CONTROLADORUSUARIO
#define CONTROLADORUSUARIO

#include <string>
#include <set>
#include <map>

#include "../interfaces/IControladorUsuario.h"

#include "../classes/Usuario/Usuario.h"

using namespace std;

// Singleton
class ControladorUsuario : public IControladorUsuario {

    private:
        // Atributos
        Usuario* usuarioActual;

        //Colecciones
        map<string, Usuario*> coleccionUsuarios;

        ControladorUsuario();
        ~ControladorUsuario();


        static IControladorUsuario* instancia;

        // Atributos para el caso de uso "Alta de Usuario"
        string actual_nickname; string actual_password; string actual_name; string actual_desc;
        string actual_pais;
        string actual_instituto;



    public:
        // Getters
        IControladorUsuario* getInstancia();

        // Operaciones
        void ingresarUsuario(string nickname, string password, string name, string desc);
        void ingresarDatosEstudiante(string pais);
        void altaProfesor(set<string> idiomas);
        DTUsuario getDataUsuarioIngresado();
        set<string> seleccionarIdioma(string nombre);
        set<string> listarNombresDeIdiomasDisponibles();
        void altaEstudiante();
        void ingresarDatosProfesor(string instituto);
        set<string> listarNombresIdiomasDeProfesor(string nicknameProfesor);
        set<string> listarNIcknameProfesores();
        set<string> listarIdiomasNoSuscriptos(string nickname);
        set<string> listarIdiomasSuscriptos(string nickname);
        void seleccionarProfesor(string nicknameProfesor);
        void suscribirse(string nombreIdioma);
        set<DTNotificacion> listarNotificaciones(string nickName);
        void eliminarNotificaciones();
        void eliminarSuscripcion(string idioma);

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

//manejo de errores 
//#include <cassert>

using namespace std;

// Singleton
IControladorUsuario* ControladorUsuario::instancia = NULL;

ControladorUsuario::ControladorUsuario() {
    this->usuarioActual = NULL;
}

ControladorUsuario::~ControladorUsuario() {

}

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
