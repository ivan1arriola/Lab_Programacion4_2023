#ifndef TRADUCIR
#define TRADUCIR

#include <string>

using namespace std;

#include "Ejercicio.h"

class Traducir : public Ejercicio {
    private:
        string fraseATraducir;
        string fraseCorrecta;
    public:
        Traducir();
        Traducir(string nombre, string descripcion, string fraseATraducir, string fraseCorrecta);

        // Getters
        string getFraseATraducir();
        string getFraseCorrecta();

        // Setters
        void setFraseATraducir(string fraseATraducir);
        void setFraseCorrecta(string fraseCorrecta);

        ~Traducir();
        friend ostream& operator<<(ostream& os, const Traducir& traducir);

};

#endif