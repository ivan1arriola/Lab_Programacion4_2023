#include "../../../include/system/Sistema.h"
#include "../../../include/system/operaciones.h"
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <sstream>
#include <typeinfo>

#include "../../../include/classes/Usuario/Usuario.h"
#include "../../../include/classes/Usuario/Estudiante.h"
#include "../../../include/classes/Usuario/Profesor.h"
#include "../../../include/classes/Curso/Ejercicio.h"
#include "../../../include/classes/Curso/Traducir.h"
#include "../../../include/classes/Curso/Completar.h"
#include "../../../include/classes/Inscripcion.h"

#include "../../../include/classes/Idioma.h"
#include "../../../include/classes/Curso/Curso.h"
#include "../../../include/classes/Curso/Leccion.h"
#include "../../../include/classes/Curso/Ejercicio.h"
#include "../../../include/classes/Curso/Completar.h"
#include "../../../include/classes/Curso/Traducir.h"

#include "../../../include/datatypes/DTUsuario.h"

#include "../../../include/datatypes/DTDate.h"
#include "../../../include/datatypes/DTNotificacion.h"

using namespace std;

void Sistema::cargarDatosdePrueba()
{
     Sistema *sistema = Sistema::getInstancia();
     if (!sistema->getSeCargaronDatos()) //Si no se cargaron los datos

     {
          //--------IDIOMAS--------//

          Idioma *idioma1 = new Idioma("Ingles");
          Idioma *idioma2 = new Idioma("Aleman");
          Idioma *idioma3 = new Idioma("Portugues");

          handlerIdioma->agregarIdioma(idioma1);
          handlerIdioma->agregarIdioma(idioma2);
          handlerIdioma->agregarIdioma(idioma3);

          //--------ESTUDIANTES--------//

          // Crear fechas de nacimiento
          DTDate *fechaNacimiento1 = new DTDate(15, 7, 1995);
          DTDate *fechaNacimiento2 = new DTDate(28, 2, 1998);
          DTDate *fechaNacimiento3 = new DTDate(10, 11, 1994);
          DTDate *fechaNacimiento4 = new DTDate(22, 4, 1997);
          DTDate *fechaNacimiento5 = new DTDate(3, 9, 1996);
          DTDate *fechaNacimiento6 = new DTDate(12, 1, 1999);
          DTDate *fechaNacimiento7 = new DTDate(25, 6, 1993);
          DTDate *fechaNacimiento8 = new DTDate(8, 12, 1997);
          DTDate *fechaNacimiento9 = new DTDate(17, 3, 1995);
          DTDate *fechaNacimiento10 = new DTDate(2, 8, 1998);

          // Crear estudiantes
          Estudiante *usuario1 = new Estudiante("jpidiom", "asdfg123", "Juan Perez", "Soy un apasionado del aprendizaje de idiomas", "Argentina", fechaNacimiento1);
          Estudiante *usuario2 = new Estudiante("marsilva", "qwer456", "Maria Silva", "Como amante de los idiomas disfruto explorando nuevas formas de interactuar.", "Ecuador", fechaNacimiento2);
          Estudiante *usuario3 = new Estudiante("pero12", "789werty", "Pedro Rodriguez", "Soy un entusiasta del aprendizaje de idiomas.", "Peru", fechaNacimiento3);
          Estudiante *usuario4 = new Estudiante("laugu", "c1v2b3m4", "Laura Gutierrez", "Estoy fascinada por la forma en que las palabras pueden unir a las personas", "Chile", fechaNacimiento4);
          Estudiante *usuario5 = new Estudiante("carlo22", "tyuipz147", "Carlos Lopez", "Emocionado por adquirir fluidez en diferentes lenguas.", "Uruguay", fechaNacimiento5);
          Estudiante *usuario6 = new Estudiante("anator", "1qsxc36", "Ana Torres", "Disfruto de la belleza de las diferentes estructuras y sonidos.", "Argentina", fechaNacimiento6);
          Estudiante *usuario7 = new Estudiante("luher24", "t7h8y5u6", "Lucia Hernandez", "Emocionada en la riqueza cultural que cada idioma ofrece.", "Colombia", fechaNacimiento7);
          Estudiante *usuario8 = new Estudiante("dagon", "1w2e3r4t5", "David Gonzalez", "Aprender nuevas lenguas y sumergirme en diferentes culturas.", "Uruguay", fechaNacimiento8);
          Estudiante *usuario9 = new Estudiante("carmor", "6yu7i8m9", "Carmen Morales", "El aprendizaje de idiomas y expandir mis habilidades comunicativas en diferentes lenguas.", "Chile", fechaNacimiento9);
          Estudiante *usuario10 = new Estudiante("jose24", "qwj789p", "Jose Fernandez", "Disfruto del proceso de descubrir nuevas formas de comunicarme", "Bolivia", fechaNacimiento10);

          //--------PROFESORES--------//

          // Profesores
          Profesor *usuario11 = new Profesor("langMaster", "P4s512", "Marta Grecia", "Soy una profesora apasionada por los idiomas.", "Instituto de Idiomas Moderno");
          Profesor *usuario12 = new Profesor("linguaPro", "Pess23", "Carlos Petro", "Mi objetivo es inspirar a mis estudiantes a explorar nuevas culturas e idiomas", "Centro Global");
          Profesor *usuario13 = new Profesor("talkExpert", "Secret1", "Laura Perez", "Soy una profesora entusiasta del aprendizaje de idiomas", "Instituto de Idiomas Vanguardia");
          Profesor *usuario14 = new Profesor("lingoSensei", "Secure2", "Franco Lopez", "Apasionada en guiar a mis estudiantes en su viaje por nuevos horizontes idiomaticos", "Centro de Idiomas");
          Profesor *usuario15 = new Profesor("wordMaestro", "Passw0", "Ana Morales", "Soy una profesora comprometida en desarrollo de habilidades idiomaticas", "Instituto de Idiomas Progreso");

          // Agregamos idiomas del profesor
          usuario11->agregarAIdiomasDeProfesor(idioma1);
          usuario11->agregarAIdiomasDeProfesor(idioma3);
          usuario12->agregarAIdiomasDeProfesor(idioma1);
          usuario12->agregarAIdiomasDeProfesor(idioma2);
          usuario12->agregarAIdiomasDeProfesor(idioma3);
          usuario13->agregarAIdiomasDeProfesor(idioma2);
          usuario14->agregarAIdiomasDeProfesor(idioma3);
          usuario15->agregarAIdiomasDeProfesor(idioma1);

          // Agregar Usuarios a la Coleccion
          handlerUsuario->agregarUsuario(dynamic_cast<Usuario *>(usuario1));
          handlerUsuario->agregarUsuario(dynamic_cast<Usuario *>(usuario2));
          handlerUsuario->agregarUsuario(dynamic_cast<Usuario *>(usuario3));
          handlerUsuario->agregarUsuario(dynamic_cast<Usuario *>(usuario4));
          handlerUsuario->agregarUsuario(dynamic_cast<Usuario *>(usuario5));
          handlerUsuario->agregarUsuario(dynamic_cast<Usuario *>(usuario6));
          handlerUsuario->agregarUsuario(dynamic_cast<Usuario *>(usuario7));
          handlerUsuario->agregarUsuario(dynamic_cast<Usuario *>(usuario8));
          handlerUsuario->agregarUsuario(dynamic_cast<Usuario *>(usuario9));
          handlerUsuario->agregarUsuario(dynamic_cast<Usuario *>(usuario10));
          handlerUsuario->agregarUsuario(dynamic_cast<Usuario *>(usuario11));
          handlerUsuario->agregarUsuario(dynamic_cast<Usuario *>(usuario12));
          handlerUsuario->agregarUsuario(dynamic_cast<Usuario *>(usuario13));
          handlerUsuario->agregarUsuario(dynamic_cast<Usuario *>(usuario14));
          handlerUsuario->agregarUsuario(dynamic_cast<Usuario *>(usuario15));

          //--------CURSOS--------//

          // Niveles
          Nivel nivel1 = PRICIPIANTE;
          Nivel nivel2 = MEDIO;
          Nivel nivel3 = AVANZADO;

          // Crear vectores de Lecciones
          vector<Leccion *> lecciones1;
          vector<Leccion *> lecciones2;
          vector<Leccion *> lecciones3;
          vector<Leccion *> lecciones4;
          vector<Leccion *> lecciones5;
          vector<Leccion *> lecciones6;

          // Crear Lecciones
          Leccion *leccion1 = new Leccion("Saludos y Presentaciones", "Aprender a saludar y despedirse");
          Leccion *leccion2 = new Leccion("Artículos y Plurales ", "Comprender y utilizar los articulos definidos e indefinidos, Aprender a formar los plurales regulares e irregulares de sustantivos");
          Leccion *leccion3 = new Leccion("Actividades Cotidianas", "Comprender y utilizar los articulos definidos e indefinidos, Aprender a formar los plurales regulares e irregulares de sustantivos");
          Leccion *leccion4 = new Leccion("Presente Simple", "Aprender el uso del presente simple");
          Leccion *leccion5 = new Leccion("Conversaciones cotidianas", "Aprender a hacer preguntas y respuestas en situaciones comunes");
          Leccion *leccion6 = new Leccion("Uso de modales avanzados", "Explorar el uso de los modales complejos");
          Leccion *leccion7 = new Leccion(" Lectura y comprension de textos", "Analizar el contenido, vocabulario y estructuras gramaticales utilizadas");

          lecciones1.push_back(leccion1);
          lecciones1.push_back(leccion2);
          lecciones2.push_back(leccion3);
          lecciones2.push_back(leccion4);
          lecciones3.push_back(leccion5);
          lecciones4.push_back(leccion6);
          lecciones1.push_back(leccion7);

          // Crear Cursos
          Curso *curso1 = new Curso("Ingles para principiantes", "Curso para personas con poco o ningun conocimiento de ingles. Se enfoca en vocabulario basico, gramatica y habilidades de conversacion.", nivel1, true, idioma1, dynamic_cast<Profesor *>(usuario11), lecciones1);
          Curso *curso2 = new Curso("Curso de ingles basico", "Construye una base solida en el idioma. Cubre gramatica, vocabulario, comprension auditiva y expresion oral.", nivel1, false, idioma1, dynamic_cast<Profesor *>(usuario11), lecciones2);
          Curso *curso3 = new Curso("Ingles intermedio: mejora tu nivel", "Para estudiantes con conocimientos basicos de ingles que desean avanzar en su habilidad comunicativa. Se centra en la fluidez oral, lectura comprensiva y escritura.", nivel2, true, idioma1, dynamic_cast<Profesor *>(usuario12), lecciones3);
          Curso *curso4 = new Curso("Curso avanzado de ingles", "Dirigido a personas con un nivel intermedio-alto que desean perfeccionar sus habilidades en todos los aspectos del idioma. Incluye gramatica avanzada, vocabulario y comprension escrita y auditiva.", nivel3, true, idioma1, dynamic_cast<Profesor *>(usuario12), lecciones4);
          Curso *curso5 = new Curso("Portugues intermedio", "Curso para aquellos que tienen conocimientos basicos de portugues y desean mejorar su nivel. Incluye practica de lectura, escritura y comprension auditiva.", nivel2, true, idioma3, dynamic_cast<Profesor *>(usuario12), lecciones5);
          Curso *curso6 = new Curso("Portugues avanzado", "Curso avanzado para personas con un nivel intermedio-alto de portugues que desean perfeccionar su fluidez y dominio del idioma. Se trabaja en la gramatica avanzada y la expresion oral.", nivel3, false, idioma3, dynamic_cast<Profesor *>(usuario14), lecciones6);

          // Cursos previos
          set<Curso *> previos3;
          set<Curso *> previos4;
          set<Curso *> previos6;

          previos3.insert(curso3);
          previos4.insert(curso1);
          previos4.insert(curso3);
          previos6.insert(curso5);

          curso3->setCursosPrevios(previos3);
          curso4->setCursosPrevios(previos4);
          curso6->setCursosPrevios(previos6);

          //--------EJERCICIOS--------//

          // Creamos palabras faltantes
          vector<string> solucion2;
          vector<string> solucion4;
          vector<string> solucion5;
          vector<string> solucion6;

          solucion2.push_back("allow");
          solucion2.push_back("myself");
          solucion4.push_back("some");
          solucion5.push_back("up");
          solucion6.push_back("have");
          solucion6.push_back("past");

          Traducir *ejercicio1 = new Traducir( "Presentaciones", "Mucho gusto en conocerte", "Nice to meet you");
          Completar *ejercicio2 = new Completar( "Presentaciones formales", "Please --- me to introduce ---", solucion2);
          Traducir *ejercicio3 = new Traducir( "Plurales regulares", "I have two brothers and three sisters", "Tengo dos hermanos y tres hermanas");
          Completar *ejercicio4 = new Completar( "Sustantivos contables en plural", "Can I have --- water, please?", solucion4);
          Completar *ejercicio5 = new Completar( "Actividades diarias", "Wake ---", solucion5);
          Completar *ejercicio6 = new Completar( "Consultas de la hora", "Q: Do you --- the time?, A: Yes, it is half --- 4", solucion6);
          Traducir *ejercicio7 = new Traducir( "Dar consejos o expresar obligacion", "You should visit that museum", "Deberias visitar ese museo");
          Traducir *ejercicio8 = new Traducir( "Imperativo", "Fale comigo", "Habla conmigo");

          // Agregamos ejercicios a lecciones correspondientes
          leccion1->agregarEjercicio(dynamic_cast<Ejercicio *>(ejercicio1));
          leccion1->agregarEjercicio(dynamic_cast<Ejercicio *>(ejercicio2));
          leccion2->agregarEjercicio(dynamic_cast<Ejercicio *>(ejercicio3));
          leccion2->agregarEjercicio(dynamic_cast<Ejercicio *>(ejercicio4));
          leccion3->agregarEjercicio(dynamic_cast<Ejercicio *>(ejercicio5));
          leccion5->agregarEjercicio(dynamic_cast<Ejercicio *>(ejercicio6));
          leccion6->agregarEjercicio(dynamic_cast<Ejercicio *>(ejercicio7));
          leccion7->agregarEjercicio(dynamic_cast<Ejercicio *>(ejercicio8));

          //--------INSCRIPCIONES--------//

          DTDate *fechaInscripcion1 = new DTDate(1, 1, 2022);
          DTDate *fechaInscripcion2 = new DTDate(12, 6, 2022);
          DTDate *fechaInscripcion3 = new DTDate(2, 3, 2023);
          DTDate *fechaInscripcion4 = new DTDate(2, 1, 2022);
          DTDate *fechaInscripcion5 = new DTDate(2, 1, 2022);
          DTDate *fechaInscripcion6 = new DTDate(3, 1, 2023);
          DTDate *fechaInscripcion7 = new DTDate(3, 1, 2023);
          DTDate *fechaInscripcion8 = new DTDate(5, 1, 2023);

          Inscripcion *inscripcion1 = new Inscripcion(fechaInscripcion1, false, usuario1, curso1);
          Inscripcion *inscripcion2 = new Inscripcion(fechaInscripcion2, false, usuario1, curso3);
          Inscripcion *inscripcion3 = new Inscripcion(fechaInscripcion3, false, usuario1, curso4);
          Inscripcion *inscripcion4 = new Inscripcion(fechaInscripcion4, false, usuario2, curso1);
          Inscripcion *inscripcion5 = new Inscripcion(fechaInscripcion5, false, usuario3, curso1);
          Inscripcion *inscripcion6 = new Inscripcion(fechaInscripcion6, false, usuario4, curso1);
          Inscripcion *inscripcion7 = new Inscripcion(fechaInscripcion7, false, usuario4, curso5);
          Inscripcion *inscripcion8 = new Inscripcion(fechaInscripcion8, false, usuario5, curso5);

          // Aprobaciones
          inscripcion1->aproboEjercicio();
          inscripcion1->aproboEjercicio();
          inscripcion1->aproboEjercicio();
          inscripcion1->aproboEjercicio();

          inscripcion2->aproboEjercicio();

          inscripcion4->aproboEjercicio();
          inscripcion4->aproboEjercicio();

          inscripcion5->aproboEjercicio();
          inscripcion5->aproboEjercicio();
          inscripcion5->aproboEjercicio();

          handlerCurso->agregarCurso(curso1);
          handlerCurso->agregarCurso(curso2);
          handlerCurso->agregarCurso(curso3);
          handlerCurso->agregarCurso(curso4);
          handlerCurso->agregarCurso(curso5);
          handlerCurso->agregarCurso(curso6);

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

          map<string, Curso *> cursos = handlerCurso->obtenerCursos();

          for (map<string, Curso *>::iterator it = cursos.begin(); it != cursos.end(); it++)
          {
               cout << it->first << endl;
          }

          cout << endl
               << "Idiomas disponibles:" << endl;
          cout << "-------------------" << endl;

          map<string, Idioma *> idiomas = handlerIdioma->obtenerIdiomas();

          for (map<string, Idioma *>::iterator it = idiomas.begin(); it != idiomas.end(); it++)
          {
               cout << it->first << endl;
          }

          cout << endl
               << "Inscripciones:" << endl;
          cout << "-------------------" << endl;

          DTInscripcion *dt1 = inscripcion1->getDTInscripcion();
          DTInscripcion *dt2 = inscripcion2->getDTInscripcion();
          DTInscripcion *dt3 = inscripcion3->getDTInscripcion();
          DTInscripcion *dt4 = inscripcion4->getDTInscripcion();
          DTInscripcion *dt5 = inscripcion5->getDTInscripcion();
          DTInscripcion *dt6 = inscripcion6->getDTInscripcion();
          DTInscripcion *dt7 = inscripcion7->getDTInscripcion();
          DTInscripcion *dt8 = inscripcion8->getDTInscripcion();

          cout << "Inscripción 1:" << endl;
          cout << *dt1 << endl;
          cout << "Inscripción 2:" << endl;
          cout << *dt2 << endl;
          cout << "Inscripción 3:" << endl;
          cout << *dt3 << endl;
          cout << "Inscripción 4:" << endl;
          cout << *dt4 << endl;
          cout << "Inscripción 5:" << endl;
          cout << *dt5 << endl;
          cout << "Inscripción 6:" << endl;
          cout << *dt6 << endl;
          cout << "Inscripción 7:" << endl;
          cout << *dt7 << endl;
          cout << "Inscripción 8:" << endl;
          cout << *dt8 << endl;

          delete dt1;
          delete dt2;
          delete dt3;
          delete dt4;
          delete dt5;
          delete dt6;
          delete dt7;
          delete dt8;
          

          delete inscripcion1;
          delete inscripcion2;
          delete inscripcion3;
          delete inscripcion4;
          delete inscripcion5;
          delete inscripcion6;
          delete inscripcion7;
          delete inscripcion8;


          sistema->setDatosCargados(); //Anotamos que ya se cargaron los datos de prueba
     }else{
          cout << "Los datos de prueba ya fueron cargados" << endl;
     }
}