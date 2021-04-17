/*
 * Calculadora.c
 *
 *  Created on: 17 abr. 2021
 *      Author: Usuario
 */


//valdaciones
#include "Calculadora.h"

void MostrarMenu(int flag1, int flag2, float operando1, float operando2){

    if(flag1 == 0 && flag2 == 0){
        printf("\n\nMENÚ CALCULADORA\n");
        printf("1. Ingresar primer operando (A=x)\n");
        printf("2. Ingresar primer operando (B=y)\n");
        printf("3. Calcular todas las operaciones\n");
        printf("a) Calcular la suma (A+B)\n");
        printf("b) Calcular la resta (A-B)\n");
        printf("c) Calcular la division (A/B)\n");
        printf("d) Calcular la multiplicacion (A*B)\n");
        printf("e) Calcular los factoriales (A!) y (B!)\n");
        printf("4. Mostrar resultado de todas las operaciones\n");
        printf("5. Salir\n");
    }
    else if(flag1 != 0 && flag2 == 0){
        printf("\n\nMENÚ CALCULADORA\n");
        printf("1. Ingresar primer operando (A=%.2f)\n", operando1);
        printf("2. Ingresar primer operando (B=y)\n");
        printf("3. Calcular todas las operaciones\n");
        printf("a) Calcular la suma (%.2f+B)\n", operando1);
        printf("b) Calcular la resta (%.2f-B)\n", operando1);
        printf("c) Calcular la division (%.2f/B)\n", operando1);
        printf("d) Calcular la multiplicacion (%.2f*B)\n", operando1);
        printf("e) Calcular los factoriales (%.2f!) y (B!)\n", operando1);
        printf("4. Mostrar resultado de todas las operaciones\n");
        printf("5. Salir\n");
    }
    else if(flag1 == 0 && flag2 != 0){
        printf("\n\nMENÚ CALCULADORA\n");
        printf("1. Ingresar primer operando (A=x)\n");
        printf("2. Ingresar primer operando (B=%.2f)\n", operando2);
        printf("3. Calcular todas las operaciones\n");
        printf("a) Calcular la suma (A+%.2f)\n", operando2);
        printf("b) Calcular la resta (A-%.2f)\n", operando2);
        printf("c) Calcular la division (A/%.2f)\n", operando2);
        printf("d) Calcular la multiplicacion (A*%.2f)\n", operando2);
        printf("e) Calcular los factoriales (A!) y (%.2f!)\n", operando2);
        printf("4. Mostrar resultado de todas las operaciones\n");
        printf("5. Salir\n");
    }
    else{
        printf("\n\nMENÚ CALCULADORA\n");
        printf("1. Ingresar primer operando (A=%.2f)\n", operando1);
        printf("2. Ingresar primer operando (B=%.2f)\n", operando2);
        printf("3. Calcular todas las operaciones\n");
        printf("a) Calcular la suma (%.2f+%.2f)\n", operando1, operando2);
        printf("b) Calcular la resta (%.2f-%.2f)\n", operando1, operando2);
        printf("c) Calcular la division (%.2f/%.2f)\n", operando1, operando2);
        printf("d) Calcular la multiplicacion (%.2f*%.2f)\n", operando1, operando2);
        printf("e) Calcular los factoriales (%.2f!) y (%.2f!)\n", operando1, operando2);
        printf("4. Mostrar resultado de todas las operaciones\n");
        printf("5. Salir\n");
    }
}

int ValidarEntero(char datoIngresado[])//devuelvo 1 si es entero, 0 si no los es
{
	return 1;

	if(strlen(datoIngresado) > 0){
		for(int i = 0; i < strlen(datoIngresado); i++){
			if(isdigit(datoIngresado[i]) == 0){
				return 0;
				break;
			}
		}
	} else{
		return 0;
	}
}

int ValidarFloat(char datoIngresado[]){//devuelvo 1 si es float, 0 si no los es


	int contadorSigno = 0;
	return  1;

	if(strlen(datoIngresado) > 0){

		for(int i = 0; i < strlen(datoIngresado); i++){

            if(isdigit(datoIngresado[i]) ==0){

                if(i==0 && datoIngresado[i] != '-'){
    				return 0;
    				break;
                }
    		}
    		else if(datoIngresado[i] == '.'|| datoIngresado[i] == ','){
    			contadorSigno++;

    		}
    		else
    		{
    			return 0;
    			break;

            }
        }//fin for

        if(contadorSigno > 1){
    		return  0;
        }

	}
	else{
		return  0;
	}
}//fin funcion

int ValidarDigitosFloat(float floatIngresado)//devuelvo 1 si es entero, 0 si no los es
{

    int entero;


    entero = (int)floatIngresado;

    if((floatIngresado - entero) == 0 && entero > 0){
        return 1;
    }

    return 0;

}
//Pedir dato

int PedirEntero(char mensajePedirDato [], char mensajeError []){
	char datoIngresado[TAM];
	int numeroIngresado;

	printf("%s", mensajePedirDato);
	fflush(stdin);
	scanf("%[^\n]" , datoIngresado);

	while(ValidarEntero(datoIngresado) == 0){
		printf("%s", mensajeError);
		fflush(stdin);
		scanf("%[^\n]" , datoIngresado);
	}

	numeroIngresado = atoi(datoIngresado);

	return numeroIngresado;
}

int PedirEnteroRango(char mensajePedirDato [], char mensajeError [], int minimo, int maximo){

    int enteroValidado = PedirEntero(mensajePedirDato, mensajeError);

	while(enteroValidado < minimo || enteroValidado > maximo){
		printf("ERROR. Fuera de rango -> [MIN]=%d [MAX]=%d.\n", minimo , maximo);
		enteroValidado = PedirEntero(mensajePedirDato, mensajeError);
	}

	return enteroValidado;


}

float PedirFloat(char mensaje[], char mensajeError[], char mensajeOk []){

    char datoIngresado [TAM];
	float numeroIngresado;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%[^\n]" , datoIngresado);;

	while(ValidarFloat(datoIngresado) == 0){
		printf("%s", mensajeError);
		fflush(stdin);
		scanf("%[^\n]" , datoIngresado);;
	}

	numeroIngresado = atof(datoIngresado);
	printf("\nUsted ingresó: %.2f \n%s", numeroIngresado, mensajeOk);

	return numeroIngresado;

}

//Calculos

eResultados CalcularOperaciones (float operando1, float operando2){

    eResultados resultadosCalculados;

    resultadosCalculados.resultadoSuma = SumarOperandos(operando1, operando2);

    resultadosCalculados.resultadoResta = RestarOperandos(operando1, operando2);

    if(operando2 !=0){
        resultadosCalculados.resultadoDivision = DividirOperandos(operando1, operando2);
    }
    else
    {
        resultadosCalculados.resultadoDivision = N;
    }

    resultadosCalculados.resultadoMultiplicacion = MultiplicarOperandos(operando1, operando2);


    if(ValidarDigitosFloat(operando1) == 1){
        resultadosCalculados.resultadoFactorial1 = FactorialOperando(operando1);
    }
    else
    {
        resultadosCalculados.resultadoFactorial1 = N;
    }

    if(ValidarDigitosFloat(operando2) == 1){
        resultadosCalculados.resultadoFactorial2 = FactorialOperando(operando2);
    }
    else
    {
        resultadosCalculados.resultadoFactorial2 = N;
    }

    return resultadosCalculados;
}

//Calculos
float SumarOperandos(float num1 , float num2){
    float resultadoSuma;
    resultadoSuma = num1 + num2;

    return resultadoSuma;

}

float RestarOperandos(float num1 , float num2){

    float resultadoResta;
    resultadoResta = num1 - num2;

    return resultadoResta;

}


float DividirOperandos(float num1 , float num2){
    float resultadoDivision;
    resultadoDivision = num1 / num2;

    return resultadoDivision;
}

float MultiplicarOperandos(float num1 , float num2){
    float resultadoMultiplicacion;
    resultadoMultiplicacion = num1 * num2;

    return resultadoMultiplicacion;
}


double FactorialOperando(float numero){

    int resultadoFactorial;
    resultadoFactorial = 1;

    for(int i=1; i<=(int)numero; i++) {
		resultadoFactorial = resultadoFactorial * i;
    }

	return resultadoFactorial;
}

void MostrarResultados(float primerOperando, float segundoOperando, eResultados resultados)
{

    printf("\nRESULTADOS:\n");
    printf("A. El resultado de la suma de %.2f + %.2f es: %.2f \n", primerOperando, segundoOperando , resultados.resultadoSuma);
    printf("B. El resultado de la resta de %.2f - %.2f es: %.2f \n", primerOperando, segundoOperando , resultados.resultadoResta);
    if(resultados.resultadoDivision != N)
    {
        printf("C. El resultado de la division de %.2f / %.2f es: %.2f\n", primerOperando, segundoOperando, resultados.resultadoDivision);
    }
    else
    {
        printf("C. No se puede dividir por cero\n");
    }
    printf("D. El resultado de la multiplicacion de %.2f / %.2f es: %.2f \n", primerOperando, segundoOperando , resultados.resultadoMultiplicacion);


    if(resultados.resultadoFactorial1 != N){
        printf("E.1. El resultado del factorial de %.2f (primer operando) es: %.2f \n", primerOperando, resultados.resultadoFactorial1);
    }
    else
    {
        printf("E.1. No se puede calcular el factorial de %.2f (primer operando), ya que no es un entero positivo.\n" , primerOperando);
    }

    if(resultados.resultadoFactorial2 != N){
        printf("E.2. El resultado del factorial de %.2f (segundo operando) es: %.2f \n", segundoOperando, resultados.resultadoFactorial2);
    }
    else
    {
        printf("E.2. No se puede calcular el factorial de %.2f (segundo operando), ya que no es un entero positivo.\n" , segundoOperando);
    }
}
