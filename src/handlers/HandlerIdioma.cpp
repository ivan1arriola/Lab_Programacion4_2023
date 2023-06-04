#include "../../include/classes/Idioma.h"
#include "../../include/handlers/HandlerIdioma.h"


HandlerIdioma* HandlerIdioma::instancia = nullptr;

HandlerIdioma::HandlerIdioma() {}

HandlerIdioma* HandlerIdioma::getInstancia() {
    if (instancia == nullptr) {
        instancia = new HandlerIdioma();
    }
    return instancia;
}

void HandlerIdioma::agregarIdioma(Idioma* idioma) {
    if (idioma == nullptr) return;
    string nombreIdioma = idioma->getNombre();
    if (!existeIdioma(nombreIdioma)) {
        idiomas[nombreIdioma] = idioma;
    }
}

Idioma* HandlerIdioma::obtenerIdioma(string nombreIdioma) {
    if (existeIdioma(nombreIdioma)) {
        return idiomas[nombreIdioma];
    }
    return nullptr;
}

bool HandlerIdioma::existeIdioma(string nombreIdioma) {
    return idiomas.find(nombreIdioma) != idiomas.end();
}

bool HandlerIdioma::existeIdioma(Idioma idioma) {
    string nombreIdioma = idioma.getNombre();
    return existeIdioma(nombreIdioma);
}

void HandlerIdioma::eliminarIdioma(string nombreIdioma) {
    idiomas.erase(nombreIdioma);
}

void HandlerIdioma::eliminarIdioma(Idioma* idioma) {
    string nombreIdioma = idioma->getNombre();
    eliminarIdioma(nombreIdioma);
}

set<string> HandlerIdioma::obtenerNombresIdiomas(){
    set<string> nombresIdiomas;
    for (auto it = idiomas.begin(); it != idiomas.end(); ++it) {
        nombresIdiomas.insert(it->first);
    }
    return nombresIdiomas;
}

// Destructor
HandlerIdioma::~HandlerIdioma() {
    for (auto it = idiomas.begin(); it != idiomas.end(); ++it) {
        delete it->second;
    }
    idiomas.clear();
}

void HandlerIdioma::deleteInstancia() {
    if (instancia != nullptr) {
        delete instancia;
        instancia = nullptr;
    }
}