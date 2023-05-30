#ifndef COLECCIONIDIOMA
#define COLECCIONIDIOMA

#include <map>
#include <string>
#include "../classes/Idioma.h"

using namespace std;

class ColeccionIdioma {
private:
    map<string, Idioma*> idiomas; // Mapa para almacenar los idiomas

    ColeccionIdioma();

    static ColeccionIdioma* instancia;

public:
    static ColeccionIdioma* getInstancia();

    // Agregar
    void agregarIdioma(Idioma* idioma);

    // Obtener
    Idioma* obtenerIdioma(string nombreIdioma);

    // Consultar
    bool existeIdioma(string nombreIdioma);
    bool existeIdioma(Idioma idioma);

    // Eliminar
    void eliminarIdioma(string nombreIdioma);
    void eliminarIdioma(Idioma* idioma);
};

#endif
