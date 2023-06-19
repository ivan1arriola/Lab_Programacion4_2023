# Variables
CXX = g++
CXXFLAGS = -std=c++11 -Wall -g -Werror
LDFLAGS =

SRCDIR = src
OBJDIR = obj
BINDIR = bin
EXECUTABLE = $(BINDIR)/app
CASOSDEUSODIR = $(SRCDIR)/system/useCases

TESTENTRADADIR = test/entrada
TESTSALIDADIR = test/salida

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


create_dirs:
	@mkdir -p $(TESTSALIDADIR)

test: $(EXECUTABLE) create_dirs test1 test2 test3 test4

test1: $(EXECUTABLE) create_dirs
	@valgrind --leak-check=full ./$(EXECUTABLE) < $(TESTENTRADADIR)/test1.in > $(TESTSALIDADIR)/test1.out 2> $(TESTSALIDADIR)/test1_valgrind.out
	@if grep -q "no leaks are possible" $(TESTSALIDADIR)/test1_valgrind.out; then \
		echo "No se encontraron fugas de memoria en test1"; \
	else \
		echo "Se detectaron fugas de memoria en test1"; \
	fi

test2: $(EXECUTABLE) create_dirs
	@valgrind --leak-check=full ./$(EXECUTABLE) < $(TESTENTRADADIR)/test2.in > $(TESTSALIDADIR)/test2.out 2> $(TESTSALIDADIR)/test2_valgrind.out
	@if grep -q "no leaks are possible" $(TESTSALIDADIR)/test2_valgrind.out; then \
		echo "No se encontraron fugas de memoria en test2"; \
	else \
		echo "Se detectaron fugas de memoria en test2"; \
	fi

test3: $(EXECUTABLE) create_dirs
	@valgrind --leak-check=full ./$(EXECUTABLE) < $(TESTENTRADADIR)/test3.in > $(TESTSALIDADIR)/test3.out 2> $(TESTSALIDADIR)/test3_valgrind.out
	@if grep -q "no leaks are possible" $(TESTSALIDADIR)/test3_valgrind.out; then \
		echo "No se encontraron fugas de memoria en test3"; \
	else \
		echo "Se detectaron fugas de memoria en test3"; \
	fi

test4: $(EXECUTABLE) create_dirs
	@valgrind --leak-check=full ./$(EXECUTABLE) < $(TESTENTRADADIR)/test4.in > $(TESTSALIDADIR)/test4.out 2> $(TESTSALIDADIR)/test4_valgrind.out
	@if grep -q "no leaks are possible" $(TESTSALIDADIR)/test4_valgrind.out; then \
		echo "No se encontraron fugas de memoria en test4"; \
	else \
		echo "Se detectaron fugas de memoria en test4"; \
	fi