#ifndef PROFESOR
#define PROFESOR

#include <string>
#include <set>

using namespace std;

#include "Usuario.h"
#include "../Idioma.h"
#include "../../datatypes/DTUsuario.h"

class Profesor : public Usuario {
    private:
        string instituto;
        set<Idioma*> idiomasDeProfesor;
    public:
        Profesor();
        Profesor(string nickname, string contrasenia, string nombre, string descripcion, string instituto);
        Profesor(string nickname, string contrasenia, string nombre, string descripcion, string instituto, set<Idioma*> idiomasDeProfesor);

        // Getters
        string getInstituto();
        bool esProfesor();
        bool esEstudiante();

        DTUsuario* getDT();

        // Setters
        void setInstituto(string instituto);

        // Operaciones
        void enviarNotificacion(string nombreCurso, string nombreIdioma);
        set<string> obtenerIdiomas();
        void agregarAIdiomasDeProfesor();
        set<DTDataCursoProfesor> getCursosProfesor();


        ~Profesor();
};

#endif