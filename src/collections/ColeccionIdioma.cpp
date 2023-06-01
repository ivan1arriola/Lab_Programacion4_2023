#include "../../include/classes/Idioma.h"
#include "../../include/collections/ColeccionIdioma.h"


ColeccionIdioma* ColeccionIdioma::instancia = nullptr;

ColeccionIdioma::ColeccionIdioma() {}

ColeccionIdioma* ColeccionIdioma::getInstancia() {
    if (instancia == nullptr) {
        instancia = new ColeccionIdioma();
    }
    return instancia;
}

void ColeccionIdioma::agregarIdioma(Idioma* idioma) {
    if (idioma == nullptr) return;
    string nombreIdioma = idioma->getNombre();
    if (!existeIdioma(nombreIdioma)) {
        idiomas[nombreIdioma] = idioma;
    }
}

Idioma* ColeccionIdioma::obtenerIdioma(string nombreIdioma) {
    if (existeIdioma(nombreIdioma)) {
        return idiomas[nombreIdioma];
    }
    return nullptr;
}

bool ColeccionIdioma::existeIdioma(string nombreIdioma) {
    return idiomas.find(nombreIdioma) != idiomas.end();
}

bool ColeccionIdioma::existeIdioma(Idioma idioma) {
    string nombreIdioma = idioma.getNombre();
    return existeIdioma(nombreIdioma);
}

void ColeccionIdioma::eliminarIdioma(string nombreIdioma) {
    idiomas.erase(nombreIdioma);
}

void ColeccionIdioma::eliminarIdioma(Idioma* idioma) {
    string nombreIdioma = idioma->getNombre();
    eliminarIdioma(nombreIdioma);
}

set<string> ColeccionIdioma::obtenerNombresIdiomas(){
    set<string> nombresIdiomas;
    for (auto it = idiomas.begin(); it != idiomas.end(); ++it) {
        nombresIdiomas.insert(it->first);
    }
    return nombresIdiomas;
}