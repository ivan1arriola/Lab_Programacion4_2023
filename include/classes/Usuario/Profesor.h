#ifndef PROFESOR
#define PROFESOR

#include <string>
#include <set>

using namespace std;

#include "Usuario.h"
#include "../Idioma.h"
#include "../../datatypes/DTUsuario.h"
#include "../../datatypes/DTDataCursoProfesor.h"
class Curso;

class Profesor : public Usuario {
    private:
        string instituto;
        set<Idioma*> idiomasDeProfesor;
        set<Curso*> cursosCreados;
    public:
        Profesor();
        Profesor(string nickname, string contrasenia, string nombre, string descripcion, string instituto);
        Profesor(string nickname, string contrasenia, string nombre, string descripcion, string instituto, set<Idioma*> idiomasDeProfesor);

        // Getters
        string getInstituto();
        bool esProfesor();
        bool esEstudiante();
        set<Curso*> getCursosCreados();

        DTUsuario* getDT();

        // Setters
        void setInstituto(string instituto);

        // Operaciones
        set<string> obtenerIdiomas();
        void agregarAIdiomasDeProfesor(Idioma *idioma);
        void agregarACursosDeProfesor(Curso *curso);
        set<DTDataCursoProfesor*> getCursosProfesor();

        set<Idioma*> getIdiomas();


        ~Profesor();
};

#endif