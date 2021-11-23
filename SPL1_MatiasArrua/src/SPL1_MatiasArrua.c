/*
 ============================================================================
 Name        : SPL1_MatiasArrua.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "matias.h"
#include "Controller.h"
#include "libro.h"


int main()
{
    setbuf (stdout, NULL);
    int option ;
    char check = 'n';
    int validacion;
    int flag =0;

    LinkedList* listaLibros = ll_newLinkedList();

    do{
    	option=menu();
        switch(option)
        {
            case 1:
              validacion =  controller_loadFromText("Datos.csv",listaLibros);
              switch(validacion)
              {

              case 0:
                  printf("\n\nSe abrio exitosamente el archivo\n\n");
                  flag=1;
                  break;
              case 1:
                  printf("\n\nNo pudo acceder a la opcion de carga desde archivo \n\n");
                  break;
              }
              system("pause");
                break;
         case 2:
        	 if (flag == 1){
        	 validacion =  controller_sortLibro_Autor(listaLibros);
        	              switch(validacion)
        	              {
        	              case -1:
        	                  printf("\n\nEl archivo no se pudo Ordenar.\n\n");
        	                  break;
        	              case 0:
        	                  printf("\n\nSe Ordeno exitosamente\n \n");
        	                  break;
        	              case 1:
        	            	  printf("\n\nError\n\n");
        	            	  break;

        	              }
        }
        	 else{
        		 printf("\n\nDebe cargar el archivo primero\n\n");
        	 }
            break;
        case 3:
        	if (flag == 1){
        	        	validacion =    controller_ListLibros(listaLibros);
        	            switch(validacion)
        	            {
        	            case -1:
        	                printf("\n\nNo pudo acceder al listado de empleados\n\n");
        	                break;
        	            case 1:
        	                printf("\n\nLa lista esta vacia\n\n");
        	                break;

        	            }
        	}
        	        	else{
        	        		printf("\n\nDebe cargar el archivo primero\n\n");
        	        	}
        	            break;
            break;
        case 4:
        	if(flag==1){
listaLibros= ll_map(listaLibros,libros_Descuentos);

if(listaLibros != NULL){
	printf("\n\nSe han realizados los descuentos correctamente\n\n");
}
        	}else{
        		printf("\n\nDebe cargar el archivo primero\n\n");
        	}
            break;
        case 5:if(flag==1){
        	if(listaLibros != NULL)
        	                {
        	                    controller_saveAsText(" mapeado.csv", listaLibros);
        	                    printf("\n\nSe creo la lista con descuentos\n\n");
        	                }
        }else{
                		printf("\n\nDebe cargar el archivo primero\n");
                	}
        	                printf("\n");
        	                system("pause");
            break;

        case 6:
        	check = getConfirmacion("\nEsta seguro que desea salir? s/n:  ");


                    break;
        default:
                    printf("Ingrese una opcion correcta.\n");
                    system("pause");
                    break;

        }
    }while(check == 'n');

    printf("Programa finalizado");
    return 0;
}

