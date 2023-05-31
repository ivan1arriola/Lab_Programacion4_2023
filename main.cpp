#include <string>
#include <iostream>

#include "include/operaciones.h"

// Casos de Uso
#include "include/CasosDeUso/altaUsuario.h"

using namespace std;


int main() {
    mensajeDeBienvenida();
    menuDeOpciones();
    int opcion = ingresarOpcion(16);
    bool quiereSalir = opcion == 0;
    imprimirLinea();

    while (!quiereSalir) {
        switch (opcion) {
            case 0 : {
                cout << "Saliendo..." << endl;
                quiereSalir = true;
                break;
            }
            case 1: {
                cout << "Alta de usuario" << endl;
                imprimirLinea();
                altaUsuario();
                imprimirLinea();
                break;
            }
            case 2: {
                cout << "Consulta de usuario" << endl;
                break;
            }
            case 3: {
                cout << "Alta de idioma" << endl;
                break;
            }
            case 4: {
                cout << "Consultar idiomas" << endl;
                break;
            }
            case 5: {
                cout << "Alta de curso" << endl;
                break;
            }
            case 6: {
                cout << "Agregar lección" << endl;
                break;
            }
            case 7: {
                cout << "Agregar ejercicio" << endl;
                break;
            }
            case 8: {
                cout << "Habilitar curso" << endl;
                break;
            }
            case 9: {
                cout << "Eliminar curso" << endl;
                break;
            }
            case 10: {
                cout << "Consultar curso" << endl;
                break;
            }
            case 11: {
                cout << "Inscribirse a curso" << endl;
                break;
            }
            case 12: {
                cout << "Realizar ejercicio" << endl;
                break;
            }
            case 13: {
                cout << "Consultar estadísticas" << endl;
                break;
            }
            case 14: {
                cout << "Suscribirse a notificaciones" << endl;
                break;
            }
            case 15: {
                cout << "Consulta de notificaciones" << endl;
                break;
            }
            case 16: {
                cout << "Eliminar suscripciones" << endl;
                break;
            }
            default: {
                continue;
            }
        }
        imprimirLinea();
        if (!quiereSalir) {
            quiereSalir = deseaContinuar() == 0;
            if (!quiereSalir) {
                menuDeOpciones();
                opcion = ingresarOpcion(16);
            }
        }
    }

    cout << "Gracias por utilizar la aplicacion" << endl;
}
