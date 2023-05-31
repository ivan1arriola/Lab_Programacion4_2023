#ifndef OPERACIONES
#define OPERACIONES

#include <set>
#include <string>


void imprimirSet(const std::set<std::string>& conjunto);

void mensajeDeBienvenida();

void menuDeOpciones();

/** Lee un numero por consola. Si no es un numero, lo vuelve a pedir. */
/** Siempre agrega la opcion 0*/
int ingresarOpcion(int cantOpciones);

int deseaContinuar();

#endif
