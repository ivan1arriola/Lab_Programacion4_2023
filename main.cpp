#include <string>
#include <iostream>

#include "include/factory/fabrica.h"
#include "include/operaciones.h"

#include "include/interfaces/IControladorCurso.h"
#include "include/interfaces/IControladorUsuario.h"
#include "include/interfaces/IControladorEstadistica.h"

using namespace std;


int main() {
    Fabrica* fabrica = Fabrica::getInstancia();

    IControladorUsuario* controladorUsuario = fabrica->getIControladorUsuario();
    //IControladorCurso* controladorCurso = fabrica->getIControladorCurso();
    //IControladorEstadistica* controladorEstadistica = fabrica->getIControladorEstadistica();


    mensajeDeBienvenida();
    menuDeOpciones();
    int opcion = ingresarOpcion(16);
    bool quiereSalir = opcion == 0;
    cout << "--------------------------------------" << endl;

    while (!quiereSalir) {
        switch (opcion) {
            case 0 : {
                cout << "Saliendo..." << endl;
                quiereSalir = true;
                break;
            }
            case 1: {
                cout << "Alta de usuario" << endl;


                cout << "Ingrese el nickname: ";
                string nickname;
                cin >> nickname;
                cout << endl;

                string password;
                do {
                    cout << "Ingrese el password: ";
                    cin >> password;
                    cout << endl;
                    if (password.length() < 6) {
                        cout << "El password debe tener al menos 6 caracteres" << endl;
                    }
                }while (password.length() < 6);
                

                cout << "Ingrese el nombre: ";
                string name;
                cin >> name;
                cout << endl;
                cout << "Ingrese la descripcion: ";
                string descripcion;
                cin >> descripcion;
                cout << endl;

                cout << nickname << " - " << password << " - " << name << " - " << descripcion << endl;
                //

                
                controladorUsuario->ingresarUsuario(nickname,password,name,descripcion);
                cout << "Tipo de usuario: " << endl;
                cout << "0. Profesor" << endl;
                cout << "1. Estudiante" << endl;

                int tipoUsuario = ingresarOpcion(1);
                cout << endl;

                if (tipoUsuario == 0) {
                    cout << "Ingrese el instituto: ";
                    string instituto;
                    cin >> instituto;
                    cout << endl;
                    controladorUsuario->ingresarDatosProfesor(instituto);


                    cout << "Lista de Idiomas disponibles " << endl;
                    set<string> idiomas = controladorUsuario->listarNombresDeIdiomasDisponibles();
                    imprimirSet(idiomas);

                    cout << "Ingrese el idioma: ";
                    string idioma;

                    controladorUsuario->seleccionarIdioma(idioma);

                    break;
                } else {
                    cout << "Ingrese el pais: ";
                    string pais;
                    cin >> pais;
                    cout << endl;
                    controladorUsuario->ingresarDatosEstudiante(pais);
                    controladorUsuario->altaEstudiante();
                    cout << "Estudiante creado con exito" << endl;
                }

                break;
            }
            case 2: {
                cout << "Consulta de usuario" << endl;
                break;
            }
            case 3: {
                cout << "Alta de idioma" << endl;
                break;
            }
            case 4: {
                cout << "Consultar idiomas" << endl;
                break;
            }
            case 5: {
                cout << "Alta de curso" << endl;
                break;
            }
            case 6: {
                cout << "Agregar lección" << endl;
                break;
            }
            case 7: {
                cout << "Agregar ejercicio" << endl;
                break;
            }
            case 8: {
                cout << "Habilitar curso" << endl;
                break;
            }
            case 9: {
                cout << "Eliminar curso" << endl;
                break;
            }
            case 10: {
                cout << "Consultar curso" << endl;
                break;
            }
            case 11: {
                cout << "Inscribirse a curso" << endl;
                break;
            }
            case 12: {
                cout << "Realizar ejercicio" << endl;
                break;
            }
            case 13: {
                cout << "Consultar estadísticas" << endl;
                break;
            }
            case 14: {
                cout << "Suscribirse a notificaciones" << endl;
                break;
            }
            case 15: {
                cout << "Consulta de notificaciones" << endl;
                break;
            }
            case 16: {
                cout << "Eliminar suscripciones" << endl;
                break;
            }
            default: {
                continue;
            }
        }
        cout << endl << "--------------------------------------" << endl;
        if (!quiereSalir) {
            quiereSalir = deseaContinuar() == 0;
            if (!quiereSalir) {
                menuDeOpciones();
                opcion = ingresarOpcion(16);
            }
        }
    }

    cout << "Gracias por utilizar la aplicacion" << endl;
}
