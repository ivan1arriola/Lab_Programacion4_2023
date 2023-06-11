#include "../../include/system/operaciones.h"

#include <iostream>
#include <string>

using namespace std;

void limpiarConsola() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void espacioSimple() {
    cout << endl;
}

string seleccionarElemento(set<string> elementos, string nombreElemento) {
    int opcion = -1;

    imprimirMensaje("Seleccione un " + nombreElemento + " de la lista:") ;
    imprimirSet(elementos, nombreElemento + "s") ;

    opcion = ingresarOpcion(elementos.size()) ;

    if (opcion == 0) {
        return string();
    }

    return obtenerOpcion(elementos, opcion) ;
}


void imprimirLinea() {
    cout << "-------------------------------------------" << endl;
}

void imprimirLineaDeSeparacion() {
    imprimirLinea();
    espacioSimple();
}

void imprimirMensajeDeError (string mensaje) {
    espacioSimple();
    imprimirLinea();
    cout << "ERROR: " << mensaje << endl;
    imprimirLinea();
    espacioSimple();
}



void imprimirMensajeBienvenida() {
    espacioSimple();
    cout << "*******************************************" << endl;
    cout << "*                                         *" << endl;
    cout << "*     Bienvenide a la aplicación de       *" << endl;
    cout << "*                idiomas                  *" << endl;
    cout << "*                                         *" << endl;
    cout << "*******************************************" << endl;
    espacioSimple();
}

void imprimirMenu() {
    cout << "Menu de opciones:" << endl;
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
    espacioSimple();
}

int ingresarOpcion(int cantOpciones) {
    int opcion;
    bool esNumero = false; 
    bool esOpcionValida = false;
    while (!esNumero || !esOpcionValida) {
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        esNumero = cin.good(); // Chequea que sea numero / eso creo?
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
    espacioSimple();
    return opcion;
}

bool deseaRealizarOtraOperacion() {
    int opcion;
    espacioSimple();
    cout << "Desea realizar otra operacion?" << endl;
    cout << "1. Si " << endl;
    cout << "0. No" << endl;
    opcion = ingresarOpcion(1);
    espacioSimple();
    return opcion == 1;
}

void imprimirSet(const set<string>& conjunto, string nombreDelConjunto) {
    if (conjunto.empty()) {
        espacioSimple();
        cout << "0 - No hay " << nombreDelConjunto << " disponibles" << endl;
    } else {
        int indice = 1;
        for (const string& elemento : conjunto) {
            cout << indice << " - " << elemento << endl;
            ++indice;
        }
        espacioSimple();
        
    }
}

void imprimirOpcionesSet(const set<string>& conjunto, string nombreDelConjunto) {
    if (conjunto.empty()) {
        espacioSimple();
        cout << "0 - No hay " << nombreDelConjunto << " disponibles para elegir" << endl;
    } else {
        int indice = 1;
        cout << "0 - Cancelar" << endl;
        for (const string& elemento : conjunto) {
            cout << indice << " - " << elemento << endl;
            ++indice;
        }
        espacioSimple();
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
  cin >> ws;  // Descartar espacios en blanco iniciales
  getline(cin, valor, '\n');
  return valor;
}

string obtenerOpcion(const set<string>& conjunto, int opcion) {
    int indice = 1;
    for (const string& elemento : conjunto) {
        if (indice == opcion) {
            return elemento;
        }
        ++indice;
    }
    return "";
}