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


CPP_FILES := $(MAIN) \
	$(SRCDIR)/operaciones.cpp \
	$(SRCDIR)/factory/fabrica.cpp \
	$(SRCDIR)/controllers/ControladorUsuario.cpp \
	$(SRCDIR)/datatypes/DTUsuario.cpp \
	$(SRCDIR)/classes/Idioma.cpp \
	$(SRCDIR)/collections/ColeccionIdioma.cpp \

CPP_FILES += $(CASOSDEUSODIR)/AltaDeUsuario.cpp


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