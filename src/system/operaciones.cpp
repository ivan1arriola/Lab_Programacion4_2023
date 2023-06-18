#include "../../include/system/operaciones.h"

#include <iostream>
#include <string>

using namespace std;

typedef unsigned long int nat;

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
    imprimirMensaje("0- Cancelar");
    imprimirSet(elementos, nombreElemento + "s") ;

    opcion = ingresarOpcion(elementos.size()) ;

    if (opcion == 0) {
        return "";
    }

    return obtenerOpcion(elementos, opcion) ;
}

int seleccionarElemento(vector<string> elementos, string nombreElemento) {
    int opcion = -1;

    imprimirMensaje("Seleccione una " + nombreElemento + " de la lista:") ;
    imprimirVector(elementos, nombreElemento + "s") ;

    opcion = ingresarOpcion(elementos.size()) ;

    if (opcion == 0) {
        return -1;
    }

    //devuelvo la posicion en el vector
    opcion--;

    return opcion;
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

#include <iostream>
#include <sstream>

int ingresarOpcion(int cantOpciones) {
    static istringstream iss;
    string entrada;

    if (!iss || iss.eof()) {
        cout << "Ingrese una opcion: ";
        getline(cin, entrada);
        iss.str(entrada);
        iss.clear();
    }

    int opcion;
    if (iss >> opcion && opcion >= 0 && opcion <= cantOpciones) {
        cout << endl;
        return opcion;
    } else {
        cout << "Debe ingresar una opcion valida" << endl;
        return ingresarOpcion(cantOpciones);
    }
}

void cancelarOperacion(string error = "", string operacion = "") {
    if (error != "") {
        imprimirMensaje(error) ;
    }
    imprimirMensaje("No se puede completar la operación " + operacion + ".") ;
    imprimirMensaje("Cancelando operación") ;
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

bool deseaContinuar (string mensaje) {
    imprimirMensaje(mensaje) ;
    imprimirMensaje("1. Sí") ;
    imprimirMensaje("0. No") ;

    int opcion = ingresarOpcion(1) ;

    return opcion == 1 ;
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

void imprimirVector(const vector<string>& conjunto, string nombreDelConjunto){
    if(conjunto.empty()){
        espacioSimple();
        cout << "0 - No hay " << nombreDelConjunto << " disponibles" << endl;
    }else{
        int indice =1;
        for(const string& elemento : conjunto){
            cout << indice << " - " << elemento << endl;
            indice++;
        }
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

  espacioSimple();
  return valor;
}

string ingresarPalabra(string parametro) {
  string valor;
  cout << "Ingrese " << parametro << ": ";
  cin >> ws;  // Descartar espacios en blanco iniciales
  getline(cin, valor, '\n');
  int i=0;
  int posicion = -1;
  char espacio = ' ';

  for(char c : valor){
    if(c == espacio){
        posicion = i;
        break;
    }
    i++;
  }
  
  valor = valor.substr(0, posicion);

  espacioSimple();
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

string obtenerOpcion(const vector<string>& conjunto, int opcion) {
    int indice = 1;
    for (const string& elemento : conjunto) {
        if (indice == opcion) {
            return elemento;
        }
        ++indice;
    }
    return "";
}

nat contarEspaciosACompletar(string frase)
{
    nat contador = 0;
    // Si es menor a 5 no puede tener 3 guiones seguidos
    if (frase.size() < 5)
    {
        return 0;
    }
    // Cuenta cuantas secuencias de 3 guiones seguidos hay y que esten rodeados de espacios
    for (nat i = 0; i < frase.size() - 3; i++)
    {
        if (frase[i] == ' ' && frase[i + 1] == '-' && frase[i + 2] == '-' && frase[i + 3] == '-')
        {
            contador++;
        }
    }
    return contador;
}

string ingresarFraseACompletar()
{
    string frase = ingresarParametro("la frase a completar");
    // Controla que tenga al menos 3 guiones seguidos
    while (contarEspaciosACompletar(frase) == 0)
    {
        imprimirMensaje("La frase debe tener al menos una secuencia de 3 guiones seguidos");
        frase = ingresarParametro("la frase a completar");
    }
    return frase;
}

vector<string> ingresarConjuntoDePalabras(int cantEspacios)
{
    vector<string> solucion;
    for (int i = 0; i < cantEspacios; i++)
    {
        string palabra = ingresarPalabra("la palabra que completa el espacio " + to_string(i + 1) + ":");
        solucion.push_back(palabra);
    }
    return solucion;
}