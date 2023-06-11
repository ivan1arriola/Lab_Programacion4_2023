#include "../../../include/system/Sistema.h"

#include <iostream>
#include <string>
#include <set>
#include <map>
#include <sstream>

#include "../../../include/classes/Usuario/Usuario.h"
#include "../../../include/classes/Usuario/Estudiante.h"
#include "../../../include/classes/Usuario/Profesor.h"

#include "../../../include/classes/Idioma.h"

#include "../../../include/datatypes/DTUsuario.h"

#include "../../../include/datatypes/DTDate.h"
#include "../../../include/datatypes/DTNotificacion.h"

using namespace std;


void Sistema::cargarDatosdePrueba()
{

     // Crear Idiomas
     Idioma *idioma1 = new Idioma("Español");
     Idioma *idioma2 = new Idioma("Inglés");
     Idioma *idioma3 = new Idioma("Portugués");
     Idioma *idioma4 = new Idioma("Francés");
     Idioma *idioma5 = new Idioma("Italiano");
     Idioma *idioma6 = new Idioma("Alemán");
     Idioma *idioma7 = new Idioma("Chino");
     Idioma *idioma8 = new Idioma("Japonés");
     Idioma *idioma9 = new Idioma("Ruso");
     Idioma *idioma10 = new Idioma("Coreano");
     Idioma *idioma11 = new Idioma("Árabe");
     Idioma *idioma12 = new Idioma("Hindi");

     // Agregar Idiomas a la Coleccion
     handlerIdioma->agregarIdioma(idioma1);
     handlerIdioma->agregarIdioma(idioma2);
     handlerIdioma->agregarIdioma(idioma3);
     handlerIdioma->agregarIdioma(idioma4);
     handlerIdioma->agregarIdioma(idioma5);
     handlerIdioma->agregarIdioma(idioma6);
     handlerIdioma->agregarIdioma(idioma7);
     handlerIdioma->agregarIdioma(idioma8);
     handlerIdioma->agregarIdioma(idioma9);
     handlerIdioma->agregarIdioma(idioma10);
     handlerIdioma->agregarIdioma(idioma11);
     handlerIdioma->agregarIdioma(idioma12);

     // Crear fechas de nacimiento
     DTDate *fechaNacimiento1 = new DTDate(11, 9, 2001);
     DTDate *fechaNacimiento2 = new DTDate(2, 2, 2002);
     DTDate *fechaNacimiento3 = new DTDate(3, 3, 2003);
     DTDate *fechaNacimiento4 = new DTDate(4, 4, 2004);

     // Crear Usuarios
     Usuario *usuario1 = new Estudiante("john_doe", "password1", "John Doe", "Estudiante de programación interesado en desarrollo web", "Estados Unidos", fechaNacimiento1);
     Usuario *usuario2 = new Estudiante("jane_smith", "password2", "Jane Smith", "Apasionada por el diseño gráfico y la ilustración", "Canadá", fechaNacimiento2);
     Usuario *usuario3 = new Estudiante("luis_perez", "password3", "Luis Pérez", "Entusiasta de las matemáticas y la ciencia", "México", fechaNacimiento3);
     Usuario *usuario4 = new Estudiante("anna_kovac", "password4", "Anna Kovac", "Amante de los idiomas y viajera incansable", "Eslovaquia", fechaNacimiento4);

     set<Idioma *> idiomasDeProfesor1;
     idiomasDeProfesor1.insert(idioma1);
     idiomasDeProfesor1.insert(idioma2);
     idiomasDeProfesor1.insert(idioma3);

     set<Idioma *> idiomasDeProfesor2;
     idiomasDeProfesor2.insert(idioma4);
     idiomasDeProfesor2.insert(idioma5);
     idiomasDeProfesor2.insert(idioma6);

     set<Idioma *> idiomasDeProfesor3;
     idiomasDeProfesor3.insert(idioma7);

     set<Idioma *> idiomasDeProfesor4;
     idiomasDeProfesor4.insert(idioma8);
     idiomasDeProfesor4.insert(idioma9);
     idiomasDeProfesor4.insert(idioma10);
     idiomasDeProfesor4.insert(idioma11);
     idiomasDeProfesor4.insert(idioma12);

     Usuario *usuario5 = new Profesor("johnsmith", "password5", "John Smith", "Profesor experimentado en enseñanza de idiomas", "Instituto de Idiomas Internacionales", idiomasDeProfesor1);
     Usuario *usuario6 = new Profesor("mariagarcia", "password6", "Maria García", "Especialista en gramática y escritura creativa", "Instituto de Lenguas Modernas", idiomasDeProfesor2);
     Usuario *usuario7 = new Profesor("michaelmuller", "password7", "Michael Müller", "Profesor nativo de alemán con enfoque en la pronunciación", "Instituto de Idiomas de Berlín", idiomasDeProfesor3);
     Usuario *usuario8 = new Profesor("sakuratanaka", "password8", "Sakura Tanaka", "Experta en enseñanza del japonés para principiantes", "Instituto de Cultura Japonesa", idiomasDeProfesor4);

     // Agregar Usuarios a la Coleccion
     handlerUsuario->agregarUsuario(usuario1);
     handlerUsuario->agregarUsuario(usuario2);
     handlerUsuario->agregarUsuario(usuario3);
     handlerUsuario->agregarUsuario(usuario4);
     handlerUsuario->agregarUsuario(usuario5);
     handlerUsuario->agregarUsuario(usuario6);
     handlerUsuario->agregarUsuario(usuario7);
     handlerUsuario->agregarUsuario(usuario8);

     // Suscribir Estudiantes a Idiomas
     idioma1->agregarSuscriptor(dynamic_cast<ISuscriptor *>(usuario1));
     idioma1->agregarSuscriptor(dynamic_cast<ISuscriptor *>(usuario2));
     idioma1->agregarSuscriptor(dynamic_cast<ISuscriptor *>(usuario3));
     idioma1->agregarSuscriptor(dynamic_cast<ISuscriptor *>(usuario4));
     idioma2->agregarSuscriptor(dynamic_cast<ISuscriptor *>(usuario5));
     idioma2->agregarSuscriptor(dynamic_cast<ISuscriptor *>(usuario6));
     idioma2->agregarSuscriptor(dynamic_cast<ISuscriptor *>(usuario7));
     idioma2->agregarSuscriptor(dynamic_cast<ISuscriptor *>(usuario8));
     idioma3->agregarSuscriptor(dynamic_cast<ISuscriptor *>(usuario1));
     idioma3->agregarSuscriptor(dynamic_cast<ISuscriptor *>(usuario2));
     idioma3->agregarSuscriptor(dynamic_cast<ISuscriptor *>(usuario3));
     idioma3->agregarSuscriptor(dynamic_cast<ISuscriptor *>(usuario4));
     idioma4->agregarSuscriptor(dynamic_cast<ISuscriptor *>(usuario5));
     idioma4->agregarSuscriptor(dynamic_cast<ISuscriptor *>(usuario6));
     idioma4->agregarSuscriptor(dynamic_cast<ISuscriptor *>(usuario7));
     idioma4->agregarSuscriptor(dynamic_cast<ISuscriptor *>(usuario8));

     // Crear vectores de Lecciones
     vector<Leccion *> lecciones1;
     vector<Leccion *> lecciones2;
     vector<Leccion *> lecciones3;
     vector<Leccion *> lecciones4;

     // Crear Lecciones
     Leccion *leccion1 = new Leccion("Introducción a la Programación", "Aprender los conceptos básicos de la programación");
     Leccion *leccion2 = new Leccion("Diseño de Interfaz de Usuario", "Explorar técnicas de diseño centrado en el usuario");
     Leccion *leccion3 = new Leccion("Marketing Digital Avanzado", "Dominar las estrategias avanzadas de marketing en línea");
     Leccion *leccion4 = new Leccion("Análisis de Datos", "Aprender a analizar y visualizar datos para la toma de decisiones");
     Leccion *leccion5 = new Leccion("Desarrollo de Aplicaciones Móviles", "Crear aplicaciones móviles para Android e iOS");
     Leccion *leccion6 = new Leccion("Inteligencia Artificial", "Explorar el campo de la inteligencia artificial y sus aplicaciones");
     Leccion *leccion7 = new Leccion("Redes Neuronales", "Aprender sobre las redes neuronales y su uso en el aprendizaje automático");
     Leccion *leccion8 = new Leccion("Seguridad Informática", "Conocer los fundamentos de la seguridad informática y protección de datos");

     // Agregar Lecciones a los vectores
     lecciones1.push_back(leccion1);
     lecciones1.push_back(leccion2);
     lecciones2.push_back(leccion3);
     lecciones2.push_back(leccion4);
     lecciones3.push_back(leccion5);
     lecciones3.push_back(leccion6);
     lecciones4.push_back(leccion7);
     lecciones4.push_back(leccion8);

     // Niveles
     Nivel nivel1 = PRICIPIANTE;
     Nivel nivel2 = MEDIO;
     Nivel nivel3 = AVANZADO;

     // Crear Cursos
     Curso *curso1 = new Curso("Programación en C++", "Aprende a programar en C++ desde cero", nivel1, true, idioma1, dynamic_cast<Profesor *>(usuario5), lecciones1);
     Curso *curso2 = new Curso("Diseño Gráfico Avanzado", "Explora técnicas avanzadas de diseño gráfico", nivel2, true, idioma2, dynamic_cast<Profesor *>(usuario6), lecciones2);
     Curso *curso3 = new Curso("Marketing Digital para Emprendedores", "Descubre estrategias de marketing para impulsar tu negocio", nivel1, false, idioma3, dynamic_cast<Profesor *>(usuario7), lecciones3);
     Curso *curso4 = new Curso("Introducción a la Inteligencia Artificial", "Aprende los conceptos básicos de la IA y sus aplicaciones", nivel3, true, idioma4, dynamic_cast<Profesor *>(usuario8), lecciones4);

     // Agregar Cursos a la Coleccion
     handlerCurso->agregarCurso(curso1);
     handlerCurso->agregarCurso(curso2);
     handlerCurso->agregarCurso(curso3);
     handlerCurso->agregarCurso(curso4);

     

     

     cout << endl
          << "Usuarios disponibles:" << endl;
     cout << "-------------------" << endl;

     set<Usuario *> usuarios = handlerUsuario->obtenerUsuarios();

     for (set<Usuario *>::iterator it = usuarios.begin(); it != usuarios.end(); it++)
     {
          cout << (*it)->getNombre() << endl;
     }

     cout << endl
          << "Cursos disponibles:" << endl;
     cout << "-------------------" << endl;

     map<string, Curso*> cursos = handlerCurso->obtenerCursos();

     for (map<string, Curso*>::iterator it = cursos.begin(); it != cursos.end(); it++)
     {
          cout << it->first << endl;
     }

     cout << endl
          << "Idiomas disponibles:" << endl;
     cout << "-------------------" << endl;

     map<string, Idioma*> idiomas = handlerIdioma->obtenerIdiomas();

     for (map<string, Idioma*>::iterator it = idiomas.begin(); it != idiomas.end(); it++)
     {
          cout << it->first << endl;
     }

     



     
}