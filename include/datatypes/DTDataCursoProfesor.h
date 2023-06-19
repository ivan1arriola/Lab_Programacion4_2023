#ifndef DTDATACURSOPROFESOR
#define DTDATACURSOPROFESOR

#include <string>

using namespace std;

class DTDataCursoProfesor {
    private:
        string nombreCurso;
        float promedioAvanceProfesor;
    public:
        DTDataCursoProfesor(string nombreCurso, float promedioAvanceProfesor);
        string getNombreCurso();
        float getPromedioAvanceProfesor();
        ~DTDataCursoProfesor();

        friend ostream& operator<<(ostream& os, const DTDataCursoProfesor& dtCursoProfesor);
};

#endif