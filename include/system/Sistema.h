#ifndef SISTEMA
#define SISTEMA

#include <set>
#include <string>

#include "../interfaces/IControladorUsuario.h"

using namespace std;

class Sistema {
    private:
        static Sistema *instancia;
        Sistema();
        ~Sistema();

        static IControladorUsuario *controladorUsuario;
        //IControladorCurso *controladorCurso;
        //IControladorEstadistica *controladorEstadistica;

    public:

        static Sistema *getInstancia();
        void destruirInstancia();
        
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