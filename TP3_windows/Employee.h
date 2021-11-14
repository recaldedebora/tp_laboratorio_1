#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include <string.h>
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();//constructor//genera espacio e inicializa en cero
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);//llama a new employee y a los seters
void employee_delete(Employee*);//destructor eloimina un empleado de la memoria

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);
int employee_CompareById(void* empleado1, void* empleado2);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);
int employee_CompareByName(void* empleado1, void* empleado2);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);
int employee_CompareByHorasTrabajadas(void* empleado1, void* empleado2);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);
int employee_CompareBySueldo(void* empleado1, void* empleado2);

void employee_show(Employee* this);



#endif // employee_H_INCLUDED
