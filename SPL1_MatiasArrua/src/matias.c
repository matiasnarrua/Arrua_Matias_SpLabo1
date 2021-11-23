
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "ctype.h"
#include "matias.h"

int menu() {
	int opcion;

	system("cls");
	printf("***---*** Menu ***---***\n\n");
	printf(
			"1. Cargar los datos de los libros desde el archivo Datos.csv (modo texto).\n2. Ordenar por autor (Ascendente).\n3. Listar Libros\n4. Generar Descuentos.\n5. Guardar libros con descuentos.\n6. Salir.\n");
	fflush(stdin);
	printf("Ingrese opcion: ");
	scanf("%d", &opcion);

	return opcion;

}

int menuMod() {
	int opcion;

	system("cls");
	printf("***---*** Menu de Modificacion ***---***\n\n");
	printf(
			"\n1. Cambiar nombre.\n2. Cambiar cantidad de horas trabajadas.\n3. Cambiar salario.\n4. Salir al menu principal.\n");
	fflush(stdin);
	printf("Ingrese opcion: ");
	scanf("%d", &opcion);

	return opcion;
}

int menuOrden() {
	int opcion;

	system("cls");
	printf("***---*** Menu de Ordenamiento ***---***\n\n");
	printf(
			"\n1.Por ID.\n2.Por nombre.\n3.Por horas trabajadas.\n4.Por salario.\n5.Salir \n");
	fflush(stdin);
	printf("Ingrese opcion: ");
	scanf("%d", &opcion);

	return opcion;
}

char getConfirmacion(char mensaje[]) {
	char letter;
	printf("%s", mensaje);
	fflush(stdin);
	scanf("%c", &letter);
	letter = tolower(letter);
	while (letter != 's' && letter != 'n') {
		printf("Error. Ingrese s para si,n para No\n");
		fflush(stdin);
		scanf("%c", &letter);
	}
	return letter;
}

int getStringLetras(char string[]) {
	int i;
	int flag = 0;
	int esEspacio = 0;
	int tam = strlen(string);
	for (i = 0; i < tam; i++) {
		if (string[i] != '\0') {
			if ((string[i] < 'a' || string[i] > 'z')
					&& (string[i] < 'A' || string[i] > 'Z')
					&& string[i] != ' ') {
				flag = -1;
			}
			if (string[i] != ' ') {
				esEspacio = -1;
			}
		}
	}
	if (esEspacio == 0) {
		flag = -1;
	}
	return flag;
}
int getStringNumeros(char string[]) {
	int i;
	int flag = 0;
	int esEspacio = 0;
	int tam = strlen(string);
	for (i = 0; i < tam; i++) {
		if (string[i] != '\0') {
			if ((string[i] < '0' || string[i] > '9') && string[i] != ' ') {
				flag = -1;
			}

		}
	}
	if (esEspacio == -1) {
		flag = -1;
	}
	return flag;
}
void pedirCadena(char mensaje[], char string[]) {
	printf("%s", mensaje);
	fflush(stdin);
	scanf("%[^\n]", string);
	while (getStringLetras(string) == -1) {
		printf("Error. Ingrese solo letras!\n");
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%[^\n]", string);
	}
	firstToUpper(string);
}
void pedirSoloNumeros(char mensaje[], char string[]) {
	printf("%s", mensaje);
	fflush(stdin);
	scanf("%[^\n]", string);
	while (getStringNumeros(string) == -1) {
		printf("Error. Ingrese solo numeros!\n");
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%[^\n]", string);
	}
}

void firstToUpper(char string[]) {
	int tam = strlen(string);
	int i;
	strlwr(string);
	string[0] = toupper(string[0]);
	for (i = 0; i < tam; i++) {
		if (string[i] != '\0') {
			if (isspace(string[i])) {
				string[i + 1] = toupper(string[i + 1]);
			}
		}
	}
}

int getInt(char *mensaje) {
	int numero;
	while ((getValidInt(&numero, mensaje)) == -1) {
		printf("Error. Ingrese solo numeros!\n");
	}
	return numero;
}
int getValidInt(int *numero, char *mensaje) {
	int sePudo = 1;
	int esEspacio = 0;
	char cadenaCargada[20];
	int i;
	printf("%s", mensaje);
	fflush(stdin);
	scanf("%[^\n]", cadenaCargada);
	for (i = 0; i < strlen(cadenaCargada); i++) {
		if (cadenaCargada[i] == ' ') {
			esEspacio = 1;
			break;
		}

		if (cadenaCargada[i] != '\0') {
			if (cadenaCargada[i] < '0' || cadenaCargada[i] > '9') {
				sePudo = -1;
			}
		}
	}
	if (esEspacio == 1) {
		sePudo = -1;
	}
	if (sePudo == 1) {
		*numero = atoi(cadenaCargada);
	}
	return sePudo;
}

int getDosEstados(char* mensaje, int primerEstado, int segundoEstado)
{
    int estadoIngresado;
    estadoIngresado = getInt(mensaje);
    while(primerEstado != estadoIngresado && segundoEstado != estadoIngresado)
    {
        printf("\nError: las opciones son %d o %d.\n",primerEstado,segundoEstado);
        printf(mensaje);
    }
    return estadoIngresado;
}
