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
    controller_ID_loadFromBinary("id.bin");
    do{

    	printf("\n\n****************************************************");
    	printf("Menu:");
    	printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).");
    	printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).");
    	printf("3. Alta de empleado");
    	printf("4. Modificar datos de empleado");
    	printf("5. Baja de empleado");
    	printf("6. Listar empleados");
    	printf("7. Ordenar empleados");
    	printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).");
    	printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario).");
    	printf("10. Salir");
    	printf("*****************************************************");
    	utn_getNumeroRango(&option, "\nIngrese opcion: ", "Error.", 1, 10, 2);


        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);

			break;

            case 2:
            	controller_loadFromBinary("data.bin" , listaEmpleados);
			break;

            case 3:
            	controller_addEmployee(listaEmpleados);
			break;

            case 4:
            	controller_editEmployee(listaEmpleados);
			break;

            case 5:
            	controller_removeEmployee(listaEmpleados);
			break;

            case 6:
            	controller_ListEmployee(listaEmpleados);
			break;

            case 7:
            	controller_sortEmployee(listaEmpleados);
			break;

            case 8:
            	controller_saveAsText("data.csv" , listaEmpleados);
			break;

            case 9:
            	controller_saveAsBinary("data.bin" , listaEmpleados);
			break;


        }
    }while(option != 10);
    return 0;
}

