#include "../../include/datatypes/DTUsuario.h"

#include <string>

using namespace std;

DTUsuario::DTUsuario() {}

DTUsuario::DTUsuario(string nickname, string password, string name, string desc, string pais, string instituto, bool esEstudiante, bool esProfesor) {
    this->nickname = nickname;
    this->password = password;
    this->name = name;
    this->desc = desc;
    this->pais = pais;
    this->instituto = instituto;
    this->esEstudiante = esEstudiante;
    this->esProfesor = esProfesor;
}

string DTUsuario::getNickname() {
    return this->nickname;
}

string DTUsuario::getPassword() {
    return this->password;
}

string DTUsuario::getName() {
    return this->name;
}

string DTUsuario::getDesc() {
    return this->desc;
}

string DTUsuario::getPais() {
    return this->pais;
}

string DTUsuario::getInstituto() {
    return this->instituto;
}

bool DTUsuario::getEsEstudiante() {
    return this->esEstudiante;
}

bool DTUsuario::getEsProfesor() {
    return this->esProfesor;
}

DTUsuario::~DTUsuario() {}


