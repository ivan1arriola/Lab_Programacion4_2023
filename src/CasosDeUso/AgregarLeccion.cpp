#include <iostream>
#include <string>

#include "../../include/CasosDeUso/AgregarLeccion.h"

#include "../../include/factory/fabrica.h"
#include "../../include/operaciones.h"

#include "../../include/interfaces/IControladorCurso.h"
#include "../../include/interfaces/IControladorEstadistica.h"
#include "../../include/interfaces/IControladorUsuario.h"

using namespace std;

void AgregarLeccion() {
    imprimirMensaje("Agregar Lección");
}
