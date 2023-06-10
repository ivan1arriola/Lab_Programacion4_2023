#ifndef SISTEMA
#define SISTEMA

#include <set>
#include <string>

#include "../factory/Fabrica.h"

#include "../interfaces/IControladorUsuario.h"
#include "../interfaces/IControladorCurso.h"
#include "../interfaces/IControladorEstadistica.h"

// Handlers de colecciones
#include "../handlers/HandlerUsuario.h"
#include "../handlers/HandlerIdioma.h"
#include "../handlers/HandlerCurso.h"

using namespace std;

class Sistema {
    private:
        static Sistema *instancia;
        Sistema();

        // Fabrica
        static Fabrica *fabricaSistema;
        
        // Controladores
        static IControladorUsuario *controladorUsuario;
        static IControladorCurso *controladorCurso;
        static IControladorEstadistica *controladorEstadistica;

        // Handlers de colecciones
        static HandlerUsuario *handlerUsuario;
        static HandlerIdioma *handlerIdioma;
        static HandlerCurso *handlerCurso;

    public:

        static Sistema *getInstancia();
        ~Sistema();
        
        // Casos de uso / Implementadas en sus respectivos .cpp
        void altaDeUsuario();
        void consultaDeUsuario();
        void altaDeIdioma();
        void consultarIdiomas();
        void altaDeCurso();
        void agregarLeccion();
        void agregarEjercicio();
        void habilitarCurso();
        void eliminarCurso();
        void consultarCurso();
        void inscribirseACurso();
        void realizarEjercicio();
        void consultarEstadisticas();
        void suscribirseANotificaciones();
        void consultaDeNotificaciones();
        void eliminarSuscripciones();

        // Datos de prueba / Implementadas en sus respectivo .cpp
        void cargarDatosdePrueba();
};

#endif