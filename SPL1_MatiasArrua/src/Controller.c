#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "parser.h"
#include "libro.h"
#include "matias.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char *path, LinkedList *pArrayList) {
	FILE *auxF;
	int retorno = 1;
	auxF = fopen(path, "r");
	if (auxF == NULL) {
		printf("Error al abrir el archivo");

	} else {
		parser_librosFromText(auxF, pArrayList);
		retorno = 0;
	}
	fclose(auxF);
	return retorno;
}


int controller_sortLibro_Autor(LinkedList *pArrayList)
	{
	int retorno = 1;
			int isEmpty = 0;

			if (pArrayList != NULL) {

				isEmpty = ll_isEmpty(pArrayList);

				if (isEmpty != 1) {

							retorno = ll_sort(pArrayList, compareByAutor,1);

							printf("\n");
							system("pause");
				}
			}
			return retorno;
		}

int controller_ListLibros(LinkedList *pArrayList) {
	int retorno = -1;
	int len;


	if (pArrayList != NULL) {
		retorno = 0;

		len = ll_len(pArrayList);
		eLibros *auxLibro;
		printf("%4s%40s%40s%40s%32s     \n", "Id", "Titulo", "Autor","Precio","Editorial");
		for (int i = 0; i < len; i++) {

			auxLibro = (eLibros*) ll_get(pArrayList, i);
			showOneLibro(auxLibro);

			/*if (i != 0 && i % 10 == 0) {
				system("pause");
	}*/
	}
			}else {
				retorno = 1;
		}

	return retorno;
}


int controller_saveAsText(char *path, LinkedList *pArrayListEmployee) {
		int retorno = -1;
		   int len;
		 FILE* pFile;
		    eLibros* auxLibros = NULL;

		    int idStr;
		    char tituloStr[51];
		    char autorStr[51];
		    int precioStr;
		    char editorialStr[51];

		    if(pArrayListEmployee != NULL && path != NULL)
		    {
		        pFile = fopen(path, "w");
		        len = ll_len(pArrayListEmployee);

		        if(pFile != NULL)
		        {
		            fprintf(pFile, "Id,Titulo,Autor,Precio,Editorial\n");
		            for(int i=0; i<len; i++)
		            {
		                auxLibros = (eLibros*) ll_get(pArrayListEmployee, i);
		                libro_getId(auxLibros, &idStr);
		                libro_getTitulo(auxLibros, tituloStr);
		                libro_getAutor(auxLibros, autorStr);
		                libro_getPrecio(auxLibros, &precioStr);
                        libro_getEditorial(auxLibros, editorialStr);
		                fprintf(pFile, "%d,%s,%s,%d,%s\n", idStr, tituloStr, autorStr, precioStr,editorialStr);
		            }
		        }
		        fclose(pFile);
		        retorno = 0;
		    }
		    return retorno;
	}
