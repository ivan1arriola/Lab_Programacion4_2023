#include <string>
#include <iostream>

#include "include/system/operaciones.h"


// Factory
#include "include/factory/fabrica.h"

// Sistema
#include "include/system/Sistema.h"


using namespace std;


int main() {
    imprimirMensajeBienvenida();
    bool quiereContinuar = true;

    // Inicializar sistema
    Sistema *sistema = Sistema::getInstancia();

    do {
        imprimirMenu();
        
        int opcion = ingresarOpcion(17);
        switch (opcion) {
            case 1:
                sistema->altaDeUsuario();
                break;
            case 2:
                sistema->consultaDeUsuario();
                break;
            case 3:
                sistema->altaDeIdioma();
                break;
            case 4:
                sistema->consultarIdiomas();
                break;
            case 5:
                sistema->altaDeCurso();
                break;
            case 6:
                sistema ->agregarLeccion();
                break;
            case 7:
                sistema->agregarEjercicio();
                break;
            case 8:
                sistema->habilitarCurso();
                break;
            case 9:
                sistema->eliminarCurso();
                break;
            case 10:
                sistema->consultarCurso();
                break;
            case 11:
                sistema->inscribirseACurso();
                break;
            case 12:
                sistema->realizarEjercicio();
                break;
            case 13:
                sistema ->consultarEstadisticas();
                break;
            case 14:
                sistema ->suscribirseANotificaciones();
                break;
            case 15:
                sistema ->consultaDeNotificaciones();
                break;
            case 16:
                sistema ->eliminarSuscripciones();
                break;
            case 17:
                sistema ->cargarDatosdePrueba();
                break;
            case 0:
                quiereContinuar = false;
                break;
        }
        if (opcion != 0) {
            quiereContinuar = deseaRealizarOtraOperacion();
        }

        limpiarConsola();

    } while (quiereContinuar);

    // Liberar memoria
    sistema->destruirInstancia();

    imprimirMensajeDespedida();
}
