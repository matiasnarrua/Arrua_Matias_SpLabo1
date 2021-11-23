
#ifndef MATIAS_H_
#define MATIAS_H_

int menu();
int menuMod();
int menuOrden();
char getConfirmacion(char mensaje[]);
int getStringLetras(char string[]);
int getStringNumeros(char string[]);
void pedirCadena(char mensaje[], char string[]);
void pedirSoloNumeros(char mensaje[], char string[]);
void firstToUpper(char string[]);
int getInt(char *mensaje);
int getValidInt(int *numero, char *mensaje);
int getDosEstados(char* mensaje, int primerEstado, int segundoEstado);
#endif /* MATIAS_H_ */

