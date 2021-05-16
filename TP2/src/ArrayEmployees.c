/*
 * ArrayEmployees.c
 *
 *  Created on: 15 may. 2021
 *      Author: Usuario
 */

#include "ArrayEmployees.h"


/*
Para indicar que todas las posiciones del array están vacías, esta función pone la bandera
(isEmpty) en TRUE en todas las posiciones del array.
Ejemplo uso:
r = initEmployees(arrayEmployees, ELEMENTS);
*/

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee* list, int len)
{
    int respuesta = -1;
	int i;
	if(list != NULL && len > 0)
	{
		respuesta = 0;
		for(i=0;i<len;i++)
		{
			list[i].isEmpty = LIBRE;
		}
	}
	return respuesta;
}


////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////

/**
 * \brief Da de alta un empleado en una posicion del array
 * \param array Array de empleados a ser actualizado
 * \param limite Limite del array de empleados
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado al empleado
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int addEmployeeByBuffer(Employee* list, int len, int* id)
{
	int respuesta = -1;
	Employee bufferEmployee;
	int index;

	index = findIndexFree(list, len);

	if(list != NULL && len > 0 && index >= 0 && id != NULL)
	{


		if(	utn_getNombre(bufferEmployee.name,NAME_LEN,"\nNombre?\n","\nERROR\n",2) == 0 &&
			utn_getDescripcion(bufferEmployee.lastName,LASTNAME_LEN,"\nApellido?\n","\nERROR\n",2) == 0 &&
			utn_getNumeroFlotante(&bufferEmployee.salary,"\nSalario?\n","\nERROR\n",0,10000,2) == 0 &&
			utn_getNumero(&bufferEmployee.sector,"Ingrese Sector :","ERROR",0,1,2)==0)
		{
			respuesta = 0;
			addEmployee(list,len,id, bufferEmployee.name,bufferEmployee.lastName,bufferEmployee.salary,bufferEmployee.sector);
		}
	}
	return respuesta;
}




/*
2.2 Función addEmployees
Agrega en un array de empleados existente los valores recibidos como parámetro en la primer
posición libre
Ejemplo uso:
r = addEmployee(arrayEmployees, ELEMENTS,id,name,lastName,salary,sector);
*/

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 *
 */
int addEmployee(Employee* list, int len, int *id, char name[],char lastName[],float salary,int sector)
{
    int respuesta = -1;
    Employee bufferEmployee;

    int index = findIndexFree(list, len);

	if(index != -1 && list != NULL && len > 0 && id != NULL)
	{
			strncpy(bufferEmployee.name,name,NAME_LEN);
			strncpy(bufferEmployee.lastName,lastName,LASTNAME_LEN);
			bufferEmployee.salary = salary;
			bufferEmployee.sector = sector;
			bufferEmployee.id = *id;
			bufferEmployee.isEmpty = OCUPADO;
			list[index] = bufferEmployee;
			(*id)++;
			respuesta = 0;
	}
	return respuesta;
}






int findIndexFree(Employee* list, int len)
{
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (list != NULL && len > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < len; i++)
		{
			//PREGUNTO POR EL ESTADO "LIBRE"
			if (list[i].isEmpty == LIBRE)
			{
				//OBTENGO EL PRIMER INDEX DEL VECTOR "LIBRE" Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

 ////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////

 /*
 2.3 Función findEmployeeById
Busca un empleado recibiendo como parámetro de búsqueda su Id.

 */

 /** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(Employee* list, int len,int id)
{
    int respuesta = -1;
	int i;
	if(list != NULL && len > 0 && id >= 0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].id == id)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}





 ////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////

 /*
 2.4 Función removeEmployee
Elimina de manera lógica (isEmpty Flag en 1) un empleado recibiendo como parámetro su Id.
Ejemplo uso:
r = removeEmployee(arrayEmployees, ELEMENTS,20)
 */

 /** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee* list, int len, int id)
{
    int respuesta = -1;
	if(list != NULL && len > 0 && id < len && id >= 0 && list[id].isEmpty == OCUPADO)
	{
		list[id].isEmpty = LIBRE;
		respuesta = 0;
	}
	return respuesta;
}


////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////



/*
2.5 Función sortEmployees
Ordena el array de empleados por apellido y sector de manera ascendente o descendente.

Ejemplo uso:
r = sortEmployeeByName(arrayEmployees, ELEMENTS, 1);

*/

 /** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee* list, int len, int order)
{
    int respuesta = -1;
    int i;
    int j;
    int auxiliarCmp;
    Employee buffer;

    printf("antes del if");
	if (list != NULL && order > 0)
	{
		printf("despues del if");
		switch (order)
		{
			case 1:
				for (i = 0; i < len - 1; i++)
				{
					for (j = i + 1; j < len; j++)
					{
						//CRITERIO DE ORDENAMIENTO
							auxiliarCmp=strncmp(list[i].lastName, list[j].lastName, LASTNAME_LEN);
							if (auxiliarCmp > 0 || (auxiliarCmp == 0 && list[i].sector > list[j].sector))
							{
								//INTERCAMBIO POSICIONES EN ARRAY
								buffer = list[i];
								list[i] = list[j];
								list[j] = buffer;
								printf("ORDENANDO");
							}

					}
				}
				respuesta = 1;
				break;
			case 0:
				for (i = 0; i < len - 1; i++)
				{
					for (j = i + 1; j < len; j++)
					{
						//CRITERIO DE ORDENAMIENTO
							auxiliarCmp=strncmp(list[i].lastName, list[j].lastName, LASTNAME_LEN);
							if (auxiliarCmp < 0 || (auxiliarCmp == 0 && list[i].sector < list[j].sector))
							{
								//INTERCAMBIO POSICIONES EN ARRAY
								buffer = list[i];
								list[i] = list[j];
								list[j] = buffer;
							}

					}
				}
				respuesta = 1;
				break;

		}//fin switch
    	printf("final ordenar");
    	printEmployees(list, len);
    }//fin if
	return respuesta;
}

//fin funcion



////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////



 /*
 2.6 Función printEmployees
Imprime el array de empleados de forma encolumnada.
Ejemplo uso:
r = printEmployees(arrayEmployees, ELEMENTS)
 */

 /** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int printEmployees(Employee* list, int length)
{
 int respuesta = -1;
	int i;
	if(list != NULL && length > 0 && list->isEmpty == OCUPADO)
	{
		respuesta = 0;
		for(i=0;i<length;i++)
		{
			printf("\nID: %3s - %8s - %8s - %6s - %3s","ID", "NOMBRE", "APELLIDO", "SALARIO", "SECTOR");
			printAnEmployee(&list[i]);
		}
	}
	return respuesta;
}





 /**
 * \brief Imprime los datos de un empleado
 * \param pElemento Puntero al empleado que se busca imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
 int printAnEmployee(Employee* pElemento)
{
	int retorno=-1;
	if(pElemento != NULL && pElemento->isEmpty == OCUPADO)
	{
		retorno=0;
		printf("\nID: %3d - %8s - %8s - %6.2f - %3d",pElemento->id,pElemento->name,pElemento->lastName,pElemento->salary,pElemento->sector);
	}
	return retorno;
}



 ////////////////////////////////////////////////////////////////////////////////////////////
 ////////////////////////////////////////////////////////////////////////////////////////////

 /**
  * \brief Actualiza los datos de un cliente en una posicion del array
  * \param array Array de clientes a ser actualizado
  * \param limite Limite del array de clientes
  * \param indice Posicion a ser actualizada
  * \return Retorna 0 (EXITO) y -1 (ERROR)
  *
  */
 int modifyEmployee(Employee* list, int len)
 {
	    int idIngresado;
	    Employee auxiliar;
	    int i;
	    int respuesta = 0;
	    int opcion;
	    int confirmar;

	    printEmployees(list, len);

	    utn_getNumero(&idIngresado, "Ingrese ID a modificar", "Error", 0, len, 2);

	    for(i=0; i<len; i++)
	    {
	        if(idIngresado == list[i].id)//lo encontre
	        {
	        	printAnEmployee(&list[i]);

	            auxiliar=list[i];

	            do{
	            	printf("\nMENU MODIFICACION\n");
					printf("1. Nombre\n");
					printf("2. Apellido\n");
					printf("3. Salario\n");
					printf("4. Sector\n");
					printf("5. Confirmar\n");
					printf("0. Volver al menu principal\n");
	            	utn_getNumero(&opcion, "Ingrese opcion: ", "Error. Reingrese: ", 0, len, 2);

	                switch(opcion)
	                {

	                    case 1:
	                    	utn_getNombre(auxiliar.name, 50,"Ingrese nombre: ", "Error. Reingrese: ", 2);
	                    break;
	                    case 2:
	                    	utn_getNombre(auxiliar.lastName, 50,"Ingrese Apellido: ", "Error. Reingrese: ", 2);
	                    break;
	                    case 3:
	                    	utn_getNumeroFlotante(&auxiliar.salary, "Ingrese salario: ", "Error. Reingrese: ", 0, SALARY_LEN, 2);
						break;
	                    case 4:
	                    	utn_getNumero(&auxiliar.sector, "Ingrese sector: ", "Error. Reingrese: ", 0, SECTOR_LEN, 2);
						break;
	                    case 5:
	                    	utn_getNumero(&confirmar, "DESEA CONTINUAR SI[1] - NO[0]: ", "Error. Reingrese: ", 0, 1, 2);

	                            if(confirmar)
	                            {
	                                list[i] = auxiliar;
	                                respuesta = 1;
	                            }
	                        opcion =0;
	                    break;
	                }

	            }while(opcion!=0);

	            break;
	        }
	    }

	    return respuesta;
 }


/**
 *
 *@fn int ListarTotalSalario_Promedio_EmpeladosSuperanPromedio(Employee*, int)
 * @brief Calula el total de los salarios, el promedio y la cantidad de empleados que superan el promedio.
 * \param array Array de clientes a ser actualizado
  * \param limite Limite del array de clientes
 * @return Retorna 1 si pudo realizar los calculos, y 0 si no pudo.
 */

int ListarTotalSalario_Promedio_EmpeladosSuperanPromedio(Employee* list, int len)
{
	int i;
	int respuesta=0;
	float acumSalarios=0;
	float promedioSalarios;
	int contadorEmpleados=0;
	int contadorEmpleadosSuperanPromedio=0;

	if(list != NULL && len > 0 && list->isEmpty == OCUPADO)
	{
		for(i=0; i<len; i++)
		{
			acumSalarios= acumSalarios + list->salary;
			contadorEmpleados++;
		}
	}

	if(contadorEmpleados !=0){
		promedioSalarios = (float)acumSalarios / contadorEmpleados;
		respuesta = 1;
	}

	if(list != NULL && len > 0 && list->isEmpty == OCUPADO)
	{
		for(i=0; i<len; i++)
		{
			if(list->salary >= promedioSalarios)
			{
				contadorEmpleadosSuperanPromedio++;
			}
		}
	}

	printf("La suma de todos los salarios es: %.2f \nEl promedio de salarios es: %.2f\nLa cantidad de empleados superan el salario promedio es: %d \n" , acumSalarios, promedioSalarios, contadorEmpleadosSuperanPromedio );

	return respuesta;
}


void MostarMenuABM(){
	printf("\n\n***MENU ABM EMPLEADOS***");
	printf("\n\n1. ALTA\n");
	printf("2. BAJA\n");
	printf("3. MODIFICACION\n");
	printf("4. LISTAR\n");
	printf("5. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.\n");
	printf("6. Total y promedio de los salarios, y cuántos empleados superan el salario promedio. \n");
	printf("7. Salir\n");

}

