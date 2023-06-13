#ifndef ESTUDIANTE
#define ESTUDIANTE

#include <string>
#include <map>

#include "Usuario.h"

#include "../../datatypes/DTDate.h"
#include "../../datatypes/DTUsuario.h"

class Inscripcion;

using namespace std;

class Estudiante : public Usuario {
private:

    string pais = "";
    DTDate* fechaNacimiento = NULL;

    map<string, Inscripcion*> inscripciones; // nicknameCurso, Inscripcion

public:
    Estudiante();
    Estudiante(string nickname, string contrasenia, string nombre, string descripcion, string pais, DTDate *fechaNacimiento);
    Estudiante(string nickname, string contrasenia, string nombre, string descripcion);
    Estudiante(string nickname, string contrasenia, string nombre, string descripcion, string pais);

    // Getters
    string getPais();
    DTDate* getFechaNacimiento();
    bool esProfesor();
    bool esEstudiante();
    map<string, Inscripcion*> getInscripciones();

    DTUsuario* getDT();

    // Setters
    void setPais(string pais);
    void setFechaNacimiento(DTDate *fechaNacimiento);
    void setFechaNacimiento(int dia, int mes, int anio);

    // Operaciones

    ~Estudiante();
};

#include "../Inscripcion.h"

#endif

