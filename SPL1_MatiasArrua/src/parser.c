#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"
#include "parser.h"
#include "libro.h"


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListLibro LinkedList*
 * \return int
 *
 */
int parser_librosFromText(FILE *pFile, LinkedList *pArrayListLibro) {
	int retorno = 1;
	char buffer[5][100];
	int cant;

	eLibros *nLib;

	if (pFile != NULL && pArrayListLibro != NULL) {
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1],buffer[2], buffer[3],buffer[4]);

		while (!feof(pFile)) {
			cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0],buffer[1], buffer[2], buffer[3],buffer[4]);
			if (cant < 5) {
				break;
			}
			nLib = libros_newParam(buffer[0], buffer[1], buffer[2],buffer[3],buffer[4]);
			ll_add(pArrayListLibro, nLib);
			retorno = 0;
		}

	} else {
		printf("Error al abrir el archivo");
		system("pause");
	}

	return retorno;
}
