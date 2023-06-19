#ifndef DTDATACURSO
#define DTDATACURSO

#include <string>
#include <vector>

#include "../enums/NIVEL.h"
#include "DTDataLeccion.h"


using namespace std;

class DTDataCurso {
    private:
        string nombre;
        string descripcion;
        Nivel nivel;
        bool disponible;

        string nombreIdioma;
        string nombreProfesor;

        vector<DTDataLeccion*> lecciones;
    public:
        DTDataCurso();
        DTDataCurso(string nombre, string descripcion, Nivel nivel, bool disponible, string nombreIdioma, string nombreProfesor);
        DTDataCurso(string nombre, string descripcion, Nivel nivel, bool disponible, string nombreIdioma, string nombreProfesor, vector<DTDataLeccion*> lecciones);

        //Getters
        string getNombre();
        string getDescripcion();
        string getNivel();
        string getDisponible();
        string getNombreIdioma();
        string getNombreProfesor();


        ~DTDataCurso();

        friend ostream& operator<<(ostream& os, const DTDataCurso& dtCurso);
};



#endif