#ifndef DTNOTIFICACION_H
#define DTNOTIFICACION_H

#include <string>
#include <iostream>

using namespace std;

class DTNotificacion {
private:
    string nombreCurso;
    string nombreIdioma;

public:
    DTNotificacion(string nombreCurso, string nombreIdioma);
    string getNombreCurso() const;
    string getNombreIdioma() const;
    ~DTNotificacion();

    friend ostream& operator<<(ostream& os, const DTNotificacion& dtNotificacion);
};

#endif
