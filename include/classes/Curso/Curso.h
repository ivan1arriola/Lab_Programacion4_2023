#ifndef CURSO
#define CURSO

#include <string>
#include <set>

using namespace std;

#include "../../enums/Nivel.h"

class Curso {
    private:
        string nombre;
        string descripcion;
        Nivel nivel;
        bool disponible;
    public:
        Curso();
        Curso(string nombre, string descripcion, Nivel nivel, bool disponible);

        // Getters
        string getNombre();
        string getDescripcion();
        Nivel getNivel();
        bool getDisponible();

        // Setters
        void setNombre(string nombre);
        void setDescripcion(string descripcion);
        void setNivel(Nivel nivel);
        void setDisponible(bool disponible);

        // Operaciones
        set<string> obtenerEjNoAprobados();
        void agregarALeccion(string desc);
        float getCantEjsTotal();
        float calcPromedioAvance();

        ~Curso();

};

#endif 