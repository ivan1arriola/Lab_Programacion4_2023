# Variables
CXX = g++
CXXFLAGS = -std=c++11 -Wall -g -Werror
LDFLAGS =

SRCDIR = src
OBJDIR = obj
BINDIR = bin
EXECUTABLE = $(BINDIR)/app
CASOSDEUSODIR = $(SRCDIR)/system/useCases


# Archivos fuente
MAIN = main.cpp

CPP_DATATYPES_FILES := $(SRCDIR)/datatypes/DTUsuario.cpp \
	$(SRCDIR)/datatypes/DTEstudiante.cpp \
	$(SRCDIR)/datatypes/DTProfesor.cpp \
	$(SRCDIR)/datatypes/DTNotificacion.cpp \
	$(SRCDIR)/datatypes/DTDate.cpp \
	$(SRCDIR)/datatypes/DTEjercicio.cpp \
	$(SRCDIR)/datatypes/DTDataCurso.cpp \
	$(SRCDIR)/datatypes/DTDataLeccion.cpp \
	$(SRCDIR)/datatypes/DTDataInfoCurso.cpp \
	$(SRCDIR)/datatypes/DTInscripcion.cpp \
	$(SRCDIR)/datatypes/DTDataCursoEstudiante.cpp \
	$(SRCDIR)/datatypes/DTDataCursoAInscribir.cpp \
	$(SRCDIR)/datatypes/DTDataCursoProfesor.cpp \

CPP_CASOSDEUSO_FILES := $(CASOSDEUSODIR)/AltaDeUsuario.cpp \
	$(CASOSDEUSODIR)/AgregarEjercicio.cpp \
	$(CASOSDEUSODIR)/AgregarLeccion.cpp \
	$(CASOSDEUSODIR)/AltaDeCurso.cpp \
	$(CASOSDEUSODIR)/AltaDeIdioma.cpp \
	$(CASOSDEUSODIR)/ConsultaDeNotificaciones.cpp \
	$(CASOSDEUSODIR)/ConsultaDeUsuario.cpp \
	$(CASOSDEUSODIR)/ConsultarCurso.cpp \
	$(CASOSDEUSODIR)/ConsultarEstadisticas.cpp \
	$(CASOSDEUSODIR)/ConsultarIdiomas.cpp \
	$(CASOSDEUSODIR)/EliminarCurso.cpp \
	$(CASOSDEUSODIR)/EliminarSuscripciones.cpp \
	$(CASOSDEUSODIR)/HabilitarCurso.cpp \
	$(CASOSDEUSODIR)/InscribirseACurso.cpp \
	$(CASOSDEUSODIR)/RealizarEjercicio.cpp \
	$(CASOSDEUSODIR)/SuscribirseANotificaciones.cpp \

CPP_CLASSES_FILES := $(SRCDIR)/classes/Usuario/Usuario.cpp \
	$(SRCDIR)/classes/Usuario/Estudiante.cpp \
	$(SRCDIR)/classes/Usuario/Profesor.cpp \
	$(SRCDIR)/classes/Idioma.cpp \
	$(SRCDIR)/classes/Curso/Curso.cpp \
	$(SRCDIR)/classes/Curso/Leccion.cpp \
	$(SRCDIR)/classes/Curso/Ejercicio.cpp \
	$(SRCDIR)/classes/Curso/Completar.cpp \
	$(SRCDIR)/classes/Curso/Traducir.cpp \
	$(SRCDIR)/classes/Inscripcion.cpp \

CPP_CONTROLLERS_FILES := $(SRCDIR)/controllers/ControladorUsuario.cpp \
	$(SRCDIR)/controllers/ControladorCurso.cpp \
	$(SRCDIR)/controllers/ControladorEstadistica.cpp \

CPP_FACTORY_FILES := $(SRCDIR)/factory/Fabrica.cpp \

CPP_COLLECTIONS_FILES := $(SRCDIR)/handlers/HandlerIdioma.cpp \
	$(SRCDIR)/handlers/HandlerUsuario.cpp \
	$(SRCDIR)/handlers/HandlerCurso.cpp \

CPP_FILES := $(MAIN) \
	$(SRCDIR)/system/operaciones.cpp \
	$(SRCDIR)/system/Sistema.cpp \
	$(CPP_DATATYPES_FILES) \
	$(CPP_CASOSDEUSO_FILES) \
	$(CPP_CLASSES_FILES) \
	$(CPP_CONTROLLERS_FILES) \
	$(CPP_FACTORY_FILES) \
	$(CPP_COLLECTIONS_FILES) \
	$(CASOSDEUSODIR)/CargarDatosDePrueba.cpp \

# Objetos
OBJECTS := $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(CPP_FILES))

# Regla principal
rebuild: clean build

build: $(EXECUTABLE)

# Regla para el ejecutable
$(EXECUTABLE): $(OBJECTS)
	@clear
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECTS) -o $(EXECUTABLE)

# Regla para los objetos
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para limpiar los archivos generados
clean:
	rm -rf $(OBJDIR) $(EXECUTABLE) $(BINDIR)

run: $(EXECUTABLE)
	@clear
	@./$(EXECUTABLE)

valgrind: $(EXECUTABLE)
	@clear
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(EXECUTABLE)



