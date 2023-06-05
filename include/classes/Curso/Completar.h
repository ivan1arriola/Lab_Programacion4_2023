#ifndef COMPLETAR
#define COMPLETAR

#include <string>
#include <vector>

using namespace std;

#include "Ejercicio.h"

class Completar : public Ejercicio {
    private:
        string fraseACompletar;
        vector<string> palabrasFaltantes;
    public:
        Completar();
        Completar(string nombre, string descripcion, string fraseACompletar, vector<string> palabrasFaltantes);

        // Getters
        string getFraseACompletar();
        vector<string> getPalabrasFaltantes();

        // Setters
        void setFraseACompletar(string fraseACompletar);
        void setPalabrasFaltantes(vector<string> palabrasFaltantes);

        ~Completar();
        friend ostream& operator<<(ostream& os, const Completar& completar);


};

#endif