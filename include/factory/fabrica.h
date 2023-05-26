#ifndef FABRICA
#define FABRICA

#include <string>

#include "../interfaces/ISuscriptor.h"

using namespace std;

class Fabrica {
public:
    virtual Fabrica() {};
    virtual getInstancia() = 0;
    virtual ISuscriptor getSuscriptor(string nickname) = 0; //No se si es necesario el nickname
    virtual ~Fabrica() {}
};

#endif 