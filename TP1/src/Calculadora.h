/*
 * Calculadora.h
 *
 *  Created on: 17 abr. 2021
 *      Author: Usuario
 */

#ifndef CALCULADORA_H_
#define CALCULADORA_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>

#define TAM 1000
#define N 0.00
#define MINIMO 1
#define MAXIMO 5


typedef struct
{
   float resultadoSuma;
    float resultadoResta;
    float resultadoDivision;
    float resultadoMultiplicacion;
    double resultadoFactorial1;
    double resultadoFactorial2;
}eResultados;

/**
 * @fn void MostrarMenu(int, int, float, float)
 * @brief Muestra men� de la calculadora, recibe las banderas para saber si se ingresaron los operandos.
 * Recibe los n�meros cargados para mostrarlos en el men�.
 *
 * @param bandera operando 1
 * @param bandera operando 2
 * @param numero ingresado 1
 * @param numero ingresado 2
 * No retorna nada.
 */
void MostrarMenu(int , int , float, float);



/**
 * @fn int ValidarEntero(char[])
 * @brief recibe el dato ingresado por teclado, lo recorre y valida que sean solo n�meros.
 * Solo acepta enteros positivos
 *
 * @param datoIngresado
 * @return devuelve 0 si no es n�merico, devuelve 1 si lo es.
 */
int ValidarEntero(char datoIngresado[]);


/**
* @brief recibe el dato ingresado por teclado, lo recorre y valida que sea n�meros y d�gitos permitidos
 * para un float (',' '.' '-')
 *
 * @param datoIngresado
 * @return devuelve 0 si no es float , devuelve 1 si lo es.
 */
int ValidarFloat(char datoIngresado[]);


/**
 * @fn int ValidarDigitosFloat(float)
 * @brief Al float ingresado (dato que recibe)le resta su entero, y al resultado de esta resta lo compara con 0 para
 * verificar si es m�s grande. En caso de ser m�s grande es porque los decimales del float no son 0.
 * Es decir, no se ingres� un n�mero entero.
 *
 * @param floatIngresado
 * @return retorna 1 si es entero, 0 si no los es
 */
int ValidarDigitosFloat(float floatIngresado);

/**
 * @fn int PedirEntero(char[], char[])
 * @brief Recibe los mensajes para pedir que se ingrese un n�mero y para informar error en caso que la validaci�n
 * a la que se llama (ValidarEntero) indique que no es un n�mero correcto. Devuelve entero ingresado.
 *
 * @param mensajePedirDato
 * @param mensajeError
 * @return n�mero ingresado
 */
int PedirEntero(char mensajePedirDato [], char mensajeError []);

/**
 * @fn int PedirEnteroRango(char[], char[], int, int)
 * @brief Recibe los mensajes para pedir que se ingrese un n�mero y para informar error en caso que la validaci�n
 * (ValidarEntero) indique que no es un n�mero correcto. Esta �ltima funci�n es llamada por la funci�n (PedirEntero)
 * Recibe el n�mero m�ximo y minimo para verificar que est� dentro del rango. Imprime mensaje de error
 * en caso de que no cumpla con el rango.
 *
 * @param mensajePedirDato
 * @param mensajeError
 * @param MIN
 * @param MAX
 * @return Retorna el entero dentro del rango.
 */
int PedirEnteroRango(char mensajePedirDato [], char mensajeError [], int MIN, int MAX);


/**
 * @fn float PedirFloat(char[], char[], char[])
 * @brief Recibe mensaje para pedir Recibe los mensajes para pedir que se ingrese un n�mero y para
 * informar error en caso que la funci�n ValidarFloat retorne 0. Una vez validado dato ingresado lo retorna en float..
 *
 * @param mensaje
 * @param mensajeError
 * @param mensajeOk
 * @return retorna el dato ingresado en float.
 */
float PedirFloat(char mensaje[], char mensajeError[], char mensajeOk []);

/**
 * @fn eResultados CalcularOperaciones(float, float)
 * @brief Recibe los operandos ingresados y llama a todas las funciones de calculos. Devuelve la
 * estructura con los resultados calculados.
 * En esta funci�n se verifica que el segundo operando no sea 0 para poder llamar a la funci�n DividirOperandos
 * En esta funci�n se verifica que los operandos no sea negativos y sean enteros para poder llamar a la
 * funci�n FactorialOperando
 *
 * @param Operando1
 * @param Operando2
 * @return devuelve la estructura con los resultados calculados
 */
eResultados CalcularOperaciones (float , float);

/**
 * @fn float SumarOperandos(float, float)
 * @brief Recibe los operandos ingresados y devuelve el resulltado de la suma.
 *
 * @param Operando1
 * @param Operando2
 * @return Resultado de la suma
 */
float SumarOperandos(float, float );

/**
 * @fn float RestarOperandos(float, float)
 * @brief Recibe los operandos ingresados y devuelve el resulltado de la resta.
 *
 *@param Operando1
 * @param Operando2
 * @return Resultado de la resta
 */
float RestarOperandos(float , float);

/**
 * @fn float DividirOperandos(float, float)
 * @brief Recibe los operandos ingresados y devuelve el resulltado de la division.
 *
 *@param Operando1
 * @param Operando2
 * @return Resultado de la division.
 */
float DividirOperandos(float , float);

/**
 * @brief Recibe los operandos ingresados y devuelve el resulltado de la multiplicaci�n.
 *
 *@param Operando1
 * @param Operando2
 * @return Resultado de la multiplicaci�n
 */
float MultiplicarOperandos(float , float);

/**
 * @fn double FactorialOperando(float)
 * @brief Recibe el operando ingresados y devuelve el resultado del factorial
 *
 * @param Operando1 � Operando2
 * @return Resultado del factorial
 */
double FactorialOperando(float);

/**
 * @fn void MostrarResultados(float, float, eResultados)
 * @brief Recibe los operandos y la estructura con los resultados de los calculos. Luego los imprime.
 * No retorna nada.
 * @param Operando1
 * @param Operando2
 * @param eResultados
 */
void MostrarResultados(float , float , eResultados);


#endif /* CALCULADORA_H_ */
