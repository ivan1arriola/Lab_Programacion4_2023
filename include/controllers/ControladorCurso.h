#ifndef CONTROLADORCURSO_H
#define CONTROLADORCURSO_H

#include "../interfaces/IControladorCurso.h"
#include "../classes/Idioma.h"

#include "../handlers/HandlerCurso.h"
#include "../handlers/HandlerUsuario.h"
#include "../handlers/HandlerIdioma.h"

#include "../enums/NIVEL.h"

class ControladorCurso : public IControladorCurso {
private:
    string nombreIdioma;
    string nombreCurso;

    Usuario* usuarioActual;

    // Datos del curso actual
    string nombreCursoActual;
    string nicknameProfesorActual;
    string descripcionCursoActual;
    Nivel dificultadlCursoActual;
    Idioma* idiomaCursoActual;
    vector<Leccion*> leccionesCursoActual;

    static ControladorCurso* instancia;

    // Colecion de cursos
    static HandlerCurso* coleccionCursos;

    // Coleccion de Usuarios
    static HandlerUsuario* coleccionUsuarios;

    // Coleccion de Idiomas
    static HandlerIdioma* coleccionIdiomas;

    ControladorCurso();

public:
    static IControladorCurso* getInstancia();

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
    DTEjercicio seleccionarEjercicio(string nombreEjercicio);
    void ingresarSolucionCompletar(set<string> solC);
    void ingresarSolucionTraducir(string solT);
    void marcarEjercicioAprobado();
    void marcarEjercicioNoAprobado();

    ~ControladorCurso();  // Destructor

    //Operaciones para Consulta Curso
    set<string> listarNombreCursos();
    DTDataCurso* mostrarDatosCurso(); 

    //Operaciones para Alta Curso
    void seleccionarProfesor(string nickname);
    void ingresarDatosCurso(string nombre, string descripcion, Nivel dificultad);
    void seleccionarIdioma(string nombreIdioma);
    set<string> listarCursosHabilitados();
    void seleccionarCurso(string nombreCurso);
    void agregarLeccion(string tema, string objetivo);
    void agregarEjercicio(string tipoEjercicio, string descEjercicio);
    void altaCurso(bool disponible);

    //operaciones para habilitar curso
    set<string> listarCursosNoHabilitados();
};

#endif
