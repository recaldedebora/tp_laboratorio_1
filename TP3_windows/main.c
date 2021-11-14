#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "UTN_input.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout,NULL);
    int option;
    LinkedList* listaEmpleados = ll_newLinkedList();
    int flag;
    int flagGuardado;
    int respuesta;
    int exito;
    flag = 0;
    flagGuardado=0;

    controller_SiguienteID("id.bin");
    do{

    	printf("\n\n****************************************************");
    	printf("\nMenu:");
    	printf("\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).");
    	printf("\n2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).");
    	printf("\n3. Alta de empleado");
    	printf("\n4. Modificar datos de empleado");
    	printf("\n5. Baja de empleado");
    	printf("\n6. Listar empleados");
    	printf("\n7. Ordenar empleados");
    	printf("\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).");
    	printf("\n9. Guardar los datos de los empleados en el archivo data.bin (modo binario).");
    	printf("\n10. Salir");
    	printf("\n*****************************************************");
    	utn_getNumeroRango(&option, "\nIngrese opcion: ", "Error.", 0, 10, 2);


        switch(option)
        {
            case 1:
            	if(controller_loadFromText("data.csv",listaEmpleados)==0){
            		printf("\nLista cargada correctamente");
					flag++;
            	}else
            	{
            		printf("\nLista NO cargada correctamente");
            	}
			break;

            case 2:
            	if(controller_loadFromBinary("data.bin" , listaEmpleados)==0){
            		printf("\nLista cargada correctamente");
					flag++;
            	}else
            	{
            		printf("\nLista NO cargada correctamente");
            	}
			break;

            case 3:
            	if(flag == 0){
                    printf("Antes de dar de alta un empleado debe cargar la lista guardada en el archivo. (opcion 1 o 2)");
            	}
            	else{
            		exito = controller_addEmployee(listaEmpleados);
            		if(exito ==1){
            			printf("\nAlta registrada correctamente");
            		}
            		else{
            			if(exito ==0){
            				printf("\nAlta calcelada");
            			}
            			else
            			{
            				printf("\nError en el alta.");
            			}

            		}
                }
			break;

            case 4:
            	if(flag == 0){
					printf("Antes de modificar un empleado debe cargar la lista guardada en el archivo. (opcion 1 o 2)");
				}
				else{
					exito = controller_editEmployee(listaEmpleados);
					if(exito ==1){
						printf("\nModificacion registrada correctamente");
					}
					else{
						if(exito ==0){
							printf("\nModificacion calcelada");
						}
						else
						{
							printf("\nError en la modificacion.");
						}

					}
				}
			break;

            case 5:
            	if(flag == 0){
					printf("Antes de eliminar un empleado debe cargar la lista guardada en el archivo. (opcion 1 o 2)");
				}
				else{
					exito = controller_removeEmployee(listaEmpleados);
					if(exito ==1){
						printf("\nEliminacion realizada correctamente");
					}
					else{
						if(exito ==0){
							printf("\nEliminacion calcelada");
						}
						else
						{
							printf("\nError en la eliminacion.");
						}

					}
				}
			break;

            case 6:
            	if(flag == 0){
					printf("\nAntes de listar los empleados debe cargar la lista guardada en el archivo. (opcion 1 o 2)");
				}
				else{
					if(controller_ListEmployee(listaEmpleados)==-1){
						printf("\nError al listar.");
					}
				}
			break;

            case 7:
            	if(flag == 0){
					printf("\nAntes de ordenar la lista de empleados debe cargar la lista guardada en el archivo. (opcion 1 o 2)");
				}
				else{
					if(controller_sortEmployee(listaEmpleados)==-1){
						printf("\nError al ordenar.");
					}
				}
			break;

            case 8:
            	if(flag == 0){
					printf("\nAntes de guardar debe abrir la lista guardada en el archivo. (opcion 1 o 2)");
				}
				else{
					flagGuardado++;
					exito = controller_saveAsText("data.csv" , listaEmpleados);
					if(exito ==1){
						printf("\nGuardado realizado correctamente");
					}
					else{
						if(exito ==0){
							printf("\nGuardado calcelado");
						}
						else
						{
							printf("\nError en el guardado.");
						}

					}
				}
			break;

            case 9:
            	if(flag == 0){
					printf("Antes de guardar debe abrir la lista guardada en el archivo. (opcion 1 o 2)");
				}
				else{
					flagGuardado++;
					exito = controller_saveAsBinary("data.bin" , listaEmpleados);
					if(exito ==1){
						printf("\nGuardado realizado correctamente");
					}
					else{
						if(exito ==0){
							printf("\nGuardado calcelado");
						}
						else
						{
							printf("\nError en el guardado.");
						}

					}
				}
			break;
            case 10:
            	if(flagGuardado == 0){
            		respuesta = ConfirmarGestion("Está por salir sin guardar los cambios, ¿Desea continuar? SI[S] - NO[N]: ","ERROR. REINGRESE.");
            		if(respuesta == 1){
            			option = 0;
            		}
            	}
				else{
					option = 0;
				}
            break;


        }
    }while(option != 0);

    controller_ID_saveAsBinary("id.bin");

    return 0;
}

