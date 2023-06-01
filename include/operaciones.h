#ifndef OPERACIONES
#define OPERACIONES

#include <set>
#include <string>

using namespace std;

/* Imprime una linea separatoria */
void imprimirLinea();

/* Imprime un mensaje de despedida */
void imprimirDespedida();

/* Imprime un conjunto de strings, con indice . Si el conjunto esta vacio,
 * imprime un mensaje indicando que no hay elementos disponibles */
void imprimirSet(const set<string>& conjunto, string nombreDelConjunto);

/* Imprime una linea de guiones, un string, otra linea de guiones y un salto de
 * linea */
void imprimirMensaje(string mensaje);

/* Imprime un mensaje de bienvenida */
void mensajeDeBienvenida();

/* Imprime una lista de todos los casos de uso disponibles */
void menuDeOpciones();

/* Lee un numero por consola.Si es un numero, verifica que sea una opcion valida
 * (entre 0 y cantOpciones). Si no es un numero, pide que se ingrese un numero.
 * Si es un numero pero no es una opcion valida, pide que se ingrese una opcion
 * valida. Devuelve la opcion elegida. */
int ingresarOpcion(int cantOpciones);

/* Pregunta si desea continuar. Devuelve 1 si desea continuar, 0 si no desea
 * continuar */
int deseaContinuar();

/* Pide un parametro por consola. Devuelve el parametro ingresado */
string ingresarParametro(string parametro);

#endif
