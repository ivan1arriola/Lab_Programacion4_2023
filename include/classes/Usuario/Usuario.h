// Usuario.h

#ifndef USUARIO
#define USUARIO

#include <set>
#include <string>
#include <vector>

#include "../../datatypes/DTNotificacion.h"
#include "../../datatypes/DTDataCursoProfesor.h"
#include "../../datatypes/DTUsuario.h"

#include "../../interfaces/ISuscriptor.h"

using namespace std;

/* Clase Abstracta */
class Usuario : public ISuscriptor {
private:
    string nickname;
    string contrasenia;
    string nombre;
    string descripcion;
    vector<DTNotificacion*> notificacionesRecibidas;
    void agregarNotificacion(DTNotificacion * notificacion);

public:
    Usuario();
    Usuario(string nickname, string contrasenia, string nombre, string descripcion);

    // Getters
    virtual string getNickname();
    virtual string getContrasenia();
    virtual string getNombre();
    virtual string getDescripcion();
    virtual vector<DTNotificacion*> getNotificacionesRecibidas();

    virtual DTUsuario* getDT() = 0;

    // Setters
    virtual void setNickname(string nickname);
    virtual void setContrasenia(string contrasenia);
    virtual void setNombre(string nombre);
    virtual void setDescripcion(string descripcion);

    // Operaciones
    void enviarNotificacion(string nombreCurso, string nombreIdioma);
    virtual bool esProfesor() = 0;
    virtual void eliminarNotificacionesRecibidas();
    virtual bool esEstudiante() = 0;

    virtual ~Usuario();
};

#endif
