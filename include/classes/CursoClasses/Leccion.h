/*tema: String
objetivo: String*/
/*
crearEjercicioYAgregarlo(desc:String)
getEjercicios()
*/

#ifndef LECCION
#define LECCION

#include <string>
#include <set>

using namespace std;

class Leccion {
    private:
        string tema;
        string objetivo;
    public:
        Leccion();
        Leccion(string descripcion);

        // Getters
        string getTema();
        string getObjetivo();

        // Setters
        void setTema(string tema);
        void setObjetivo(string objetivo);

        // Operaciones
        void crearEjercicioYAgregarlo(string desc);
        set<Ejercicio> getEjercicios(); // Aun no esta linkeado con Ejercicio

        ~Leccion();

};

#endif