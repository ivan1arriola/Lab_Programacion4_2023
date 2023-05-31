#include "../include/operaciones.h"

#include <iostream>
#include <string>

using namespace std;

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

int ingresarOpcion(int cantOpciones) {
    int opcion;
    bool esNumero = false;
    bool esOpcionValida = false;
    while (!esNumero || !esOpcionValida) {
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        cout << endl;
        esNumero = cin.good();
        if (!esNumero) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Debe ingresar un numero" << endl;
        }
        if (esNumero && (opcion < 0 || opcion > cantOpciones)) {
            cout << "Debe ingresar una opcion valida" << endl;
            esOpcionValida = false;
        } else {
            esOpcionValida = true;
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
    opcion = ingresarOpcion(1);
    return opcion;
}

void imprimirSet(const set<string>& conjunto) {
    if (conjunto.empty()) {
        cout << "0 - No hay elementos disponibles para elegir" << endl;
        cout << endl;
    } else {
        int indice = 1;
        cout << "0 - Cancelar" << endl;
        for (const string& elemento : conjunto) {
            cout << indice << " - " << elemento << endl;
            ++indice;
        }
        cout << endl;
    }
}
