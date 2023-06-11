#include <iostream>
#include <string>

#include "../../../include/system/Sistema.h"

#include "../../../include/system/operaciones.h"

using namespace std;

/**
 * Nombre Agregar lección
Actores Usuario
Sinopsis El caso de uso comienza cuando se desea agregar una nueva lección a la definición de
un curso. Para ello, el Sistema lista todos los cursos no habilitados, el Usuario
selecciona uno y el Sistema solicita el nombre del tema que tratará la lección y su
objetivo. Opcionalmente, el Sistema permite también que el Usuario agregue los
ejercicios que la componen. Por cada ejercicio que se desea agregar, el Usuario ingresa
el tipo de ejercicio y la descripción. Para los ejercicios de completar palabras, el
Usuario ingresa la frase a completar, donde las palabras faltantes se representan
mediante 3 guiones, por ejemplo, “Mi --- es Juan y tengo 21 ---”, y, por otro lado, el
conjunto ordenado de palabras separados por una coma que conforman la solución (en
el caso anterior sería: “nombre”, “años”). Por otra parte, para los ejercicios de
traducción, el Usuario ingresa la frase a traducir, seguida de la frase traducida, por
ejemplo, “Soy Juan”, y su traducción, “I am Juan”. Notar que el sistema admite agregar
lecciones sin que estas tengan necesariamente ejercicios. Una vez que el Usuario
termina, el Sistema da de alta la lección con los datos ingresados al final de la lista
ordenada de lecciones y sus ejercicios, en caso de existir.
 * 
*/

void Sistema::agregarLeccion() {
    imprimirMensaje("Agregar Lección");
}


