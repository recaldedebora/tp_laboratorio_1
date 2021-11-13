/*
 * parser.h
 *
 *  Created on: 9 nov. 2021
 *      Author: Usuario
 */

#ifndef PARSER_H_
#define PARSER_H_

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_IDFromBinary(FILE* pFile , int* id);
#endif /* PARSER_H_ */
