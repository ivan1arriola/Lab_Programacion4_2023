
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


        static ControladorUsuario* instancia;

        // Atributos para el caso de uso "Alta de Usuario"
        string actual_nickname; string actual_password; string actual_name; string actual_desc;
        string actual_pais;
        string actual_instituto;

    public:
        // Getters
        static IControladorUsuario* getInstancia();

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