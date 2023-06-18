#ifndef CONTROLADORCURSO_H
#define CONTROLADORCURSO_H

#include "../interfaces/IControladorCurso.h"
#include "../classes/Idioma.h"

#include "../handlers/HandlerCurso.h"
#include "../handlers/HandlerUsuario.h"
#include "../handlers/HandlerIdioma.h"

#include "../enums/NIVEL.h"

class ControladorCurso : public IControladorCurso
{
private:
    string nombreIdioma;
    string nombreCurso;

    Usuario *usuarioActual;

    // Datos del curso actual
    string nombreCursoActual;
    string nicknameProfesorActual;
    string descripcionCursoActual;
    Nivel dificultadlCursoActual;
    Idioma *idiomaCursoActual;
    vector<Leccion *> leccionesCursoActual;

    // Datos de la leccion actual
    Leccion *leccionActual;

    // Datos del ejercicio actual
    Ejercicio *ejercicioActual;
    set<Ejercicio *> *ejerciciosLeccionActual;

    static ControladorCurso *instancia;

    // Colecion de cursos
    static HandlerCurso *coleccionCursos;

    // Coleccion de Usuarios
    static HandlerUsuario *coleccionUsuarios;

    // Coleccion de Idiomas
    static HandlerIdioma *coleccionIdiomas;

    ControladorCurso();

public:
    static IControladorCurso *getInstancia();

    set<string> obtenerCursos();
    string getNombreCurso();
    set<string> getDataCurso();
    string getNickProfesor();
    set<string> getNombresCursosPrevios();
    set<DTDataLeccion> getLecciones();
    void eliminarCurso(string nombre);
    void ingresarNicknameEstudiante(string nomEstudiante);
    set<string> listarCursosInscrip();
    set<string> mostrarCursosNoAprobados();
    set<string> mostrarEjerciciosNoAprobados();
    // DTEjercicio seleccionarEjercicio(string nombreEjercicio);
    void ingresarSolucionCompletar(set<string> solC);
    void ingresarSolucionTraducir(string solT);
    void marcarEjercicioAprobado();
    void marcarEjercicioNoAprobado();
    void setLeccionActual(Leccion *leccion);

    ~ControladorCurso(); // Destructor

    // Operaciones para Consulta Curso
    set<string> listarNombreCursos();
    DTDataCurso *mostrarDatosCurso();
    int cantidadDeLecciones();
    DTDataLeccion *mostrarDatosLeccion(int posicion);
    int cantidadDeEjerciciosLeccion(int posicion);
    set<DTEjercicio*> mostrarEjercicios(int posLeccion);
    set<DTInscripcion*> mostrarInscripciones();

    // Operaciones para Alta Curso
    void seleccionarProfesor(string nickname);
    void ingresarDatosCurso(string nombre, string descripcion, Nivel dificultad);
    void seleccionarIdioma(string nombreIdioma);
    set<string> listarCursosHabilitados();
    void seleccionarCurso(string nombreCurso);
    void agregarLeccion(string tema, string objetivo);
    void agregarEjercicio(string nombre, string tipoEjercicio, string descEjercicio);
    void altaCurso(bool disponible);
    void agregarFraseTraducir(string fraseATraducir, string fraseTraducida);
    void agregarFraseCompletar(string fraseACompletar, vector<string> palabras);

    //Operacion agregarLeccion
    void agregarLeccionACurso(Leccion *leccion);

    //Operaciones para agregarEjercicio
    //Lista los temas de cada leccion en orden
    vector<string> listarLecciones(Curso *curso);
    void darDeAltaCompletar(string descripcion, string fraseACompletar, vector<string> palabrasFaltantes);
    void darDeAltaTraducir(string descripcion, string fraseATraducir, string fraseTraducida);

    // operaciones para habilitar curso
    set<string> listarCursosNoHabilitados();
};

#endif
