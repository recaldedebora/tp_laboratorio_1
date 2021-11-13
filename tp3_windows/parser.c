#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

//static char* cabeceraEployee= "";


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno;
	Employee* pAuxiliar;
	retorno=-1;
	char id[50];
	char nombre[50];
	char horasTrabajadas[50];
	char sueldo[50];
	char cabecera[50];
	//char prueba[50];
	int cantidad;

	if(pFile!=NULL && pArrayListEmployee!= NULL)
	{
		/*
		printf("Parser");
		fscanf(pFile,"%[^\n]\n", cabecera);
		printf("%s", cabecera);


		strcpy(cabeceraEployee , cabecera);
		printf("prueba cabecera:  %s", cabeceraEployee);


		printf("Parser despues falsa lectura");*/

		fscanf(pFile,"%[^\n]\n", cabecera);
		while(!feof(pFile))
		{

			cantidad = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", id, nombre,horasTrabajadas,sueldo);
			if(cantidad==4)
			{
				pAuxiliar = employee_newParametros(id,nombre,horasTrabajadas, sueldo);

				if(ll_add(pArrayListEmployee, pAuxiliar) == -1)
				{
					employee_delete(pAuxiliar);
				}
				retorno = 0;
			}
			else
			{
				break;
			}

		}
	}


	return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno;
	Employee* pAuxiliar;
	retorno=-1;

	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		while(!feof(pFile))
		{
			if(!feof(pFile)){
				break;
			}
			pAuxiliar = employee_new();
			fread(pAuxiliar, sizeof(Employee),1,pFile);

			ll_add(pArrayListEmployee,pAuxiliar);
			retorno=0;
		}

	}
    return retorno;
}

int parser_IDFromBinary(FILE* pFile , int* id)
{
	int retorno;
	int* pAuxiliarId;
	retorno=-1;

	if(pFile!=NULL && id!=NULL)
	{
		while(!feof(pFile))
		{
			if(!feof(pFile)){
				break;
			}
			pAuxiliarId = (int*) malloc(sizeof(int));

			if(pAuxiliarId!=NULL){


				fread(pAuxiliarId, sizeof(int),1,pFile);
				id = pAuxiliarId;
				retorno=0;
			}


		}

	}
    return retorno;
}
