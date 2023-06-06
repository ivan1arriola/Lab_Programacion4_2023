#ifndef CONTROLADORCURSO_H
#define CONTROLADORCURSO_H

#include "../interfaces/IControladorCurso.h"

class ControladorCurso : public IControladorCurso {
private:
    string nombreIdioma;
    string nombreCurso;
    static ControladorCurso* instancia;

    ControladorCurso();

public:
    static IControladorCurso* getInstancia();

    set<string> listarCursosHabilitados();
    void seleccionarIdioma(string nombreIdioma);
    void seleccionarCurso(string nombreCurso);
    void altaCurso(bool disponible);
    set<string> obtenerCursos();
    string getNombreCurso();
    set<string> getDataCurso();
    string getNickProfesor();
    set<string> getNombresCursosPrevios();
    set<DTDataLeccion> getLecciones();
    void eliminarCurso(string nombre);
    void agregarLeccion(string tema, string objetivo);
    void agregarEjercicio(string tipoEjercicio, string descEjercicio);
    void ingresarNicknameEstudiante(string nomEstudiante);
    void ingresarDatosCurso(string nombre, string desc, string dificultad);
    set<string> listarCursosInscrip();
    set<string> mostrarCursosNoAprobados();
    set<string> mostrarEjerciciosNoAprobados();
    DTEjercicio seleccionarEjercicio(string nombreEjercicio);
    void ingresarSolucionCompletar(set<string> solC);
    void ingresarSolucionTraducir(string solT);
    void marcarEjercicioAprobado();
    void marcarEjercicioNoAprobado();

    ~ControladorCurso();  // Destructor
};

#endif
