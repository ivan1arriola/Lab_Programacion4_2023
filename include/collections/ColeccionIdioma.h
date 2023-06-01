#ifndef COLECCIONIDIOMA
#define COLECCIONIDIOMA

#include <map>
#include <set>
#include <string>

#include "../classes/Idioma.h"

using namespace std;

class ColeccionIdioma {
private:
    map<string, Idioma*> idiomas; //Coleccion de punteros a Idioma
    ColeccionIdioma();
    static ColeccionIdioma* instancia;

public:
    static ColeccionIdioma* getInstancia();

    // Agregar
    void agregarIdioma(Idioma* idioma);

    // Obtener
    Idioma* obtenerIdioma(string nombreIdioma);
    set<string> obtenerNombresIdiomas();

    // Consultar
    bool existeIdioma(string nombreIdioma);
    bool existeIdioma(Idioma idioma);


    // Eliminar
    void eliminarIdioma(string nombreIdioma);
    void eliminarIdioma(Idioma* idioma);
};

#endif
