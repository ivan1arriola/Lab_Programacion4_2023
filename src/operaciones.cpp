#include "../include/operaciones.h"

#include <iostream>
#include <string>

using namespace std;

void imprimirLinea(){
    cout << "***************" << endl;
}

void imprimirMensajeBienvenida() {
    std::cout << "*******************************************" << std::endl;
    std::cout << "*                                         *" << std::endl;
    std::cout << "*     Bienvenide a la aplicación de        *" << std::endl;
    std::cout << "*                idiomas                  *" << std::endl;
    std::cout << "*                                         *" << std::endl;
    std::cout << "*******************************************" << std::endl;
}

void imprimirMenu() {
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
    cout << "17. Cargar datos de prueba" << endl;
    cout << "0. Salir" << endl;
}

int ingresarOpcion(int cantOpciones) {
    int opcion;
    bool esNumero = false;
    bool esOpcionValida = false;
    while (!esNumero || !esOpcionValida) {
        cout << "Ingrese una opcion: ";
        cin >> opcion;
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

bool deseaRealizarOtraOperacion() {
    int opcion;
    cout << "Desea realizar otra operacion?" << endl;
    cout << "1. Si " << endl;
    cout << "0. No" << endl;
    opcion = ingresarOpcion(1);
    return opcion == 1;
}

void imprimirSet(const set<string>& conjunto, string nombreDelConjunto) {
    if (conjunto.empty()) {
        cout << "0 - No hay " << nombreDelConjunto << " disponibles" << endl;
    } else {
        int indice = 1;
        for (const string& elemento : conjunto) {
            cout << indice << " - " << elemento << endl;
            ++indice;
        }
        
    }
}

void imprimirOpcionesSet(const set<string>& conjunto, string nombreDelConjunto) {
    if (conjunto.empty()) {
        cout << "0 - No hay " << nombreDelConjunto << " disponibles para elegir" << endl;
    } else {
        int indice = 1;
        cout << "0 - Cancelar" << endl;
        for (const string& elemento : conjunto) {
            cout << indice << " - " << elemento << endl;
            ++indice;
        }
    }
}

void imprimirMensaje(string mensaje) {
    cout << mensaje << endl;
}

void imprimirMensajeDespedida() {
    imprimirMensaje("Gracias por utilizar la aplicacion de idiomas");
    imprimirMensaje("Saliendo del sistema...");
    imprimirMensaje("Hasta luego!");
}


string ingresarParametro(string parametro) {
  string valor;
  cout << "Ingrese " << parametro << ": ";
  cin >> valor; 
  return valor;
}