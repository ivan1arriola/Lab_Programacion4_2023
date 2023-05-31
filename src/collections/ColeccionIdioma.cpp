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
    if (idioma != nullptr) {
        idiomas[idioma->getNombre()] = idioma;
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
    for (const auto& par : idiomas) {
        if (*(par.second) == idioma) {
            return true;
        }
    }
    return false;
}

void ColeccionIdioma::eliminarIdioma(string nombreIdioma) {
    idiomas.erase(nombreIdioma);
}

void ColeccionIdioma::eliminarIdioma(Idioma* idioma) {
    if (idioma != nullptr) {
        idiomas.erase(idioma->getNombre());
    }
}
