#include "../../../include/classes/Curso/Traducir.h"

#include <iostream>

Traducir::Traducir() {
    // Implementación del constructor por defecto
}

Traducir::Traducir(string nombre, string descripcion) : Ejercicio(nombre, descripcion) {
    this->fraseATraducir = "";
    this->fraseCorrecta = "";

}

Traducir::Traducir(string nombre, string descripcion, string fraseATraducir, string fraseCorrecta) : Ejercicio(nombre, descripcion) {
    this->fraseATraducir = fraseATraducir;
    this->fraseCorrecta = fraseCorrecta;
}

string Traducir::getFraseATraducir() {
    return fraseATraducir;
}

string Traducir::getFraseCorrecta() {
    return fraseCorrecta;
}

void Traducir::setFraseATraducir(string fraseATraducir) {
    this->fraseATraducir = fraseATraducir;
}

void Traducir::setFraseCorrecta(string fraseCorrecta) {
    this->fraseCorrecta = fraseCorrecta;
}

Traducir::~Traducir() {
}

ostream& operator<<(ostream& os, const Traducir& traducir) {
    // Implementación del operador de inserción para imprimir el objeto Traducir
    os << "Tipo de ejercicio: Traducir" << endl;
    os << "Frase a traducir: " << traducir.fraseATraducir << endl;
    return os;
}
