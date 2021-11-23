#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "libro.h"

eLibros* eLibro_new() {
	eLibros *nuevoLibro = NULL;
	nuevoLibro = (eLibros*) malloc(sizeof(eLibros));

	if (nuevoLibro != NULL) {

		libro_setId(nuevoLibro, 0);
		libro_setAutor(nuevoLibro, " ");
		libro_setEditorial(nuevoLibro, " ");
		libro_setPrecio(nuevoLibro, 0);
	}
	return nuevoLibro;
}
eLibros* libros_newParam(char *id, char *titulo,char *autor, char *precio, char*editorial) {
	eLibros *nuevoLibro = NULL;

	if (id != NULL && titulo != NULL && autor  != NULL && precio != NULL && editorial!= NULL) {
		nuevoLibro = eLibro_new();
		if (nuevoLibro != NULL) {
			if (libro_setAutor(nuevoLibro,(autor ))== 1 || libro_setId(nuevoLibro, atoi(id)) == 1|| libro_setTitulo(nuevoLibro, titulo) == 1|| libro_setEditorial(nuevoLibro, editorial) == 1|| libro_setPrecio(nuevoLibro, atoi(precio)) == 1) {
				printf("Fallo algun setter\n");
				free(nuevoLibro);
				nuevoLibro = NULL;
			}
		}
	}
	return nuevoLibro;
}

int libro_setId(eLibros *this, int id) {
	int retorno = -1;

	if (this != NULL) {
		this->id_Libro = id;
		retorno = 0;
	}

	return retorno;
}

int libro_getId(eLibros *this, int *id) {
	int retorno = -1;

	if (this != NULL && id != NULL) {
		*id = this->id_Libro;
		retorno = 0;
	}

	return retorno;
}



int libro_setEditorial(eLibros *this, char *editorial) {
	int retorno = -1;

	if (this != NULL && editorial != NULL) {
		strcpy(this->editorialId, editorial);
		retorno = 0;
	}

	return retorno;
}

int libro_getEditorial(eLibros *this, char *editorial) {
	int retorno = -1;

	if (this != NULL && editorial != NULL) {
		strcpy(editorial, this->editorialId);
		retorno = 0;
	}

	return retorno;
}
int libro_setPrecio(eLibros *this, int precio) {
	int retorno = -1;

	if (this != NULL) {
		this->precio = precio;
		retorno = 0;
	}

	return retorno;
}

int libro_getPrecio(eLibros *this, int *precio) {
	int retorno = -1;

	if (this != NULL && precio != NULL) {
		*precio = this->precio;
		retorno = 0;
	}

	return retorno;
}

int libro_setTitulo(eLibros *this, char *titulo) {
	int retorno = -1;

	if (this != NULL && titulo != NULL) {
		strcpy(this->titulo, titulo);
		retorno = 0;
	}

	return retorno;
}

int libro_getTitulo(eLibros *this, char *titulo) {
	int retorno = -1;

	if (this != NULL && titulo != NULL) {
		strcpy(titulo, this->titulo);
		retorno = 0;
	}

	return retorno;
}

int libro_setAutor(eLibros *this, char *autor) {
	int retorno = -1;

	if (this != NULL && autor != NULL) {
		strcpy(this->autor, autor);
		retorno = 0;
	}

	return retorno;
}

int libro_getAutor(eLibros *this, char* autor) {
	int retorno = -1;

	if (this != NULL && autor != NULL) {
		strcpy(autor, this->autor);
		retorno = 0;

	}

	return retorno;
}

int compareByAutor(void *pElement1, void *pElement2) {
		int retorno;
	char nombre_Uno[50];
	char nombre_Dos[50];

	//eLibros* libro_Uno = (eLibros*) pElement1;
	//eLibros* libro_Dos = (eLibros*) pElement2;

	 libro_getAutor((eLibros*)pElement1, nombre_Uno);
	libro_getAutor((eLibros*)pElement2, nombre_Dos);


	retorno = strcmp(nombre_Uno, nombre_Dos);


	return retorno;
}

int showOneLibro(eLibros *libro) {
	int retorno = -1;

	if (libro != NULL) {
		printf("%4d %40s %40s %40d  %40s  \n", libro->id_Libro, libro->titulo,libro->autor, libro->precio, libro->editorialId);
		retorno = 0;
	}

	return retorno;
}

int compareByEditorial(void *pElement1,int option) {
	int retorno =-1;
	char nombre_Uno[50];


	eLibros *libro= (eLibros*) pElement1;
	libro_getEditorial(libro, nombre_Uno);

	if (option ==1){

	retorno = strcmp(nombre_Uno, "Planeta");
	}
	else if(option ==0){

	retorno = strcmp(nombre_Uno, "SIGLO XXI EDITORES");
	}

	return retorno;
}
void libros_Descuentos(void* libro){
	int validacion;
	int precio;
	int descuento;

	if(libro != NULL){
		validacion =compareByEditorial(libro, 1);
	if(validacion ==0){
		libro_getPrecio(libro, &precio);
		if(precio>=300 ){
			descuento= precio*20/100;
			precio = precio - descuento;
		}
		libro_setPrecio(libro, precio);
	}

	validacion = compareByEditorial(libro, 0);
	if(validacion ==0){
		libro_getPrecio(libro, &precio);
				if(precio<=200){
					descuento= precio*10/100;
					precio = precio - descuento;
				}
				libro_setPrecio(libro, precio);
			}
	}

}









