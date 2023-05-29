// version provisional

#ifndef DTUSUARIO
#define DTUSUARIO

#include <string>

using namespace std;

class DTUsuario {
    private:
        string nickname;
        string password;
        string name;
        string desc;
        string pais;
        string instituto;
        bool esEstudiante;
        bool esProfesor;
    public:
        DTUsuario();
        DTUsuario(string nickname, string password, string name, string desc, string pais, string instituto, bool esEstudiante, bool esProfesor);
        string getNickname();
        string getPassword();
        string getName();
        string getDesc();
        string getPais();
        string getInstituto();
        bool getEsEstudiante();
        bool getEsProfesor();
        ~DTUsuario();
};

#endif

