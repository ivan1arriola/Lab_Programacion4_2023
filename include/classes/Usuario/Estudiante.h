#ifndef ESTUDIANTE
#define ESTUDIANTE

#include <string>

#include "Usuario.h"

#include "../../datatypes/DTDate.h"
#include "../../datatypes/DTUsuario.h"

using namespace std;

class Estudiante : public Usuario {
private:

    string pais = "";
    DTDate* fechaNacimiento = NULL;

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

    DTUsuario* getDT();

    // Setters
    void setPais(string pais);
    void setFechaNacimiento(DTDate *fechaNacimiento);
    void setFechaNacimiento(int dia, int mes, int anio);

    // Operaciones
    void enviarNotificacion(string nombreCurso, string nombreIdioma);

    ~Estudiante();
};

#endif
