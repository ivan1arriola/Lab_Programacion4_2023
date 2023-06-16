#ifndef LECCION
#define LECCION

#include <string>
#include <set>
#include <vector>

#include "Ejercicio.h"

using namespace std;

class Leccion {
    private:
        string tema;
        string objetivo;
        set<Ejercicio*> ejercicios;
    public:
        Leccion();
        Leccion(string descripcion);
        Leccion(string tema, string objetivo);
        Leccion(string tema,string objetivo,set<Ejercicio*>);

        // Getters
        string getTema();
        string getObjetivo();
        set<Ejercicio*> getEjercicios();
        int getCantEj();

        // Setters
        void setTema(string tema);
        void setObjetivo(string objetivo);

        // Operaciones
        void crearEjercicioCompletarYAgregarlo(string nombre, string desc, string fraseCompletar, vector<string> palabrasFaltantes);
        void crearEjercicioTraducirYAgregarlo(string nombre, string desc, string fraseTraducir, string fraseTraducida);
       

        ~Leccion();

};

#endif