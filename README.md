# Laboratorio de Programación 4 - FING - 2023 - Grupo 01

## Laboratorio 4 - Implementación
Fecha Límite - lunes, 19 de junio de 2023, 15:00

[Letra del laboratorio](https://drive.google.com/file/d/1Y0D_zd7lZzLsieHDqj8DCGuhldjupDoa/view?usp=sharing)

### Makefile

Este es un Makefile utilizado para compilar y ejecutar este proyecto. Para utilizarlo, es necesario tener instalado GNU Make y g++.

El Makefile tiene las siguientes reglas:

- `rebuild`: Limpia los archivos generados y compila nuevamente el programa.
- `build`: Compila el programa sin limpiar los archivos generados.
- `clean`: Elimina los archivos generados por la compilación.
- `run`: Compila y ejecuta el programa.
- `valgrind`: Ejecuta el programa utilizando Valgrind para detectar fugas de memoria.

- `test`: Ejecuta los tests unitarios.

Para utilizar una regla, simplemente ejecuta el comando `make` seguido del nombre de la regla. Por ejemplo, para compilar y ejecutar el programa, puedes ejecutar el siguiente comando:

```
make run
```

Ejecutar el comando `make` sin argumentos ejecutará la regla `rebuild`.

Los warnings se tratan como errores, por lo que si el programa no compila, es necesario corregir los warnings.

### Todos los casos de uso
- :memo: Alta de usuario  :white_check_mark:
- Consulta de usuario :white_check_mark:
- Alta de idioma :white_check_mark:
- Consultar idiomas :white_check_mark:
- :memo: Alta de curso  :white_check_mark:
- Agregar lección
- Agregar ejercicio
- Habilitar curso :white_check_mark:
- :memo: Eliminar curso
- Consultar curso  :warning:
- Inscribirse a curso
- :memo: Realizar ejercicio
- :memo: Consultar estadísticas
- :memo: Suscribirse a notificaciones :white_check_mark:
- :memo: Consulta de notificaciones :white_check_mark:
- :memo: Eliminar suscripciones :white_check_mark:

Los casos de uso marcados con :memo: tienen sus diagramas de comunicación desde el laboratorio 3.
Los casos de uso marcados con :white_check_mark: están implementados.
Los casosd de uso que estan a medio implementar tienen un :warning:.

Se debe modificar los archivos .h y .cpp de cada caso de uso, y agregar los archivos .h y .cpp de cada entidad que se necesite.
Después, se tiene que modificar el Makefile para que compile los archivos nuevos.

#### Diagramas nuevos
- Alta de idioma - [Diagrama de comunicación](https://lucid.app/lucidchart/bd189033-7811-47d9-8ed5-b375405f4afd/edit?viewport_loc=89%2C-35%2C1966%2C1054%2C0_0&invitationId=inv_79068b57-019b-4de9-a9d3-1806658e2078)

## Laboratorio 3 - Diseño
- [Entrega Lab3 PDF](https://drive.google.com/file/d/1eTmGxfd2WR2FJMvlEBxYaVORVtMyeBVh/view?usp=drive_link)
- [Documento de Word](https://finguy-my.sharepoint.com/:w:/g/personal/ivan_arriola_fing_edu_uy/ERzphtEka7JFuR_Gi3pB9pABNgsM6_nyMeSTR1DvscjRQQ?e=WfN7dr)
- [Letra PDF](https://drive.google.com/file/d/17chVHTmNlhoKWHBJRXUi1Gq9RBr7hDw0/view?usp=drive_link)
- [Carpeta General de archivos del laboratorio](https://drive.google.com/drive/folders/17ClHWC9tWL7NhrbmM17Po3jbBHjzcfmm?usp=sharing) en Drive para subir las imágenes de los diagramas, los enlaces, archivos de drawio, etc.
- [Diagrama De Clase de Diseño](https://lucid.app/lucidchart/3458c2c8-6672-4edd-9548-c3d645f5ea91/edit?invitationId=inv_7c7f22eb-924c-46ee-8132-b38194db2913)

### Diagramas de Comunicación por Caso de Uso

#### Alta de usuario
- Alta Estudiante
- Ingresar Datos Profesor
- Alta Profesor
- Ingresar Usuario
- Ingresar Datos Estudiante
- Listar Nombres de Idiomas Disponibles
- Seleccionar Idiomas

#### Alta de curso
- Agregar Ejercicio
- Alta curso
- Listar Nicknames Profesores
- Listar Nombres Idiomas Profesor
- Seleccionar Curso
- Agregar Leccion
- Seleccionar Idioma
- Listar Cursos Habilitados
- Seleccionar Profesor
- Ingresar Datos Curso
- Ingresar Frase Completar
- Ingresar Frase Traducir
- Agregar Ejercicio a Leccion

#### Eliminar curso
- Obtener Cursos
- Eliminar Curso

#### Realizar ejercicio
- Ingresar Nickname Estudiante
- Listar Cursos Inscriptos
- Mostrar Cursos No Aprobados
- Seleccionar Curso
- Mostrar Ejercicio No Aprobados
- Seleccionar Ejercicio
- Mostrar Ejercicio
- Ingresar Sol Completar
- Ingresar Sol Traducir
- Marcar Ejercicio Aprobado
- Marcar Ejercicio No Aprobado

#### Consultar estadísticas
- Listar Nicknames Estudiantes
- Seleccionar Estudiante
- Listar Cursos Estudiante
- Listar Nickname Profesores
- Seleccionar Profesor
- Listar Cursos Profesor
- Listar Cursos
- Seleccionar Curso
- Listar Info Curso

#### Suscribirse a notificaciones
- Listar Idiomas No Suscriptos
- Suscribirse

#### Consulta de notificaciones
- Listar Notificaciones
- Eliminar Notificaciones

#### Eliminar suscripciones
- Listar Idiomas Suscriptos
- Eliminar Suscripcion

## Laboratorio 2 - Análisis
- [Entrega Lab2 PDF](https://drive.google.com/file/d/1CClxYtyDUOQkkNU7UJgjDbDdh5msP9KP/view?usp=drive_link)
- [Documento de Word](https://onedrive.live.com/edit.aspx?resid=4E0A101CDC8F4A2F!189&ithint=file%2cdocx&authkey=!AKC4te03l7HlkPA)
- [Letra de Laboratorio](https://drive.google.com/file/d/1pWrl68r8fAUNFgne8Zzs5a3b1wM2B2w1/view?usp=sharing)

## Laboratorio 1 - Análisis
- [Entrega Lab 1 PDF](https://drive.google.com/file/d/1GlqOHeRIDiy9trB3AGfMMIMgmW7wOcyM/view?usp=drive_link)
- [Diagrama de Laboratorio 1](https://lucid.app/documents/view/f7ecc9ab-83bd-4ba7-abec-bfbdf07caae4).

