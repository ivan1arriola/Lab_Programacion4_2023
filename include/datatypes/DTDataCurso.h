#ifndef DTDATACURSO
#define DTDATACURSO

#include <string>
#include <vector>

#include "../enums/NIVEL.h"

#include "DTLeccion.h"


using namespace std;

class DTDataCurso {
    private:
        string nombre;
        string descripcion;
        Nivel nivel;
        bool disponible;

        string nombreIdioma;
        string nombreProfesor;

        // vector<DTLeccion*> lecciones;


    public:
        DTDataCurso();
        DTDataCurso(string nombre, string descripcion, Nivel nivel, bool disponible, string nombreIdioma, string nombreProfesor);
        // DTDataCurso(string nombre, string descripcion, Nivel nivel, bool disponible, string nombreIdioma, string nombreProfesor, vector<DTLeccion*> lecciones);

        //Getters
        string getNombre();
        string getDescripcion();
        string getNivel();
        string getDisponible();
        string getNombreIdioma();
        string getNombreProfesor();
        // vector<DTLeccion*> getLecciones();


        ~DTDataCurso();

        friend ostream& operator<<(ostream& os, const DTDataCurso& dtCurso);
};



#endif