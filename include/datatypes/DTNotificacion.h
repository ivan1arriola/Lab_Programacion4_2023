/* nombreCurso:String
nombreIdioma:String*/

#ifndef DTNOTIFICACION
#define DTNOTIFICACION

#include <string>


using namespace std;

class DTNotificacion {
    private:
        string nombreCurso;
        string nombreIdioma;
    public:
        DTNotificacion(string nombreCurso, string nombreIdioma);
        string getNombreCurso();
        string getNombreIdioma();
        ~DTNotificacion();
        friend ostream& operator<<(ostream& os, const DTNotificacion& dtNotificacion);
};

#endif