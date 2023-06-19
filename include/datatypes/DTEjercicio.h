/*tipoEjercicio:String
desc:String*/
#ifndef DTEJERCICIO
#define DTEJERCICIO

#include <string>
#include <set>

using namespace std;

class DTEjercicio {
    private:
        string tipoEjercicio;
        string desc;
    public:
        DTEjercicio();
        DTEjercicio(string tipoEjercicio, string desc);

        string getTipoEjercicio();
        string getDesc();
        ~DTEjercicio();

        friend ostream& operator<<(ostream& os, const DTEjercicio& dtEjercicio);
};

#endif