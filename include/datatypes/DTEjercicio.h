/*tipoEjercicio:String
desc:String*/
#ifndef DTEJERCICIO
#define DTEJERCICIO

#include <string>

using namespace std;

class DTEjercicio {
    private:
        string nombre;
        string tipoEjercicio;
        string desc;
    public:
        DTEjercicio();
        DTEjercicio(string nombre, string tipoEjercicio, string desc);
        DTEjercicio(string nombre, string tipoEjercicio, string desc, set<DTEjercicio*> ejercicios); 

        string getNombre();
        string getTipoEjercicio();
        string getDesc();
        ~DTEjercicio();
};

#endif