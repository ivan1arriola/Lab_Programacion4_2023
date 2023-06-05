#ifndef DTDATAINFOCURSO
#define DTDATAINFOCURSO

#include <string>

using namespace std;

class DTDataInfoCurso {
    private:
        string nombreCurso;
        float promedioAvanceCurso;
    public:
        DTDataInfoCurso(string nombreCurso, float promedioAvanceCurso);
        string getNombreCurso();
        float getPromedioAvanceCurso();
        ~DTDataInfoCurso();
};

#endif