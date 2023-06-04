#include <iostream>
#include <string>

#include "../../../include/system/Sistema.h"

#include "../../../include/factory/fabrica.h"
#include "../../../include/system/operaciones.h"

#include "../../../include/interfaces/IControladorCurso.h"
#include "../../../include/interfaces/IControladorEstadistica.h"
#include "../../../include/interfaces/IControladorUsuario.h"

using namespace std;

void Sistema::habilitarCurso() {
    imprimirMensaje("Habilitar Curso");
}
