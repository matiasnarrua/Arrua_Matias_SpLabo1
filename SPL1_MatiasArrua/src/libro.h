#include <stdio.h>
#include <stdlib.h>
#include "string.h"

#ifndef LIBRO_H_
#define LIBRO_H_



typedef struct
{
    int id_Libro;
    char titulo[50];
    char autor[30];
    int precio;
    char editorialId[30];

}eLibros;

#endif /* LIBRO_H_ */

eLibros* eLibro_new();

eLibros* libros_newParam(char *id, char *titulo,char *autor, char *precio, char*editorial);
int libro_setId(eLibros *this, int id);
int libro_getId(eLibros *this, int *id);

int libro_setAutor(eLibros *this, char *autor);
int libro_getAutor(eLibros *this, char *autor);

int libro_setEditorial(eLibros *this, char *editorial);
int libro_getEditorial(eLibros *this, char *editorial);

int libro_setPrecio(eLibros *this, int precio);
int libro_getPrecio(eLibros *this, int *precio);

int libro_setTitulo(eLibros *this, char *titulo);
int libro_getTitulo(eLibros *this, char *titulo);

int compareByAutor(void *pElement1, void *pElement2);
int showOneLibro(eLibros *libro) ;


int compareByEditorial(void *pElement1,int option);
void libros_Descuentos(void* this);

