#include <gtest/gtest.h>
#include "DTNotificacion.h" // Incluye el archivo de encabezado del DTNotificacion

// Prueba para verificar el nombre del curso en DTNotificacion
TEST(DTNotificacionTest, GetNombreCurso) {
  // Crear una instancia de DTNotificacion
  DTNotificacion dtNotificacion("Curso A", "Español");

  // Verificar el valor del nombre del curso
  EXPECT_EQ(dtNotificacion.getNombreCurso(), "Curso A");
}

// Prueba para verificar el nombre del idioma en DTNotificacion
TEST(DTNotificacionTest, GetNombreIdioma) {
  // Crear una instancia de DTNotificacion
  DTNotificacion dtNotificacion("Curso B", "Inglés");

  // Verificar el valor del nombre del idioma
  EXPECT_EQ(dtNotificacion.getNombreIdioma(), "Inglés");
}

int main(int argc, char** argv) {
  // Inicializar el framework de pruebas
  ::testing::InitGoogleTest(&argc, argv);
  // Ejecutar las pruebas
  return RUN_ALL_TESTS();
}
