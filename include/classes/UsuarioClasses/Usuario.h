#ifndef USUARIO

#define USUARIO
#include <set>
#include <string>
#include <vector>

#include "../../datatypes/DTNotificacion.h"
#include "../../datatypes/DTDataCursoProfesor.h"

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
    Usuario() {};

    // Getters
    virtual string getNickname() = 0;
    virtual string getContrasenia() = 0;
    virtual string getNombre() = 0;
    virtual string getDescripcion() = 0;
    virtual vector<DTNotificacion> getNotificacionesRecibidas() = 0;

    // Setters
    virtual void setNickname(string nickname) = 0;
    virtual void setContrasenia(string contrasenia) = 0;
    virtual void setNombre(string nombre) = 0;
    virtual void setDescripcion(string descripcion) = 0;

    // Operaciones
    virtual void enviarNotificacion(string nombreCurso, string nombreIdioma) = 0;
    virtual bool esProfesor() = 0;
    virtual set<string> obtenerIdiomas() = 0;
    virtual void eliminarNotificacionesRecibidas() = 0;
    virtual bool esEstudiante() = 0;
    virtual set<DTDataCursoProfesor> getCursosProfesor() = 0;

    virtual ~Usuario() {}

};

#endif