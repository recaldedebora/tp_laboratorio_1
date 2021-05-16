/*
 * utn.h
 *
 *  Created on: 15 may. 2021
 *      Author: Usuario
 */

#ifndef UTN_H_
#define UTN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM_BUFFER 1000
//#include <stdio_ext.h>


int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int utn_getDescripcion(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int ConfirmarGestion(char MSJ[], char ERROR_MSJ[]);
char Get_Char(char MSJ[], char ERROR_MSJ[]);
int Validar_OnlyAlphabet(char pData[]);
#endif /* UTN_H_ */
