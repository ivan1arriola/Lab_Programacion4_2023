#include "../../include/CasosDeUso/CargarDatos.h"

#include <iostream>
#include <string>
#include <set>
#include <map>
#include <sstream>


#include "../../include/classes/Usuario/Usuario.h"
#include "../../include/classes/Usuario/Estudiante.h"
#include "../../include/classes/Usuario/Profesor.h"

#include "../../include/classes/Idioma.h"

#include "../../include/handlers/HandlerIdioma.h"
#include "../../include/handlers/HandlerUsuario.h"

#include "../../include/datatypes/DTUsuario.h"

#include "../../include/datatypes/DTDate.h"

using namespace std;

//Coleccion de punteros a Idiomas
HandlerIdioma* idiomaHandler = HandlerIdioma::getInstancia();

//Coleccion de punteros a Usuarios
HandlerUsuario* usuariosHandler = HandlerUsuario::getInstancia();

void CargarDatos () {

    // Crear Idiomas
    Idioma* idioma1 = new Idioma("Español");
    Idioma* idioma2 = new Idioma("Inglés");
    Idioma* idioma3 = new Idioma("Portugués");
    Idioma* idioma4 = new Idioma("Francés");
    Idioma* idioma5 = new Idioma("Italiano");
    Idioma* idioma6 = new Idioma("Alemán");
    Idioma* idioma7 = new Idioma("Chino");
    Idioma* idioma8 = new Idioma("Japonés");
    Idioma* idioma9 = new Idioma("Ruso");
    Idioma* idioma10 = new Idioma("Coreano");
    Idioma* idioma11 = new Idioma("Árabe");
    Idioma* idioma12 = new Idioma("Hindi");
  

    // Agregar Idiomas a la Coleccion
    idiomaHandler->agregarIdioma(idioma1);
    idiomaHandler->agregarIdioma(idioma2);
    idiomaHandler->agregarIdioma(idioma3);
    idiomaHandler->agregarIdioma(idioma4);
    idiomaHandler->agregarIdioma(idioma5);
    idiomaHandler->agregarIdioma(idioma6);
    idiomaHandler->agregarIdioma(idioma7);
    idiomaHandler->agregarIdioma(idioma8);
    idiomaHandler->agregarIdioma(idioma9);
    idiomaHandler->agregarIdioma(idioma10);
    idiomaHandler->agregarIdioma(idioma11);
    idiomaHandler->agregarIdioma(idioma12);

    // Crear Usuarios
    //Crear Estudiante(string nickname, string contrasenia, string nombre, string descripcion, string pais, DTDate *fechaNacimiento);
    Usuario* usuario1 = new Estudiante("nick1", "pass1", "nombre1", "descripcion1", "pais1", new DTDate(11, 9, 2001));
    Usuario* usuario2 = new Estudiante("nick2", "pass2", "nombre2", "descripcion2", "pais2", new DTDate(2, 2, 2002));
    Usuario* usuario3 = new Estudiante("nick3", "pass3", "nombre3", "descripcion3", "pais3", new DTDate(3, 3, 2003));
    Usuario* usuario4 = new Estudiante("nick4", "pass4", "nombre4", "descripcion4", "pais4", new DTDate(4, 4, 2004));

    //Crear Profesor(string nickname, string contrasenia, string nombre, string descripcion, string instituto, set<Idioma*> idiomasDeProfesor)
    set<Idioma*> idiomasDeProfesor1;
    idiomasDeProfesor1.insert(idioma1);
    idiomasDeProfesor1.insert(idioma2);
    idiomasDeProfesor1.insert(idioma3);

    set<Idioma*> idiomasDeProfesor2;
    idiomasDeProfesor2.insert(idioma4);
    idiomasDeProfesor2.insert(idioma5);
    idiomasDeProfesor2.insert(idioma6);

    set<Idioma*> idiomasDeProfesor3;    
    idiomasDeProfesor3.insert(idioma7);

    set<Idioma*> idiomasDeProfesor4;
    idiomasDeProfesor4.insert(idioma8);
    idiomasDeProfesor4.insert(idioma9);
    idiomasDeProfesor4.insert(idioma10);
    idiomasDeProfesor4.insert(idioma11);
    idiomasDeProfesor4.insert(idioma12);

    Usuario* usuario5 = new Profesor("nick5", "pass5", "nombre5", "descripcion5", "instituto1", idiomasDeProfesor1);
    Usuario* usuario6 = new Profesor("nick6", "pass6", "nombre6", "descripcion6", "instituto2", idiomasDeProfesor2);
    Usuario* usuario7 = new Profesor("nick7", "pass7", "nombre7", "descripcion7", "instituto3", idiomasDeProfesor3);
    Usuario* usuario8 = new Profesor("nick8", "pass8", "nombre8", "descripcion8", "instituto4", idiomasDeProfesor4);

    // Agregar Usuarios a la Coleccion
    usuariosHandler->agregarUsuario(usuario1);
    usuariosHandler->agregarUsuario(usuario2);
    usuariosHandler->agregarUsuario(usuario3);
    usuariosHandler->agregarUsuario(usuario4);
    usuariosHandler->agregarUsuario(usuario5);
    usuariosHandler->agregarUsuario(usuario6);
    usuariosHandler->agregarUsuario(usuario7);
    usuariosHandler->agregarUsuario(usuario8);
}