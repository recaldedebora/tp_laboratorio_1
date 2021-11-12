#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
    int option = 0;
    LinkedList* listaEmpleados;
    LinkedList* listaEmpleados = ll_newLinkedList();//CREAR ESPACIO DE MEMORIA DINAMICA EN EL HEAP

    e1 = (Employee*) malloc(sizeof(Empleyee*));
    e1->id=1009;
    e1->horasTrabajadas = 130;
    e1->sueldo=500;
    strcpy(e5->"Ana");


    ll_add(listaEmpleados, e1);
    ll_add(listaEmpleados, e2);
    ll_add(listaEmpleados, e3);
    ll_add(listaEmpleados, e4);

    len = ll_len(listaEmpleados);

    printf("Len: %d", len);

    for(i=0; i<len; i++){

    	aux=(Empleyee*) ll_get(listaEmpleados, i);
    	printf ("%4d %10s %4d %8d", aux->id, aux->nombre, aux->horasTrabajadas, aux->idsueldo );//getter
    }

    e5 = (Employee*) malloc(sizeof(Empleyee*));
    e5->id=1009;
    e5->horasTrabajadas = 130;
    e5->sueldo=500;
    strcpy(e5->"Harry/Mathi");

    ll_set(listaEmpleados, 1 , 5);



    /*do{
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
        }
    }while(option != 10);*/
    return 0;
}

