/*
 ============================================================================
 Name        : TP1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "Calculadora.h"

#define TAM 1000
#define N 0.00
#define MINIMO 1
#define MAXIMO 5

int main()
{


	setbuf(stdout,NULL);

    int opcion;
    float primerOperando;
    float segundoOperando;

    eResultados misResultados;

    int flagOperando1=0;
    int flagOperando2=0;
    int flagCalculos=0;

   do{

	   MostrarMenu(flagOperando1, flagOperando2, primerOperando, segundoOperando);
	   opcion = PedirEnteroRango("Elija una opcion: ", "Error. Elija una opcion entre 1 y 5: ", MINIMO , MAXIMO);


        switch(opcion)
        {
            case 1:
                primerOperando = PedirFloat("1. Ingrese primer operando: ", "1. Error. Reingrese primer operando: ", "1. Primer operando registrado con éxito\n\n");
                flagOperando1++;

            break;


            case 2:
                segundoOperando = PedirFloat("2. Ingrese segundo operando: ", "2. Error. Reingrese segundo operando: ", "2. Segundo operando registrado con éxito\n\n");
                flagOperando2++;
            break;



            case 3:
            	 if(flagOperando1 !=0 && flagOperando2!=0)
            	 {
            		 misResultados = CalcularOperaciones (primerOperando , segundoOperando);
            		 printf("3. Calculos realizados con éxito. Elija opción 4 para ver los resultados\n\n");
            	     flagCalculos++;
            	 }
            	 else
            	 {
            		 printf("No ingreso los operandos necesarios para hacer los calculos\n\n");
            	 }


            break;


            case 4:
            	if(flagCalculos==0){
            		printf("Error. Antes debe ingresar a la opción 3 para realizar los calculos\n\n");
            	}
            	else
            	{
            		MostrarResultados(primerOperando , segundoOperando , misResultados);
            	}
            	break;

        }



    }while(opcion != 5);

   return EXIT_SUCCESS;
}
