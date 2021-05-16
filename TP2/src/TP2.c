/******************************************************************************

El sistema deberá tener el siguiente menú de opciones:
1. ALTAS: Se debe permitir ingresar un empleado calculando automáticamente el número
de Id. El resto de los campos se le pedirá al usuario.
2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
o Salario o Sector
3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.
4. INFORMAR:
1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.
2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.
NOTA: Se deberá realizar el menú de opciones y las validaciones a través de funciones.
Tener en cuenta que no se podrá ingresar a los casos 2, 3 y 4; sin antes haber realizado la
carga de algún empleado.
Para la realización de este programa, se utilizará una biblioteca llamada “ArrayEmployees”

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "utn.h"
#define TAM_EMPLOYEE 5

int main()
{
	setbuf(stdout, NULL);

    Employee arrayEmployee[TAM_EMPLOYEE];
    int idEmployee=0;
    int opcion;
    int auxiliarId;
    int auxiliarIndice;
    int flagAlta=0;

    if(initEmployees(arrayEmployee, TAM_EMPLOYEE) == 0)
    {
        printf("Array inicializado correctamente. \n\n");
    }

		//addEmployee(arrayEmployee, TAM_EMPLOYEE, &idEmployee, "Juan","Fernández",15000.2,1);
		//addEmployee(arrayEmployee, TAM_EMPLOYEE, &idEmployee, "Ana","Gómez",90000.2,2);
		//addEmployee(arrayEmployee, TAM_EMPLOYEE, &idEmployee, "Maria","Martinez",19000.6,1);
		//addEmployee(arrayEmployee, TAM_EMPLOYEE, &idEmployee, "José","Fernández",10000.8,3);

    do{
    	MostarMenuABM();
        utn_getNumero(&opcion,"\nIngrese opcion: ","\nError.Reingrese.",1,7,2);

        switch(opcion){
            case 1:
            	if(addEmployeeByBuffer(arrayEmployee, TAM_EMPLOYEE, &idEmployee)==0)
            	{
            		flagAlta++;
            	}
            break;

            case 2:
                if(flagAlta != 0 && utn_getNumero(&auxiliarId,"\nIndique el ID del empleado a eliminar","\nID invalido",0,idEmployee,2) ==0)
				{
					auxiliarIndice = findEmployeeById(arrayEmployee, TAM_EMPLOYEE,auxiliarId);
					if(	auxiliarIndice >= 0 && removeEmployee(arrayEmployee, TAM_EMPLOYEE, auxiliarIndice)== 0)
					{
						printf("\nBaja realizada con exito\n");
					}
					else
					{
	                	printf("\nBaja cancelada\n");
					}
				}
            break;

            case 3:
            	if(flagAlta !=0 && modifyEmployee(arrayEmployee, TAM_EMPLOYEE)==0)
            	{
            		printf("\nModificación realizada con exito\n");
            	}
            	else
            	{
					printf("\nBaja cancelada\n");
				}

            break;
            case 4:
            	if(flagAlta !=0){
            		printEmployees(arrayEmployee, TAM_EMPLOYEE);
            	}
			break;
            case 5:
            	if(flagAlta !=0){
            		sortEmployees(arrayEmployee, TAM_EMPLOYEE, 1);
            	}
            break;
            case 6:
				if(flagAlta !=0 && ListarTotalSalario_Promedio_EmpeladosSuperanPromedio(arrayEmployee, TAM_EMPLOYEE)==0){
					printf("No hay empleados registrados, no se puede calcular total ni promedio.");
				}
            break;

        }

    }while(opcion!=7);

	return EXIT_SUCCESS;
}


