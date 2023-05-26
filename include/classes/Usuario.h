#ifndef USUARIO

#define USUARIO
#include <string>
#include <vector>

#include "../datatypes/DTNotificacion.h"

using namespace std;

/*Clase Abstracta*/
class Usuario {
  private:
    string nickname;
    string contrasenia;
    string nombre;
    string descripcion;
    vector<DTNotificacion> notificacionesRecibidas;

    void agregarNotificacion(DTNotificacion notificacion);

  public:
    virtual Usuario() {};

    // Getters
    string getNickname() = 0;
    string getContrasenia() = 0;
    string getNombre() = 0;
    string getDescripcion() = 0;
    vector<DTNotificacion> getNotificacionesRecibidas() = 0;

    // Setters
    void setNickname(string nickname) = 0;
    void setContrasenia(string contrasenia) = 0;
    void setNombre(string nombre) = 0;
    void setDescripcion(string descripcion) = 0;

    // Operaciones
    void enviarNotificacion(string nombreCurso, string nombreIdioma) = 0;
    bool esProfesor() = 0;
    set<string> obtenerIdiomas() = 0;
    void eliminarNotificacionesRecibidas() = 0;
    bool esEstudiante() = 0;
    set<DataCursoProfesor> getCursosProfesor() = 0;

    virtual ~Usuario() {}

};

#endif