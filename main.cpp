#include <string>
#include <iostream>

#include "include/factory/fabrica.h"

void mensajeDeBienvenida() {
    cout << "------------------------------------" << endl;
    cout << "Bienvenide a la aplicacion de idiomas" << endl;
    cout << "------------------------------------" << endl;
    cout << endl;
}

void menuDeOpciones() {
    cout << "--------------------------------------" << endl;
    cout << "1. Alta de usuario" << endl;
    cout << "2. Consulta de usuario" << endl;
    cout << "3. Alta de idioma" << endl;
    cout << "4. Consultar idiomas" << endl;
    cout << "5. Alta de curso" << endl;
    cout << "6. Agregar lección" << endl;
    cout << "7. Agregar ejercicio" << endl;
    cout << "8. Habilitar curso" << endl;
    cout << "9. Eliminar curso" << endl;
    cout << "10. Consultar curso" << endl;
    cout << "11. Inscribirse a curso" << endl;
    cout << "12. Realizar ejercicio" << endl;
    cout << "13. Consultar estadísticas" << endl;
    cout << "14. Suscribirse a notificaciones" << endl;
    cout << "15. Consulta de notificaciones" << endl;
    cout << "16. Eliminar suscripciones" << endl;
    cout << "0. Salir" << endl;
    cout << "--------------------------------------" << endl;
}

/** Lee un numero natural de la entrada estandar. En caso de no ser un numero, lo ignora y lo pide devuelta*/
int ingresarOpcion() {
    int opcion;
    bool esNumero = false;
    while (!esNumero) {
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        cout << endl;
        esNumero = cin.good();
        if (!esNumero) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Debe ingresar un numero" << endl;
        }
    }
    return opcion;
}


int deseaContinuar() {
    int opcion;
    cout << "Desea continuar?" << endl;
    cout << "1. Si " << endl;
    cout << "0. No" << endl;
    cout << "(Cualquiero otro numero se interpretara como Sí)" << endl;
    cout << endl;
    opcion = ingresarOpcion();
    return opcion;
}




int main() {
    mensajeDeBienvenida();
    menuDeOpciones();
    int opcion = ingresarOpcion();
    bool quiereSalir = opcion == 0;
    cout << "--------------------------------------" << endl;

    while (!quiereSalir) {
        switch (opcion) {
            case 0 : {
                cout << "Saliendo..." << endl;
                quiereSalir = true;
                break;
            }
            case 1: {
                cout << "Alta de usuario" << endl;
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
                cout << "Opcion no valida. Ingrese nuevamente una opcion" << endl;
                opcion = ingresarOpcion();
                continue;
                break;
            }
        }
        cout << "--------------------------------------" << endl;
        if (!quiereSalir) {
            quiereSalir = deseaContinuar() == 0;
            if (!quiereSalir) {
                menuDeOpciones();
                opcion = ingresarOpcion();
            }
        }
    }

    cout << "Gracias por utilizar la aplicacion" << endl;
}
