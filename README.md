# prog4_2023_gr01

# Laboratorio 4 - Implementacion
Fecha Limite - lunes, 19 de junio de 2023, 15:00

[Letra del laboratorio](https://drive.google.com/file/d/1Y0D_zd7lZzLsieHDqj8DCGuhldjupDoa/view?usp=sharing)

## Funciones de Makefile
- `make build` o `make` : compila el programa
- `make run` : compila y ejecuta el programa
- `make clean` : borra los archivos .o y el ejecutable
- `make valgrind` : compila y ejecuta el programa con valgrind

Ejecutar `make clean build run` para compilar en limpio y ejecutar el programa.
Ejecutar `make clean build valgrind` para compilar en limpio y ejecutar el programa con valgrind.


## Todos los casos de uso
- Alta de usuario [✓]
- Consulta de usuario
- Alta de idioma - [Diagrama de comunicacion](https://lucid.app/lucidchart/bd189033-7811-47d9-8ed5-b375405f4afd/edit?viewport_loc=89%2C-35%2C1966%2C1054%2C0_0&invitationId=inv_79068b57-019b-4de9-a9d3-1806658e2078)
- Consultar idiomas
- Alta de curso [✓]
- Agregar lección
- Agregar ejercicio
- Habilitar curso
- Eliminar curso [✓]
- Consultar curso
- Inscribirse a curso
- Realizar ejercicio [✓]
- Consultar estadísticas [✓]
- Suscribirse a notificaciones [✓]
- Consulta de notificaciones [✓]
- Eliminar suscripciones [✓]

Los casos de uso marcados con [✓] tienen sus diagramas de comunicacion desde el laboratorio 3.

Se debe modificar los archivos .h y .cpp de cada caso de uso, y agregar los archivos .h y .cpp de cada entidad que se necesite.
Despues se tiene que modificar el Makefile para que compile los archivos nuevos.


# Laboratorio 3 - Diseño
[Documento de Word](https://finguy-my.sharepoint.com/:w:/g/personal/ivan_arriola_fing_edu_uy/ERzphtEka7JFuR_Gi3pB9pABNgsM6_nyMeSTR1DvscjRQQ?e=WfN7dr)

[Letra PDF](https://drive.google.com/file/d/17chVHTmNlhoKWHBJRXUi1Gq9RBr7hDw0/view?usp=drive_link)

[Carpeta General de archivos del laboratorio](https://drive.google.com/drive/folders/17ClHWC9tWL7NhrbmM17Po3jbBHjzcfmm?usp=sharing) en Drive para subir las imagenes de los diagramas, los links, archivos de drawio, etc

## Diagramas de clases de diseño

- [Diagrama](https://lucid.app/lucidchart/3458c2c8-6672-4edd-9548-c3d645f5ea91/edit?invitationId=inv_7c7f22eb-924c-46ee-8132-b38194db2913)





## Patrones de disenio utilizados
Para cada patrón, indicar las clases participantes y sus
roles, y justificar brevemente por qué resuelven los requerimientos.

### Observer
Se utilizo este patron para resolver el requerimiento de que los Usuarios sean notificados cuando se creen nuevos cursos del idioma de preferencia.
Las clases participantes son:
- Usuario : Observer Concreto
- Idioma como subject

Solucionan el problema porque cuando se cree un nuevo curso c, c va a mandar un mensaje a su Idioma y este mandara un mensaje a todos los suscriptores (Observer concreto) y solamente a esos. Como el orden en que los notifiquen no es relevante, esa contra del patron tampoco lo es.

### Singleton
Se utilizo este patron para todos los controladores 

## Notas
- Agregar al documento los links de los diagramas si es posible, sino agregar las imagenes a la carpeta correspondiente

## Cambios a Diagrama de dominio


## Diagramas de Comunicacion por Caso de Uso

:question: : puede ser que se repita el diagrama en otro caso de uso, hay que verificar

### Alta de usuario

Diagramas listos :
- Alta Estudiante
- Ingresar Datos Profesor
- Alta Profesor
- Ingresar Usuario
- Ingresar Datos Estudiante
- Listar Nombres de Idiomas Disponibles
- Seleccionar Idiomas


**Links**
- [Carpeta de Alta Usuario](https://drive.google.com/drive/folders/129GjvqSSXX7ejyN_UdrQX64P6pqmUhJj?usp=drive_link)
- [Diagrama de Comunicación - Alta Curso (Enlace 1)](https://lucid.app/lucidchart/f68b4506-f530-42a7-a476-2227b60930d5/edit?invitationId=inv_e2a321f6-bd07-4022-8b62-1b5e65a9c7b2&page=0_0#)
- [Diagrama de Comunicación - Alta Curso (Enlace 2)](https://lucid.app/lucidchart/42ae0698-8f82-4362-b670-18e559e35f56/edit?invitationId=inv_83e9943e-9093-4a3c-b684-1f57194674bb&page=0_0#)

### Alta de curso
-PRONTO
-Link con imagenes de diagramas: estan en wspp

**Modificar DSS**


**Links**
- [Carpeta de Alta Curso](https://drive.google.com/drive/folders/1x3qob5hBnLBHIWwY4TKMzlRSvM-2O92X?usp=drive_link)


### Eliminar curso
Estan los diagramas de 
- Obtener Cursos :question:
- Eliminar Curso

**Hay que modificar DSS**

**Links**
- [Carpeta de Eliminar Curso](https://drive.google.com/drive/folders/1olwpiMdvbLemWOtkZCZkNVFGH4g63wrp?usp=drive_link)
- [Diagrama de Comunicación - Eliminar Curso](https://lucid.app/lucidchart/7c05ec32-10eb-4785-9fb7-40e911fd5f62/edit?invitationId=inv_a0bfb6a7-8bc2-4e49-9ad1-62a6fde43fbf&page=0_0#)

### Realizar ejercicio

Faltan los diagramas de :exclamation:
- Ingresar Nickname Estudiante
- Listar Cursos Inscriptos
- MOstrar Cursos No Aprobados
- Seleccionar Curso :question:
- Mostrar Ejercicio No Aprobados
- Seleccionar Ejercicio
- Mostrar Ejercicio
- Ingresar Sol Completar
- Ingresar SOl Traducir
- Marcar Ejercicio Aprobado
- Marcar Ejercicio No Aprobado

**Links**
- [Carpeta de Realizar Ejercicio](https://drive.google.com/drive/folders/1O_mDEhTe_gN43leJtgKYpNqjM5islF_S?usp=drive_link)

### Consultar estadísticas

Faltan los diagramas de :exclamation:
- Listar Nicknames Estudiantes :question:
- Seleccionar Estudiante :question:
- Listar Cursos Estudiante 
- Listar Nickname Profesores :question:
- Seleccionar Profesor :question:
- Listar Cursos Profesor
- Listar Cursos :question:
- Seleccionar Curso :question:
- Listar Info Curso

**Links**
- [Carpeta de Consultar Estadisticas](https://drive.google.com/drive/folders/1O_mDEhTe_gN43leJtgKYpNqjM5islF_S?usp=drive_link)

### Suscribirse a notificaciones
Diagramas a revisar:
- Listar Idiomas No Suscriptos
- Suscribirse


**Links**
- [Carpeta de Suscribirse a Notificaciones](https://drive.google.com/drive/folders/17z85Q0oAVJleJuyoMyA8pzuV1rxuApFu?usp=drive_link)
- [Diagrama de Comunicacion](https://lucid.app/lucidchart/2533be8a-4594-47a5-89ec-2eece39a3e47/edit?viewport_loc=-19%2C162%2C1972%2C1057%2C0_0&invitationId=inv_ee1a0240-7630-40fb-a37c-be860d53ec14)

### Consulta de notificaciones
Diagramas listos
- Listar Notificaciones
- Eliminar Notificaciones

**Links**
- [Carpeta de Consultar Notificaciones](https://drive.google.com/drive/folders/1bzpz8-GWqc40va9V2jWk0G_gajwG113L?usp=drive_link)

### Eliminar suscripciones
Faltan los diagramas de :exclamation:
- Listar Idiomas Suscriptos
- Eliminar Suscripcion // En el dss esta en plural pero mejor implementarlo como una funcion que se ejecuta una vez por suscripcion

**Links**
- [Carpeta de Eliminar Suscripciones](https://drive.google.com/drive/folders/13knw99Zy6G8XyoVpBiymcwdVwUXX9RwY?usp=drive_link)
- [Diagrama de comunicacion](https://drive.google.com/drive/folders/13knw99Zy6G8XyoVpBiymcwdVwUXX9RwY)




## Letra

1. Analizar el impacto de los nuevos requerimientos en el modelo de dominio y diagramas de
secuencia de casos de uso realizados en los laboratorios anteriores. Agregar una sección en el
documento de entrega donde se indican los cambios identificados junto a una explicación breve.
La explicación puede hacer mención a cambios necesarios en conceptos, datatypes u
operaciones (parámetros, resultado, pre/post-condiciones, etc).
2. Aplicar patrones de diseño para resolver los requerimientos solicitados en la etapa actual.
3. Realizar los diagramas de comunicación de las operaciones del sistema de los casos de uso
pedidos, mostrando en los diagramas el tipo de visibilidad que existe sobre el objeto al que se
le envía un mensaje.
4. Realizar el diseño de la estructura (Diagrama de Clases de Diseño) correspondiente a las
interacciones diseñadas (un único diagrama para todo el diseño de interacciones).
5. Agregar una sección en el documento explicando qué criterios GRASP fueron considerados y
qué patrones de diseño se utilizaron. Para cada patrón, indicar las clases participantes y sus
roles, y justificar brevemente por qué resuelven los requerimientos. 




# Laboratorio 2 - Analisis 
[Documento de Word](https://onedrive.live.com/edit.aspx?resid=4E0A101CDC8F4A2F!189&ithint=file%2cdocx&authkey=!AKC4te03l7HlkPA)
[Letra de Laboratorio](https://drive.google.com/file/d/1pWrl68r8fAUNFgne8Zzs5a3b1wM2B2w1/view?usp=sharing)

# Laboratorio 1 - Analisis

[Diagrama de Laboratorio 1](https://lucid.app/documents/view/f7ecc9ab-83bd-4ba7-abec-bfbdf07caae4).

