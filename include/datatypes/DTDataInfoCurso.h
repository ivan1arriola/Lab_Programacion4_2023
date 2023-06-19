#ifndef DTDATAINFOCURSO
#define DTDATAINFOCURSO

#include <string>
#include "../../include/enums/NIVEL.h"

using namespace std;

class DTDataInfoCurso {
    private:
        string nombreCurso;
        float promedioAvanceCurso;
        string descripcion;
        Nivel nivel;
        bool disponible;
        string nombreIdioma;
        // string nombreProfesor;

    public:
        DTDataInfoCurso(string nombreCurso, string descripcion, Nivel nivel, bool disponible, string nombreIdioma, float promedioAvanceCurso);
        string getNombreCurso();
        float getPromedioAvanceCurso();
        string getDescripcion();
        string getNivel();
        string getDisponible();
        string getNombreIdioma();
        // string getNombreProfesor();
        ~DTDataInfoCurso();

        friend ostream& operator<<(ostream& os, const DTDataInfoCurso& dtCurso);
};

#endif