/*
 * ArrayEmployees.h
 *
 *  Created on: 15 may. 2021
 *      Author: Usuario
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#include "utn.h"
#define NAME_LEN 20
#define LASTNAME_LEN 20
#define SALARY_LEN 200000
#define SECTOR_LEN 20
#define LIBRE 0
#define OCUPADO 1

struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}typedef Employee;

void MostarMenuABM();
int initEmployees(Employee* list, int len);
int findIndexFree(Employee* list, int len);
int addEmployee(Employee* list, int len, int* id, char name[],char lastName[],float salary,int sector);
int findEmployeeById(Employee* list, int len,int id);
int removeEmployee(Employee* list, int len, int id);
int sortEmployees(Employee* list, int len, int order);
int printEmployees(Employee* list, int length);
int printAnEmployee(Employee* pElemento);
int modifyEmployee(Employee* list, int len);
int addEmployeeByBuffer(Employee* list, int len, int* id);
int ListarTotalSalario_Promedio_EmpeladosSuperanPromedio(Employee* list, int len);

#endif /* ARRAYEMPLOYEES_H_ */
