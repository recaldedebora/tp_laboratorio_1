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
    FILE* pArchivo;
    int numero;
    numero=1000;

    pArchivo= fopen("id.bin","wb");

    if(pArchivo!=NULL)
    {
    fwrite(&numero, sizeof(int),1, pArchivo);
    fclose(pArchivo);
    }

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

    controller_ID_saveAsBinary("id.bin");

    return 0;
}

