#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"

/*
static int idStatic = 0;

static int obtenerId(){
	static int id = 0;

	id++;
	return id;
}
*/


	//constructor//genera espacio e inicializa en cero
Employee* employee_new(){
	Employee* unEmpleado;

	unEmpleado = (Employee*) malloc(sizeof(Employee));



	return unEmpleado;

}



Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr){

	Employee* unEmpleado;
	int id;
	int horasTrabajadas;
	int sueldo;
	//llama a new employee y a los seters

	id= atoi(idStr);
	horasTrabajadas=atoi(horasTrabajadasStr);
	sueldo =atoi(sueldoStr);

	unEmpleado= employee_new();
	employee_setId(unEmpleado,id);
	employee_setNombre(unEmpleado,nombreStr);
	employee_setHorasTrabajadas(unEmpleado,horasTrabajadas);
	employee_setSueldo(unEmpleado,sueldo);


	printf("Empleado dado de alta:\n ID: %d - NOMBRE: %s - HORAS: %d - SUELDO: %d\n",id,nombreStr,horasTrabajadas,sueldo);

	return unEmpleado;
}



void employee_delete(Employee* this){
//ver si cambio y pongo retorno
	if(this != NULL){

		free(this);
	}

	//destructor elimina un empleado de la memoria
}


int employee_setId(Employee* this,int id){
	int retorno;
	retorno =0;

	if(this != NULL && id>0){//1500 ejemplo
		this->id = id;
		retorno=1;

	}

	return retorno;
}





int employee_getId(Employee* this,int* id){
	int retorno;
	retorno =0;

	if(this != NULL && id!=NULL){
		*id = this->id;
		retorno=1;

	}
	return retorno;

}


int employee_CompareById(void* employee1, void* employee2){

	int retorno;
	int id1;
	int id2;
	Employee* empleado1;
	Employee* empleado2;

	empleado1 = (Employee*)employee1;
	empleado2 = (Employee*)employee2;


	if(employee1 != NULL && employee2!=NULL)
	{
		employee_getId(empleado1,&id1);
		employee_getId(empleado2,&id2);

		if(id1 == id2)
		{
			retorno=0;
		}
		else
		{
			if(id1 > id2)
			{
				retorno=1;
			}
			else
			{
				retorno=-1;
			}
		}
	}

	return retorno;
}




int employee_setNombre(Employee* this,char* nombre){

	int retorno;
		retorno =0;

		if(this != NULL ){
			strcpy(this->nombre, nombre);
			retorno=1;

		}

		return retorno;
}




int employee_getNombre(Employee* this,char* nombre){
	int retorno;
	retorno =0;

	if(this != NULL && nombre!=NULL){
		strcpy(nombre, this->nombre);
		retorno=1;

	}
	return retorno;

}






int employee_CompareByName(void* employee1, void* employee2){

	int retorno;
	char nombre1[50];
	char nombre2[50];
	Employee* empleado1;
	Employee* empleado2;
	empleado1 = (Employee*)employee1;
	empleado2 = (Employee*)employee2;

	if(employee1 != NULL && employee2!=NULL){
		employee_getNombre(empleado1,nombre1);
		employee_getNombre(empleado2,nombre2);

		retorno= strcmp(nombre1 , nombre2);
	}

	return retorno;
}







int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){

	int retorno;
		retorno =0;

		if(this != NULL){
			this->horasTrabajadas = horasTrabajadas;
			retorno=1;

		}

		return retorno;
}






int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){

	int retorno;
	retorno =0;

	if(this != NULL && horasTrabajadas!=NULL){
		*horasTrabajadas = this->horasTrabajadas;
		retorno=1;

	}
	return retorno;
}






int employee_CompareByHorasTrabajadas(void* employee1, void* employee2){

	int retorno;
	int horasTrabajadas1;
	int horasTrabajadas2;
	Employee* empleado1;
	Employee* empleado2;
	empleado1 = (Employee*)employee1;
	empleado2 = (Employee*)employee2;

	if(employee1 != NULL && employee2!=NULL)
	{
		employee_getHorasTrabajadas(empleado1,&horasTrabajadas1);
		employee_getHorasTrabajadas(empleado2,&horasTrabajadas2);

		if(horasTrabajadas1 == horasTrabajadas2)
		{
			retorno=0;
		}
		else
		{
			if(horasTrabajadas1 > horasTrabajadas2)
			{
				retorno=1;
			}
			else
			{
				retorno=-1;
			}
		}
	}

	return retorno;
}





int employee_setSueldo(Employee* this,int sueldo){

	int retorno;
		retorno =0;

		if(this != NULL){
			this->sueldo = sueldo;
			retorno=1;

		}

		return retorno;
}






int employee_getSueldo(Employee* this,int* sueldo){

	int retorno;
	retorno =0;

	if(this != NULL && sueldo!=NULL){
		*sueldo = this->sueldo;
		retorno=1;

	}
	return retorno;
}





int employee_CompareBySueldo(void* employee1, void* employee2){

	int retorno;
	int sueldo1;
	int sueldo2;
	Employee* empleado1;
	Employee* empleado2;
	empleado1 = (Employee*)employee1;
	empleado2 = (Employee*)employee2;

	if(employee1 != NULL && employee2!=NULL)
	{
		employee_getSueldo(empleado1,&sueldo1);
		employee_getSueldo(empleado2,&sueldo2);

		if(sueldo1 == sueldo2)
		{
			retorno=0;
		}
		else
		{
			if(sueldo1 > sueldo2)
			{
				retorno=1;
			}
			else
			{
				retorno=-1;
			}
		}
	}

	return retorno;
}



void employee_show(Employee* this){

	int id;
	char nombre[50];
	int horasTrabajadas;
	int sueldo;

	if(this !=NULL)
	{
		employee_getId(this,&id);
		employee_getNombre(this,nombre);
		employee_getHorasTrabajadas(this,&horasTrabajadas);
		employee_getSueldo(this,&sueldo);
		printf("%5d | %15s | %15d | %8d\n",id,nombre,horasTrabajadas,sueldo);
	}

}
