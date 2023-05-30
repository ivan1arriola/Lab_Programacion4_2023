#ifndef PROFESOR
#define PROFESOR

#include <string>
#include <set>

using namespace std;

#include "Usuario.h"

class Profesor : public Usuario {
    private:
        string instituto;
    public:
        Profesor();
        Profesor(string nickname, string contrasenia, string nombre, string descripcion, string instituto);

        // Getters
        string getInstituto();
        bool esProfesor();
        bool esEstudiante();

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