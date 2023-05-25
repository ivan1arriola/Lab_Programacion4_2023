# prog4_2023_gr01

# Laboratorio 4 - Implementacion

# Laboratorio 3 - Diseño
[Documento de Word](https://finguy-my.sharepoint.com/:w:/g/personal/ivan_arriola_fing_edu_uy/ERzphtEka7JFuR_Gi3pB9pABNgsM6_nyMeSTR1DvscjRQQ?e=WfN7dr)

[Letra PDF](https://drive.google.com/file/d/17chVHTmNlhoKWHBJRXUi1Gq9RBr7hDw0/view?usp=drive_link)

[Carpeta General de archivos del laboratorio](https://drive.google.com/drive/folders/17ClHWC9tWL7NhrbmM17Po3jbBHjzcfmm?usp=sharing) en Drive para subir las imagenes de los diagramas, los links, archivos de drawio, etc

## Patrones de disenio utilizados
Para cada patrón, indicar las clases participantes y sus
roles, y justificar brevemente por qué resuelven los requerimientos.

### Observer
Se utilizo este patron para resolver el requerimiento de que los Usuarios sean notificados cuando se creen nuevos cursos del idioma de preferencia.
Las clases participantes son:
- Usuario : Observer Concreto
- Idioma como subject

Solucionan el problema porque cuando se cree un nuevo curso c, c va a mandar un mensaje a su Idioma y este mandara un mensaje a todos los suscriptores (Observer concreto) y solamente a esos. Como el orden en que los notifiquen no es relevante, esa contra del patron tampoco lo es.

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
Estan los diagramas de
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

Falta revisar todos los diagramas, a la mayoria le falta cosas para corregir y agregar al word los diagramas

Faltan los diagramas de  :exclamation:
- Ingresar Frase Completar
- Ingresar Frase Traducir
- Agregar Ejercicio a Leccion

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
Diagramas a revisar:
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


## Diagramas de clases de diseño

- [Carpeta DSS](https://drive.google.com/drive/folders/1uUdIckAbFp5WeqigkbeunN73zlCOnq3l?usp=drive_link)
- [De Casos de Uso relacionadas con Usuario y Cursos](https://lucid.app/lucidchart/3458c2c8-6672-4edd-9548-c3d645f5ea91/edit?invitationId=inv_7c7f22eb-924c-46ee-8132-b38194db2913)
- [De Casos de Uso relacionadas con Notificaciones](https://lucid.app/lucidchart/ec928ee1-b2e1-493d-af6f-04e33d4db0f4/edit?beaconFlowId=89A312D3D24096BB&invitationId=inv_d7de60fd-94c8-461d-99a0-59f2e8f117c1&page=0_0#)


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

# Laboratorio 1 - Analisis

[Diagrama de Laboratorio 1](https://lucid.app/documents/view/f7ecc9ab-83bd-4ba7-abec-bfbdf07caae4).

