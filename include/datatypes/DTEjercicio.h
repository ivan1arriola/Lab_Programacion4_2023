/*tipoEjercicio:String
desc:String*/
#ifndef DTEJERCICIO
#define DTEJERCICIO

#include <string>

using namespace std;

class DTEjercicio {
    private:
        string tipoEjercicio;
        string desc;
    public:
        DTEjercicio(string tipoEjercicio, string desc);
        string getTipoEjercicio();
        string getDesc();
        ~DTEjercicio();
};

#endif