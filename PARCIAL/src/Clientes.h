/*
 * Clientes.h
 *
 *  Created on: 1 may. 2021
 *      Author: Llorj
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef CLIENTES_H_
#define CLIENTES_H_

#define QTY_CLIENTES 100
#define QTY_COMPRAS 1000

typedef struct {

	char nombre[51];
	char apellido[51];
	int cuit;
	int flagIsEmpty;
	int idCliente;

} Cliente;

int utn_getNumero(int* pResultado, char* mensaje, char *mensajeError, int minimo, int maximo, int reintentos);
int utn_getDescripcion(char* pResultado, int longitud, char* mensaje, char * mensajeError, int reintentos);
int myGets (char* cadena, int longitud);
int cli_getEmptyIndex(Cliente* array, int limite);
int cli_altaArray(Cliente* array, int limite, int indice, int* id);
int cli_inicilizarArray(Cliente* pArray, int limite);
int cli_buscarId(Cliente* array, int limite, int valorBuscado);
int cli_modificarArray(Cliente* array, int limite, int indice, int* id);
int cli_bajaArray(Cliente* array, int limite, int indice, int* id);
int cli_imprimirArray(Cliente* array, int limite);


#endif /* CLIENTES_H_ */
