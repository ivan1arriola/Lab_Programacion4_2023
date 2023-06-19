#ifndef DTDATACURSOAINSCRIBIR
#define DTDATACURSOAINSCRIBIR

#include <string>

#include "../enums/NIVEL.h"


using namespace std;

class DTDataCursoAInscribir {
    private:
        string nombre;
        string descripcion;
        Nivel nivel;
        string nombreIdioma;
        string nombreProfesor;
        int cantLecciones;
        int cantEjercicios;
    public:
        DTDataCursoAInscribir();
        DTDataCursoAInscribir(string nombre, string descripcion, Nivel nivel, string nombreIdioma, string nombreProfesor, int cantLecciones, int cantEjercicios);

        //Getters
        string getNombre();
        string getDescripcion();
        string getNivel();
        string getNombreIdioma();
        string getNombreProfesor();
        int getCantLecciones();
        int getCantEjercicios();


        ~DTDataCursoAInscribir();

        friend ostream& operator<<(ostream& os, const DTDataCursoAInscribir& dtCursoAInscribir);
};



#endif