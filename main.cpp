#include <string>
#include <iostream>

#include "include/operaciones.h"

// Interfaces
#include "include/interfaces/IControladorUsuario.h"
#include "include/interfaces/IControladorCurso.h"
#include "include/interfaces/IControladorEstadistica.h"

// Factory
#include "include/factory/fabrica.h"

// Casos de Uso
#include "include/CasosDeUso/AltaDeUsuario.h"
#include "include/CasosDeUso/ConsultaDeUsuario.h"
#include "include/CasosDeUso/AltaDeIdioma.h"
#include "include/CasosDeUso/AltaDeCurso.h"
#include "include/CasosDeUso/AgregarEjercicio.h"
#include "include/CasosDeUso/HabilitarCurso.h"
#include "include/CasosDeUso/EliminarCurso.h"
#include "include/CasosDeUso/InscribirseACurso.h"
#include "include/CasosDeUso/RealizarEjercicio.h"
#include "include/CasosDeUso/SuscribirseANotificaciones.h"
#include "include/CasosDeUso/ConsultaDeNotificaciones.h"
#include "include/CasosDeUso/EliminarSuscripciones.h"
#include "include/CasosDeUso/ConsultarIdiomas.h"
#include "include/CasosDeUso/ConsultarCurso.h"
#include "include/CasosDeUso/AgregarLeccion.h"
#include "include/CasosDeUso/ConsultarEstadisticas.h"
#include "include/CasosDeUso/AgregarLeccion.h"


using namespace std;


int main() {
    imprimirMensajeBienvenida();
    bool quiereContinuar = true;

    // Inicializar sistema
    //Fabrica *fabrica = Fabrica::getInstancia();

    //IControladorUsuario *controladorUsuario = fabrica->getIControladorUsuario();
    //IControladorCurso *controladorCurso = fabrica->getIControladorCurso();
    //IControladorEstadistica *controladorEstadistica = fabrica->getIControladorEstadistica();

    do {
        imprimirMenu();
        
        int opcion = ingresarOpcion(16);
        switch (opcion) {
            case 1:
                AltaDeUsuario();
                break;
            case 2:
                ConsultaDeUsuario();
                break;
            case 3:
                AltaDeIdioma();
                break;
            case 4:
                ConsultarIdiomas();
                break;
            case 5:
                AltaDeCurso();
                break;
            case 6:
                AgregarLeccion();
                break;
            case 7:
                AgregarEjercicio();
                break;
            case 8:
                HabilitarCurso();
                break;
            case 9:
                EliminarCurso();
                break;
            case 10:
                ConsultarCurso();
                break;
            case 11:
                InscribirseACurso();
                break;
            case 12:
                RealizarEjercicio();
                break;
            case 13:
                ConsultarEstadisticas();
                break;
            case 14:
                SuscribirseANotificaciones();
                break;
            case 15:
                ConsultaDeNotificaciones();
                break;
            case 16:
                EliminarSuscripciones();
                break;
            case 0:
                quiereContinuar = false;
                break;
        }
        if (opcion != 0) {
            quiereContinuar = deseaRealizarOtraOperacion();
        }

    } while (quiereContinuar);

    // Liberar memoria
    //TODO: liberar memoria de los controladores y de la fabrica?

    imprimirMensajeDespedida();
}
