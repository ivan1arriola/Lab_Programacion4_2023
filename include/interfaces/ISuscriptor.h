#ifndef #ISUSCRIPTOR
#define #ISUSCRIPTOR

#include <string>

using namespace std;

class ISuscriptor {
public:
    virtual ISuscriptor() {};
    virtual void enviarNotificacion(string nombreCurso, string nombreIdioma) = 0;
    virtual string getNickname() = 0;
    virtual ~ISuscriptor() {}
};

#endif // #ISUSCRIPTOR
