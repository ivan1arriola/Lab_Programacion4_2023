# Variables
CXX = g++
CXXFLAGS = -std=c++11 -Wall
SRCDIR = src
OBJDIR = obj
BINDIR = bin
EXECUTABLE = $(BINDIR)/app
CASOSDEUSODIR = $(SRCDIR)/CasosDeUso

# Archivos fuente
MAIN = main.cpp

CPP_DATATYPES_FILES := $(SRCDIR)/datatypes/DTUsuario.cpp \
	$(SRCDIR)/datatypes/DTNotificacion.cpp \
	$(SRCDIR)/datatypes/DTDate.cpp \

CPP_CASOSDEUSO_FILES := $(CASOSDEUSODIR)/AltaDeUsuario.cpp \

CPP_CLASSES_FILES := $(SRCDIR)/classes/Usuario/Usuario.cpp \
	$(SRCDIR)/classes/Usuario/Estudiante.cpp \
	$(SRCDIR)/classes/Usuario/Profesor.cpp \
	$(SRCDIR)/classes/Idioma.cpp \

CPP_CONTROLLERS_FILES := $(SRCDIR)/controllers/ControladorUsuario.cpp 

CPP_FACTORY_FILES := $(SRCDIR)/factory/fabrica.cpp \

CPP_COLLECTIONS_FILES := $(SRCDIR)/collections/ColeccionIdioma.cpp \

CPP_FILES := $(MAIN) \
	$(SRCDIR)/operaciones.cpp \
	$(CPP_DATATYPES_FILES) \
	$(CPP_CASOSDEUSO_FILES) \
	$(CPP_CLASSES_FILES) \
	$(CPP_CONTROLLERS_FILES) \
	$(CPP_FACTORY_FILES) \
	$(CPP_COLLECTIONS_FILES) \



# Objetos
OBJECTS := $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(CPP_FILES))

# Regla principal
all: $(EXECUTABLE)

# Regla para el ejecutable
$(EXECUTABLE): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXECUTABLE)

# Regla para los objetos
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para limpiar los archivos generados
clean:
	rm -rf $(OBJDIR) $(EXECUTABLE) $(BINDIR)

run:
	@clear
	@./$(EXECUTABLE)