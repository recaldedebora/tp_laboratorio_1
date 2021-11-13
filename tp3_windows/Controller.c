#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pArchivo;

	pArchivo = fopen(path, "r");
	int retorno;
	retorno = -1;

	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		if(parser_EmployeeFromText(pArchivo, pArrayListEmployee)== 0)
		{
			retorno = 0;
		}
	}

	fclose(pArchivo);

    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno;
	retorno = -1;
	FILE* pArchivo;

	pArchivo = fopen(path, "rb");

	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		if(parser_EmployeeFromBinary(pArchivo, pArrayListEmployee)== 0)
		{
			retorno = 0;
		}
	}
	fclose(pArchivo);

	return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
	int id;
	int sueldo;
	int horasTrabajadas;
	char idStr[50];
	char nombreStr[50];
	char horasTrabajadasStr[50];
	char sueldoStr[50];
	int len;
	Employee* auxiliar;
	retorno = -1;

	if(pArrayListEmployee!=NULL)
	{
		utn_getNumero(&sueldo, "Ingrese sueldo: ", "Error.", 2);
		utn_getNumero(&horasTrabajadas, "Ingrese horas Trabajadas: ", "Error.", 2);
		utn_getNombre(nombreStr, 50,"Ingrese nombre: ", "Error.", 2);
		id = 1001;
		sprintf(idStr, "%d", id);
		sprintf(horasTrabajadasStr, "%d", horasTrabajadas);
		sprintf(sueldoStr, "%d", sueldo);

		auxiliar = employee_newParametros(idStr,nombreStr,horasTrabajadasStr,sueldoStr);
		ll_add(pArrayListEmployee, (Employee*)auxiliar);
		len= ll_len(pArrayListEmployee);
		printf("LEN DSPUES ALTA: %d", len);
	}
	retorno = 0;

	return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	Employee* unEmpleado;
	Employee* auxiliar;
	int retorno;
	int idEmployee;
	int idBuscado;
	int len;
	int i;
	int opcion;
	int confirmar;
	int flag;
	int flagModificaciones;
	int sueldo;
	int horasTrabajadas;
	char nombreStr[50];
	flag = 0;
	flagModificaciones = 0;
	retorno = -1;

	if(pArrayListEmployee!=NULL)
	{
		controller_ListEmployee(pArrayListEmployee);
		utn_getNumero(&idBuscado, "Ingrese ID del empleado a modificar: ", "Error.", 2);

		len = ll_len(pArrayListEmployee);
		for(i=0; i<len;i++)
		{
			unEmpleado = ll_get(pArrayListEmployee, i);
			employee_getId(unEmpleado,&idEmployee);
			if(idEmployee == idBuscado)
			{
				printf("Empleado a eliminar: \n");
				employee_show(unEmpleado);
				auxiliar = unEmpleado;

				do{
					 printf("\n\nMENU MODIFICACIÓN\n");
					 printf("1. Modificar nombre\n");
					 printf("2. Modificar horas trabajadas\n");
					 printf("3. Modificar sueldo\n");
					 printf("4. Confirmar/Cancelar modificaciones\n");
					 printf("5. Salir\n");
					 utn_getNumeroRango(&opcion, "Ingrese opcion: ", "Error.", 1, 5, 2);
					 switch(opcion)
					 {
						 case 1:

							utn_getNombre(nombreStr, 50,"Ingrese nombre: ", "Error.", 2);
							employee_setNombre(auxiliar,nombreStr);
							flagModificaciones = 1;
						 break;
						 case 2:

							utn_getNumero(&horasTrabajadas, "Ingrese horas Trabajadas: ", "Error.", 2);
							employee_setHorasTrabajadas(auxiliar,horasTrabajadas);
							flagModificaciones = 1;
						 break;
						 case 3:
							utn_getNumero(&sueldo, "Ingrese sueldo: ", "Error.", 2);
							employee_setSueldo(auxiliar,sueldo);

							flagModificaciones = 1;
						 break;

						 case 4:
							if(flagModificaciones == 0)
							{
								printf("No se realizaron modificaciones.");
							}
							else
							{

								confirmar = ConfirmarGestion("DESEA CONTINUAR SI[S] - NO[N]: ","ERROR. REINGRESE.");
								if(confirmar)
								{

									 ll_set(pArrayListEmployee, i,auxiliar);
									 printf("Modificacion/es confirmada/s\n");
									 retorno = 0;
								}
								else
								{
									printf("Modificacion/es cancelada/s\n");
								}
								flag = 1;
							}
						 break;
						 case 5:
							 if(flag == 0)
							 {
								 printf("Debe ingresar a la opción 4 para Confirmar/Cancelar modificaciones\n");
							 }
							 else
							 {
									 opcion = 0;
							 }
						 break;
					 }

				 }while(opcion!=0);

			}

		}

	}


	retorno = 0;

	return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
	int idEmployee;
	int idBuscado;
	int len;
	Employee* unEmpleado;
	int i;
	retorno = -1;

	if(pArrayListEmployee!=NULL)
	{
		controller_ListEmployee(pArrayListEmployee);
		utn_getNumero(&idBuscado, "Ingrese ID del empleado a eliminar: ", "Error.", 2);

		len = ll_len(pArrayListEmployee);
		for(i=0; i<len;i++)
		{
			unEmpleado = ll_get(pArrayListEmployee, i);
			employee_getId(unEmpleado,&idEmployee);
			if(idEmployee == idBuscado)
			{
				printf("Empleado a eliminar: \n");
				employee_show(unEmpleado);
				if(ConfirmarGestion("DESEA CONTINUAR SI[S] - NO[N]: ","ERROR. REINGRESE.")==1)
				{
					ll_remove(pArrayListEmployee, i);

				}
			}

		}
	}


	retorno = 0;

	return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	Employee* unEmpleado;
	int retorno;
	int len;
	int i;
	retorno = -1;

	if(pArrayListEmployee!=NULL)
	{
		len = ll_len(pArrayListEmployee);
		printf("%d", len);
		printf("\nListado de Empleados:");
		printf("\n   Id |          Nombre |   Hs trabajadas |  Sueldo\n");
		for(i=0; i<len;i++)
		{
			unEmpleado = ll_get(pArrayListEmployee, i);
			employee_show(unEmpleado);

		}
	}

	retorno = 0;


	return retorno;
}





/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
	retorno = -1;
	int opcion;
	int criterio;
	int lista;
	LinkedList* listAuxiliar;


	if(pArrayListEmployee!=NULL)
	{
		listAuxiliar= ll_clone(pArrayListEmployee);

		do{
			puts("\n\n*****************************************************");
			printf("\nMENU SORT");
			printf("\n1- Ordenar por ID");
			printf("\n2- Ordenar por Nombre");
			printf("\n3- Ordenar por Horas trabajadas");
			printf("\n4- Ordenar por Sueldo");
			printf("\n5- Salir\n");
			puts("*****************************************************\n");
			utn_getNumeroRango(&opcion, "Ingrese opcion de criterio por el que quiere ordenar: ", "Error.", 1, 5, 2);
			if(opcion!=5)
			{
				utn_getNumeroRango(&criterio, "Ingrese 1 para ordenar de menor a mayor o ingrese 0 para ordenar de mayor a menor: ", "Error.", 0, 1, 2);
				utn_getNumeroRango(&lista, "Ingrese 1 para realizar el ordenamiento sobre la lista origina o ingrese 0 para realizar el ordenamiento sobre una lista auxiliar: ", "Error.", 0, 1, 2);
				if(lista==1){
					printf("\nOrdenando los empleados sobre lista original...\n");
				}
				else{
					printf("\nOrdenando los empleados sobre una lista auxiliar...\n");
				}

				printf("\nAguarde, por favor.\n");
			}


			switch(opcion){
			case 1:
				if(lista==1){
					ll_sort(pArrayListEmployee,employee_CompareById, criterio);
				}
				else{
					ll_sort(listAuxiliar,employee_CompareById, criterio);
				}
			break;
			case 2:
				if(lista==1){
					ll_sort(pArrayListEmployee,employee_CompareByName, criterio);
				}
				else{
					ll_sort(listAuxiliar,employee_CompareByName, criterio);
				}

			break;
			case 3:
				if(lista==1){
					ll_sort(pArrayListEmployee,employee_CompareByHorasTrabajadas, criterio);
				}
				else{
					ll_sort(listAuxiliar,employee_CompareByHorasTrabajadas, criterio);
				}

			break;
			case 4:
				if(lista==1){
					ll_sort(pArrayListEmployee,employee_CompareBySueldo, criterio);
				}
				else{
					ll_sort(listAuxiliar,employee_CompareBySueldo, criterio);
				}
			break;
			case 5:
				opcion=0;
				printf("\nVolviendo al menu principal...\n");
			break;
			}

			if(opcion!=0)
			{
				if(lista==1){
					controller_ListEmployee(pArrayListEmployee);
				}
				else{
					controller_ListEmployee(listAuxiliar);
				}
			}

		}while(opcion != 0);

		ll_deleteLinkedList(listAuxiliar);


	}


	retorno = 0;

	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pArchivo;
	Employee* unEmpleado;
	int retorno;
	int len;
	int i;
	int id;
	char nombre[50];
	int horasTrabajadas;
	int sueldo;
	char cabecera[50]="id,nombre,horasTrabajadas,sueldo";
	retorno = -1;

	if(path!= NULL && pArrayListEmployee!=NULL)
	{
		pArchivo= fopen(path,"w");

		if(pArchivo!=NULL){
			len= ll_len(pArrayListEmployee);
			fprintf(pArchivo, "%s\n",cabecera);
			for(i=0;i<len;i++){
				unEmpleado = ll_get(pArrayListEmployee, i);
				employee_getId(unEmpleado,&id);
				employee_getNombre(unEmpleado,nombre);
				employee_getHorasTrabajadas(unEmpleado,&horasTrabajadas);
				employee_getSueldo(unEmpleado,&sueldo);
				fprintf(pArchivo, "%d,%s,%d,%d\n",id,nombre,horasTrabajadas,sueldo);
				retorno = 0;
			}

		}

	}

	fclose(pArchivo);
	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pArchivo;
	Employee* unEmpleado;
	int retorno;
	int len;
	int i;
	retorno = -1;

	if(path!= NULL && pArrayListEmployee!=NULL)
	{
		pArchivo= fopen(path, "wb");

		if(pArchivo!=NULL){
			len= ll_len(pArrayListEmployee);
			for(i=0;i<len;i++){
				unEmpleado = ll_get(pArrayListEmployee, i);

				fwrite(unEmpleado, sizeof(Employee), 1,pArchivo);
				retorno = 0;

			}

		}

	}

	fclose(pArchivo);
	return retorno;
}



int controller_ID_loadFromBinary(char* path)
{
	int retorno;
	retorno = -1;
	FILE* pArchivoID;
	int numero;

	if(path!=NULL)
	{
		pArchivoID = fopen(path, "rb");

		if(pArchivoID!=NULL)
		{
			fread(&numero, sizeof(int),1, pArchivoID);
			printf("id archivo: %d", numero);
			retorno = 0;
		}
		fclose(pArchivoID);
	}



	return retorno;
}

int controller_ID_saveAsBinary(char* path , int* idStatic)
{
	FILE* pArchivoID;
	int retorno;
	retorno = -1;

	if(path!= NULL && idStatic!=NULL)
	{
		pArchivoID= fopen(path, "wb");

		if(pArchivoID!=NULL){

				fwrite(idStatic, sizeof(int), 1,pArchivoID);
				retorno = 0;

		}

	}

	fclose(pArchivoID);
	return retorno;
}
