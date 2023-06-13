

#ifndef ICONTROLADORUSUARIO
#define ICONTROLADORUSUARIO

#include <string>
#include <set>
#include <vector>

#include "../datatypes/DTUsuario.h"
#include "../datatypes/DTNotificacion.h"
#include "../classes/Idioma.h"

using namespace std;

class IControladorUsuario {
    public:
        virtual void ingresarUsuario(string nickname, string password, string name, string desc) = 0;
        virtual void ingresarDatosEstudiante(string pais) = 0;
        virtual void altaProfesor(set<string> idiomas) = 0;
        virtual DTUsuario* getDataUsuarioIngresado() = 0;
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
        virtual vector<DTNotificacion*> listarNotificaciones(string nickName) = 0;
        virtual void eliminarNotificaciones() = 0;
        virtual void eliminarSuscripcion(string idioma) = 0;

        // Destructor
        virtual ~IControladorUsuario() {};

        // Operaciones para el caso de uso "Alta Idioma"
        virtual void crearIdioma(string nombre) = 0;
        virtual void altaIdioma() = 0;

        // Operaciones para el caso de uso "Consulta de usuario"
        virtual set<string> listarNicknameUsuarios() = 0;
        virtual DTUsuario* seleccionarUsuario(string nickname) = 0;

        


};

#endif